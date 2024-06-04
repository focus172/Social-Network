QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/network/network.cpp \
    src/network/post.cpp \
    src/network/user.cpp \
    src/pages/makepostpage.cpp \
    src/widgets/postwidget.cpp \
    src/pages/loginpage.cpp \
    src/pages/profilepage.cpp \
    src/socialnetworkwindow.cpp

HEADERS += \
    src/network/network.h \
    src/network/post.h \
    src/network/user.h \
    src/pages/makepostpage.h \
    src/widgets/postwidget.h \
    src/pages/loginpage.h \
    src/pages/profilepage.h \
    src/socialnetworkwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
