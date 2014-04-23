TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    launch_tests.c \
    cm_string_tests.c \
    cm_helpers_tests.c \
    cm_test_base.c

HEADERS += \
    cm_string_tests.h \
    cm_helpers_tests.h \
    cm_test_base.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-c-mantras-Desktop-Debug/release/ -lc-mantras
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-c-mantras-Desktop-Debug/debug/ -lc-mantras
else:unix: LIBS += -L$$PWD/../build-c-mantras-Desktop-Debug/ -lc-mantras

INCLUDEPATH += $$PWD/../c-mantras
DEPENDPATH += $$PWD/../c-mantras
