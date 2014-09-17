#include "stdafx.h"
#include "qjsonconfig.h"

QJsonConfig::QJsonConfig(const QString &fileName)
  : _configData(), _fileName(fileName)
{
  
}

QJsonConfig::~QJsonConfig()
{
  
}

bool QJsonConfig::load(const QString &fileName)
{
  setFileName(fileName);

  if (_fileName.isEmpty())
    return false;
  
  QFile inpFile(_fileName);
  if (!inpFile.open(QIODevice::ReadOnly))
    return false;

  QByteArray data = inpFile.readAll();
  QJsonDocument doc(QJsonDocument::fromJson(data, &_error));
  _configData = doc.object();

  return _error.error == QJsonParseError::NoError;
}

bool QJsonConfig::save(const QString &fileName)
{
  setFileName(fileName);

  if (_fileName.isEmpty())
    return false;

  QFile outFile(_fileName);
  if (!outFile.open(QIODevice::WriteOnly))
    return false;

  QJsonDocument doc(_configData);
  outFile.write(doc.toJson());

  return true;
}

void QJsonConfig::setData(const QJsonObject &config)
{
  _configData = config;
}

void QJsonConfig::setFileName(const QString &fileName)
{
  if (!fileName.isEmpty())
    _fileName = qApp->buildRelativeFilePath(fileName);
}
