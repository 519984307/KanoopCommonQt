QT       += network
QT       -= gui

TEMPLATE = lib

CONFIG += c++11

unix {
    QMAKE_CXXFLAGS += -Wno-format-nonliteral -Wno-format-security
    TARGET = KanoopCommon
}

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += KANOOP_LIBRARY
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# load qmake variables which need to be brought in from from environment
OUTPUT_PREFIX=$$(OUTPUT_PREFIX)
IS_TARGET_BUILD=$$(IS_TARGET_BUILD)

if(!isEmpty(OUTPUT_PREFIX):isEmpty(IS_TARGET_BUILD)) {
    OUTPUT_PREFIX=$$OUTPUT_PREFIX/target/$$basename(QMAKESPEC)
}

target.path = $$OUTPUT_PREFIX/usr/lib

SOURCES += \
    addresshelper.cpp \
    datetimeutil.cpp \
    fileutil.cpp \
    jsonhelper.cpp \
    klog.cpp \
    mutexevent.cpp \
    pathutil.cpp \
    ratemonitor.cpp \
    timespan.cpp

HEADERS += \
    addresshelper.h \
    datetimeutil.h \
    fileutil.h \
    jsonhelper.h \
    kanoopcommon.h \
    klog.h \
    lockingqueue.h \
    mutexevent.h \
    pathutil.h \
    ratemonitor.h \
    timeconstants.h \
    timespan.h

header_files.files = $$HEADERS
header_files.path = $$OUTPUT_PREFIX/usr/include/Kanoop

INSTALLS += target
INSTALLS += header_files

QMAKE_POST_LINK=$(MAKE) install
