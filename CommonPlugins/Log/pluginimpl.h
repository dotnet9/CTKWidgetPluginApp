#ifndef PLUGINIMPL_H
#define PLUGINIMPL_H

#include <QObject>
#include "pluginservice.h"

class ctkPluginContext;
class PluginImpl : public QObject, public PluginService
{
    Q_OBJECT
    Q_INTERFACES(PluginService)
public:
    PluginImpl(ctkPluginContext* context);
    QWidget* getWidget() Q_DECL_OVERRIDE;

private:
    ctkPluginContext* m_pContext;
};

#endif // PLUGINIMPL_H
