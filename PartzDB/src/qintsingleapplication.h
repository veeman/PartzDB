#ifndef QINTSINGLEAPPLICATION_H
#define QINTSINGLEAPPLICATION_H

#include <QtSingleApplication>
#include "qprivateapplicationpointer.h"
#include "qjsonconfig.h"
#include "qloggermodel.h"
#include "quimain.h"

#if defined(qApp)
  #undef qApp
#endif
#define qApp (static_cast<QIntSingleApplication*>(QCoreApplication::instance()))

class QIntSingleApplication : public QtSingleApplication
{
  Q_OBJECT

public:
    QIntSingleApplication(int &argc, char **argv, bool GUIenabled = true);
    ~QIntSingleApplication();
    
    static QString buildRelativeFilePath(const QString &fileName);

    QMetaObject::Connection registerMessageHandle(const QObject *receiver, const char *member);

	  typedef QPair<QObject*, QString> ModuleEntry;
        //!< Association of plugin classe and the plugin IID 

    QPrivateApplicationPointer<QLoggerModel> internalLogger;    
        //!< Global application logger
    QPrivateApplicationPointer<QJsonConfig> internalConfig;     
        //!< Global application config
    QPrivateApplicationPointer<QSystemTrayIcon> internalSystemTray; 
        //!< Global application tray
    QPrivateApplicationPointer<QNetworkAccessManager> internalNetworkManager;
        //!< Global network manager
	  QVector<ModuleEntry> internalModuleList; 
        //!< Global application module list
    QUiMain *internalMainWindow; 
        //!< Global application main window, auto delete by qt
};

inline 
QMetaObject::Connection 
QIntSingleApplication::registerMessageHandle(const QObject *receiver, const char *member)
{
  return QObject::connect(this, SIGNAL(messageReceived(const QString&)), receiver, member);
}

#endif // QINTSINGLEAPPLICATION_H
