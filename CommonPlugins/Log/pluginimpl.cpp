#include "pluginimpl.h"
#include <ctkPluginContext.h>
#include <QtDebug>
#include <logview.h>

PluginImpl::PluginImpl(ctkPluginContext* context)
    : m_pContext(context)
{
    context->registerService<PluginService>(this);
    m_pLogView = new LogView(context);
}

PluginImpl::~PluginImpl()
{
    delete m_pLogView;
}

QWidget* PluginImpl::getWidget()
{
    return m_pLogView;
}
