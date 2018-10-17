#ifndef CLIENTLISTVIEW_H
#define CLIENTLISTVIEW_H

#include <QWidget>

namespace Ui {
class ClientBaseView;
}

class ctkPluginContext;
class ClientBaseView : public QWidget
{
    Q_OBJECT

public:
    ClientBaseView(const int clientMark, QWidget *parent = 0);
    ~ClientBaseView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ClientBaseView *ui;
    ctkPluginContext* m_pContext;
    int m_clientMark;
};

#endif // CLIENTLISTVIEW_H
