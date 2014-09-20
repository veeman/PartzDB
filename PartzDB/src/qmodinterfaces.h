#ifndef QMODINTERFACES_H
#define QMODINTERFACES_H

#include <QtPlugin>

class QAppModTabWidget
{
	public:
		virtual ~QAppModTabWidget() {}
};

#define QAppModTabWidgetIid "org.partzdb.modules.tabwidget"

Q_DECLARE_INTERFACE(QAppModTabWidget, QAppModTabWidgetIid)

#endif // QMODINTERFACES_H