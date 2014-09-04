#include "stdafx.h"
#include "qjsonconfig.h"

QJsonConfig::QJsonConfig(const QString &fileName)
  : QJsonObject(), _fileName(fileName)
{
  
}

QJsonConfig::~QJsonConfig()
{
  
}

bool QJsonConfig::load(const QString &fileName)
{
  return true;
}

void QJsonConfig::setFileName(const QString &fileName)
{
  _fileName = fileName;
}
