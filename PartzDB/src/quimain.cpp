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
  Event handler of close menu.
*/
void QUiMain::on_actionClose_triggered(bool checked)
{

}

/*!
  Event handler of close menu.
*/
void QUiMain::on_actionCloseAll_triggered(bool checked)
{

}

/*!
  Event handler of exit menu.
*/
void QUiMain::on_actionExit_triggered(bool checked)
{
  // shutdown application
  close();
}

/*!
  Event handler of log window menu.
*/
void QUiMain::on_actionLogWindow_triggered(bool checked)
{
  // show logging window, create one if not exist
  QUiLog *log = findChild<QUiLog*>();
  if (!log)
  {
    log = new QUiLog(this);
  }

  log->show();
}

/*!
  Event handler of about menu.
*/
void QUiMain::on_actionAbout_triggered(bool checked)
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