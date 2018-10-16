#ifndef CLIENTLISTVIEW_H
#define CLIENTLISTVIEW_H

#include <QWidget>

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

private:
    Ui::LogView *ui;
    ctkPluginContext* m_pContext;
};

#endif // CLIENTLISTVIEW_H
