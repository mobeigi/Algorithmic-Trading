#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>         //for processing directories

#ifdef _WIN32 //windows 32 and 64bit
#include <Windows.h>
#endif

#include <string>
#include <iostream>
#include <fstream>      //for creating a params file
#include <vector>       //for params error checking

//For checking params
#define INPUTCSV_EQ_OUTPUTCSV 1
#define ENDDATE_BEFORE_STARTDATE 2

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
    void on_browseModule_clicked();
    void on_browseCSV_clicked();
    int on_execute_button_clicked();
    vector<int> check_params(void);

private:
    Ui::MainWindow *ui;
    string construct_date_string(int day, int month, int year);
};

#endif // MAINWINDOW_H
