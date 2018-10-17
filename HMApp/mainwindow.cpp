#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDirIterator>
#include <QtDebug>

#include <ctkPluginFrameworkLauncher.h>
#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

#include "pluginservice.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->splitterTopHor->setStretchFactor(0, 3);
    ui->splitterTopHor->setStretchFactor(1, 1);

    ui->splitterBottomVer->setStretchFactor(0, 3);
    ui->splitterBottomVer->setStretchFactor(1, 1);

    loadPlugin("MainPlugins");
    loadPlugin("CommonPlugins");
    loadPlugin("ClientPlugins");
}

MainWindow::~MainWindow()
{
    ctkPluginFrameworkLauncher::stop();

    delete ui;
}

void MainWindow::loadPlugin(const QString& pluginDir)
{
    QString path = QString("%1/%2").arg(QApplication::applicationDirPath()).arg(pluginDir);
    ctkPluginFrameworkLauncher::addSearchPath(path);
    ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");

    context = ctkPluginFrameworkLauncher::getPluginContext();

    QDirIterator itPlugin(path, QStringList() << "*.dll" << "*.so", QDir::Files);
    while(itPlugin.hasNext()) {
        QString strPlugin = itPlugin.next();
        try {
            QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(strPlugin));

            // 获取符号名
            QString symb = plugin->getSymbolicName();
            qDebug() << "Symbolic Name:" << symb << "\r\n";

            plugin->start(ctkPlugin::START_TRANSIENT);
            qDebug() << pluginDir << " Plugin start ...";

            ctkServiceReference reference = context->getServiceReference<PluginService>();
            if (reference) {
                PluginService* service = qobject_cast<PluginService *>(context->getService(reference));
                if(service != Q_NULLPTR) {
                    QWidget* w = service->getWidget();
                    if(w == nullptr) {
                        continue;
                    }
                    if("MainPlugin.ClientList" == symb) {
                        ui->gridLayoutTopLeft->addWidget(w);
                    }
                    else if("MainPlugin.ClientCount" == symb) {
                        ui->gridLayoutTopRight->addWidget(w);
                    }
                    else if("CommonPlugin.Log" == symb){
                        ui->gridLayoutBottom->addWidget(w);
                    }
                }
            }
        } catch(const ctkPluginException &e) {
            qDebug() << "Failed to install plugin" << e.what();
            return;
        }
    }
}
