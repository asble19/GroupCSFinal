QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    CReadFile.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    CReadFile.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc

DISTFILES += \
    ..\..\Desktop/input.txt \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/input.txt
