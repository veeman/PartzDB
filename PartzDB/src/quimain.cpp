#include "stdafx.h"
#include "quimain.h"
#include "quiabout.h"

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
    //ui.listView->setModel(&(*qApp->internalLogger));
}

/*!
    Destroys the main window.
*/
QUiMain::~QUiMain()
{

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

/*!
    Event handler of exit menu.
*/
void QUiMain::on_actionExit_triggered(bool checked)
{
  // shutdown application
  close();
}