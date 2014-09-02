#include "stdafx.h"
#include "quimain.h"

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
}

/*!
  Destroys the main window.
*/
QUiMain::~QUiMain()
{

}
