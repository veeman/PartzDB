#ifndef QUIFETCHOCTOPART_H
#define QUIFETCHOCTOPART_H

#include <QtWidgets/QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include "ui_fetchoctopart.h"
#include <qjsondocument>

class QUiFetchOctopart : public QWidget
{
	Q_OBJECT

public:
  QUiFetchOctopart(QWidget *parent, QNetworkAccessManager *nam);
	~QUiFetchOctopart();

public slots:
	void finishedSlot();
	void on_pushButtonRunRequest_clicked();

private:
	Ui::FetchOctopartClass ui;
	QNetworkAccessManager* _networkManager;
  QNetworkReply* _reply;
	QJsonDocument _octoData;
	void interpretOctoData();
};

#endif // QUIFETCHOCTOPART_H
