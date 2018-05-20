QT += widgets
QT += xml
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

CONFIG += console

HEADERS += \
    main_UI.h \
    autocell.h \
    automate_dim1.h \
    automate2.h \
    document_xml.h \
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
    automate_dim1.cpp \
    automate2.cpp \
    document_xml.cpp \
    automate.cpp \
    etat.cpp \
    automatemanager.cpp \
    simulateur.cpp \
    motif.cpp \
    index.cpp
