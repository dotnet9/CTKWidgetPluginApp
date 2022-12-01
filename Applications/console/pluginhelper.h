#ifndef PLUGINHELPER_H
#define PLUGINHELPER_H

#include <QString>
#include <QList>

class ctkPluginContext;
class ctkPlugin;
class ctkPluginFramework;

class PluginHelper
{
public:
    PluginHelper();

    static bool initPluginFW();
    static bool loadPlugins(const QString &path = "plugins");
    static bool startPlugins();
private:

    static void enableDebug();

    static ctkPluginFramework* framework;
    static QList<QSharedPointer<ctkPlugin> > ctkPluginList;
};

#endif // PLUGINHELPER_H
