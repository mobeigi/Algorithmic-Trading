#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T12:41:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AlgorithmicTradingDisplayAnalysis
TEMPLATE = app


SOURCES += main.cpp\
        DisplayAnalysis.cpp \
    AnalysisData.cpp \
    ParseCSVData.cpp

HEADERS  += DisplayAnalysis.h \
    AnalysisData.h \
    ParseCSVData.h

FORMS    += DisplayAnalysis.ui

CONFIG += c++11
