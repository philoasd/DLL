#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CANVASCORE_LIB)
#  define EASYCANVASCORESHARED_EXPORT Q_DECL_EXPORT
# else
#  define EASYCANVASCORESHARED_EXPORT Q_DECL_IMPORT
# endif
#else
# define EASYCANVASCORESHARED_EXPORT
#endif
