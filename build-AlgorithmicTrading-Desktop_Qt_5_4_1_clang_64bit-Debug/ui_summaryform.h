/********************************************************************************
** Form generated from reading UI file 'summaryform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMMARYFORM_H
#define UI_SUMMARYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SummaryForm
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLabel *summary_totalnetreturns;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *summary_mostprofitableequity;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *summary_leastprofitableequity;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *summary_returnsTable;

    void setupUi(QWidget *SummaryForm)
    {
        if (SummaryForm->objectName().isEmpty())
            SummaryForm->setObjectName(QStringLiteral("SummaryForm"));
        SummaryForm->resize(750, 652);
        verticalLayout = new QVBoxLayout(SummaryForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(SummaryForm);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("font: 14pt \"Verdana\";"));

        horizontalLayout_3->addWidget(label_6);

        summary_totalnetreturns = new QLabel(SummaryForm);
        summary_totalnetreturns->setObjectName(QStringLiteral("summary_totalnetreturns"));
        summary_totalnetreturns->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";color:red;"));

        horizontalLayout_3->addWidget(summary_totalnetreturns);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(SummaryForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("font: 14pt \"Verdana\";"));

        horizontalLayout_2->addWidget(label_3);

        summary_mostprofitableequity = new QLabel(SummaryForm);
        summary_mostprofitableequity->setObjectName(QStringLiteral("summary_mostprofitableequity"));
        summary_mostprofitableequity->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(summary_mostprofitableequity);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(SummaryForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("font: 14pt \"Verdana\";"));

        horizontalLayout->addWidget(label_2);

        summary_leastprofitableequity = new QLabel(SummaryForm);
        summary_leastprofitableequity->setObjectName(QStringLiteral("summary_leastprofitableequity"));
        summary_leastprofitableequity->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(summary_leastprofitableequity);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        summary_returnsTable = new QTableWidget(SummaryForm);
        if (summary_returnsTable->columnCount() < 2)
            summary_returnsTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        summary_returnsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        summary_returnsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        summary_returnsTable->setObjectName(QStringLiteral("summary_returnsTable"));
        summary_returnsTable->setSortingEnabled(true);
        summary_returnsTable->horizontalHeader()->setCascadingSectionResizes(true);
        summary_returnsTable->horizontalHeader()->setDefaultSectionSize(330);
        summary_returnsTable->verticalHeader()->setDefaultSectionSize(30);
        summary_returnsTable->verticalHeader()->setMinimumSectionSize(30);

        verticalLayout_3->addWidget(summary_returnsTable);


        verticalLayout->addLayout(verticalLayout_3);


        retranslateUi(SummaryForm);

        QMetaObject::connectSlotsByName(SummaryForm);
    } // setupUi

    void retranslateUi(QWidget *SummaryForm)
    {
        SummaryForm->setWindowTitle(QApplication::translate("SummaryForm", "Form", 0));
        label_6->setText(QApplication::translate("SummaryForm", "Total Net Returns:", 0));
        summary_totalnetreturns->setText(QString());
        label_3->setText(QApplication::translate("SummaryForm", "Most Profitable Equity:", 0));
        summary_mostprofitableequity->setText(QString());
        label_2->setText(QApplication::translate("SummaryForm", "Least Profitable Equity:", 0));
        summary_leastprofitableequity->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = summary_returnsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SummaryForm", "Equity", 0));
        QTableWidgetItem *___qtablewidgetitem1 = summary_returnsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SummaryForm", "Net Returns (%)", 0));
    } // retranslateUi

};

namespace Ui {
    class SummaryForm: public Ui_SummaryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMMARYFORM_H
