#include "stdafx.h"
#include "quilog.h"

QUiLog::QUiLog(QWidget *parent)
	: QWidget(parent, Qt::Window)
{
	setAttribute(Qt::WA_DeleteOnClose);
	ui.setupUi(this);
	ui.listView->setModel(&(*qApp->internalLogger));
}

QUiLog::~QUiLog()
{

}
