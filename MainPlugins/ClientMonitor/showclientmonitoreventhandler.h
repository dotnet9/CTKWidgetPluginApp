#ifndef SHOWCLIENTMONITOREVENTHANDLER_H
#define SHOWCLIENTMONITOREVENTHANDLER_H

#include <QObject>
#include <service/event/ctkEventHandler.h>

class ShowClientMonitorEventHandler : public QObject, public ctkEventHandler
{
    Q_OBJECT
    Q_INTERFACES(ctkEventHandler)

public:
    void handleEvent(const ctkEvent& event) Q_DECL_OVERRIDE;

signals:
    void showMonitorView(const int clientMark);
};

#endif // SHOWCLIENTMONITOREVENTHANDLER_H
