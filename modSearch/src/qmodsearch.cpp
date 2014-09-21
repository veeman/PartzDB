#include "stdafx.h"
#include "qmodsearch.h"
#include "quifetchoctopart.h"

QModSearch::QModSearch()
  : _menuSearch(0), _networkAccessManager(0), _tabWidget(0)
{

}

QModSearch::~QModSearch()
{

}

void QModSearch::setTabWidget(QTabWidget *widget)
{
  _tabWidget = widget;
}

void QModSearch::setNetworkManager(QNetworkAccessManager *nam)
{
  _networkAccessManager = nam;
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
  QUiFetchOctopart *search = new QUiFetchOctopart(_tabWidget, _networkAccessManager);
  _tabWidget->addTab(search, search->windowTitle());
  _tabWidget->setCurrentWidget(search);
}