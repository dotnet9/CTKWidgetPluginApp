#ifndef CLIENTLISTVIEW_H
#define CLIENTLISTVIEW_H

#include <QWidget>

namespace Ui {
class ClientCountView;
}

class ctkPluginContext;
class ClientCountView : public QWidget
{
    Q_OBJECT

public:
    ClientCountView(ctkPluginContext* context, QWidget *parent = 0);
    ~ClientCountView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ClientCountView *ui;
    ctkPluginContext* m_pContext;
};

#endif // CLIENTLISTVIEW_H
