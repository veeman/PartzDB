#ifndef MODSEARCH_H
#define MODSEARCH_H

#include <QtCore/QObject>
#include "..\PartzDB\src\qmodinterfaces.h"

class QModSearch : public QObject, public QAppModTabWidget
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.partzdb.modules.tabwidget.search" FILE "modSearch.json")
	Q_INTERFACES(QAppModTabWidget)

public:
	QModSearch();
	~QModSearch();

private:

};

#endif // MODSEARCH_H
