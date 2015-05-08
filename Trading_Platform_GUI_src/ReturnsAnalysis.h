#ifndef RETURNSANALYSIS_H
#define RETURNSANALYSIS_H

#include <QMainWindow>
#include "AnalysisDisplays.h"
#include "AnalysisData.h"

//For reading in the csv file
#include <fstream>
#include <sstream>
#include <string>

#define PRICE 2
#define DATE 1
#define BUY_SELL_SIGNAL 5

using namespace std;

namespace Ui {
class ReturnsAnalysis;
}

class ReturnsAnalysis : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReturnsAnalysis(QWidget *parent = 0);
    ~ReturnsAnalysis();

private slots:
    void on_readFile_clicked(void); //read in a particular csv file
    void returnsAnalysis(std::AnalysisData *data);

private:
    Ui::ReturnsAnalysis *ui;
};

#endif // RETURNSANALYSIS_H
