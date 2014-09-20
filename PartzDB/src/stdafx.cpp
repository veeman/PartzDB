/*!
    \file stdafx.cpp
*/
#include "stdafx.h"
#include "version.h"

#ifdef Q_OS_WIN
	#define LIBRARY_EXTENSION ".dll"
#else
	#define LIBRARY_EXTENSION ".so"
#endif

// Strings
const char* STR_TIMEFORMAT = "hh:mm:ss.zzz";                      //!< TODO
const char* STR_UNKNOWN = "unknown";                              //!< TODO
const char* STR_VERSION = "Version: %0 %1";                       //!< TODO

const char* STR_INITIALIZE = "Initalize";                         //!< TODO
const char* STR_LOAD_CONFIG = "Load Configuration";               //!< TODO
const char* STR_LOAD_MODULE = "Load Modules";		                  //!< TODO
const char* STR_LOAD_MODULES = "Load Module '%0'\t%1%";		        //!< TODO
const char* STR_SETUP_MODULES = "Setup Modules";                  //!< TODO

const char* STR_CFG_NOTFOUND = "Configuration file '%0' not found. Use default settings.";  //!< TODO
const char* STR_CFG_FAILED = "Failed to load configuration file '%0'. %1";  //!< TODO
const char* STR_CFG_LOADED = "Configuration file '%0' loaded.";  //!< TODO
const char* STR_MOD_FAILED = "Failed to load module '%0'";  //!< TODO
const char* STR_MOD_LOADED = "Module '%0' loaded.";  //!< TODO

// resources and file path
const char* RES_IMGSPLASHSCREEN = ":/res/splash.png";             //!< TODO
const char* RES_ICON_MAIN = ":/res/appicon.ico";                  //!< TODO
const char* RES_ICON_INFO = ":/res/info.png";                     //!< TODO
const char* RES_ICON_WARNING = ":/res/warning.png";               //!< TODO
const char* RES_ICON_CRITICAL = ":/res/critical.png";             //!< TODO
const char* PATH_CONFIG = "config.json";                          //!< TODO
const char* PATH_MODULES = "modules";							  //!< TODO
const char* FILTER_MODULES = "mod*" PLATTFORMS LIBRARY_EXTENSION; //!< TODO

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

const char** QUIAPPLOADER_STR_INIT = &STR_INITIALIZE;             //!< TODO
const char** QUIAPPLOADER_STR_LOADCONFIG = &STR_LOAD_CONFIG;      //!< TODO
const char** QUIAPPLOADER_STR_LOADMODULE = &STR_LOAD_MODULE;	    //!< TODO
const char** QUIAPPLOADER_STR_LOADMODULES = &STR_LOAD_MODULES;	  //!< TODO
const char** QUIAPPLOADER_STR_SETUPMODULES = &STR_SETUP_MODULES;	//!< TODO
const char** QUIAPPLOADER_MODULEPATH = &PATH_MODULES;			        //!< TODO
const char** QUIAPPLOADER_MODULEFILTER = &FILTER_MODULES;		      //!< TODO


const char** QSYSTEMTRAY_ICON = &RES_ICON_MAIN;                   //!< TODO

const char** QJSONCONFIG_PATH = &PATH_CONFIG;                     //!< TODO