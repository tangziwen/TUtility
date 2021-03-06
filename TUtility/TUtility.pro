TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
SOURCES += \
    test.cpp \
    log/Tlog.cpp \
    string/Tstring.cpp \
    log/TstatckTrace.cpp \
    math/TbaseMath.cpp \
    math/Tvector.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    log/Tlog.h \
    TUtility.h \
    string/Tstring.h \
    log/TstatckTrace.h \
    math/TbaseMath.h \
    math/Tvector.h

