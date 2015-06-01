/********************************************************************************
** Form generated from reading UI file 'QuantitativeAnalysisDisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUANTITATIVEANALYSISDISPLAY_H
#define UI_QUANTITATIVEANALYSISDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuantitativeAnalysisDisplay
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *QuantitativeAnalysisDisplay)
    {
        if (QuantitativeAnalysisDisplay->objectName().isEmpty())
            QuantitativeAnalysisDisplay->setObjectName(QStringLiteral("QuantitativeAnalysisDisplay"));
        QuantitativeAnalysisDisplay->resize(640, 640);
        gridLayout_2 = new QGridLayout(QuantitativeAnalysisDisplay);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea = new QScrollArea(QuantitativeAnalysisDisplay);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 614, 542));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout->addLayout(gridLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(QuantitativeAnalysisDisplay);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 60));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 151, 31));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(130, 10, 174, 26));

        horizontalLayout->addWidget(widget);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(QuantitativeAnalysisDisplay);

        QMetaObject::connectSlotsByName(QuantitativeAnalysisDisplay);
    } // setupUi

    void retranslateUi(QWidget *QuantitativeAnalysisDisplay)
    {
        QuantitativeAnalysisDisplay->setWindowTitle(QApplication::translate("QuantitativeAnalysisDisplay", "Quantitative Analysis", 0));
        label->setText(QApplication::translate("QuantitativeAnalysisDisplay", "Display Options:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("QuantitativeAnalysisDisplay", "Display All", 0)
         << QApplication::translate("QuantitativeAnalysisDisplay", "Returns", 0)
         << QApplication::translate("QuantitativeAnalysisDisplay", "Granality", 0)
         << QApplication::translate("QuantitativeAnalysisDisplay", "Volatility", 0)
         << QApplication::translate("QuantitativeAnalysisDisplay", "Display Sum", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class QuantitativeAnalysisDisplay: public Ui_QuantitativeAnalysisDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUANTITATIVEANALYSISDISPLAY_H
