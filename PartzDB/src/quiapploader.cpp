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
  : QUiAbout(parent), _state(PREINIT), _progress(-1)
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
  case PREINIT: // ********************************************************************************
    showMessage(tr(*QUIAPPLOADER_STR_INIT));
    ++_state;
    break;
  case INIT:
    qApp->internalLogger.set(new QLoggerModel(0));

    showMessage(tr(*QUIAPPLOADER_STR_LOADCONFIG));
    ++_state;
    break;
  case CONFIG: // ********************************************************************************
    {
      qApp->internalConfig.set(new QJsonConfig());
      QString cfgFileName = qApp->buildRelativeFilePath(*QJSONCONFIG_PATH);
      bool loaded = qApp->internalConfig->load(cfgFileName);

      if (!loaded)
      {
        QString err = qApp->internalConfig->error();
        if (err.isEmpty())
          qApp->internalLogger->warning(
          QString(tr(STR_CFG_NOTFOUND)).arg(*QJSONCONFIG_PATH), this);
        else
          qApp->internalLogger->critical(
          QString(tr(STR_CFG_FAILED)).arg(*QJSONCONFIG_PATH).arg(err), this);
      }
      else
        qApp->internalLogger->info(
        QString(tr(STR_CFG_LOADED)).arg(*QJSONCONFIG_PATH), this);

      _progress = -1;
      ++_state;
      showMessage(tr(*QUIAPPLOADER_STR_LOADMODULE));
    }
    break;
  case PLUGINS: // ********************************************************************************
    {
      if (_progress < 0)
      {
        // generate module list
        QStringList listFilter(*QUIAPPLOADER_MODULEFILTER);
        QDir modulePath = QDir(qApp->buildRelativeFilePath(*QUIAPPLOADER_MODULEPATH));
        modulePath.setNameFilters(listFilter);
        _modules = modulePath.entryList(QDir::Files, QDir::Name);
        _progress = 0;

        if (_modules.count())
          showMessage(QString(tr(*QUIAPPLOADER_STR_LOADMODULES)).arg(_modules[0]).arg(0));
      }
      else
        if (_progress < _modules.count())
        {
          // load module
          QString modFileName = QString(*QUIAPPLOADER_MODULEPATH) + "/" + _modules[_progress];
          QString modFilePath = qApp->buildRelativeFilePath(modFileName);

          QPluginLoader loader(modFileName);
          QString moduleIID = loader.metaData()["IID"].toString(); // TODO: process loading?

          QObject *moduleObj = loader.instance();

          if (moduleObj)
          {
            QIntSingleApplication::ModuleEntry modEntry(moduleObj, _modules[_progress]);
            qApp->internalModuleList.push_back(modEntry);

            qApp->internalLogger->info(
              QString(tr(STR_MOD_LOADED)).arg(_modules[_progress]), this);
          }
          else
            qApp->internalLogger->critical(
            QString(tr(STR_MOD_FAILED)).arg(_modules[_progress]), this);

          // goto next module
          ++_progress;
          if (_modules.count() - _progress > 0)
          {
            float percent = float(_progress)/float(_modules.count());
            QString msg = QString(tr(*QUIAPPLOADER_STR_LOADMODULES)).
                              arg(_modules[_progress]).arg(percent);
            showMessage(msg);
          }
        }
        else
        {
          // move to next init state
          ++_state;
          _progress = -1;
        }
    }
    break;
  case TRAY: // ***********************************************************************************
    qApp->internalSystemTray.set(new QSystemTrayIcon(QIcon(*QSYSTEMTRAY_ICON)));
    qApp->internalSystemTray->setVisible(true);
    ++_state;
    break;
  case MAINWINDOW: // *****************************************************************************
    {
      QUiMain *win = new QUiMain();
      qApp->registerMessageHandle(win, SLOT(instanceMessage(const QString &)));
      win->show();
      ++_state;
    }
    break;
  case SETUP: // **********************************************************************************
    if (_progress < 0)
    {
      _progress = 0;
      showMessage(*QUIAPPLOADER_STR_SETUPMODULES);
    }
    else
      if (_progress < qApp->internalModuleList.count())
      {
        // TODO: setup modules
        ++_progress;
      }
      else
        ++_state;
    break;
  default: // *************************************************************************************
    ++_state;
    break;
  }
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


