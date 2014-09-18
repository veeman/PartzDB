#ifndef QUIABOUT_H
#define QUIABOUT_H

#include <QtWidgets/QWidget>

class QUiAbout : public QWidget
{
  Q_OBJECT

public:
  explicit QUiAbout(QWidget *parent = 0);
  ~QUiAbout();

  inline void setClosable(bool close = true);
  inline bool closable() const;

protected:
  virtual void paintEvent(QPaintEvent *event);
  virtual void keyPressEvent(QKeyEvent * event);
  virtual void mousePressEvent(QMouseEvent * event);

public slots:
  void showMessage(const QString &message);

private:
  QPixmap _background;      //!< Widget background image
  QString _copyMessage;     //!< Copyright message
  QFont   _fontCopyMessage; //!< Copyright message font
  QString _infoMessage;     //!< Info message
  QFont   _fontInfoMessage; //!< Info message font
  bool    _closable;        //!< Is Windows closable by click or Esc
};

inline void QUiAbout::setClosable(bool close)
{
  _closable = close;
}

inline bool QUiAbout::closable() const
{
  return _closable;
}

#endif // QUIABOUT_H
