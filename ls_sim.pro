#-------------------------------------------------
#
# Project created by QtCreator 2012-03-29T14:19:49
#
#-------------------------------------------------

QMAKE_CXXFLAGS += --std=c++0x

TEMPLATE = app

QT       -= gui

TARGET = ls_sim
CONFIG   += console
CONFIG   -= app_bundle
SOURCES += main.cpp

HEADERS += \
    verbalsaint.h \
    Directory.h \
    FileSize.h \
    PrintEng.h \
    ArgParser.h \
    Exception.h \
    BuildTree.h \
    mainheader.h

OTHER_FILES += \
    Request.txt
