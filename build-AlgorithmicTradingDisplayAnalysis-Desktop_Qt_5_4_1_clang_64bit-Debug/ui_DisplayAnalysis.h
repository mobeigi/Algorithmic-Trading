/********************************************************************************
** Form generated from reading UI file 'DisplayAnalysis.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYANALYSIS_H
#define UI_DISPLAYANALYSIS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayAnalysis
{
public:
    QAction *actionDsdsasdsd;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsGraphDisplay;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *DisplayAnalysis)
    {
        if (DisplayAnalysis->objectName().isEmpty())
            DisplayAnalysis->setObjectName(QStringLiteral("DisplayAnalysis"));
        DisplayAnalysis->resize(550, 550);
        DisplayAnalysis->setMinimumSize(QSize(550, 550));
        DisplayAnalysis->setLocale(QLocale(QLocale::English, QLocale::Australia));
        actionDsdsasdsd = new QAction(DisplayAnalysis);
        actionDsdsasdsd->setObjectName(QStringLiteral("actionDsdsasdsd"));
        centralWidget = new QWidget(DisplayAnalysis);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 524, 468));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsGraphDisplay = new QGraphicsView(scrollAreaWidgetContents);
        graphicsGraphDisplay->setObjectName(QStringLiteral("graphicsGraphDisplay"));

        verticalLayout->addWidget(graphicsGraphDisplay);

        scrollArea_2 = new QScrollArea(scrollAreaWidgetContents);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 496, 200));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea_2);


        gridLayout_2->addLayout(verticalLayout, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 2, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        DisplayAnalysis->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(DisplayAnalysis);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DisplayAnalysis->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DisplayAnalysis);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DisplayAnalysis->setStatusBar(statusBar);
        menuBar = new QMenuBar(DisplayAnalysis);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 550, 22));
        DisplayAnalysis->setMenuBar(menuBar);

        retranslateUi(DisplayAnalysis);

        QMetaObject::connectSlotsByName(DisplayAnalysis);
    } // setupUi

    void retranslateUi(QMainWindow *DisplayAnalysis)
    {
        DisplayAnalysis->setWindowTitle(QApplication::translate("DisplayAnalysis", "Display Analysis", 0));
        actionDsdsasdsd->setText(QApplication::translate("DisplayAnalysis", "dsdsasdsd", 0));
        label->setText(QApplication::translate("DisplayAnalysis", "<span style=\"color:blue\">Blue - Buy</span>", 0));
        label_2->setText(QApplication::translate("DisplayAnalysis", "<html><head/><body><p><span style=\" color:#009940;\">Green - Sell</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class DisplayAnalysis: public Ui_DisplayAnalysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYANALYSIS_H
