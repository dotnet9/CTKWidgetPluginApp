#include "pluginimpl.h"
#include <ctkPluginContext.h>
#include <QtDebug>

PluginImpl::PluginImpl(ctkPluginContext* context)
    : m_pContext(context)
{
    context->registerService<PluginService>(this);
}

QWidget* PluginImpl::getWidget()
{
    return nullptr;
}
