#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>
#include <QtWidgets/QStyle>
#include <QtWidgets/QSystemTrayIcon>

#include <QtGui/QClipboard>
#include <QtGui/QKeyEvent>

#include <QtCore/QFile>
#include <QtCore/QTime>
#include <QtCore/qglobal.h>
#include <QtCore/QDebug>

#include <QtSingleApplication>
#include "qintsingleapplication.h"

extern const char*  STR_VERSION;
extern const char*  STR_CFG_NOTFOUND;  
extern const char*  STR_CFG_FAILED;  
extern const char*  STR_CFG_LOADED;  
extern const char*  STR_MOD_FAILED;
extern const char*  STR_MOD_LOADED;

extern const char** QLOGGERVIEW_FONT;
extern quint32      QLOGGERVIEW_FONT_SIZE;
extern const char** QLOGGERVIEW_ICONPATH_INFO;
extern const char** QLOGGERVIEW_ICONPATH_WARNING;
extern const char** QLOGGERVIEW_ICONPATH_CRITICAL;
extern const char** QLOGGERVIEW_STR_TIMEFORMAT;
extern const char** QLOGGERVIEW_STR_UNKNOWN;

extern const char** QUIABOUT_FONT;
extern const char** QUIABOUT_BGRES;

extern const char** QUIAPPLOADER_STR_INIT;
extern const char** QUIAPPLOADER_STR_LOADCONFIG;
extern const char** QUIAPPLOADER_STR_LOADMODULE;
extern const char** QUIAPPLOADER_STR_LOADMODULES;
extern const char** QUIAPPLOADER_STR_SETUPMODULES;
extern const char** QUIAPPLOADER_MODULEPATH;
extern const char** QUIAPPLOADER_MODULEFILTER;

extern const char** QSYSTEMTRAY_ICON;

extern const char** QJSONCONFIG_PATH;