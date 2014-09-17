#include "stdafx.h"
#include "qintsingleapplication.h"

QIntSingleApplication::QIntSingleApplication(int &argc, char **argv, bool GUIenabled)
  : QtSingleApplication(argc, argv, GUIenabled)
{

}

QIntSingleApplication::~QIntSingleApplication()
{
  internalSystemTray.free();
  internalConfig.free();
  internalLogger.free();
}

QString QIntSingleApplication::buildRelativeFilePath(const QString &fileName)
{
  return qApp->applicationDirPath() + '/' + fileName;
}

/*!
  \fn QIntSingleApplication::registerMessageHandle
  \brief Register an application message handler.
*/