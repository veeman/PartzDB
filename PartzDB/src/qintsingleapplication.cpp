#include "stdafx.h"
#include "qintsingleapplication.h"

QIntSingleApplication::QIntSingleApplication(int &argc, char **argv, bool GUIenabled)
  : QtSingleApplication(argc, argv, GUIenabled)
{

}


/*!
  \fn QIntSingleApplication::registerMessageHandle
  \brief Register an application message handler.
*/