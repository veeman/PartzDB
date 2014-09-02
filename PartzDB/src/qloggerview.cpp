#include "stdafx.h"
#include "qloggerview.h"

/*!
    \class QLoggerView
    \brief The %QLoggerView class provides a list view onto a model.

    A QLoggerView presents items stored in a model, preferred from QLoggerModel.
    Further more it display the logged messages and has the ability to select,
    copy and delete items provided by the underling model.

    Use setModel() to set a QLoggerModel.

    \sa QLoggerModel and QListView
*/

/*!
    Creates a new QLoggerView with the given \a parent to view a model.
    Use setModel() to set a QLoggerModel.
*/
QLoggerView::QLoggerView(QWidget *parent)
  : QListView(parent)
{
    setEditTriggers(QListView::NoEditTriggers);
    setSelectionMode(QAbstractItemView::ExtendedSelection);
    setAlternatingRowColors(true);
    setFont(QFont(*QLOGGERVIEW_FONT, QLOGGERVIEW_FONT_SIZE));
}

/*!
    Destroys the view.
*/
QLoggerView::~QLoggerView()
{
}

/*!
    Receive press events and interpret shotrcuts for select-all, copy and delete of items.
*/
void QLoggerView::keyPressEvent(QKeyEvent *event)
{
    if (event->matches(QKeySequence::SelectAll))
    {
        selectAll();
    } 
    else
    if (event->matches(QKeySequence::Copy))
    {
        const QModelIndexList idxList = selectedIndexes();
        if (!idxList.count())
            return;

        QStringList selectedText;
        foreach(auto item, idxList)
            selectedText << item.data(Qt::DisplayRole).toString();

        QApplication::clipboard()->setText(selectedText.join("\n"));
    }
    else
    if (event->matches(QKeySequence::Delete)) 
    {
        QModelIndexList idxList = selectedIndexes();
        qSort(idxList.begin(), idxList.end(), qGreater<QModelIndex>());

        foreach(auto item, idxList)
            model()->removeRow(item.row());
    }
    else
        QListView::keyPressEvent(event);
}