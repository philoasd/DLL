#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CUSTOMWIDGETS_LIB)
#  define CUSTOMWIDGETSSHARED_EXPORT Q_DECL_EXPORT
# else
#  define CUSTOMWIDGETSSHARED_EXPORT Q_DECL_IMPORT
# endif
#else
# define CUSTOMWIDGETSSHARED_EXPORT
#endif
