#include "stdafx.h"
#include "quiapploader.h"
#include "quimain.h"

QUiAppLoader::QUiAppLoader(QWidget *parent)
  : QUiAbout(parent), _state(PREINIT)
{
  QTimer::singleShot(0, this, SLOT(processLoading(void)));
}

QUiAppLoader::~QUiAppLoader()
{
}

void QUiAppLoader::load(void)
{
  const char* CFG_NOTFOUND = "Configuration file '%0' not found. Use default settings.";
  const char* CFG_FAILED = "Failed to load configuration file '%0'. %1";
  const char* CFG_LOADED = "Configuration file '%0' loaded.";

  // TODO: Load Config File
  // TODO: Load Plugins
  // TODO: 
  switch (_state)
  {
    case PREINIT:
      showMessage(tr(*QUIAPPLOADER_STR_INIT));
      break;
    case INIT:
      qApp->internalLogger.reset(new QLoggerModel(0));
      showMessage(tr(*QUIAPPLOADER_STR_LOADCONFIG));
      break;
    case CONFIG:
      {
        qApp->internalConfig.reset(new QJsonConfig());
        bool loaded = qApp->internalConfig->load(*QJSONCONFIG_PATH);
        QString cfgFileName = qApp->internalConfig->fileName();

        if (!loaded)
        {
          QString err = qApp->internalConfig->error();
          if (err.isEmpty())
            qApp->internalLogger->warning(QString(tr(CFG_NOTFOUND)).arg(cfgFileName), this);
          else
            qApp->internalLogger->critical(QString(tr(CFG_FAILED)).arg(cfgFileName).arg(err), this);
        }
        else
          qApp->internalLogger->info(QString(tr(CFG_LOADED)).arg(cfgFileName), this);
      }
      break;
    case PLUGINS:
      break;
    case SETUP:
      qApp->internalSystemTray.reset(new QSystemTrayIcon(QIcon(*QSYSTEMTRAY_ICON)));
      qApp->internalSystemTray->setVisible(true);
      break;
    case MAINWINDOW:
      {
        QUiMain *win = new QUiMain();
        win->show();
      }
      break;
    default:
      break;
  }
  ++_state;
}

void QUiAppLoader::processLoading(void)
{
  load();
  if (_state == DONE)
    close();
  else
    QTimer::singleShot(500, this, SLOT(processLoading(void)));
}

void QUiAppLoader::instanceMessage(const QString &message)
{

}


