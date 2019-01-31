#include <QCoreApplication>
#include <QtWidgets/QApplication>
#include "ctkPluginFrameworkFactory.h"
#include "ctkPluginFramework.h"
#include "ctkPluginException.h"
#include "ctkPluginContext.h"
#include "ctkPluginFrameworkLauncher.h"
#include <QDebug>
#include <QDir>
#include <QDirIterator>

#include "imainwindow.h"

#include "pluginhelper.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName("ctkExample");//给框架创建名称，Linux下没有这步会报错

    QString libPath = QCoreApplication::applicationDirPath();

    //plugin加载
    PluginHelper::initPluginFW();
    PluginHelper::loadPlugins("plugins");
    PluginHelper::startPlugins();

    ctkPluginContext* context = ctkPluginFrameworkLauncher::getPluginContext();
    ctkServiceReference ref = context->getServiceReference<iMainWindow>();
    iMainWindow* mainWindow = nullptr;
    if(ref)
        mainWindow = context->getService<iMainWindow>(ref);

    if(mainWindow)
    {
        mainWindow->popMainWindow();
        context->ungetService(ref);
    }

//    ctkPluginFrameworkLauncher::stop("org.commontk.eventadmin");


    return a.exec();
}
