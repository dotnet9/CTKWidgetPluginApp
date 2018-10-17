#include "pluginimpl.h"
#include <ctkPluginContext.h>
#include <QtDebug>
#include <clientmonitorview.h>

PluginImpl::PluginImpl(ctkPluginContext* context)
    : m_pContext(context)
{
    context->registerService<PluginService>(this);
}

QWidget* PluginImpl::getWidget()
{
    return nullptr;//new ClientMonitorView(m_pContext);
}
