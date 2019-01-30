# CTK install directory path
CONFIG += debug_and_release

# CTK plugin lib directory path(such as: libCTKCore.lib、libCTKPluginFramework.lib)
CONFIG(debug, debug | release) {
    CTK_INSTALL_PATH = $$PWD/lib/debug
}
else {
    CTK_INSTALL_PATH = $$PWD/lib/release
}
CTK_LIB_PATH = $$CTK_INSTALL_PATH


LIBS += -L$$CTK_LIB_PATH -lCTKCore -lCTKPluginFramework

INCLUDEPATH += $$PWD/include \
               $$PWD/include/core \
               $$PWD/include/pluginFramework
