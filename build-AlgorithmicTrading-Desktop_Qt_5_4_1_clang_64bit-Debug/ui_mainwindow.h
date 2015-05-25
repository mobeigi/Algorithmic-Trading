/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *analysis_prep;
    QWidget *quantitative_tab;
    QVBoxLayout *verticalLayout_8;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *analysisInputCSVField;
    QPushButton *analysisInputCSVButton;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_11;
    QFrame *frame;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *analysisStrategyLabel;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *analysisBrowseStrategyField;
    QPushButton *analysisBrowseStrategyButton;
    QHBoxLayout *analysisThresholdFrame;
    QLabel *label_3;
    QDoubleSpinBox *analysisThreshold;
    QHBoxLayout *analysisReturnsFrame;
    QLabel *label_4;
    QDoubleSpinBox *analysisReturns;
    QFrame *analysisStrategyFrame;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *clearStrategyButton;
    QPushButton *addStrategyButton;
    QTableWidget *analysisStrategyList;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QDateEdit *analysisStartDate;
    QLabel *label_7;
    QDateEdit *analysisEndDate;
    QFrame *analysisDateButtonFrame;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *analysisClearDateButton;
    QPushButton *analysisAddDateButton;
    QTableWidget *analysisListDate;
    QPushButton *analysisExecuteButton;
    QWidget *run_tab;
    QVBoxLayout *verticalLayout_3;
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
    QGridLayout *_2;
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
    QWidget *analysis_tab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *strategyModuleLayout_2;
    QLabel *outputcsv_label;
    QLineEdit *output_csv_location;
    QPushButton *browse_outputcsv;
    QHBoxLayout *horizontalLayout;
    QLabel *output_csv_valid;
    QPushButton *loadorder_button;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *analysis_error_msg;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *selectall;
    QPushButton *deselectall;
    QPushButton *inverseSelection;
    QPushButton *showanalysis_button;
    QLabel *companylabel;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(520, 722);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(80);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(520, 700));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        analysis_prep = new QTabWidget(centralWidget);
        analysis_prep->setObjectName(QStringLiteral("analysis_prep"));
        quantitative_tab = new QWidget();
        quantitative_tab->setObjectName(QStringLiteral("quantitative_tab"));
        quantitative_tab->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_8 = new QVBoxLayout(quantitative_tab);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label = new QLabel(quantitative_tab);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_8->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        analysisInputCSVField = new QLineEdit(quantitative_tab);
        analysisInputCSVField->setObjectName(QStringLiteral("analysisInputCSVField"));

        horizontalLayout_4->addWidget(analysisInputCSVField);

        analysisInputCSVButton = new QPushButton(quantitative_tab);
        analysisInputCSVButton->setObjectName(QStringLiteral("analysisInputCSVButton"));

        horizontalLayout_4->addWidget(analysisInputCSVButton);


        verticalLayout_8->addLayout(horizontalLayout_4);

        frame_2 = new QFrame(quantitative_tab);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_2);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        frame = new QFrame(frame_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        analysisStrategyLabel = new QLabel(frame);
        analysisStrategyLabel->setObjectName(QStringLiteral("analysisStrategyLabel"));
        analysisStrategyLabel->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));

        horizontalLayout_8->addWidget(analysisStrategyLabel);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        analysisBrowseStrategyField = new QLineEdit(frame);
        analysisBrowseStrategyField->setObjectName(QStringLiteral("analysisBrowseStrategyField"));

        horizontalLayout_5->addWidget(analysisBrowseStrategyField);

        analysisBrowseStrategyButton = new QPushButton(frame);
        analysisBrowseStrategyButton->setObjectName(QStringLiteral("analysisBrowseStrategyButton"));

        horizontalLayout_5->addWidget(analysisBrowseStrategyButton);


        verticalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_9->addLayout(verticalLayout_6);

        analysisThresholdFrame = new QHBoxLayout();
        analysisThresholdFrame->setSpacing(6);
        analysisThresholdFrame->setObjectName(QStringLiteral("analysisThresholdFrame"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        analysisThresholdFrame->addWidget(label_3);

        analysisThreshold = new QDoubleSpinBox(frame);
        analysisThreshold->setObjectName(QStringLiteral("analysisThreshold"));
        analysisThreshold->setDecimals(7);

        analysisThresholdFrame->addWidget(analysisThreshold);


        verticalLayout_9->addLayout(analysisThresholdFrame);

        analysisReturnsFrame = new QHBoxLayout();
        analysisReturnsFrame->setSpacing(6);
        analysisReturnsFrame->setObjectName(QStringLiteral("analysisReturnsFrame"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        analysisReturnsFrame->addWidget(label_4);

        analysisReturns = new QDoubleSpinBox(frame);
        analysisReturns->setObjectName(QStringLiteral("analysisReturns"));
        analysisReturns->setDecimals(0);
        analysisReturns->setMaximum(100);

        analysisReturnsFrame->addWidget(analysisReturns);


        verticalLayout_9->addLayout(analysisReturnsFrame);

        analysisStrategyFrame = new QFrame(frame);
        analysisStrategyFrame->setObjectName(QStringLiteral("analysisStrategyFrame"));
        horizontalLayout_9 = new QHBoxLayout(analysisStrategyFrame);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        clearStrategyButton = new QPushButton(analysisStrategyFrame);
        clearStrategyButton->setObjectName(QStringLiteral("clearStrategyButton"));

        horizontalLayout_9->addWidget(clearStrategyButton);

        addStrategyButton = new QPushButton(analysisStrategyFrame);
        addStrategyButton->setObjectName(QStringLiteral("addStrategyButton"));

        horizontalLayout_9->addWidget(addStrategyButton);


        verticalLayout_9->addWidget(analysisStrategyFrame);

        analysisStrategyList = new QTableWidget(frame);
        if (analysisStrategyList->columnCount() < 4)
            analysisStrategyList->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        analysisStrategyList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        analysisStrategyList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        analysisStrategyList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        analysisStrategyList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        analysisStrategyList->setObjectName(QStringLiteral("analysisStrategyList"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(analysisStrategyList->sizePolicy().hasHeightForWidth());
        analysisStrategyList->setSizePolicy(sizePolicy2);
        analysisStrategyList->setMinimumSize(QSize(460, 107));

        verticalLayout_9->addWidget(analysisStrategyList);


        verticalLayout_11->addWidget(frame);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("qproperty-alignment: AlignCenter;"));

        horizontalLayout_11->addWidget(label_5);


        verticalLayout_10->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_12->addWidget(label_6);

        analysisStartDate = new QDateEdit(frame_2);
        analysisStartDate->setObjectName(QStringLiteral("analysisStartDate"));

        horizontalLayout_12->addWidget(analysisStartDate);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_12->addWidget(label_7);

        analysisEndDate = new QDateEdit(frame_2);
        analysisEndDate->setObjectName(QStringLiteral("analysisEndDate"));

        horizontalLayout_12->addWidget(analysisEndDate);


        verticalLayout_10->addLayout(horizontalLayout_12);


        verticalLayout_11->addLayout(verticalLayout_10);

        analysisDateButtonFrame = new QFrame(frame_2);
        analysisDateButtonFrame->setObjectName(QStringLiteral("analysisDateButtonFrame"));
        horizontalLayout_10 = new QHBoxLayout(analysisDateButtonFrame);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        analysisClearDateButton = new QPushButton(analysisDateButtonFrame);
        analysisClearDateButton->setObjectName(QStringLiteral("analysisClearDateButton"));

        horizontalLayout_10->addWidget(analysisClearDateButton);

        analysisAddDateButton = new QPushButton(analysisDateButtonFrame);
        analysisAddDateButton->setObjectName(QStringLiteral("analysisAddDateButton"));

        horizontalLayout_10->addWidget(analysisAddDateButton);


        verticalLayout_11->addWidget(analysisDateButtonFrame);

        analysisListDate = new QTableWidget(frame_2);
        if (analysisListDate->columnCount() < 2)
            analysisListDate->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        analysisListDate->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        analysisListDate->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        analysisListDate->setObjectName(QStringLiteral("analysisListDate"));
        analysisListDate->setStyleSheet(QStringLiteral(""));

        verticalLayout_11->addWidget(analysisListDate);


        verticalLayout_8->addWidget(frame_2);

        analysisExecuteButton = new QPushButton(quantitative_tab);
        analysisExecuteButton->setObjectName(QStringLiteral("analysisExecuteButton"));

        verticalLayout_8->addWidget(analysisExecuteButton);

        analysis_prep->addTab(quantitative_tab, QString());
        run_tab = new QWidget();
        run_tab->setObjectName(QStringLiteral("run_tab"));
        run_tab->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_3 = new QVBoxLayout(run_tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        programLayout = new QVBoxLayout();
        programLayout->setSpacing(6);
        programLayout->setObjectName(QStringLiteral("programLayout"));
        strategy_module_label = new QLabel(run_tab);
        strategy_module_label->setObjectName(QStringLiteral("strategy_module_label"));

        programLayout->addWidget(strategy_module_label);

        strategyModuleLayout = new QHBoxLayout();
        strategyModuleLayout->setSpacing(6);
        strategyModuleLayout->setObjectName(QStringLiteral("strategyModuleLayout"));
        strategy_module_location = new QLineEdit(run_tab);
        strategy_module_location->setObjectName(QStringLiteral("strategy_module_location"));

        strategyModuleLayout->addWidget(strategy_module_location);

        browseModule = new QPushButton(run_tab);
        browseModule->setObjectName(QStringLiteral("browseModule"));
        browseModule->setEnabled(true);

        strategyModuleLayout->addWidget(browseModule);


        programLayout->addLayout(strategyModuleLayout);

        input_csv_label = new QLabel(run_tab);
        input_csv_label->setObjectName(QStringLiteral("input_csv_label"));

        programLayout->addWidget(input_csv_label);

        inputCSVLayout = new QHBoxLayout();
        inputCSVLayout->setSpacing(6);
        inputCSVLayout->setObjectName(QStringLiteral("inputCSVLayout"));
        input_csv_location = new QLineEdit(run_tab);
        input_csv_location->setObjectName(QStringLiteral("input_csv_location"));

        inputCSVLayout->addWidget(input_csv_location);

        browseCSV = new QPushButton(run_tab);
        browseCSV->setObjectName(QStringLiteral("browseCSV"));

        inputCSVLayout->addWidget(browseCSV);


        programLayout->addLayout(inputCSVLayout);

        inputcsv_valid = new QLabel(run_tab);
        inputcsv_valid->setObjectName(QStringLiteral("inputcsv_valid"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        inputcsv_valid->setFont(font);
        inputcsv_valid->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        programLayout->addWidget(inputcsv_valid);

        parameters_label = new QLabel(run_tab);
        parameters_label->setObjectName(QStringLiteral("parameters_label"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        parameters_label->setFont(font1);

        programLayout->addWidget(parameters_label);

        _2 = new QGridLayout();
        _2->setSpacing(6);
        _2->setObjectName(QStringLiteral("_2"));
        _2->setContentsMargins(1, -1, -1, -1);
        threshold_label = new QLabel(run_tab);
        threshold_label->setObjectName(QStringLiteral("threshold_label"));

        _2->addWidget(threshold_label, 0, 1, 1, 1);

        threshold = new QDoubleSpinBox(run_tab);
        threshold->setObjectName(QStringLiteral("threshold"));
        threshold->setDecimals(4);
        threshold->setMaximum(1);
        threshold->setSingleStep(1);
        threshold->setValue(0.0001);

        _2->addWidget(threshold, 0, 2, 1, 1);


        programLayout->addLayout(_2);

        returnInCalculationLayout = new QHBoxLayout();
        returnInCalculationLayout->setSpacing(6);
        returnInCalculationLayout->setObjectName(QStringLiteral("returnInCalculationLayout"));
        returnsInCalculation_label = new QLabel(run_tab);
        returnsInCalculation_label->setObjectName(QStringLiteral("returnsInCalculation_label"));

        returnInCalculationLayout->addWidget(returnsInCalculation_label);

        returnsInCalculation = new QSpinBox(run_tab);
        returnsInCalculation->setObjectName(QStringLiteral("returnsInCalculation"));
        returnsInCalculation->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        returnsInCalculation->setMaximum(9999);
        returnsInCalculation->setValue(5);

        returnInCalculationLayout->addWidget(returnsInCalculation);


        programLayout->addLayout(returnInCalculationLayout);

        dateLayout = new QHBoxLayout();
        dateLayout->setSpacing(6);
        dateLayout->setObjectName(QStringLiteral("dateLayout"));
        start_date_label = new QLabel(run_tab);
        start_date_label->setObjectName(QStringLiteral("start_date_label"));

        dateLayout->addWidget(start_date_label);

        start_date = new QDateEdit(run_tab);
        start_date->setObjectName(QStringLiteral("start_date"));
        start_date->setCalendarPopup(true);

        dateLayout->addWidget(start_date);

        end_date_label = new QLabel(run_tab);
        end_date_label->setObjectName(QStringLiteral("end_date_label"));

        dateLayout->addWidget(end_date_label);

        end_date = new QDateEdit(run_tab);
        end_date->setObjectName(QStringLiteral("end_date"));
        end_date->setCalendarPopup(true);

        dateLayout->addWidget(end_date);


        programLayout->addLayout(dateLayout);

        date_valid = new QLabel(run_tab);
        date_valid->setObjectName(QStringLiteral("date_valid"));
        date_valid->setStyleSheet(QStringLiteral("color:red;"));

        programLayout->addWidget(date_valid);

        executeLayout = new QGridLayout();
        executeLayout->setSpacing(5);
        executeLayout->setObjectName(QStringLiteral("executeLayout"));
        execution_status = new QLabel(run_tab);
        execution_status->setObjectName(QStringLiteral("execution_status"));
        sizePolicy.setHeightForWidth(execution_status->sizePolicy().hasHeightForWidth());
        execution_status->setSizePolicy(sizePolicy);

        executeLayout->addWidget(execution_status, 0, 0, 1, 1, Qt::AlignLeft);

        execute_button = new QPushButton(run_tab);
        execute_button->setObjectName(QStringLiteral("execute_button"));

        executeLayout->addWidget(execute_button, 0, 1, 1, 1);


        programLayout->addLayout(executeLayout);


        verticalLayout_3->addLayout(programLayout);

        analysis_prep->addTab(run_tab, QString());
        analysis_tab = new QWidget();
        analysis_tab->setObjectName(QStringLiteral("analysis_tab"));
        verticalLayout = new QVBoxLayout(analysis_tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        strategyModuleLayout_2 = new QHBoxLayout();
        strategyModuleLayout_2->setSpacing(6);
        strategyModuleLayout_2->setObjectName(QStringLiteral("strategyModuleLayout_2"));
        outputcsv_label = new QLabel(analysis_tab);
        outputcsv_label->setObjectName(QStringLiteral("outputcsv_label"));

        strategyModuleLayout_2->addWidget(outputcsv_label);

        output_csv_location = new QLineEdit(analysis_tab);
        output_csv_location->setObjectName(QStringLiteral("output_csv_location"));

        strategyModuleLayout_2->addWidget(output_csv_location);

        browse_outputcsv = new QPushButton(analysis_tab);
        browse_outputcsv->setObjectName(QStringLiteral("browse_outputcsv"));
        browse_outputcsv->setEnabled(true);

        strategyModuleLayout_2->addWidget(browse_outputcsv);


        verticalLayout->addLayout(strategyModuleLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        output_csv_valid = new QLabel(analysis_tab);
        output_csv_valid->setObjectName(QStringLiteral("output_csv_valid"));
        output_csv_valid->setAutoFillBackground(false);
        output_csv_valid->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(output_csv_valid);


        verticalLayout->addLayout(horizontalLayout);

        loadorder_button = new QPushButton(analysis_tab);
        loadorder_button->setObjectName(QStringLiteral("loadorder_button"));

        verticalLayout->addWidget(loadorder_button);

        listWidget = new QListWidget(analysis_tab);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        analysis_error_msg = new QLabel(analysis_tab);
        analysis_error_msg->setObjectName(QStringLiteral("analysis_error_msg"));
        analysis_error_msg->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        horizontalLayout_3->addWidget(analysis_error_msg);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        selectall = new QPushButton(analysis_tab);
        selectall->setObjectName(QStringLiteral("selectall"));

        horizontalLayout_2->addWidget(selectall);

        deselectall = new QPushButton(analysis_tab);
        deselectall->setObjectName(QStringLiteral("deselectall"));

        horizontalLayout_2->addWidget(deselectall);

        inverseSelection = new QPushButton(analysis_tab);
        inverseSelection->setObjectName(QStringLiteral("inverseSelection"));

        horizontalLayout_2->addWidget(inverseSelection);


        verticalLayout->addLayout(horizontalLayout_2);

        showanalysis_button = new QPushButton(analysis_tab);
        showanalysis_button->setObjectName(QStringLiteral("showanalysis_button"));

        verticalLayout->addWidget(showanalysis_button);

        analysis_prep->addTab(analysis_tab, QString());

        verticalLayout_2->addWidget(analysis_prep);

        companylabel = new QLabel(centralWidget);
        companylabel->setObjectName(QStringLiteral("companylabel"));
        companylabel->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(companylabel);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        analysis_prep->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Trock Testing Platform", 0));
        label->setText(QApplication::translate("MainWindow", "Input CSV", 0));
        analysisInputCSVButton->setText(QApplication::translate("MainWindow", "Browse", 0));
        analysisStrategyLabel->setText(QApplication::translate("MainWindow", "Strategies", 0));
        analysisBrowseStrategyButton->setText(QApplication::translate("MainWindow", "Browse", 0));
        label_3->setText(QApplication::translate("MainWindow", "Threshold", 0));
        label_4->setText(QApplication::translate("MainWindow", "Returns In Calculation", 0));
        clearStrategyButton->setText(QApplication::translate("MainWindow", "Clear Strategies", 0));
        addStrategyButton->setText(QApplication::translate("MainWindow", "Add Strategy", 0));
        QTableWidgetItem *___qtablewidgetitem = analysisStrategyList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Strategy", 0));
        QTableWidgetItem *___qtablewidgetitem1 = analysisStrategyList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Threshold", 0));
        QTableWidgetItem *___qtablewidgetitem2 = analysisStrategyList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Returns in Calculation", 0));
        QTableWidgetItem *___qtablewidgetitem3 = analysisStrategyList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "CSV file", 0));
        label_5->setText(QApplication::translate("MainWindow", "Add New Date Range", 0));
        label_6->setText(QApplication::translate("MainWindow", "Start Date", 0));
        label_7->setText(QApplication::translate("MainWindow", "End Date", 0));
        analysisClearDateButton->setText(QApplication::translate("MainWindow", "Clear Date Ranges", 0));
        analysisAddDateButton->setText(QApplication::translate("MainWindow", "Add Date Range", 0));
        QTableWidgetItem *___qtablewidgetitem4 = analysisListDate->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Start Date", 0));
        QTableWidgetItem *___qtablewidgetitem5 = analysisListDate->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "End Date", 0));
        analysisExecuteButton->setText(QApplication::translate("MainWindow", "Execute", 0));
        analysis_prep->setTabText(analysis_prep->indexOf(quantitative_tab), QApplication::translate("MainWindow", "Quantitative Analysis", 0));
        strategy_module_label->setText(QApplication::translate("MainWindow", "Strategy Module", 0));
        browseModule->setText(QApplication::translate("MainWindow", "Browse", 0));
        input_csv_label->setText(QApplication::translate("MainWindow", "Input CSV", 0));
        browseCSV->setText(QApplication::translate("MainWindow", "Browse", 0));
        inputcsv_valid->setText(QString());
        parameters_label->setText(QApplication::translate("MainWindow", "Parameters", 0));
        threshold_label->setText(QApplication::translate("MainWindow", "Threshold", 0));
        returnsInCalculation_label->setText(QApplication::translate("MainWindow", "Returns in calculation", 0));
        start_date_label->setText(QApplication::translate("MainWindow", "Start Date", 0));
        start_date->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM/yyyy", 0));
        end_date_label->setText(QApplication::translate("MainWindow", "End Date", 0));
        end_date->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM/yyyy", 0));
        date_valid->setText(QString());
        execution_status->setText(QString());
        execute_button->setText(QApplication::translate("MainWindow", "Execute", 0));
        analysis_prep->setTabText(analysis_prep->indexOf(run_tab), QApplication::translate("MainWindow", "Run Strategy Module", 0));
        outputcsv_label->setText(QApplication::translate("MainWindow", "Output Order CSV File:", 0));
        browse_outputcsv->setText(QApplication::translate("MainWindow", "Browse", 0));
        output_csv_valid->setText(QString());
        loadorder_button->setText(QApplication::translate("MainWindow", "Load Order CSV File", 0));
        analysis_error_msg->setText(QString());
        selectall->setText(QApplication::translate("MainWindow", "Select All", 0));
        deselectall->setText(QApplication::translate("MainWindow", "Deselect All", 0));
        inverseSelection->setText(QApplication::translate("MainWindow", "Inverse Selection", 0));
        showanalysis_button->setText(QApplication::translate("MainWindow", "Display Analysis", 0));
        analysis_prep->setTabText(analysis_prep->indexOf(analysis_tab), QApplication::translate("MainWindow", "Analyse Order CSV File", 0));
        companylabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Trock Pty Ltd. Version (v1.30). Web: <a href=\"http://www.trock.net/\"><span style=\" text-decoration: underline; color:#0000ff;\">http://www.trock.net/</span></a></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
