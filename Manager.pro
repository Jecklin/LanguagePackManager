QT += core
QT -= gui

CONFIG += c++11

TARGET = Manager
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    CLanguagePackManager.cpp

HEADERS += \
    CLanguagePackManager.h
