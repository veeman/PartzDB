#ifndef QUIABOUT_H
#define QUIABOUT_H

#include <QtWidgets/QWidget>

class QUiAbout : public QWidget
{
  Q_OBJECT

public:
  explicit QUiAbout(QWidget *parent = 0);
  ~QUiAbout();

protected:
  virtual void paintEvent(QPaintEvent *event);

public slots:
  void showMessage(const QString &message);

private:
  QPixmap _background;      //!< Widget background image
  QString _copyMessage;     //!< Copyright message
  QFont   _fontCopyMessage; //!< Copyright message font
  QString _infoMessage;     //!< Info message
  QFont   _fontInfoMessage; //!< Info message font
};

#endif // QUIABOUT_H
