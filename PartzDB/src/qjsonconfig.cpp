#include "stdafx.h"
#include "qjsonconfig.h"

/*!
    \class QJsonConfig
    \brief The %QJsonConfig class manages the loading and saving of configuration files.
*/

/*!
    \brief Creates a new QJsonConfig with the given \a fileName.
    The specifed file can either loaded or saved by calling the corrosponding function.

    The configruation data can be set by setData() or received by calling data().

    \sa save() load()
*/
QJsonConfig::QJsonConfig(const QString &fileName)
  : _configData(), _fileName(fileName)
{
  
}

/*!
    Destroys the QJsonConfig class.

    \note The current configuration data is not explictly saved. Call save() before desturction.
*/
QJsonConfig::~QJsonConfig()
{
  
}

/*!
    Try to load the specified configurationy file.

    \param fileName Optional, the filename wich should be loaded. 
                    If not specified use internal stored file name.
    \return True if no error.
*/
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

/*!
    Try to save the specified configurationy file.

    \param fileName Optional, the filename of the destination file.
                    If not specified use internal stored file name.
    \return True if no error.
*/
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

/*!
  \fn QJsonConfig::data()
  Reutrns the current stored JSON cinfiguration
  \sa setData()
*/

/*!
    Assign a new JSON configuration object \a config.
*/
void QJsonConfig::setData(const QJsonObject &config)
{
  _configData = config;
}

/*!
    \fn QJsonConfig::fileName()
    Reutrns the current assigned filename.
    \sa setFileName()
*/

/*!
    Assign a new /a fileName, wich is used for load or save a configuration file.
*/
void QJsonConfig::setFileName(const QString &fileName)
{
  if (!fileName.isEmpty())
    _fileName = fileName;
}

/*!
    \fn QJsonConfig::error()
    Reutrns the error messages generated by the last loading process.
*/