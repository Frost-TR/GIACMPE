#-------------------------------------------------
#
# Project created by QtCreator 2016-04-02T00:54:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ICP
TEMPLATE = app

SOURCES += \
    Source/main.cpp \
    Source/mainwindow.cpp \
    Source/gamewindow.cpp \
    Source/gamedata.cpp \
    Source/gameinteligence.cpp \
    Source/gamelogic.cpp

HEADERS += \
    Headers/mainwindow.h \
    Headers/gamewindow.h \
    Headers/gamedata.h \
    Headers/gameinteligence.h \
    Headers/gamelogic.h

RESOURCES += \
    resources.qrc
