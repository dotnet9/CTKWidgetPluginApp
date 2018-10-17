#include "screenview.h"
#include "ui_screenview.h"
#include <QDateTime>
#include <QDebug>
#include <ctkPluginContext.h>

ScreenView::ScreenView(const int clientMark, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScreenView),
    m_clientMark(clientMark)
{
    ui->setupUi(this);
    ui->labelTitle->setText(QString("Client screen for client: %1").arg(clientMark));
}

ScreenView::~ScreenView()
{
    delete ui;
}

void ScreenView::on_pushButton_clicked()
{
    qDebug() << "Screen: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
}
