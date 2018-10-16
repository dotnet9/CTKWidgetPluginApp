#include "clientcountview.h"
#include "ui_clientcountview.h"
#include <QDateTime>
#include <QDebug>
#include <ctkPluginContext.h>

ClientCountView::ClientCountView(ctkPluginContext* context, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientCountView),
    m_pContext(context)
{
    ui->setupUi(this);
}

ClientCountView::~ClientCountView()
{
    delete ui;
}

void ClientCountView::on_pushButton_clicked()
{
    qDebug() << "ClientCount: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
}
