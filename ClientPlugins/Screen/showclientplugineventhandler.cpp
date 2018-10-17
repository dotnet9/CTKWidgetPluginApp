#include "showclientplugineventhandler.h"

void ShowClientPluginEventHandler::handleEvent(const ctkEvent& event)
{
    int clientMark = event.getProperty("ClientMark").toInt();
    QString clientPluginMark = event.getProperty("ClientPluginMark").toString();

    emit showPluginView(clientMark, clientPluginMark);
}
