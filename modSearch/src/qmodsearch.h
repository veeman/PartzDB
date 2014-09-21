#ifndef MODSEARCH_H
#define MODSEARCH_H

#include <QtCore/QObject>
#include "..\PartzDB\src\qmodinterfaces.h"

class QModSearch : public QObject,
                   public QIModTabWidget,
                   public QIModMainMenu,
                   public QIModNetwork
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.partzdb.modules.tabwidget.search" FILE "modSearch.json")
  Q_INTERFACES(QIModMainMenu QIModTabWidget QIModNetwork)

public:
	QModSearch();
	~QModSearch();

  void setNetworkManager(QNetworkAccessManager *nam);
  void setTabWidget(QTabWidget *widget);
  void populateMenu(QMenuBar *menu);

protected slots:
  void on_menuSearch_triggered();

private:
  QAction *_menuSearch;
  QNetworkAccessManager *_networkAccessManager;
  QTabWidget *_tabWidget;
};

#endif // MODSEARCH_H
