#ifndef QINTSINGLEAPPLICATION_H
#define QINTSINGLEAPPLICATION_H

#include <QtSingleApplication>
#include "qloggermodel.h"
#include "qjsonconfig.h"
#include "qprivateapplicationpointer.h"

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

    QPrivateApplicationPointer<QLoggerModel>    internalLogger;
    QPrivateApplicationPointer<QJsonConfig>     internalConfig;
    QPrivateApplicationPointer<QSystemTrayIcon> internalSystemTray;
};

inline 
QMetaObject::Connection 
QIntSingleApplication::registerMessageHandle(const QObject *receiver, const char *member)
{
  return QObject::connect(this, SIGNAL(messageReceived(const QString&)), receiver, member);
}

#endif // QINTSINGLEAPPLICATION_H
