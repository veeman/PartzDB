#ifndef VERSION_H
#define VERSION_H

#define QUOTE(name) #name
#define STRQ(macro) QUOTE(macro)

#define VERSION_MAJOR		1
#define VERSION_MINOR		0
#define VERSION_REVISION	0
#define VERSION_BUILD		7

#if _DEBUG
  #if _WIN64
    #define PLATTFORM "x64 dbg"
	#define PLATTFORMS "x64d"
  #else
    #define PLATTFORM "x86 dbg"
	#define PLATTFORMS "x86d"
  #endif
#else
  #if _WIN64
    #define PLATTFORM "x64"
	#define PLATTFORMS "x64"
  #else
    #define PLATTFORM "x86"
	#define PLATTFORMS "x86"
  #endif
#endif

#define AUTHORS           "Vitalij Mast\nPhlipp Germann"
#define COMPANYNAME       "mage-dev"
#define FILEDESCRIPTION   "Easy Project Management"
#define INTERNALNAME      "PartzDB"
#define LEGALCOPYRIGHT    "Copyright (c) 2014 www.mage-dev.de"
#define ORIGINALFILENAME  "PartzDB.exe" 
#define PRODUCTNAME       "PartzDB"
#define FILEVERSN         VERSION_MAJOR,VERSION_MINOR,VERSION_REVISION,VERSION_BUILD
#define FILEVERS          STRQ(VERSION_MAJOR)    "." STRQ(VERSION_MINOR) "." \
                          STRQ(VERSION_REVISION) "." STRQ(VERSION_BUILD)
#define PRODUCTVERSN      FILEVERSN
#define PRODUCTVERS       FILEVERS

#endif // VERSION_H
