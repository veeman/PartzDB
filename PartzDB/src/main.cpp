/*!
    \file main.cpp
*/
#include "stdafx.h"
#include "quiapploader.h"

/*!
    \brief Application entry point.

    \param argc Parameter count
    \param argv Parameter string list passed by the command line
	  \return Application error code
*/
int main(int argc, char *argv[]);

/*!
    \brief This functions verifies if an instance of the application is already running.

    If an instance is running, the current command line will transmitted to this instance.

    \return True if an instance exists 
*/
static bool sendInstanceMessage(void);

int main(int argc, char *argv[])
{
    QScopedPointer<QtSingleApplication> app(new QtSingleApplication(argc, argv));
    if (sendInstanceMessage())
      return 0x420; // already running

    // create apploader instance, will destroyed by the qt engine
    QUiAppLoader *win = new QUiAppLoader();
    qAppRegisterMessageHandle(win, SLOT(instanceMessage(const QString &)));
    win->show();

    // enter main event loop
    return app->exec();
}

static bool sendInstanceMessage(void)
{
  QtSingleApplication *app = qobject_cast<QtSingleApplication*>(qApp);
  if (!app)
    return false;

  // build argument list and send it to other instance
  const QStringList argList = app->arguments();
  const QString argMsg = argList.join(" ");

  return app->sendMessage(argMsg);
}
