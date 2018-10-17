#ifndef CLIENTLISTVIEW_H
#define CLIENTLISTVIEW_H

#include <QWidget>

namespace Ui {
class ScreenView;
}

class ctkPluginContext;
class ScreenView : public QWidget
{
    Q_OBJECT

public:
    ScreenView(const int clientMark, QWidget *parent = 0);
    ~ScreenView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ScreenView *ui;
    ctkPluginContext* m_pContext;
    int m_clientMark;
};

#endif // CLIENTLISTVIEW_H
