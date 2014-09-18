/*!
    \file main.cpp
*/
#include "stdafx.h"
#include "quiapploader.h"
#include "qintsingleapplication.h"

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

/*!
    \brief This function prints out debug messages, warnings, critical and fatal error messages.
    \sa qInstallMessageHandler
*/
void applicationMessageOutput(QtMsgType type, const QMessageLogContext &ctx, const QString &msg);

int main(int argc, char *argv[])
{
    qInstallMessageHandler(applicationMessageOutput);

    QScopedPointer<QIntSingleApplication> app(new QIntSingleApplication(argc, argv));
    if (sendInstanceMessage())
      return 0x420; // already running

    // create apploader instance, will destroyed by the qt engine
    QUiAppLoader *win = new QUiAppLoader();
    app->registerMessageHandle(win, SLOT(instanceMessage(const QString &)));
    win->show();

    // enter main event loop
    return app->exec();
}

static bool sendInstanceMessage(void)
{
  if (!qApp)
    return false;

  // build argument list and send it to other instance
  const QStringList argList = qApp->arguments();
  const QString argMsg = argList.join(" ");

  return qApp->sendMessage(argMsg);
}

void applicationMessageOutput(QtMsgType type, const QMessageLogContext &ctx, const QString &msg)
{
  QString f = QString("Error in File %0@%1\n\tFunction: %2\n\tMessage: %3\n")
                  .arg(ctx.file).arg(ctx.line).arg(ctx.function).arg(msg);
  OutputDebugStringA(f.toLocal8Bit().data());
}
