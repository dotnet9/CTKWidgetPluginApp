#ifndef PLUGINACTIVATOR_H
#define PLUGINACTIVATOR_H

#include <QMap>
#include <ctkPluginActivator.h>
#include "pluginservice.h"

class ShowClientPluginEventHandler;
class ScreenView;
class ctkPluginContext;
class PluginActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "ClientBase")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext *context);

private:
    void showPluginViewHandler(const int clientMark, const QString& clientPluginMark);

private:
    QScopedPointer<PluginService> s;
    ctkPluginContext* m_pContext;
    ShowClientPluginEventHandler* m_pEventHandler;
    QMap<int, ScreenView*> m_mapViews;
};

#endif // PLUGINACTIVATOR_H
