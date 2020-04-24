TEMPLATE        = lib
CONFIG         += plugin c++17
DEFINES        += QT_DEPRECATED_WARNINGS
QT             += widgets qml quick quickwidgets
TARGET          = karunit_camera_plugin
DESTDIR         = $$PWD/../karunit/app/plugins

LIBS += -L$$PWD/../karunit/plugininterface/ -lplugininterface
INCLUDEPATH += $$PWD/../karunit/plugininterface

LIBS += -L$$PWD/../karunit/common/ -lcommon
INCLUDEPATH += $$PWD/../karunit/common

LIBS += -L$$PWD/../karunit/third-party/xblog/ -lxblog
INCLUDEPATH += $$PWD/../karunit/third-party/xblog/src

SUBDIRS += \
    src/ \
    qml/

include(src/src.pri)
include(qml/qml.pri)

RESOURCES += \
    karunit_camera.qrc
