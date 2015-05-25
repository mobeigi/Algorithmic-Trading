#include "QuantitativeAnalysisDisplay.h"
#include "ui_QuantitativeAnalysisDisplay.h"

QuantitativeAnalysisDisplay::QuantitativeAnalysisDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuantitativeAnalysisDisplay)
{
    ui->setupUi(this);
}

void QuantitativeAnalysisDisplay::buildAnalysis(std::vector<std::ParamSet> analysisData) {
    //accesses the param for the first row, the second column (strategy), and the return param (out of the three types)
    analysisData[0].getQuantifiedParameter(std::paraReturns, 1);
}

QuantitativeAnalysisDisplay::~QuantitativeAnalysisDisplay()
{
    delete ui;
}
