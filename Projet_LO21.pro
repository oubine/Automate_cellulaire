QT += widgets
QT += xml
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

HEADERS += \
    main_UI.h \
    automate.h \
    etat.h \
    motif.h \
    index.h \
    automate1d.h \
    automate2d.h \
    Window.h

SOURCES += \
    main.cpp \
    main_ui.cpp \
    automate.cpp \
    etat.cpp \
    motif.cpp \
    index.cpp \
    automate1d.cpp \
    automate2d.cpp \
    Window.cpp

RESOURCES+=\
    ressources.qrc
