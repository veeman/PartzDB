#include "stdafx.h"
#include "qintsingleapplication.h"

/*!
    \class QIntSingleApplication
    \brief The %QIntSingleApplication class provides an application object with common used objects.

    \sa QApplication
*/

/*!
    Creates a new QIntSingleApplication object.

    \sa QApplication::QApplication(int &argc, char **argv, bool GUIenabled)
*/
QIntSingleApplication::QIntSingleApplication(int &argc, char **argv, bool GUIenabled)
  : QtSingleApplication(argc, argv, GUIenabled)
{

}

/*!
    Application destructor. Destroy all global variable in hierarchical order.
*/
QIntSingleApplication::~QIntSingleApplication()
{
  internalSystemTray.free();
  internalConfig.free();
  internalNetworkManager.free();
  internalLogger.free();
}

/*!
    Build filepath relativ to application directory.

    \param fileName The relative filename.
    \return The concated path.
*/
QString QIntSingleApplication::buildRelativeFilePath(const QString &fileName)
{
  return qApp->applicationDirPath() + '/' + fileName;
}

/*!
    \fn QIntSingleApplication::registerMessageHandle
    
    Register an application message handler.
*/