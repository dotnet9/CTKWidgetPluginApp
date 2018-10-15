#ifndef LOG_GLOBAL_H
#define LOG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LOG_LIBRARY)
#  define LOGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LOGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LOG_GLOBAL_H
