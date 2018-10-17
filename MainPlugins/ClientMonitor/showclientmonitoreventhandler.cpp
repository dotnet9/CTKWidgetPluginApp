#include "showclientmonitoreventhandler.h"
#include "clientmonitorview.h"


void ShowClientMonitorEventHandler::handleEvent(const ctkEvent& event)
{
    int clientMark = event.getProperty("ClientMark").toInt();

    emit showMonitorView(clientMark);
}
