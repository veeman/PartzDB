#include "stdafx.h"
#include "quimain.h"
#include "quiabout.h"
#include "quilog.h"

/*!
  \class QUiMain
  \brief The %QUiMain class represents the main window.

  All application related functions are displayed on this widget.
*/

/*!
  Creates a new main window with the given \a parent.
*/
QUiMain::QUiMain(QWidget *parent)
  : QMainWindow(parent)
{
  ui.setupUi(this);
  setAttribute(Qt::WA_DeleteOnClose);
}

/*!
  Destroys the main window.
*/
QUiMain::~QUiMain()
{
  qApp->internalConfig->save();
}

/*!
  Message handler for received messages from other applications.

  \param message The application message, eg. the command line input.
*/
void QUiMain::instanceMessage(const QString &message)
{
  // TODO: process message
  show();
}

/*!
  Event handler of close tab button.
*/
void QUiMain::on_tabWidget_tabCloseRequested(int index)
{
  QWidget *widget = ui.tabWidget->widget(index);
  ui.tabWidget->removeTab(index);
  widget->deleteLater();
}

/*!
  Event handler of close menu.
*/
void QUiMain::on_actionClose_triggered()
{
  on_tabWidget_tabCloseRequested(ui.tabWidget->currentIndex());
}

/*!
  Event handler of close menu.
*/
void QUiMain::on_actionCloseAll_triggered()
{
  for (int i = ui.tabWidget->count(); i>=0; --i)
    on_tabWidget_tabCloseRequested(i);
}

/*!
  Event handler of exit menu.
*/
void QUiMain::on_actionExit_triggered()
{
  // shutdown application
  close();
}

/*!
  Event handler of log window menu.
*/
void QUiMain::on_actionLogWindow_triggered()
{
  // show logging window, create one if not exist
  QUiLog *log = ui.tabWidget->findChild<QUiLog*>();
  if (!log)
  {
    log = new QUiLog(ui.tabWidget);
    ui.tabWidget->addTab(log, log->windowTitle());
  }

  ui.tabWidget->setCurrentWidget(log);
}

/*!
  Event handler of about menu.
*/
void QUiMain::on_actionAbout_triggered()
{
  // show about window, create one if not exist
  QUiAbout *about = findChild<QUiAbout*>();
  if (!about)
  {
    about = new QUiAbout(this);
    about->setClosable();
  }

  about->show();
}