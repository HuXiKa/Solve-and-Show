#-------------------------------------------------
#
# Project created by QtCreator 2011-05-24T19:28:06
#
#-------------------------------------------------

QT       += core gui xml

TARGET = DataCreator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    variable.cpp \
    equation.cpp \
    mmlparser.cpp \
    independentlineedit.cpp \
    editabletabbar.cpp \
    editabletabwidget.cpp \
    equationgroup.cpp \
    curve.cpp

HEADERS  += mainwindow.h \
    variable.h \
    equation.h \
    mmlparser.h \
    independentlineedit.h \
    editabletabbar.h \
    editabletabwidget.h \
    equationgroup.h \
    curve.h

FORMS    += mainwindow.ui

RC_FILE = icon.rc