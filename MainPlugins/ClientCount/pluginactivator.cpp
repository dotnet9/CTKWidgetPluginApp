#include "pluginactivator.h"
#include "pluginimpl.h"

void PluginActivator::start(ctkPluginContext *context)
{
    s.reset(new PluginImpl(context));
}

void PluginActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context);
}
