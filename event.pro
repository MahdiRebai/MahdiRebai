QT       += core gui
QT += sql
QT += printsupport
QT += charts
QT += serialport
QT       += core gui charts


QT       += sql core gui
QT       += svg
QT       += network
QT       += serialport
QT       += qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    avis.cpp \
    client.cpp \
    connection.cpp \
    evenement.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    paiement.cpp \
    penalite.cpp \
    qrcode.cpp \
    rdv.cpp \
    service.cpp \
    statclient.cpp \
    stats_event.cpp

HEADERS += \
    arduino.h \
    avis.h \
    client.h \
    connection.h \
    evenement.h \
    mainwindow.h \
    notification.h \
    paiement.h \
    penalite.h \
    rdv.h \
    service.h \
    statclient.h \
    stats_event.h
    qrcode.hpp
FORMS += \
    mainwindow.ui \
    statclient.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    RES.qrc

DISTFILES += \
    ../../Downloads/graphic.png \
    ../../Downloads/pdf.png \
    ../../Pictures/home1.png

