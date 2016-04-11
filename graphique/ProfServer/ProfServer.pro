#-------------------------------------------------
#
# Project created by QtCreator 2016-04-10T14:01:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProfServer
TEMPLATE = app
QT += widgets network
DEPENDPATH += .
INCLUDEPATH += .

SOURCES += main.cpp\
        fenserveur.cpp

HEADERS  += fenserveur.h

FORMS    += fenserveur.ui
