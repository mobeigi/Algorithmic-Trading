#-------------------------------------------------
#
# Project created by QtCreator 2015-03-13T08:42:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AlgorithmicTrading
TEMPLATE = app
CONFIG += c++11


SOURCES +=\
        mainwindow.cpp \
    main.cpp \ 
    AnalysisData.cpp \
    ParseCSVData.cpp \
    AnalysisDisplays.cpp \
    DisplayAnalysis.cpp \
    QuantPara.cpp \
    ParamAnalysisHelper.cpp \
    ParamSet.cpp \
    SummaryForm.cpp \
    QuantitativeAnalysisDisplay.cpp \
    CamelPushButton.cpp

HEADERS  += mainwindow.h\
         GlobalIncludes.h \ 
    AnalysisData.h \
    ParseCSVData.h \
    AnalysisDisplays.h \
    DisplayAnalysis.h \
    QuantPara.h \
    ParamAnalysisHelper.h \
    ParamSet.h \
    MyTabWindow.h \
    SummaryForm.h \
    QuantitativeAnalysisDisplay.h \
    CamelPushButton.h

FORMS    += mainwindow.ui \
    DisplayAnalysis.ui \
    summaryform.ui \
    QuantitativeAnalysisDisplay.ui

RC_FILE = iconise.rc

QMAKE_LFLAGS += -Wl,-rpath,"'\$$ORIGIN'"
