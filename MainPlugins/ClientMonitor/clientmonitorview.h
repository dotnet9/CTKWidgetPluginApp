#ifndef CLIENTLISTVIEW_H
#define CLIENTLISTVIEW_H

#include <QWidget>
#include <QMap>

namespace Ui {
class ClientMonitorView;
}

class ctkPluginContext;
class ClientMonitorView : public QWidget
{
    Q_OBJECT

public:
    ClientMonitorView(const int clientMark, ctkPluginContext* context, QWidget *parent = 0);
    ~ClientMonitorView();

    void showPlugin(const QString &clientPluginMark, QWidget* view);

private:
    void showClientPlugin(const QString &clientPluginMark);

private slots:
    void on_pushButtonShowBase_clicked();

    void on_pushButtonShowScreen_clicked();

private:
    Ui::ClientMonitorView *ui;
    ctkPluginContext* m_pContext;
    int m_clientMark;
    QMap<QString, QWidget*> m_mapPluginWidgets;
};

#endif // CLIENTLISTVIEW_H
