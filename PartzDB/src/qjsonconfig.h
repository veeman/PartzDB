#ifndef QJSONCONFIG_H
#define QJSONCONFIG_H

#include <QtCore/QJsonObject>

class QJsonConfig
{
public:
  QJsonConfig(const QString &fileName = QString());
  ~QJsonConfig();

  bool load(const QString &fileName = QString());
  bool save(const QString &fileName = QString());

  void setFileName(const QString &fileName = QString());
  void setData(const QJsonObject &config);

  QString fileName() const;
  QJsonObject data() const;
  QString error() const;

protected:
  QJsonObject _configData;  //!< Internal JSON structure

private:
  QJsonParseError _error;   //!< Error state of last loaded file
  QString _fileName;        //!< Current selected filename
};

inline QString QJsonConfig::fileName() const
{
  return _fileName;
}

inline QJsonObject QJsonConfig::data() const
{
  return _configData;
}

inline QString QJsonConfig::error() const
{
  return _error.errorString();
}

#endif // QJSONCONFIG_H
