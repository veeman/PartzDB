#ifndef QMODINTERFACES_H
#define QMODINTERFACES_H

#include <QtPlugin>
#include <QtWidgets/QMenuBar>

class QIModTabWidget
{
public:
  virtual ~QIModTabWidget() {}
};

class QIModMainMenu
{
public:
  virtual ~QIModMainMenu() {}
  virtual void populateMenu(QMenuBar *menu) = 0;
};

#define QIModTabWidgetIid "org.partzdb.modules.tabwidget"
#define QIModMainMenuIid  "org.partzdb.modules.mainmenu"

Q_DECLARE_INTERFACE(QIModTabWidget, QIModTabWidgetIid)
Q_DECLARE_INTERFACE(QIModMainMenu, QIModMainMenuIid)

#endif // QMODINTERFACES_H