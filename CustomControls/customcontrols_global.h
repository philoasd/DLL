#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CUSTOMCONTROLS_LIB)
#  define CUSTOMCONTROLSSHARED_EXPORT Q_DECL_EXPORT
# else
#  define CUSTOMCONTROLSSHARED_EXPORT Q_DECL_IMPORT
# endif
#else
# define CUSTOMCONTROLSSHARED_EXPORT
#endif
