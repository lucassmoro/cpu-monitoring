TARGET = program
TEMPLATE = app

# Bibliotecas do Qt necessárias
QT += core gui widgets

SOURCES += main.cpp \
           monitor.cpp \
           mainwindow.cpp

HEADERS += monitor.h \
            mainwindow.h

FORMS += mainwindow.ui

