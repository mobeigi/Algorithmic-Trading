#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir> //for processing directories

#ifdef _WIN32 //windows 32 and 64bit
#include <Windows.h>
#endif

#include <string>
#include <iostream>
#include <fstream>  //for creating a params file

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

private:
    Ui::MainWindow *ui;
    //string ExePath();

};

#endif // MAINWINDOW_H
