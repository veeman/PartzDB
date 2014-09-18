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

public slots:
  void instanceMessage(const QString &message);
  void on_actionAbout_triggered(bool checked);
  void on_actionExit_triggered(bool checked);
  
private:
  Ui::QUiMainClass ui;  //!< UI layout
};

#endif // QUIMAIN_H
