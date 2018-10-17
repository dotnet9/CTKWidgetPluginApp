#include "clientbaseview.h"
#include "ui_clientbaseview.h"
#include <QDateTime>
#include <QDebug>
#include <ctkPluginContext.h>

ClientBaseView::ClientBaseView(const int clientMark, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientBaseView),
    m_clientMark(clientMark)
{
    ui->setupUi(this);
    ui->labelTitle->setText(QString("Client base for client: %1").arg(clientMark));
}

ClientBaseView::~ClientBaseView()
{
    delete ui;
}

void ClientBaseView::on_pushButton_clicked()
{
    qDebug() << "ClientBase: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
}
