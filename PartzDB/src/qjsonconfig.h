#ifndef QJSONCONFIG_H
#define QJSONCONFIG_H

#include <QtCore/QJsonObject>

class QJsonConfig : public QJsonObject
{
public:
  QJsonConfig(const QString &fileName = QString());
  ~QJsonConfig();

  bool load(const QString &fileName = QString());
  void setFileName(const QString &fileName = QString());
  QString getFileName() const;

private:
  QString _fileName;
};

inline QString QJsonConfig::getFileName() const
{
  return _fileName;
}

#endif // QJSONCONFIG_H
