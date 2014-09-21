#ifndef QUIMAIN_H
#define QUIMAIN_H

#include <QtWidgets/QMainWindow>
#include "ui_quimain.h"

class QUiMain : public QMainWindow
{
  friend class QUiAppLoader;

  Q_OBJECT

public:
  QUiMain(QWidget *parent = 0);
  ~QUiMain();
  
public slots:
  void instanceMessage(const QString &message);
  
  void on_actionClose_triggered();
  void on_actionCloseAll_triggered();
  void on_actionExit_triggered();
  void on_actionLogWindow_triggered();
  void on_actionAbout_triggered();
  
private:
  Ui::QUiMainClass ui;  //!< UI layout
};

#endif // QUIMAIN_H
