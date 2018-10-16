# CTK install directory path
CONFIG += debug_and_release
CONFIG(debug, debug | release) {
    CTK_INSTALL_PATH = $$(HMPUBLIC)/libs/mingw/debug/CTKInstall
}
else {
    CTK_INSTALL_PATH = $$(HMPUBLIC)/libs/mingw/release/CTKInstall
}
CTKSource = $$(HMPUBLIC)/include/CTK

# CTK plugin lib directory path(such as: libCTKCore.lib、libCTKPluginFramework.lib)
CTK_LIB_PATH = $$CTK_INSTALL_PATH/lib/ctk-0.1

# CTK install include direcotry path(such as: ctkPluginFramework.h)
CTK_INCLUDE_INSTALL_PATH = $$CTK_INSTALL_PATH/include/ctk-0.1

# CTK source framework include directory path
CTK_INCLUDE_SOURCE_FRAMEWORK_PATH = $$CTKSource/Libs/PluginFramework

LIBS += -L$$CTK_LIB_PATH -llibCTKCore -llibCTKPluginFramework

INCLUDEPATH += $$CTK_INCLUDE_INSTALL_PATH \
               $$CTK_INCLUDE_SOURCE_FRAMEWORK_PATH
