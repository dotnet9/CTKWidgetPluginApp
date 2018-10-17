#ifndef PLUGINACTIVATOR_H
#define PLUGINACTIVATOR_H

#include <ctkPluginActivator.h>
#include <QMap>
#include "pluginservice.h"

class ShowClientMonitorEventHandler;
class ShowClientPluginEventHandler;
class ClientMonitorView;
class ctkPluginContext;
class PluginActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "ClientMonitor")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext *context);

private:
    void showMonitorViewHandler(const int clientMark);
    void showPluginViewHandler(const int clientMark, const QString& clientPluginMark, QWidget* view);

private:
    QScopedPointer<PluginService> s;
    ctkPluginContext* m_pContext;
    ShowClientMonitorEventHandler* m_pEventHandler;
    ShowClientPluginEventHandler* m_pPluginEventHandler;
    QMap<int, ClientMonitorView*> m_mapViews;
};

#endif // PLUGINACTIVATOR_H
