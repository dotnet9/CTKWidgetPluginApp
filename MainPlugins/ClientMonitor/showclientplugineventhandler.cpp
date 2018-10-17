#include "showclientplugineventhandler.h"

void ShowClientPluginEventHandler::handleEvent(const ctkEvent& event)
{
    int clientMark = event.getProperty("ClientMark").toInt();
    QString clientPluginMark = event.getProperty("ClientPluginMark").toString();
    QWidget* pluginView = event.getProperty("View").value<QWidget *>();

    emit showPluginView(clientMark, clientPluginMark, pluginView);
}
