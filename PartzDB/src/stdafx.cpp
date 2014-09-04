/*!
    \file stdafx.cpp
*/
#include "stdafx.h"

// Strings
const char* STR_TIMEFORMAT = "hh:mm:ss.zzz";                      //!< TODO
const char* STR_UNKNOWN = "unknown";                              //!< TODO
const char* STR_VERSION = "Version: %0 %1";                       //!< TODO

// resources and file path
const char* RES_IMGSPLASHSCREEN = ":/res/splash.png";             //!< TODO
const char* RES_ICON_MAIN = ":/res/appicon.ico";                  //!< TODO
const char* RES_ICON_INFO = ":/res/info.png";                     //!< TODO
const char* RES_ICON_WARNING = ":/res/warning.png";               //!< TODO
const char* RES_ICON_CRITICAL = ":/res/critical.png";             //!< TODO
const char* PATH_CONFIG = "/config.json";                         //!< TODO

// font family
const char* FONT_COURIERNEW = "Courier New";                      //!< TODO
const char* FONT_ARIAL = "Arial";                                 //!< TODO

// object Properties
const char** QLOGGERVIEW_FONT = &FONT_COURIERNEW;                 //!< TODO
quint32      QLOGGERVIEW_FONT_SIZE = 10;                          //!< TODO
const char** QLOGGERVIEW_ICONPATH_INFO = &RES_ICON_INFO;          //!< TODO
const char** QLOGGERVIEW_ICONPATH_WARNING = &RES_ICON_WARNING;    //!< TODO
const char** QLOGGERVIEW_ICONPATH_CRITICAL = &RES_ICON_CRITICAL;  //!< TODO
const char** QLOGGERVIEW_STR_TIMEFORMAT = &STR_TIMEFORMAT;        //!< TODO
const char** QLOGGERVIEW_STR_UNKNOWN = &STR_UNKNOWN;              //!< TODO

const char** QUIABOUT_FONT = &FONT_ARIAL;                         //!< TODO
const char** QUIABOUT_BGRES = &RES_IMGSPLASHSCREEN;               //!< TODO

const char** QSYSTEMTRAY_ICON = &RES_ICON_MAIN;                   //!< TODO

const char** QJSONCONFIG_PATH = &PATH_CONFIG;                     //!< TODO