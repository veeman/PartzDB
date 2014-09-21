#include "stdafx.h"
#include "qmodsearch.h"

QModSearch::QModSearch()
  : _menuSearch(0)
{

}

QModSearch::~QModSearch()
{

}

void QModSearch::populateMenu(QMenuBar *menu)
{
  QMenu* menuNew = menu->findChild<QMenu*>("menuNew");
  if (menuNew)
  {
    _menuSearch = new QAction("&Search (octopart.com)", this);
    menuNew->addAction(_menuSearch);
    connect(_menuSearch, SIGNAL(triggered()), this, SLOT(on_menuSearch_triggered()));
  }
}

void QModSearch::on_menuSearch_triggered()
{
  // add widget
}