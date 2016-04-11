#-------------------------------------------------
#
# Project created by QtCreator 2016-04-10T16:58:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client4
TEMPLATE = app
QT += widgets network

DEPENDPATH += .
INCLUDEPATH += .

SOURCES += main.cpp\
        fenclient.cpp

HEADERS  += fenclient.h

FORMS    += fenclient.ui

RESOURCES += \
    imags.qrc
