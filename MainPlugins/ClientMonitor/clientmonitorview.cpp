#include "clientmonitorview.h"
#include "ui_clientmonitorview.h"
#include <QDateTime>
#include <QDirIterator>
#include <QtDebug>

#include <ctkPluginFrameworkLauncher.h>
#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

#include <service/event/ctkEventAdmin.h>

#include "pluginservice.h"

ClientMonitorView::ClientMonitorView(const int clientMark, ctkPluginContext* context, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientMonitorView),
    m_pContext(context)
{
    ui->setupUi(this);
    m_clientMark = clientMark;
    setWindowTitle(QString("Client Monitor %1").arg(m_clientMark));

    ui->splitterHor->setStretchFactor(0, 1);
    ui->splitterHor->setStretchFactor(1, 3);
}

ClientMonitorView::~ClientMonitorView()
{
    delete ui;
}

void ClientMonitorView::showClientPlugin(const QString &clientPluginMark)
{
    //get service interface
    ctkServiceReference ref;
    ctkEventAdmin* eventAdmin;
    ref = m_pContext->getServiceReference<ctkEventAdmin>();
    if(ref)
    {
        eventAdmin = m_pContext->getService<ctkEventAdmin>(ref);
        m_pContext->ungetService(ref);

        if(eventAdmin) {
            QString topic("com/lsquange/clientmonitor/published");
            ctkDictionary message;
            message["ClientMark"] = m_clientMark;
            message["ClientPluginMark"] = clientPluginMark;
            eventAdmin->postEvent(ctkEvent(topic, message));
        }
    }

}


void ClientMonitorView::showPlugin(const QString &clientPluginMark, QWidget* view)
{
    if(ui->label->isVisible()) {
        ui->label->hide();
        ui->gridLayoutRight->removeWidget(ui->label);
    }
    bool exist(false);
    QMap<QString, QWidget*>::iterator pMapI;
    for(pMapI = m_mapPluginWidgets.begin(); pMapI != m_mapPluginWidgets.end(); ++pMapI) {
        if(clientPluginMark == pMapI.key())
        {
            exist = true;

            if (view->isHidden()){
                ui->gridLayoutRight->addWidget(view);
                view->show();
            } else {
                ui->gridLayoutRight->removeWidget(view);
                view->hide();
            }
        }

    }
    if(!exist) {
        m_mapPluginWidgets.insert(clientPluginMark, view);
        ui->gridLayoutRight->addWidget(view);
    }
}

void ClientMonitorView::on_pushButtonShowBase_clicked()
{
    showClientPlugin("ClientPlugin.ClientBase");
}

void ClientMonitorView::on_pushButtonShowScreen_clicked()
{
    showClientPlugin("ClientPlugin.Screen");
}
