QT += widgets
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

HEADERS += \
    main_UI.h \
    autocell.h \
    automate_dim1.h \
    automate2.h

SOURCES += \
    main.cpp \
    main_ui.cpp \
    autocell.cpp \
    automate_dim1.cpp \
    automate2.cpp
