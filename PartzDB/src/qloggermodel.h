#ifndef QLOGGERMODEL_H
#define QLOGGERMODEL_H

#include <QtGui/QStandardItemModel>

class QLoggerModel : public QStandardItemModel
{
  Q_OBJECT
  Q_ENUMS(Level);

public:
  explicit QLoggerModel(QObject * parent = 0);
  ~QLoggerModel();

  enum Level { Info, Warning, Critical };
  
public slots:
  void log(const Level level, const QString &message, const QString &module);
  void log(const Level level, const QString &message, const QObject *sender = 0);
  inline void info(const QString &message, const QString &module);
  inline void warning(const QString &message, const QString &module);
  inline void critical(const QString &message, const QString &module);
  inline void info(const QString &message, const QObject *sender = 0);
  inline void warning(const QString &message, const QObject *sender = 0);
  inline void critical(const QString &message, const QObject *sender = 0);

private:
  QList<QIcon> _iconList;  //!< Message icons: info, warning and error icon. In this order.
};

inline void QLoggerModel::info(const QString &message, const QString &module)
{
  log(QLoggerModel::Info, message, module);
}

inline void QLoggerModel::warning(const QString &message, const QString &module)
{
  log(QLoggerModel::Warning, message, module);
}

inline void QLoggerModel::critical(const QString &message, const QString &module)
{
  log(QLoggerModel::Critical, message, module);
}

inline void QLoggerModel::info(const QString &message, const QObject *sender)
{
  log(QLoggerModel::Info, message, sender);
}

inline void QLoggerModel::warning(const QString &message, const QObject *sender)
{
  log(QLoggerModel::Warning, message, sender);
}

inline void QLoggerModel::critical(const QString &message, const QObject *sender)
{
  log(QLoggerModel::Critical, message, sender);
}

#endif // QLOGGERMODEL_H
