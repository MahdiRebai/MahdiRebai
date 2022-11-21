#-------------------------------------------------
#
# Project created by QtCreator 2022-10-02T22:00:18
#
#-------------------------------------------------

QT       += core gui sql
QT += printsupport
QT       += core gui charts
QT       +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestion_des_services
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        arduino.cpp \
        connection.cpp \
        main.cpp \
        mainwindow.cpp \
        service.cpp

HEADERS += \
        arduino.h \
        connection.h \
        mainwindow.h \
        service.h

FORMS += \
        mainwindow.ui
