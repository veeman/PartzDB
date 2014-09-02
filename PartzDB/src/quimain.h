#ifndef QUIMAIN_H
#define QUIMAIN_H

#include <QtWidgets/QMainWindow>
#include "ui_quimain.h"

class QUiMain : public QMainWindow
{
  Q_OBJECT

public:
  QUiMain(QWidget *parent = 0);
  ~QUiMain();

private:
  Ui::QUiMainClass ui;  //!< UI layout
};

#endif // QUIMAIN_H
