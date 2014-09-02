#ifndef QLOGGERVIEW_H
#define QLOGGERVIEW_H

#include <QtWidgets/QListView>

class QKeyEvent;

class QLoggerView : public QListView
{
  Q_OBJECT

public:
  explicit QLoggerView(QWidget *parent = 0);
  ~QLoggerView();

protected:
  virtual void keyPressEvent(QKeyEvent *event);
    
};

#endif // QLOGGERVIEW_H
