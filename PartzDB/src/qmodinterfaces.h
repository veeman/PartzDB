#ifndef QMODINTERFACES_H
#define QMODINTERFACES_H

#include <QtPlugin>
#include <QtWidgets/QMenuBar>
#include <QtNetwork/QNetworkAccessManager>
#include <QtWidgets/QTabWidget>

class QIModNetwork
{
public:
  virtual ~QIModNetwork() {}
  virtual void setNetworkManager(QNetworkAccessManager *nam) = 0;
};

class QIModMainMenu
{
public:
  virtual ~QIModMainMenu() {}
  virtual void populateMenu(QMenuBar *menu) = 0;
};

class QIModTabWidget
{
public:
  virtual ~QIModTabWidget() {}
  virtual void setTabWidget(QTabWidget *widget) = 0;
};

#define QIModNetworkIid   "org.partzdb.modules.network"
#define QIModMainMenuIid  "org.partzdb.modules.mainmenu"
#define QIModTabWidgetIid "org.partzdb.modules.tabwidget"

Q_DECLARE_INTERFACE(QIModNetwork, QIModNetworkIid)
Q_DECLARE_INTERFACE(QIModMainMenu, QIModMainMenuIid)
Q_DECLARE_INTERFACE(QIModTabWidget, QIModTabWidgetIid)

#endif // QMODINTERFACES_H