#include "pluginimpl.h"
#include <ctkPluginContext.h>
#include <QtDebug>
#include <clientcountview.h>

PluginImpl::PluginImpl(ctkPluginContext* context)
    : m_pContext(context)
{
    context->registerService<PluginService>(this);
}

QWidget* PluginImpl::getWidget()
{
    return new ClientCountView(m_pContext);
}
