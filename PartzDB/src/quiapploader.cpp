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
      qAppLogger.reset(new QLoggerModel(0));
      break;
    case CONFIG:
      qAppConfig.reset(new QJsonConfig());
      break;
    case PLUGINS:
      break;
    case SYSTEMTRAY:
      qAppSystemTray.reset(new QSystemTrayIcon(QIcon(*QSYSTEMTRAY_ICON)));
      qAppSystemTray->setVisible(true);
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


