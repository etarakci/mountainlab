#-------------------------------------------------
#
# Project created by QtCreator 2016-08-04T17:50:49
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

DESTDIR = ..
TARGET = tst_mlcomputetest
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_mlcomputetest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
include(../setupdirs.pri)
include($${MOUNTAINLAB_CPP}/mlcommon/mlcommon.pri)
