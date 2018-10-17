#include "pluginactivator.h"

#include "pluginimpl.h"
#include "showclientplugineventhandler.h"
#include "service/event/ctkEventConstants.h"
#include "clientbaseview.h"
#include <service/event/ctkEventAdmin.h>

void PluginActivator::start(ctkPluginContext *context)
{
    m_pContext = context;
    s.reset(new PluginImpl(m_pContext));

    m_pEventHandler = new ShowClientPluginEventHandler();
    connect(m_pEventHandler, &ShowClientPluginEventHandler::showPluginView,
            this, &PluginActivator::showPluginViewHandler);

    ctkDictionary props;
    props[ctkEventConstants::EVENT_TOPIC] = "com/lsquange/clientmonitor/published";
    m_pContext->registerService<ctkEventHandler>(m_pEventHandler, props);
}

void PluginActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context);
}

void PluginActivator::showPluginViewHandler(const int clientMark, const QString& clientPluginMark)
{
    if("ClientPlugin.ClientBase" != clientPluginMark) {
        return;
    }

    ClientBaseView* view = nullptr;
    if(m_mapViews.contains(clientMark)) {
        view = m_mapViews[clientMark];
        if(view == nullptr || view->isHidden()) {
            delete view;
            view = nullptr;
            m_mapViews.remove(clientMark);
        }
    }
    if(view == nullptr) {
        view = new ClientBaseView(clientMark);
        m_mapViews.insert(clientMark, view);
    }


    ctkServiceReference ref;
    ctkEventAdmin* eventAdmin;
    ref = m_pContext->getServiceReference<ctkEventAdmin>();
    if(ref)
    {
        eventAdmin = m_pContext->getService<ctkEventAdmin>(ref);
        m_pContext->ungetService(ref);
    }

    if(eventAdmin) {
        QString topic("com/lsquange/clientplugin/published");
        ctkDictionary message;
        message["ClientMark"] = clientMark;
        message["ClientPluginMark"] = clientPluginMark;
        message["View"] = QVariant::fromValue(view);
        eventAdmin->postEvent(ctkEvent(topic, message));
    }
}
