#include "stdafx.h"
#include "quiapploader.h"
#include "quimain.h"

/*!
    \class QUiAppLoader
    \brief The %QLoggerModel class shows a splash screen
    and perfroms several application initializations.

    \sa load(void)
*/

/*!
    \enum QUiAppLoader::LoadState
    LoadState represents the current initalization process.

    \var QUiAppLoader::LoadState QUiAppLoader::PREINIT
    Shows only the next initialization process.

    \var QUiAppLoader::LoadState QUiAppLoader::INIT
    Initalize some global functions eg. logging class.
    \sa QLoggerModel

    \var QUiAppLoader::LoadState QUiAppLoader::CONFIG
    Try to load a configuration file wich cann used by the application.

    \var QUiAppLoader::LoadState QUiAppLoader::PLUGINS
    Search and loads all plugins. 

    \var QUiAppLoader::LoadState QUiAppLoader::TRAY
    Initalize the tray object.

    \var QUiAppLoader::LoadState QUiAppLoader::MAINWINDOW
    Create the main application window.

    \var QUiAppLoader::LoadState QUiAppLoader::SETUP
    Perfrom some plugin initializations after all application objects are created.

    \var QUiAppLoader::LoadState QUiAppLoader::DONE
    All initializations are done. Close the window.
*/

/*!
    Creates a new QUiAppLoader with the given \a parent.
*/
QUiAppLoader::QUiAppLoader(QWidget *parent)
  : QUiAbout(parent), _state(PREINIT)
{
  QTimer::singleShot(0, this, SLOT(processLoading(void)));
}

/*!
    Destroys the window.
*/
QUiAppLoader::~QUiAppLoader()
{
}

/*!
    \brief Application initialization.

    Performs several initalizations, like setup logging class, load configurations file and plugins.

    \sa processLoading() LoadState
*/
void QUiAppLoader::load(void)
{
  switch (_state)
  {
    case PREINIT:
      showMessage(tr(*QUIAPPLOADER_STR_INIT));
      break;
    case INIT:
      qApp->internalLogger.set(new QLoggerModel(0));
      showMessage(tr(*QUIAPPLOADER_STR_LOADCONFIG));
      break;
    case CONFIG:
      {
        qApp->internalConfig.set(new QJsonConfig());
        QString cfgFileName = qApp->buildRelativeFilePath(*QJSONCONFIG_PATH);
        bool loaded = qApp->internalConfig->load(cfgFileName);

        if (!loaded)
        {
          QString err = qApp->internalConfig->error();
          if (err.isEmpty())
            qApp->internalLogger->warning(
                                QString(tr(STR_CFG_NOTFOUND)).arg(cfgFileName), this);
          else
            qApp->internalLogger->critical(
                                QString(tr(STR_CFG_FAILED)).arg(cfgFileName).arg(err), this);
        }
        else
          qApp->internalLogger->info(
                                QString(tr(STR_CFG_LOADED)).arg(cfgFileName), this);
      }
      break;
    case PLUGINS:
      // TODO: Load Plugins
      break;
    case TRAY:
      qApp->internalSystemTray.set(new QSystemTrayIcon(QIcon(*QSYSTEMTRAY_ICON)));
      qApp->internalSystemTray->setVisible(true);
      break;
    case MAINWINDOW:
      {
        QUiMain *win = new QUiMain();
        qApp->registerMessageHandle(win, SLOT(instanceMessage(const QString &)));
        win->show();
      }
      break;
    case SETUP:
      // TODO: Setup Plugins
      break;
    default:
      break;
  }
  ++_state;
}

/*!
    \brief Asynchron initialization loop.

    Calls load() until the load state reaches DONE. After that the window is closed. 
*/
void QUiAppLoader::processLoading(void)
{
  load();
  if (_state == DONE)
    QTimer::singleShot(500, this, SLOT(close(void)));
  else
    QTimer::singleShot(10, this, SLOT(processLoading(void)));
}

/*!
    \brief Message handler for received messages from other applications.

    All messages are buffered until the application is fully initialized.
    Then all messages are passed to the main message handler.

    \param message The application message, eg. the command line input.
*/
void QUiAppLoader::instanceMessage(const QString &message)
{
  // TODO: buffer messeges
}


