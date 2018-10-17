#include "pluginactivator.h"
#include "pluginimpl.h"
#include "showclientmonitoreventhandler.h"
#include "showclientplugineventhandler.h"
#include "service/event/ctkEventConstants.h"
#include "clientmonitorview.h"

void PluginActivator::start(ctkPluginContext *context)
{
    m_pContext = context;
    s.reset(new PluginImpl(context));

    m_pEventHandler = new ShowClientMonitorEventHandler();
    connect(m_pEventHandler, &ShowClientMonitorEventHandler::showMonitorView,
            this, &PluginActivator::showMonitorViewHandler);

    ctkDictionary props;
    props[ctkEventConstants::EVENT_TOPIC] = "com/lsquange/client/published";
    context->registerService<ctkEventHandler>(m_pEventHandler, props);


    m_pPluginEventHandler = new ShowClientPluginEventHandler();
    connect(m_pPluginEventHandler, &ShowClientPluginEventHandler::showPluginView,
            this, &PluginActivator::showPluginViewHandler);

    ctkDictionary props2;
    props2[ctkEventConstants::EVENT_TOPIC] = "com/lsquange/clientplugin/published";
    context->registerService<ctkEventHandler>(m_pPluginEventHandler, props2);
}

void PluginActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context);
}

void PluginActivator::showMonitorViewHandler(const int clientMark)
{
    ClientMonitorView* view = nullptr;
    if(m_mapViews.contains(clientMark)) {
        view = m_mapViews[clientMark];
        if(view == nullptr || view->isHidden()) {
            delete view;
            view = nullptr;
            m_mapViews.remove(clientMark);
        }
    }
    if(view == nullptr) {
        view = new ClientMonitorView(clientMark, m_pContext);
        m_mapViews.insert(clientMark, view);
        view->show();
    }
}

void PluginActivator::showPluginViewHandler(const int clientMark, const QString& clientPluginMark, QWidget* view)
{
    ClientMonitorView* monitorView = nullptr;
    if(m_mapViews.contains(clientMark)) {
        monitorView = m_mapViews[clientMark];
    }
    if(monitorView == nullptr || monitorView->isHidden()) {
        return;
    }
    monitorView->showPlugin(clientPluginMark, view);
}
