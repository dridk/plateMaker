#-------------------------------------------------
#
# Project created by QtCreator 2015-01-27T18:15:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlateMaker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paramwidget.cpp \
    finalgridwidget.cpp \
    parammodel.cpp

HEADERS  += mainwindow.h \
    paramwidget.h \
    finalgridwidget.h \
    parammodel.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons/icons.qrc

win32:RC_ICONS = app.ico



