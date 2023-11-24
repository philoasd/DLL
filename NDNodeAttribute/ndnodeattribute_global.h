#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(NDNODEATTRIBUTE_LIB)
#  define NDNODEATTRIBUTESHARED_EXPORT Q_DECL_EXPORT
# else
#  define NDNODEATTRIBUTESHARED_EXPORT Q_DECL_IMPORT
# endif
#else
# define NDNODEATTRIBUTESHARED_EXPORT
#endif
