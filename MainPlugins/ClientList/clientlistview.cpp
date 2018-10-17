#include "clientlistview.h"
#include "ui_clientlistview.h"
#include <QDateTime>
#include <QDebug>
#include <ctkPluginContext.h>
#include "pluginservice.h"
#include <service/event/ctkEventAdmin.h>

ClientListView::ClientListView(ctkPluginContext* context, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientListView),
    m_pContext(context)
{
    ui->setupUi(this);
}

ClientListView::~ClientListView()
{
    delete ui;
}

void ClientListView::on_pushButton_clicked()
{
    qDebug() << "ClientList: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
}


void ClientListView::showClientDetail(const int clientMark)
{
    //get service interface
    ctkServiceReference ref;
    ctkEventAdmin* eventAdmin;
    ref = m_pContext->getServiceReference<ctkEventAdmin>();
    if(ref)
    {
        eventAdmin = m_pContext->getService<ctkEventAdmin>(ref);
        m_pContext->ungetService(ref);
    }

    if(eventAdmin) {
        QString topic("com/lsquange/client/published");
        ctkDictionary message;
        message["ClientMark"] = clientMark;
        eventAdmin->postEvent(ctkEvent(topic, message));
    }
}

void ClientListView::on_btnMonitor1_clicked()
{
    showClientDetail(1);
}

void ClientListView::on_btnMonitor2_clicked()
{
    showClientDetail(2);
}
