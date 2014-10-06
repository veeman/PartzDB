#include "stdafx.h"
#include "quilog.h"

/*!
  \class QUiLog
  \brief The %QUiLog class shows an window with alle applications logs.

  \sa QLoggerModel QLoggerView
*/

/*!
  Creates a new QUiLog widget with the given \a parent.
*/
QUiLog::QUiLog(QWidget *parent)
	: QWidget(parent, Qt::Window)
{
	setAttribute(Qt::WA_DeleteOnClose);
	ui.setupUi(this);
	ui.listView->setModel(&(*qApp->internalLogger));
}

/*!
  Destroys the window.
*/
QUiLog::~QUiLog()
{

}
