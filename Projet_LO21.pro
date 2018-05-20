QT += widgets
QT += xml
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

CONFIG += console

HEADERS += \
    main_UI.h \
    autocell.h \
    automate.h \
    etat.h \
    automatemanager.h \
    simulateur.h \
    motif.h \
    index.h

SOURCES += \
    main.cpp \
    main_ui.cpp \
    autocell.cpp \
    automate.cpp \
    etat.cpp \
    automatemanager.cpp \
    simulateur.cpp \
    motif.cpp \
    index.cpp
