QT += core
QT -= gui

CONFIG += c++11

TARGET = QtCommandLine
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    commandline.cpp

HEADERS += \
    commandline.h
