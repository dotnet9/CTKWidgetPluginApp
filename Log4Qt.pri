# Log4Qt lib path
CONFIG += debug_and_release
CONFIG(debug, debug | release) {
    LOG4QT_LIB_PATH = $$(HMPUBLIC)/libs/mingw/debug/Log4Qt
} else {
    LOG4QT_LIB_PATH = $$(HMPUBLIC)/libs/mingw/release/Log4Qt
}

Log4QtSource = $$(HMPUBLIC)/include/Log4Qt

LIBS += -L$$LOG4QT_LIB_PATH -llog4qt

INCLUDEPATH += $$Log4QtSource/src \
               $$Log4QtSource/src/log4qt \
               $$Log4QtSource/include \
               $$Log4QtSource/include/log4qt

DEFINES += QT_MESSAGELOGCONTEXT
