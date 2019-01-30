#ifndef CLIENTLISTVIEW_H
#define CLIENTLISTVIEW_H

#include <QWidget>
#include <QMutex>

namespace Ui {
class LogView;
}

class ctkPluginContext;
class LogView : public QWidget
{
    Q_OBJECT

public:
    LogView(ctkPluginContext* context, QWidget *parent = 0);
    ~LogView();

private slots:
    /**
     * @brief 接收日志信息的槽函数
     * @param log，输入参数，格式化后的日志信息
     */
    void onAppendLog(const QString& log);

private:
    Ui::LogView *ui;
    ctkPluginContext* m_pContext;
    QMutex m_mutex;

};

#endif // CLIENTLISTVIEW_H
