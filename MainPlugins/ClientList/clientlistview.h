#ifndef CLIENTLISTVIEW_H
#define CLIENTLISTVIEW_H

#include <QWidget>

namespace Ui {
class ClientListView;
}

class ctkPluginContext;
class ClientListView : public QWidget
{
    Q_OBJECT

public:
    ClientListView(ctkPluginContext* context, QWidget *parent = 0);
    ~ClientListView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ClientListView *ui;
    ctkPluginContext* m_pContext;
};

#endif // CLIENTLISTVIEW_H
