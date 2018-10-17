#ifndef SHOWCLIENTPLUGINEVENTHANDLER_H
#define SHOWCLIENTPLUGINEVENTHANDLER_H

#include <QObject>
#include <service/event/ctkEventHandler.h>

class ShowClientPluginEventHandler : public QObject, public ctkEventHandler
{
    Q_OBJECT
    Q_INTERFACES(ctkEventHandler)

public:
    void handleEvent(const ctkEvent& event) Q_DECL_OVERRIDE;

signals:
    void showPluginView(const int clientMark, const QString &clientPluginMark);
};

#endif // SHOWCLIENTPLUGINEVENTHANDLER_H
