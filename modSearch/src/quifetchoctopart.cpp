#include "stdafx.h"
#include "quifetchoctopart.h"
#include "qresultoctoitem.h"


QUiFetchOctopart::QUiFetchOctopart(QWidget *parent, QNetworkAccessManager *nam)
	: QWidget(parent)
{
	ui.setupUi(this);

	_networkManager = nam;
}

QUiFetchOctopart::~QUiFetchOctopart()
{

}

void QUiFetchOctopart::on_pushButtonRunRequest_clicked()
{
	QString octopart_URL = "http://octopart.com/api/v3/parts/search?";
	
	QString search_keyword = ui.lineEditSearch->text();
		
	QString requestUrl = octopart_URL;
	
	requestUrl += "&apikey=APIKEYHERE";
	requestUrl += "&pretty_print=true";
	requestUrl += "&include[]=datasheets";
	requestUrl += "&include[]=imagesets";
	requestUrl += "&include[]=descriptions";
	requestUrl += "&limit=100";	
	requestUrl += "&q=" + search_keyword;

  _reply = _networkManager->get(QNetworkRequest(requestUrl));
  QObject::connect(_reply, SIGNAL(finished()),
    this, SLOT(finishedSlot()));

	ui.pushButtonRunRequest->setEnabled(false);
}

void QUiFetchOctopart::finishedSlot()
{
	// Reading attributes of the reply
	// e.g. the HTTP status code
	QVariant statusCodeV =
    _reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	// Or the target URL if it was a redirect:
	QVariant redirectionTargetUrl =
    _reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
	// see CS001432 on how to handle this

	// no error received?
  if (_reply->error() == QNetworkReply::NoError)
	{
		// Example 2: Reading bytes form the reply
    QByteArray bytes = _reply->readAll();  // bytes
		QString string(bytes); // string
				
		_octoData = QJsonDocument::fromJson(bytes);
		interpretOctoData();
	}
	// Some http error received
	else
	{
		
		// handle errors here
	}

	// We receive ownership of the reply object
	// and therefore need to handle deletion.
  _reply->deleteLater();

	ui.pushButtonRunRequest->setEnabled(true);
}

void QUiFetchOctopart::interpretOctoData(){

	ui.listWidgetResults->clear();

	QJsonObject octo_data_object = _octoData.object();

	// parse all items
	QJsonArray results = octo_data_object["results"].toArray();
	foreach(const QJsonValue &value, results)
	{
		// get item global information
		QString part_mpn = value.toObject()["item"].toObject()["mpn"].toString();
		QString part_manufacturer = value.toObject()["item"].toObject()["manufacturer"].toObject()["name"].toString();
		QString description = value.toObject()["snippet"].toString();

		// get datasheet
		QJsonArray part_datasheets = value.toObject()["item"].toObject()["datasheets"].toArray();
		QString part_datasheet;
		foreach(const QJsonValue &part_data_value, part_datasheets){
			part_datasheet = part_data_value.toObject()["url"].toString();
		}

		// create entry
		QListWidgetItem *item = new QListWidgetItem(QString(), ui.listWidgetResults);
		QResultOctoItem *widget = new QResultOctoItem(ui.listWidgetResults);

		ui.listWidgetResults->addItem(item);
		ui.listWidgetResults->setItemWidget(item, widget);
		item->setSizeHint(widget->sizeHint());

		widget->ui.label->setText(QString("<strong>%0 - %1</strong><br/>%2").arg(part_manufacturer).arg(part_mpn).arg(description));

		// get all offers
		QJsonArray part_sellers = value.toObject()["item"].toObject()["offers"].toArray();
		foreach(const QJsonValue &part_value, part_sellers){

			QString part_seller = part_value.toObject()["seller"].toObject()["name"].toString();
			QString part_seller_sku = part_value.toObject()["sku"].toString();
			int part_seller_instockquantity = part_value.toObject()["in_stock_quantity"].toInt();
			
			QTreeWidgetItem *distItem = new QTreeWidgetItem(widget->ui.treeWidget);
			widget->ui.treeWidget->addTopLevelItem(distItem);

			distItem->setText(0, part_seller);
			distItem->setText(1, part_seller_sku);
			distItem->setText(2, QString::number(part_seller_instockquantity));

			// Search for USD prices and quantitys	
			QStringList currencyList = part_value.toObject()["prices"].toObject().keys();
			QString currency = "USD";
			if (currencyList.count())
				currency = currencyList[0];

			QJsonArray part_seller_price = part_value.toObject()["prices"].toObject()[currency].toArray();
			distItem->setText(3, currency);

			distItem->setText(4, "--");
			distItem->setText(5, "--");
			distItem->setText(6, "--");

			foreach(const QJsonValue &part_seller_quantity_price, part_seller_price){
				int part_seller_unit = part_seller_quantity_price.toArray().at(0).toInt();
				QString part_seller_unit_price = part_seller_quantity_price.toArray().at(1).toString();

				switch (part_seller_unit) {
					case 1: distItem->setText(4, part_seller_unit_price); break;
					case 100: distItem->setText(5, part_seller_unit_price); break;
					case 1000: distItem->setText(6, part_seller_unit_price); break;
					default: break;
				}
			}
		}

	}


}