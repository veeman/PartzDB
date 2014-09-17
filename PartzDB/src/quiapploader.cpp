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
  // TODO: Load Plugins
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
        bool loaded = qApp->internalConfig->load(*QJSONCONFIG_PATH);
        QString cfgFileName = qApp->internalConfig->fileName();

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
      break;
    case SETUP:
      qApp->internalSystemTray.set(new QSystemTrayIcon(QIcon(*QSYSTEMTRAY_ICON)));
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
    QTimer::singleShot(500, this, SLOT(close(void)));
  else
    QTimer::singleShot(10, this, SLOT(processLoading(void)));
}

void QUiAppLoader::instanceMessage(const QString &message)
{

}


