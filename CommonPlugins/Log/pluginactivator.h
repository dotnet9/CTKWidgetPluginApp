#ifndef PLUGINACTIVATOR_H
#define PLUGINACTIVATOR_H

#include <ctkPluginActivator.h>
#include "pluginservice.h"

class PluginActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "Log")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext *context);

private:
    QScopedPointer<PluginService> s;
};

#endif // PLUGINACTIVATOR_H
