#-------------------------------------------------
#
# Project created by QtCreator 2014-11-29T15:50:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PPP
TEMPLATE = app


SOURCES += \
    Game.cpp\
    main.cpp\
    newScene.cpp\
    Scene.cpp\
    StartScene.cpp\
    Window.cpp\
    mainwindow.cpp \
    loadscene.cpp \
    shopscene.cpp \
    olympicnanido.cpp \
    selectscene.cpp \
    selectsinglescene.cpp
HEADERS  += \
    Game.h\
    newScene.h\
    Scene.h\
    StartScene.h\
    Window.h\
    Global.h\
    mainwindow.h \
    loadscene.h \
    shopscene.h \
    olympicnanido.h \
    selectscene.h \
    selectsinglescene.h

DESTDIR += \
    Resources \


FORMS    += mainwindow.ui
