#ifndef MODSEARCH_H
#define MODSEARCH_H

#include <QtCore/QObject>
#include "..\PartzDB\src\qmodinterfaces.h"

class QModSearch : public QObject,
                   public QIModMainMenu
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.partzdb.modules.tabwidget.search" FILE "modSearch.json")
  Q_INTERFACES(QIModMainMenu)

public:
	QModSearch();
	~QModSearch();

  void populateMenu(QMenuBar *menu);

protected slots:
  void on_menuSearch_triggered();

private:
  QAction *_menuSearch;
};

#endif // MODSEARCH_H
