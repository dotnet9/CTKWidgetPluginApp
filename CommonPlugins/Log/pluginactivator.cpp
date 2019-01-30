#include "pluginactivator.h"
#include "pluginimpl.h"
#include "WidgetAppender.h"

#include <log4qt/logger.h>
#include <log4qt/logmanager.h>
#include <log4qt/loggerrepository.h>
#include <log4qt/ttcclayout.h>
#include <log4qt/propertyconfigurator.h>

void PluginActivator::start(ctkPluginContext *context)
{
    Log4Qt::LogManager::setHandleQtMessages(true);

    s.reset(new PluginImpl(context));

    Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
    Log4Qt::WidgetAppender *appender = new Log4Qt::WidgetAppender(this);
    appender->setName("WidgetAppender");
    Log4Qt::TTCCLayout *layout = new Log4Qt::TTCCLayout(Log4Qt::TTCCLayout::ISO8601);
    layout->setThreadPrinting(true);
    appender->setLayout(layout);
    appender->activateOptions();
    //设置日志信息输出的窗口组件
    appender->setLogWidget(*s->getWidget());
    logger->addAppender(appender);

}

void PluginActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context);
}
