QT       += core gui
QT += sql
<<<<<<< HEAD
<<<<<<< HEAD

=======
QT += printsupport
QT += charts
QT += serialport
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
QT += printsupport
QT += charts
QT += serialport
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
    arduino.cpp \
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
    connection.cpp \
    evenement.cpp \
    main.cpp \
    mainwindow.cpp \
    penalite.cpp \
    service.cpp \
    stats_event.cpp

HEADERS += \
    arduino.h \
    connection.h \
    evenement.h \
<<<<<<< HEAD
    mainwindow.h
=======
    arduino.cpp \
    connection.cpp \
    evenement.cpp \
    main.cpp \
    mainwindow.cpp \
    penalite.cpp \
    service.cpp \
    stats_event.cpp

HEADERS += \
    arduino.h \
    connection.h \
    evenement.h \
=======
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
    mainwindow.h \
    penalite.h \
    service.h \
    stats_event.h
<<<<<<< HEAD
>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    RES.qrc

DISTFILES += \
<<<<<<< HEAD
<<<<<<< HEAD
    ../../Pictures/home1.png
=======
    ../../Downloads/pdf.png \
    ../../Pictures/home1.png

>>>>>>> d417753b0206d5dcaf751e7329a8634bb1685c15
=======
    ../../Downloads/pdf.png \
    ../../Pictures/home1.png

>>>>>>> 0ab4f713885d0fe53e6e35a8fab2b7c8e8d296d1
