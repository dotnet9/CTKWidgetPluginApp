#include "pluginimpl.h"
#include <ctkPluginContext.h>
#include <QtDebug>
#include <clientlistview.h>

PluginImpl::PluginImpl(ctkPluginContext* context)
    : m_pContext(context)
{
    context->registerService<PluginService>(this);
}

QWidget* PluginImpl::getWidget()
{
    return new ClientListView(m_pContext);
}
