#-------------------------------------------------
#
# Project created by QtCreator 2018-10-15T23:18:32
#
#-------------------------------------------------

QT       += widgets

QT       += gui core

TARGET = Client1
TEMPLATE = lib

include(../../CTK.pri)
INCLUDEPATH += ../../include


CONFIG(debug, debug|release){
    DESTDIR = ../../../CTKWidgetPluginApp/bin/debug/plugins
} else {
    DESTDIR = ../../../CTKWidgetPluginApp/bin/release/plugins
}

DEFINES += CLIENT1_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    client1activator.h \
    client1plugin.h \
    client1dlg.h

SOURCES += \
    client1activator.cpp \
    client1plugin.cpp \
    client1dlg.cpp

RESOURCES += \
    client1.qrc

FORMS += \
    client1dlg.ui
