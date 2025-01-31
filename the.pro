QT += core gui widgets multimedia multimediawidgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        headerButtons.cpp \
        icon.cpp \
        scrub.cpp \
        the_player.cpp \
        snapcap.cpp \
        settings_page.cpp \
        tool.cpp \
        toolbox.cpp

HEADERS += \
    headerButtons.h \
    icon.h \
    scrub.h \
    the_player.h \
    settings_page.h \
    tool.h \
    toolbox.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons/icons.qrc

DISTFILES +=
