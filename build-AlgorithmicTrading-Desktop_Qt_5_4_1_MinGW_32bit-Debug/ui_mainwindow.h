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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *inpu_csv_label;
    QLineEdit *strategy_module_location;
    QLineEdit *input_csv_location;
    QLabel *strategy_module_label;
    QPushButton *browseCSV;
    QPushButton *browseModule;
    QPushButton *execute_button;
    QGroupBox *groupBox;
    QDateEdit *start_date;
    QLabel *threshold_label;
    QLabel *returnsInCalculation_label;
    QSpinBox *returnsInCalculation;
    QDoubleSpinBox *threshold;
    QLabel *start_date_label;
    QLabel *end_date_label;
    QDateEdit *end_date;
    QLabel *execution_status;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(472, 394);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inpu_csv_label = new QLabel(centralWidget);
        inpu_csv_label->setObjectName(QStringLiteral("inpu_csv_label"));
        inpu_csv_label->setGeometry(QRect(50, 80, 131, 31));
        strategy_module_location = new QLineEdit(centralWidget);
        strategy_module_location->setObjectName(QStringLiteral("strategy_module_location"));
        strategy_module_location->setGeometry(QRect(50, 50, 251, 20));
        input_csv_location = new QLineEdit(centralWidget);
        input_csv_location->setObjectName(QStringLiteral("input_csv_location"));
        input_csv_location->setGeometry(QRect(50, 110, 251, 20));
        strategy_module_label = new QLabel(centralWidget);
        strategy_module_label->setObjectName(QStringLiteral("strategy_module_label"));
        strategy_module_label->setGeometry(QRect(50, 20, 131, 31));
        browseCSV = new QPushButton(centralWidget);
        browseCSV->setObjectName(QStringLiteral("browseCSV"));
        browseCSV->setGeometry(QRect(310, 110, 75, 23));
        browseModule = new QPushButton(centralWidget);
        browseModule->setObjectName(QStringLiteral("browseModule"));
        browseModule->setGeometry(QRect(310, 50, 75, 23));
        execute_button = new QPushButton(centralWidget);
        execute_button->setObjectName(QStringLiteral("execute_button"));
        execute_button->setGeometry(QRect(360, 330, 91, 31));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 150, 331, 161));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        groupBox->setFont(font);
        start_date = new QDateEdit(groupBox);
        start_date->setObjectName(QStringLiteral("start_date"));
        start_date->setGeometry(QRect(40, 110, 81, 22));
        threshold_label = new QLabel(groupBox);
        threshold_label->setObjectName(QStringLiteral("threshold_label"));
        threshold_label->setGeometry(QRect(40, 30, 51, 16));
        returnsInCalculation_label = new QLabel(groupBox);
        returnsInCalculation_label->setObjectName(QStringLiteral("returnsInCalculation_label"));
        returnsInCalculation_label->setGeometry(QRect(40, 60, 111, 16));
        returnsInCalculation = new QSpinBox(groupBox);
        returnsInCalculation->setObjectName(QStringLiteral("returnsInCalculation"));
        returnsInCalculation->setGeometry(QRect(230, 60, 61, 22));
        threshold = new QDoubleSpinBox(groupBox);
        threshold->setObjectName(QStringLiteral("threshold"));
        threshold->setGeometry(QRect(230, 30, 62, 22));
        threshold->setDecimals(4);
        start_date_label = new QLabel(groupBox);
        start_date_label->setObjectName(QStringLiteral("start_date_label"));
        start_date_label->setGeometry(QRect(40, 90, 71, 16));
        end_date_label = new QLabel(groupBox);
        end_date_label->setObjectName(QStringLiteral("end_date_label"));
        end_date_label->setGeometry(QRect(160, 90, 71, 16));
        end_date = new QDateEdit(groupBox);
        end_date->setObjectName(QStringLiteral("end_date"));
        end_date->setGeometry(QRect(160, 110, 81, 22));
        execution_status = new QLabel(centralWidget);
        execution_status->setObjectName(QStringLiteral("execution_status"));
        execution_status->setGeometry(QRect(60, 330, 171, 16));
        MainWindow->setCentralWidget(centralWidget);
        groupBox->raise();
        inpu_csv_label->raise();
        strategy_module_location->raise();
        input_csv_location->raise();
        strategy_module_label->raise();
        browseCSV->raise();
        browseModule->raise();
        execute_button->raise();
        execution_status->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        inpu_csv_label->setText(QApplication::translate("MainWindow", "Input CSV", 0));
        strategy_module_label->setText(QApplication::translate("MainWindow", "Strategy Module", 0));
        browseCSV->setText(QApplication::translate("MainWindow", "Browse", 0));
        browseModule->setText(QApplication::translate("MainWindow", "Browse", 0));
        execute_button->setText(QApplication::translate("MainWindow", "Execute", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Parameters", 0));
        threshold_label->setText(QApplication::translate("MainWindow", "Threshold", 0));
        returnsInCalculation_label->setText(QApplication::translate("MainWindow", "Returns in calculation", 0));
        start_date_label->setText(QApplication::translate("MainWindow", "Start Date", 0));
        end_date_label->setText(QApplication::translate("MainWindow", "End Date", 0));
        execution_status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
