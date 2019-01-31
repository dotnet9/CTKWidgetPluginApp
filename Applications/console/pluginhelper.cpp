#include "pluginhelper.h"

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QDirIterator>

#include "ctkPluginFrameworkFactory.h"
#include "ctkPluginFramework.h"
#include "ctkPluginException.h"
#include "ctkPluginContext.h"
#include "ctkPluginFrameworkLauncher.h"

#include "service/debug/ctkDebugOptions.h"

//defined
ctkPluginFramework* PluginHelper::framework;
QList<QSharedPointer<ctkPlugin> > PluginHelper::ctkPluginList;

PluginHelper::PluginHelper()
{

}

bool PluginHelper::initPluginFW()
{
    try {
        ctkProperties fwProps;

        fwProps.insert("ctk.debug", ".ctk.options");
        fwProps.insert("org.commontk.pluginfw/debug", "1");
        fwProps.insert("org.commontk.pluginfw/debug/errors", "1");
        fwProps.insert("org.commontk.pluginfw/debug/pluginfw", "1");
        fwProps.insert("org.commontk.pluginfw/debug/hooks", "1");
        fwProps.insert("org.commontk.pluginfw/debug/lazy_activation", "1");
        fwProps.insert("org.commontk.pluginfw/debug/ldap", "1");
        fwProps.insert("org.commontk.pluginfw/debug/service_reference", "1");
        fwProps.insert("org.commontk.pluginfw/debug/startlevel", "1");
        fwProps.insert("org.commontk.pluginfw/debug/url", "1");
        fwProps.insert("org.commontk.pluginfw/debug/resolve", "1");

        ctkPluginFrameworkLauncher::setFrameworkProperties(fwProps);
        ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");

        //enableDebug();

        qDebug() << "plugin:" << "org.commontk.eventadmin" << "installed.";
    }catch(ctkPluginException e){
        qWarning() << e.message() << e.getType();
        qWarning() << e.what();
        return false;
    }catch(ctkUnsupportedOperationException e)
    {
        qWarning() << e.what();
        return false;
    }catch(ctkInvalidArgumentException e)
    {
        qWarning() << e.what();
        return false;
    }
    catch(ctkIllegalStateException e)
    {
         qWarning() << e.what();
         return false;
    }
    catch(ctkRuntimeException e)
    {
         qWarning() << e.what();
         return false;
    }
    catch(const ctkException& e)
    {
        qWarning() << "framework init failed at" << "org.commontk.eventadmin";
        qWarning() << e.message();
        qWarning() << e.what();
        e.printStackTrace();
        return false;
    }

    return true;
}

bool PluginHelper::loadPlugins(const QString &path)
{
    QString fullPath = QString("%1/%2").arg(QApplication::applicationDirPath()).arg(path);
    ctkPluginFrameworkLauncher::addSearchPath(fullPath);


    ctkPluginContext *context = ctkPluginFrameworkLauncher::getPluginContext();

    QDirIterator itPlugin(fullPath, QStringList() << "*.dll" << "*.so", QDir::Files);
    while(itPlugin.hasNext()) {
        QString strPlugin = itPlugin.next();
        try {
            QUrl pluginUrl = QUrl::fromLocalFile(strPlugin);
            QSharedPointer<ctkPlugin> plugin = context->installPlugin(pluginUrl);
        }catch(ctkPluginException e){
            qWarning() << e.message() << e.getType();
            qWarning() << e.what();
            return false;
        }catch(ctkUnsupportedOperationException e)
        {
            qWarning() << e.what();
            return false;
        }catch(ctkInvalidArgumentException e)
        {
            qWarning() << e.what();
            return false;
        }
        catch(ctkIllegalStateException e)
        {
             qWarning() << e.what();
             return false;
        }
        catch(ctkRuntimeException e)
        {
             qWarning() << e.what();
             return false;
        }
        catch(const ctkException& e)
        {
            qWarning() << "framework init failed at" << path;
            qWarning() << e.message();
            qWarning() << e.what();
            e.printStackTrace();
            return false;
        }
        qDebug() << "plugin:" << strPlugin << "installed.";
    }

    return true;
}


bool PluginHelper::startPlugins()
{
    try {
        QList<QSharedPointer<ctkPlugin> > plugins = ctkPluginFrameworkLauncher::getPluginFramework()->getPluginContext()->getPlugins();

        foreach (QSharedPointer<ctkPlugin> plugin, plugins)
        {
            // 获取符号名
            QString symb = plugin->getSymbolicName();
            qDebug() << "Symbolic Name:" << symb << "\r\n";

            plugin->start(ctkPlugin::START_TRANSIENT);
            qDebug() << symb << " Plugin start ...";
        }
    }catch(ctkPluginException e){
        qWarning() << e.message() << e.getType();
        qWarning() << e.what();
        return false;
    }catch(ctkUnsupportedOperationException e)
    {
        qWarning() << e.what();
        return false;
    }catch(ctkInvalidArgumentException e)
    {
        qWarning() << e.what();
        return false;
    }
    catch(ctkIllegalStateException e)
    {
         qWarning() << e.what();
         return false;
    }
    catch(ctkRuntimeException e)
    {
         qWarning() << e.what();
         return false;
    }
    catch(const ctkException& e)
    {
        qWarning() << e.message();
        qWarning() << e.what();
        e.printStackTrace();
        return false;
    }

    return true;
}

void PluginHelper::enableDebug()
{
    ctkPluginContext* context = ctkPluginFrameworkLauncher::getPluginFramework()->getPluginContext();
    ctkServiceReference ref = context->getServiceReference<ctkDebugOptions>();
    ctkDebugOptions *options = nullptr;
    if(ref)
    {
        options = context->getService<ctkDebugOptions>(ref);
        if(options)
        {
            /*QHash<QString, QVariant> ohash = options->getOptions();

            QHash<QString, QVariant>::Iterator stlIter;

            for( stlIter = ohash.begin(); stlIter != ohash.end(); ++stlIter )
            {
                qDebug() << stlIter.key() << stlIter.value().toString();
            }
            */
            options->setDebugEnabled(true);

        }
        context->ungetService(ref);
    }
}
