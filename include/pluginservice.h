#ifndef PLUGINSERVICE_H
#define PLUGINSERVICE_H

#include <QtPlugin>
#include <QWidget>

/*!
 * \brief  The PluginService class
 * all plugin interfice
 * \author lsq
 * \date   2018-10-16 22:08
 */
class PluginService
{
public:
    virtual ~PluginService(){}
    /*!
     * \brief  getWidget
     * The plugin-in service destructor, when not using the service, delete the
     * service, must do the resource release operation.
     * \author lsq
     * \return plugin widget
     */
    virtual QWidget* getWidget() = 0;
};

#define PluginService_iid "com.lsquange.service.PluginService"
Q_DECLARE_INTERFACE(PluginService, PluginService_iid)

#endif // PLUGINSERVICE_H
