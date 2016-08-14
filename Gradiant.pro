#-------------------------------------------------
#
# Project created by QtCreator 2016-06-25T16:08:56
#
#-------------------------------------------------

#QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = Gradiant
#TEMPLATE = app


#SOURCES += main.cpp\
#        mainwindow.cpp\
#    gradientwindow.cpp

#HEADERS  += mainwindow.h\
#    gradientwindow.h

#FORMS    += mainwindow.ui

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gradiant
TEMPLATE = app

SOURCES += main.cpp\
    choosegradeswindow.cpp \
    chooseweights.cpp \
    entergradeswindow.cpp \
    resultswindow.cpp \
    startmenu.cpp \
    gradeclass.cpp

HEADERS  += \
    choosegradeswindow.h \
    chooseweights.h \
    entergradeswindow.h \
    resultswindow.h \
    startmenu.h \
    gradeclass.h

FORMS += \
    choosegradeswindow.ui \
    chooseweights.ui \
    entergradeswindow.ui \
    resultswindow.ui \
    startmenu.ui

