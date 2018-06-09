QT += widgets
QT += xml
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

CONFIG += console

HEADERS += \
    main_UI.h \
    automate.h \
    etat.h \
    automatemanager.h \
    simulateur.h \
    motif.h \
    index.h \
    automate1d.h \
    automate2d.h \
    Window.h \
    intervalleabr.h

SOURCES += \
    main.cpp \
    main_ui.cpp \
    automate.cpp \
    etat.cpp \
    automatemanager.cpp \
    simulateur.cpp \
    motif.cpp \
    index.cpp \
    automate1d.cpp \
    automate2d.cpp \
    Window.cpp \
    intervalleabr.cpp

RESOURCES+=\
    ressources.qrc
