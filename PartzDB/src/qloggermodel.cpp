#include "stdafx.h"
#include "qloggermodel.h"

// static icon sources, used by the QLoggerModel 
static const char *ICONPATHS[] = { *QLOGGERVIEW_ICONPATH_INFO, 
                                   *QLOGGERVIEW_ICONPATH_WARNING,
                                   *QLOGGERVIEW_ICONPATH_CRITICAL 
                                 };
static const Qt::GlobalColor FOREGROUNDCOLORS[] = { Qt::darkBlue, 
                                                    Qt::darkYellow, 
                                                    Qt::darkRed 
                                                  };

/*!
    \class QLoggerModel
    \brief The %QLoggerModel class provides a model for logging messages.

    This class is mainly used for logging user defined application messages, such as information, 
    warnings and errors. Therefore exist several log() functions, wich can be used to do this.

    \image html pic/qloggerview.png

    The upper output is given by the following example:
    \snippet src/ex_qloggermodel.cpp 0

    \sa QLoggerView log()
*/

/*!
    \enum QLoggerModel::Level
    Logging level is used to specify the message type and determinate also
    the particular display representation.

    \var QLoggerModel::Level QLoggerModel::Info
    Information (blue)

    \var QLoggerModel::Level QLoggerModel::Warning
    Warning (yellow)

    \var QLoggerModel::Level QLoggerModel::Critical
    Critical/Error (red)
*/

/*!
    Creates a new QLoggerModel with the given \a parent.
*/
QLoggerModel::QLoggerModel(QObject *parent)
  : QStandardItemModel(0, 0, parent)
{
    qDebug() << "QLoggerModel constructor";

    // load icons
    const QStyle *style = qApp->style();
    const quint32 iconOffset = static_cast<quint32>(QStyle::SP_MessageBoxInformation);
    const quint32 count = sizeof(ICONPATHS) / sizeof(char*);

    for (quint32 i = 0; i < count; ++i)
    {
        if (QFile::exists(ICONPATHS[i]))
            _iconList << QIcon(ICONPATHS[i]);
        else
            _iconList << style->standardIcon(static_cast<QStyle::StandardPixmap>(iconOffset + i));
    }
}

/*!
    Destroys the model.
*/
QLoggerModel::~QLoggerModel()
{
    qDebug() << "QLoggerModel destructor";
}

/*!
    Log a message.

    If the module should determinated automaticly use the function
    log(const Level level, const QString &message, const QObject *sender) instead.

    \param level One of the message level identifiers, e.g., Warning
    \param message The message
    \param module The calling module
*/
void QLoggerModel::log(const Level level, const QString &message, const QString &module)
{
    if (message.isEmpty())
        return;

    const quint32 iLevel = static_cast<quint32>(level);
    const QBrush textColor(FOREGROUNDCOLORS[iLevel]);

    const QString strTime = QTime::currentTime().toString(*QLOGGERVIEW_STR_TIMEFORMAT);
    const QString strModule = module.isEmpty() ? tr(*QLOGGERVIEW_STR_UNKNOWN) : module;
    const QString strMsg = QString("%0 [%1] %2").arg(strTime).arg(strModule).arg(message);

    QStandardItem *item = new QStandardItem(_iconList.at(iLevel), strMsg);
    item->setForeground(textColor);

    appendRow(item);
}

/*!
    Log a message, with one object parameter.

    \param level One of the message level identifiers, e.g., Warning
    \param message The message
    \param sender The calling object
*/
void QLoggerModel::log(const Level level, const QString &message, const QObject *sender)
{
    QString module;
    if (sender)
        module = sender->objectName();
    log(level, message, module);
}

/*!
    \fn QLoggerModel::info(const QString &message, const QString &module)
    
    Log a info  message.

    \param message The message
    \param module The calling module
*/

/*!
    \fn QLoggerModel::info(const QString &message, const QObject *sender)

    Log a info  message.

    \param message The message
    \param sender The calling object
*/

/*!
    \fn QLoggerModel::warning(const QString &message, const QString &module)

    Log a warning message.

    \param message The message
    \param module The calling module
*/

/*!
    \fn QLoggerModel::warning(const QString &message, const QObject *sender)

    Log a warning message.

    \param message The message
    \param sender The calling object
*/

/*!
    \fn QLoggerModel::critical(const QString &message, const QString &module)

    Log a critical message.

    \param message The message
    \param module The calling module
*/

/*!
    \fn QLoggerModel::critical(const QString &message, const QObject *sender)

    Log a critical message.

    \param message The message
    \param sender The calling object
*/