/********************************************************************************
** Form generated from reading UI file 'DisplayAnalysis.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QTableWidget>
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
    QWidget *scrollViewGraph;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsGraphDisplay;
    QTableWidget *returnsAnalysis;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLabel *net_return_value_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *DisplayAnalysis)
    {
        if (DisplayAnalysis->objectName().isEmpty())
            DisplayAnalysis->setObjectName(QStringLiteral("DisplayAnalysis"));
        DisplayAnalysis->resize(750, 750);
        DisplayAnalysis->setMinimumSize(QSize(700, 700));
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
        scrollViewGraph = new QWidget();
        scrollViewGraph->setObjectName(QStringLiteral("scrollViewGraph"));
        scrollViewGraph->setGeometry(QRect(0, 0, 730, 677));
        gridLayout_2 = new QGridLayout(scrollViewGraph);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsGraphDisplay = new QGraphicsView(scrollViewGraph);
        graphicsGraphDisplay->setObjectName(QStringLiteral("graphicsGraphDisplay"));

        verticalLayout->addWidget(graphicsGraphDisplay);

        returnsAnalysis = new QTableWidget(scrollViewGraph);
        returnsAnalysis->setObjectName(QStringLiteral("returnsAnalysis"));

        verticalLayout->addWidget(returnsAnalysis);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_8 = new QLabel(scrollViewGraph);
        label_8->setObjectName(QStringLiteral("label_8"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_8);

        net_return_value_label = new QLabel(scrollViewGraph);
        net_return_value_label->setObjectName(QStringLiteral("net_return_value_label"));

        horizontalLayout->addWidget(net_return_value_label);

        horizontalLayout->setStretch(1, 20);

        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(scrollViewGraph);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        label_5 = new QLabel(scrollViewGraph);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        label = new QLabel(scrollViewGraph);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(scrollViewGraph);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label_4 = new QLabel(scrollViewGraph);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        label_3 = new QLabel(scrollViewGraph);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 2, 1);

        scrollArea->setWidget(scrollViewGraph);

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
        menuBar->setGeometry(QRect(0, 0, 750, 21));
        DisplayAnalysis->setMenuBar(menuBar);

        retranslateUi(DisplayAnalysis);

        QMetaObject::connectSlotsByName(DisplayAnalysis);
    } // setupUi

    void retranslateUi(QMainWindow *DisplayAnalysis)
    {
        DisplayAnalysis->setWindowTitle(QApplication::translate("DisplayAnalysis", "Display Analysis", 0));
        actionDsdsasdsd->setText(QApplication::translate("DisplayAnalysis", "dsdsasdsd", 0));
        label_8->setText(QApplication::translate("DisplayAnalysis", "Net Return:", 0));
        net_return_value_label->setText(QString());
        label_6->setText(QString());
        label_5->setText(QString());
        label->setText(QApplication::translate("DisplayAnalysis", "<span style=\"color:blue\">Blue - Buy</span>", 0));
        label_2->setText(QApplication::translate("DisplayAnalysis", "<html><head/><body><p><span style=\" color:#009940;\">Green - Sell</span></p></body></html>", 0));
        label_4->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DisplayAnalysis: public Ui_DisplayAnalysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYANALYSIS_H
