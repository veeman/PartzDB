#include "stdafx.h"
#include "qjsonconfig.h"

QJsonConfig::QJsonConfig()
  : QJsonObject()
{
  qDebug() << "QJsonConfig constructor";
}

QJsonConfig::~QJsonConfig()
{
  qDebug() << "QJsonConfig destructor";
}
