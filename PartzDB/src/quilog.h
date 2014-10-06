#ifndef QUILOG_H
#define QUILOG_H

#include <QWidget>
#include "ui_quilog.h"

class QUiLog : public QWidget
{
	Q_OBJECT

public:
	QUiLog(QWidget *parent = 0);
	~QUiLog();

private:
	Ui::QUiLog ui; //!< UI layout
};

#endif // QUILOG_H
