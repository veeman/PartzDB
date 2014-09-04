#include "stdafx.h"
#include "quiapploader.h"
#include "quimain.h"

QUiAppLoader::QUiAppLoader(QWidget *parent)
  : QUiAbout(parent), _state(INIT)
{
  QTimer::singleShot(0, this, SLOT(processLoading(void)));
}

QUiAppLoader::~QUiAppLoader()
{
}

void QUiAppLoader::load(void)
{
  // TODO: Load Config File
  // TODO: Load Plugins
  // TODO: 
  switch (_state)
  {
    case INIT:
      qApp->internalLogger.reset(new QLoggerModel(0));
      break;
    case CONFIG:
      qApp->internalConfig.reset(new QJsonConfig());
      qApp->internalConfig->load(*QJSONCONFIG_PATH);
      break;
    case PLUGINS:
      break;
    case SYSTEMTRAY:
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


