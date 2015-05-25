#include "QuantitativeAnalysisDisplay.h"
#include "ui_QuantitativeAnalysisDisplay.h"

QuantitativeAnalysisDisplay::QuantitativeAnalysisDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuantitativeAnalysisDisplay)
{
    ui->setupUi(this);
}

QuantitativeAnalysisDisplay::~QuantitativeAnalysisDisplay()
{
    delete ui;
}
