#ifndef WIDGETAPPENDER_H
#define WIDGETAPPENDER_H

#include <QObject>
#include <QWidget>
#include "appenderskeleton.h"
#include <QDebug>

namespace Log4Qt
{
/**
 * @brief WidgetAppender继承自AppenderSkeleton类，用于将日志信息重定向到QWidget组件
 * @author scorpio
 * @note WidgetAppender的使用注意事项：
 *      1、必须使用setLogWidget接口设置日志信息的重定向位置，即输出窗口组件
 *      2、必须实现一个槽函数onAppendLog(const QString& msg),用于接收WidgetAppender
 *      发送的logAppend(const QString& msg)信号，参数msg即接收的日志信息，输出窗口组件
 *      需要将msg输出到相应窗体。
 */
class WidgetAppender : public AppenderSkeleton
{
    Q_OBJECT
public:
    WidgetAppender(QObject *parent = NULL);
    ~WidgetAppender();
    /**
     * @brief 设置日志信息输出的QWidget组件
     * @param widget，输入参数，日志信息输出窗口，需要开发者自己实现
     */
    void setLogWidget(const QWidget& widget);

signals:
    /**
     * @brief 新增加一条日志信息的信号
     * @param msg，输入参数，格式化后的日志信息
     * @note logAppend信号由QWidget输出窗口组件接收，开发者需要在输出窗口组件实现
     *      槽函数onAppendLog(const QString& msg)。
     */
    void logAppend(const QString& msg);
protected:
    virtual bool requiresLayout() const;
    virtual void append(const Log4Qt::LoggingEvent &rEvent);

#ifndef QT_NO_DEBUG_STREAM
    virtual QDebug debug(QDebug &rDebug) const;
#endif //QT_NO_DEBUG_STREAM

private:
    QWidget *m_logWidget;
};

}
#endif // WIDGETAPPENDER_H