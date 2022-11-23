#ifndef QLEDINDICATORAPI_H
#define QLEDINDICATORAPI_H

#include <QtCore/qglobal.h>

QT_BEGIN_NAMESPACE

#if 0
// pragma for syncqt, don't remove.
#pragma qt_class(QDesignerExportWidget)
#endif

#if defined(QDESIGNER_EXPORT_WIDGETS)
#  define QDESIGNER_WIDGET_EXPORT Q_DECL_EXPORT
#else
#  define QDESIGNER_WIDGET_EXPORT Q_DECL_IMPORT
#endif

QT_END_NAMESPACE

#endif // QLEDINDICATORAPI_H
