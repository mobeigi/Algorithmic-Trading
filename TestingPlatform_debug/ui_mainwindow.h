/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *analysis_prep;
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *programLayout;
    QLabel *strategy_module_label;
    QHBoxLayout *strategyModuleLayout;
    QLineEdit *strategy_module_location;
    QPushButton *browseModule;
    QLabel *input_csv_label;
    QHBoxLayout *inputCSVLayout;
    QLineEdit *input_csv_location;
    QPushButton *browseCSV;
    QLabel *inputcsv_valid;
    QLabel *parameters_label;
    QGridLayout *tresholdLayout;
    QLabel *threshold_label;
    QDoubleSpinBox *threshold;
    QHBoxLayout *returnInCalculationLayout;
    QLabel *returnsInCalculation_label;
    QSpinBox *returnsInCalculation;
    QHBoxLayout *dateLayout;
    QLabel *start_date_label;
    QDateEdit *start_date;
    QLabel *end_date_label;
    QDateEdit *end_date;
    QLabel *date_valid;
    QGridLayout *executeLayout;
    QLabel *execution_status;
    QPushButton *execute_button;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QHBoxLayout *strategyModuleLayout_2;
    QLabel *outputcsv_label;
    QLineEdit *output_csv_location;
    QPushButton *browse_outputcsv;
    QPushButton *analyse_button;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *output_csv_valid;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(506, 495);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(80);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        analysis_prep = new QTabWidget(centralWidget);
        analysis_prep->setObjectName(QStringLiteral("analysis_prep"));
        analysis_prep->setGeometry(QRect(30, 20, 451, 441));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 431, 401));
        programLayout = new QVBoxLayout(verticalLayoutWidget);
        programLayout->setSpacing(6);
        programLayout->setContentsMargins(11, 11, 11, 11);
        programLayout->setObjectName(QStringLiteral("programLayout"));
        programLayout->setContentsMargins(0, 0, 0, 0);
        strategy_module_label = new QLabel(verticalLayoutWidget);
        strategy_module_label->setObjectName(QStringLiteral("strategy_module_label"));

        programLayout->addWidget(strategy_module_label);

        strategyModuleLayout = new QHBoxLayout();
        strategyModuleLayout->setSpacing(6);
        strategyModuleLayout->setObjectName(QStringLiteral("strategyModuleLayout"));
        strategy_module_location = new QLineEdit(verticalLayoutWidget);
        strategy_module_location->setObjectName(QStringLiteral("strategy_module_location"));

        strategyModuleLayout->addWidget(strategy_module_location);

        browseModule = new QPushButton(verticalLayoutWidget);
        browseModule->setObjectName(QStringLiteral("browseModule"));
        browseModule->setEnabled(true);

        strategyModuleLayout->addWidget(browseModule);


        programLayout->addLayout(strategyModuleLayout);

        input_csv_label = new QLabel(verticalLayoutWidget);
        input_csv_label->setObjectName(QStringLiteral("input_csv_label"));

        programLayout->addWidget(input_csv_label);

        inputCSVLayout = new QHBoxLayout();
        inputCSVLayout->setSpacing(6);
        inputCSVLayout->setObjectName(QStringLiteral("inputCSVLayout"));
        input_csv_location = new QLineEdit(verticalLayoutWidget);
        input_csv_location->setObjectName(QStringLiteral("input_csv_location"));

        inputCSVLayout->addWidget(input_csv_location);

        browseCSV = new QPushButton(verticalLayoutWidget);
        browseCSV->setObjectName(QStringLiteral("browseCSV"));

        inputCSVLayout->addWidget(browseCSV);


        programLayout->addLayout(inputCSVLayout);

        inputcsv_valid = new QLabel(verticalLayoutWidget);
        inputcsv_valid->setObjectName(QStringLiteral("inputcsv_valid"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        inputcsv_valid->setFont(font);

        programLayout->addWidget(inputcsv_valid);

        parameters_label = new QLabel(verticalLayoutWidget);
        parameters_label->setObjectName(QStringLiteral("parameters_label"));
        parameters_label->setFont(font);

        programLayout->addWidget(parameters_label);

        tresholdLayout = new QGridLayout();
        tresholdLayout->setSpacing(6);
        tresholdLayout->setObjectName(QStringLiteral("tresholdLayout"));
        tresholdLayout->setContentsMargins(1, -1, -1, -1);
        threshold_label = new QLabel(verticalLayoutWidget);
        threshold_label->setObjectName(QStringLiteral("threshold_label"));

        tresholdLayout->addWidget(threshold_label, 0, 1, 1, 1);

        threshold = new QDoubleSpinBox(verticalLayoutWidget);
        threshold->setObjectName(QStringLiteral("threshold"));
        threshold->setDecimals(4);

        tresholdLayout->addWidget(threshold, 0, 2, 1, 1);


        programLayout->addLayout(tresholdLayout);

        returnInCalculationLayout = new QHBoxLayout();
        returnInCalculationLayout->setSpacing(6);
        returnInCalculationLayout->setObjectName(QStringLiteral("returnInCalculationLayout"));
        returnsInCalculation_label = new QLabel(verticalLayoutWidget);
        returnsInCalculation_label->setObjectName(QStringLiteral("returnsInCalculation_label"));

        returnInCalculationLayout->addWidget(returnsInCalculation_label);

        returnsInCalculation = new QSpinBox(verticalLayoutWidget);
        returnsInCalculation->setObjectName(QStringLiteral("returnsInCalculation"));

        returnInCalculationLayout->addWidget(returnsInCalculation);


        programLayout->addLayout(returnInCalculationLayout);

        dateLayout = new QHBoxLayout();
        dateLayout->setSpacing(6);
        dateLayout->setObjectName(QStringLiteral("dateLayout"));
        start_date_label = new QLabel(verticalLayoutWidget);
        start_date_label->setObjectName(QStringLiteral("start_date_label"));

        dateLayout->addWidget(start_date_label);

        start_date = new QDateEdit(verticalLayoutWidget);
        start_date->setObjectName(QStringLiteral("start_date"));

        dateLayout->addWidget(start_date);

        end_date_label = new QLabel(verticalLayoutWidget);
        end_date_label->setObjectName(QStringLiteral("end_date_label"));

        dateLayout->addWidget(end_date_label);

        end_date = new QDateEdit(verticalLayoutWidget);
        end_date->setObjectName(QStringLiteral("end_date"));

        dateLayout->addWidget(end_date);


        programLayout->addLayout(dateLayout);

        date_valid = new QLabel(verticalLayoutWidget);
        date_valid->setObjectName(QStringLiteral("date_valid"));
        date_valid->setStyleSheet(QStringLiteral("color:red;"));

        programLayout->addWidget(date_valid);

        executeLayout = new QGridLayout();
        executeLayout->setSpacing(5);
        executeLayout->setObjectName(QStringLiteral("executeLayout"));
        execution_status = new QLabel(verticalLayoutWidget);
        execution_status->setObjectName(QStringLiteral("execution_status"));
        sizePolicy.setHeightForWidth(execution_status->sizePolicy().hasHeightForWidth());
        execution_status->setSizePolicy(sizePolicy);

        executeLayout->addWidget(execution_status, 0, 0, 1, 1, Qt::AlignLeft);

        execute_button = new QPushButton(verticalLayoutWidget);
        execute_button->setObjectName(QStringLiteral("execute_button"));

        executeLayout->addWidget(execute_button, 0, 1, 1, 1, Qt::AlignRight);


        programLayout->addLayout(executeLayout);

        analysis_prep->addTab(widget, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 429, 45));
        strategyModuleLayout_2 = new QHBoxLayout(layoutWidget);
        strategyModuleLayout_2->setSpacing(6);
        strategyModuleLayout_2->setContentsMargins(11, 11, 11, 11);
        strategyModuleLayout_2->setObjectName(QStringLiteral("strategyModuleLayout_2"));
        strategyModuleLayout_2->setContentsMargins(0, 0, 0, 0);
        outputcsv_label = new QLabel(layoutWidget);
        outputcsv_label->setObjectName(QStringLiteral("outputcsv_label"));

        strategyModuleLayout_2->addWidget(outputcsv_label);

        output_csv_location = new QLineEdit(layoutWidget);
        output_csv_location->setObjectName(QStringLiteral("output_csv_location"));

        strategyModuleLayout_2->addWidget(output_csv_location);

        browse_outputcsv = new QPushButton(layoutWidget);
        browse_outputcsv->setObjectName(QStringLiteral("browse_outputcsv"));
        browse_outputcsv->setEnabled(true);

        strategyModuleLayout_2->addWidget(browse_outputcsv);

        analyse_button = new QPushButton(tab_2);
        analyse_button->setObjectName(QStringLiteral("analyse_button"));
        analyse_button->setGeometry(QRect(360, 370, 75, 23));
        horizontalLayoutWidget = new QWidget(tab_2);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 60, 431, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        output_csv_valid = new QLabel(horizontalLayoutWidget);
        output_csv_valid->setObjectName(QStringLiteral("output_csv_valid"));
        output_csv_valid->setAutoFillBackground(false);
        output_csv_valid->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(output_csv_valid);

        analysis_prep->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        analysis_prep->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        strategy_module_label->setText(QApplication::translate("MainWindow", "Strategy Module", 0));
        browseModule->setText(QApplication::translate("MainWindow", "Browse", 0));
        input_csv_label->setText(QApplication::translate("MainWindow", "Input CSV", 0));
        browseCSV->setText(QApplication::translate("MainWindow", "Browse", 0));
        inputcsv_valid->setText(QString());
        parameters_label->setText(QApplication::translate("MainWindow", "Parameters", 0));
        threshold_label->setText(QApplication::translate("MainWindow", "Threshold", 0));
        returnsInCalculation_label->setText(QApplication::translate("MainWindow", "Returns in calculation", 0));
        start_date_label->setText(QApplication::translate("MainWindow", "Start Date", 0));
        end_date_label->setText(QApplication::translate("MainWindow", "End Date", 0));
        date_valid->setText(QString());
        execution_status->setText(QString());
        execute_button->setText(QApplication::translate("MainWindow", "Execute", 0));
        analysis_prep->setTabText(analysis_prep->indexOf(widget), QApplication::translate("MainWindow", "Choose a Module", 0));
        outputcsv_label->setText(QApplication::translate("MainWindow", "Output CSV File", 0));
        browse_outputcsv->setText(QApplication::translate("MainWindow", "Browse", 0));
        analyse_button->setText(QApplication::translate("MainWindow", "Analyse", 0));
        output_csv_valid->setText(QString());
        analysis_prep->setTabText(analysis_prep->indexOf(tab_2), QApplication::translate("MainWindow", "Choose an output csv", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
