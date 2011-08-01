QT       += xml script

HEADERS += mainwindow.h \
    abbrevations.h \
    coordinatesystem.h \
    settingsdialog.h \
    initdialog.h \
    edouble.h \
    fiscaldialog.h \
    monetarydialog.h \
    ecurve.h \
    modelsettingsdialog.h \    
    equation.h \
    mmlparser.h \
    equationgroup.h \
    equationtab.h \
    addequationdialog.h
SOURCES += mainwindow.cpp \
    main.cpp \
    coordinatesystem.cpp \
    settingsdialog.cpp \
    initdialog.cpp \
    abbrevations.cpp \
    edouble.cpp \
    fiscaldialog.cpp \
    monetarydialog.cpp \
    ecurve.cpp \
    modelsettingsdialog.cpp \
    equation.cpp \
    mmlparser.cpp \
    equationgroup.cpp \
    equationtab.cpp \
    addequationdialog.cpp
FORMS += mainwindow.ui \
    settingsdialog.ui \
    initdialog.ui \
    fiscaldialog.ui \
    monetarydialog.ui \
    modelsettingsdialog.ui \
    equationtab.ui \
    addequationdialog.ui
TRANSLATIONS = economydisplayer_hu.ts \
               economydisplayer_en.ts

RESOURCES += \
    icons.qrc

RC_FILE = icon.rc
