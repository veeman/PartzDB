#include "stdafx.h"
#include "quiabout.h"
#include "../version.h"

/*!
    \class QUiAbout
    \brief The %QUiAbout class is a frameless widget with a static background.

    It displays the current copyright info and can show temporary messages.
    /sa showMessage()
*/

/*!
    Creates a new QUiAbout widget with the given \a parent.
*/
QUiAbout::QUiAbout(QWidget *parent)
  : QWidget(parent, Qt::SplashScreen | Qt::FramelessWindowHint)
{
  setAttribute(Qt::WA_DeleteOnClose);

  _background.load(*QUIABOUT_BGRES);
  resize(_background.size());

  _fontCopyMessage = QFont(*QUIABOUT_FONT, 10);
  _fontInfoMessage = QFont(*QUIABOUT_FONT, 8);
  _copyMessage += QString(AUTHORS) + "\n\n\n\n\n\n\n";
  _copyMessage += QString(STR_VERSION).arg(FILEVERS).arg(PLATTFORM) + "\n";
  _copyMessage += QString(LEGALCOPYRIGHT);
}

/*!
  Destroys the about widget.
*/
QUiAbout::~QUiAbout()
{

}

/*!
  This event handler is reimplemented and draws the default about widget layout.
*/
void QUiAbout::paintEvent(QPaintEvent * event)
{
  QPainter painter(this);

  QRectF rectCopy(28, 140, 400, 160);
  QRectF rectInfo(10, height() - 20, width() - 20, 20);
  QTextOption optInfo;
  QList<QTextOption::Tab> tabList;
  tabList << QTextOption::Tab(width() - 20, QTextOption::RightTab);
  optInfo.setAlignment(Qt::AlignVCenter);
  optInfo.setTabs(tabList);

  // draw background
  painter.drawPixmap(0, 0, _background);

  // draw copyrigt and info message
  painter.setFont(_fontCopyMessage);
  painter.drawText(rectCopy, _copyMessage);
  painter.setFont(_fontInfoMessage);
  painter.drawText(rectInfo, _infoMessage, optInfo);
}

/*!
  Displays the \a message at the bottom of the widget.
*/
void QUiAbout::showMessage(const QString &message)
{
  _infoMessage = message;
  update();
}
