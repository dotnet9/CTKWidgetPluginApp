#include "WidgetAppender.h"
#include "loggingevent.h"
#include <log4qt/ttcclayout.h>

namespace Log4Qt
{

WidgetAppender::WidgetAppender(QObject *parent): AppenderSkeleton(parent)
{
    m_logWidget = NULL;
}

WidgetAppender::~WidgetAppender()
{

}

void WidgetAppender::setLogWidget(const QWidget &widget)
{
    m_logWidget = const_cast<QWidget*>(&widget);
    //连接槽函数到输出窗口的onAppendLog(const QString&)槽函数
    connect(this, SIGNAL(logAppend(const QString&)), m_logWidget, SLOT(onAppendLog(const QString&)));

}

bool WidgetAppender::requiresLayout() const
{
    return true;
}

void WidgetAppender::append(const LoggingEvent &rEvent)
{
    // 格式化日志信息
    QString message = dynamic_cast<TTCCLayout*>(layout())->format(rEvent);
    emit logAppend(message);
}
#ifndef QT_NO_DEBUG_STREAM
QDebug WidgetAppender::debug(QDebug &rDebug) const
{
    return rDebug.space();
}
#endif //QT_NO_DEBUG_STREAM

}