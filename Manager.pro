QT += core
QT -= gui

CONFIG += c++11

TARGET = Manager
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
#    CLanguagePackManager.cpp \
#    CLanguagePackManager2.cpp \
    CLanguagePackManager3.cpp 

HEADERS += \
#    CLanguagePackManager.h \
#    CLanguagePackManager2.h \
    CLanguagePackManager3.h
