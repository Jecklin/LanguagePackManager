QT += core
QT -= gui

CONFIG += c++11

TARGET = Manager
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    CLanguagePackManager.cpp \
    CLanguagePackManger2.cpp

HEADERS += \
    CLanguagePackManager.h \
    CLanguagePackManger2.h
