#ifndef QMODINTERFACES_H
#define QMODINTERFACES_H

#include <QtPlugin>
#include <QtWidgets/QMenuBar>
#include <QtNetwork/QNetworkAccessManager>
#include <QtWidgets/QTabWidget>

/*!
  \brief Virtual interface class provides access to the network manager.
*/
class QIModNetwork
{
public:
  /*!
    Destroys the interface.
  */
  virtual ~QIModNetwork() {}

  /*!
    Reimplement this function to get access to the network manager.
  */
  virtual void setNetworkManager(QNetworkAccessManager *nam) = 0;
};

/*!
  \brief Virtual interface class provides access to the menubar.
*/
class QIModMainMenu
{
public:
  /*!
    Destroys the interface.
  */
  virtual ~QIModMainMenu() {}

  /*!
    Reimplement this function to get access to the network manager.
  */
  virtual void populateMenu(QMenuBar *menu) = 0;
};

/*!
  \brief Virtual interface class provides access to the tabwidget of the main window.
*/
class QIModTabWidget
{
public:
  /*!
    Destroys the interface.
  */
  virtual ~QIModTabWidget() {}

  /*!
    Reimplement this function to get access to the tabwidget.
  */
  virtual void setTabWidget(QTabWidget *widget) = 0;
};

#define QIModNetworkIid   "org.partzdb.modules.network"
#define QIModMainMenuIid  "org.partzdb.modules.mainmenu"
#define QIModTabWidgetIid "org.partzdb.modules.tabwidget"

Q_DECLARE_INTERFACE(QIModNetwork, QIModNetworkIid)
Q_DECLARE_INTERFACE(QIModMainMenu, QIModMainMenuIid)
Q_DECLARE_INTERFACE(QIModTabWidget, QIModTabWidgetIid)

#endif // QMODINTERFACES_H