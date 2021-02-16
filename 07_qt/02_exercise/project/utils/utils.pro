QT -= gui

TEMPLATE = lib
DEFINES += UTILS_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acceleration.cpp \
    displacement.cpp \
    speed.cpp \
    utils.cpp

HEADERS += \
    acceleration.h \
    displacement.h \
    speed.h \
    utils_global.h \
    utils.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
