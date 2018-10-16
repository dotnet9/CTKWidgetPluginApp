#include "pluginimpl.h"
#include <ctkPluginContext.h>
#include <QtDebug>
#include <logview.h>

PluginImpl::PluginImpl(ctkPluginContext* context)
    : m_pContext(context)
{
    context->registerService<PluginService>(this);
}

QWidget* PluginImpl::getWidget()
{
    return new LogView(m_pContext);
}
