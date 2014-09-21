#-------------------------------------------------
#
# Project created by QtCreator 2014-09-19T08:23:52
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrabalhoDeCG
CONFIG += console
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    arq_tratamento.cpp \
    face.cpp \
    vertice.cpp \
    objeto.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    arq_tratamento.h \
    face.h \
    vertice.h \
    objeto.h \
    vector4.h \
    matriz4.h \
    transformationLibrary.h

FORMS    += mainwindow.ui
