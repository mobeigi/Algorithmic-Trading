#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "GlobalIncludes.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QDir>         //for processing directories

#ifdef _WIN32 //windows 32 and 64bit
#include <Windows.h>
#endif

#include "AnalysisDisplays.h"
#include "ParamAnalysisHelper.h"
#include "QuantitativeAnalysisDisplay.h"

#include <tuple>
#include <string>
#include <iostream>
#include <fstream>      //for creating a params file
#include <vector>       //for params error checking

//For checking params
#define OK 0                        //ok status
#define INPUTCSV_EQ_OUTPUTCSV 1
#define ENDDATE_BEFORE_STARTDATE 2
#define NO_INPUTCSV_SELECTED 3
#define NO_OUTPUTCSV_SELECTED 4

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    //for analysing a module
    void on_browseModule_clicked();
    void on_browseCSV_clicked();
    int on_execute_button_clicked();
    vector<int> check_params(void);

    //for analysing an output csv
    void on_browse_outputcsv_clicked();
    int loadordercsvfile();
    int on_showanalysis_button_clicked();

    int on_selectall_clicked();
    int on_deselectall_clicked();
    int on_inverseSelection_clicked();

    int check_outputcsv(void);

    //quantative analysis
    //returns param set and list of strategies (name, threshold, returns)
    tuple<vector<ParamSet>, vector<tuple<string, string, string>>> doExecuteAnalysis(bool formatForCSV);
    void on_analysisInputCSVButton_clicked();
    void on_analysisBrowseStrategyButton_clicked();
    void on_clearStrategyButton_clicked();
    void on_analysisClearDateButton_clicked();
    void on_addStrategyButton_clicked();
    void on_analysisAddDateButton_clicked();
    void on_analysisExecuteButton_clicked();
    void on_saveCSVExecuteButton_clicked();


private:
    Ui::MainWindow *ui;
    AnalysisDisplays *ad = nullptr;
    string construct_date_string(int day, int month, int year);
    QString getRandomString() const;
    QString getYear(QString yr);
};

#endif // MAINWINDOW_H
