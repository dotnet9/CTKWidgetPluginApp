#include "clientlistview.h"
#include "ui_clientlistview.h"
#include <QDateTime>
#include <QDebug>
#include <ctkPluginContext.h>

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
