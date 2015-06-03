/********************************************************************************
** Form generated from reading UI file 'DisplayAnalysis.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYANALYSIS_H
#define UI_DISPLAYANALYSIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayAnalysis
{
public:
    QVBoxLayout *verticalLayout_2;
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

    void setupUi(QWidget *DisplayAnalysis)
    {
        if (DisplayAnalysis->objectName().isEmpty())
            DisplayAnalysis->setObjectName(QStringLiteral("DisplayAnalysis"));
        DisplayAnalysis->resize(750, 652);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DisplayAnalysis->sizePolicy().hasHeightForWidth());
        DisplayAnalysis->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(DisplayAnalysis);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea = new QScrollArea(DisplayAnalysis);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollViewGraph = new QWidget();
        scrollViewGraph->setObjectName(QStringLiteral("scrollViewGraph"));
        scrollViewGraph->setGeometry(QRect(0, 0, 726, 628));
        gridLayout_2 = new QGridLayout(scrollViewGraph);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsGraphDisplay = new QGraphicsView(scrollViewGraph);
        graphicsGraphDisplay->setObjectName(QStringLiteral("graphicsGraphDisplay"));

        verticalLayout->addWidget(graphicsGraphDisplay);

        returnsAnalysis = new QTableWidget(scrollViewGraph);
        returnsAnalysis->setObjectName(QStringLiteral("returnsAnalysis"));
        returnsAnalysis->setSortingEnabled(true);

        verticalLayout->addWidget(returnsAnalysis);

        horizontalLayout = new QHBoxLayout();
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

        verticalLayout_2->addWidget(scrollArea);


        retranslateUi(DisplayAnalysis);

        QMetaObject::connectSlotsByName(DisplayAnalysis);
    } // setupUi

    void retranslateUi(QWidget *DisplayAnalysis)
    {
        DisplayAnalysis->setWindowTitle(QApplication::translate("DisplayAnalysis", "Form", 0));
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
