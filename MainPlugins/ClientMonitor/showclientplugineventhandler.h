#ifndef SHOWCLIENTPLUGINEVENTHANDLER_H
#define SHOWCLIENTPLUGINEVENTHANDLER_H


#include <QObject>
#include <service/event/ctkEventHandler.h>
#include <QWidget>

class ShowClientPluginEventHandler : public QObject, public ctkEventHandler
{
    Q_OBJECT
    Q_INTERFACES(ctkEventHandler)

public:
    void handleEvent(const ctkEvent& event) Q_DECL_OVERRIDE;

signals:
    void showPluginView(const int clientMark, const QString& clientPluginMark, QWidget* view);
};
#endif // SHOWCLIENTPLUGINEVENTHANDLER_H
