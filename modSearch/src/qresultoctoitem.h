#ifndef QRESULTOCTOITEM_H
#define QRESULTOCTOITEM_H

#include <QWidget>
#include "ui_qresultoctoitem.h"

class QResultOctoItem : public QWidget
{
	Q_OBJECT

public:
	QResultOctoItem(QWidget *parent = 0);
	~QResultOctoItem();

public:
	Ui::QResultOctoItem ui;
};

#endif // QRESULTOCTOITEM_H
