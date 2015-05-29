#include "QuantitativeAnalysisDisplay.h"
#include "ui_QuantitativeAnalysisDisplay.h"

//#include <iostream>

QuantitativeAnalysisDisplay::QuantitativeAnalysisDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuantitativeAnalysisDisplay)
{
    ui->setupUi(this);

    setAnalysisCalled = false;

    connect(ui->comboBox,SIGNAL(currentIndexChanged(const int)),
            this,SLOT(handleSelectionChanged(const int)));
}

#define __WID 80.0
#define __HEI 50.0
#define __WID_TITLES_EQUITY 3
#define __WID_TITLES_STRATS 4

void QuantitativeAnalysisDisplay::drawTitle(QGridLayout *layout, std::string text, int row, int col, int width, int height) {
    QLabel *l = new QLabel();
    l->setText(QString::fromStdString(text));
    l->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    l->setStyleSheet("QLabel { background-color : white; color : black; }");
    l->setFixedSize(__WID * width, __HEI * height);
    layout->addWidget(l, row, col, height, width);
}

#define RND_CCMP(i) (((int)(i))>255)?255:((((int)(i))<COL_LOW)?COL_LOW:((int)(i)))
#define DIFF_COL 155.0
#define COL_LOW 100.0

void QuantitativeAnalysisDisplay::drawQuantValue(QGridLayout *layout, std::Para para, int row, int col, int width, int height) {
    QLabel *l = new QLabel();
    if (para.valid) {
        l->setText(QString::fromStdString(std::Helper::formatDoubleSmall(para.qnt) +
                                      " \n(" + std::Helper::formatDoubleSmall(para.raw) + ")"));
        l->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        int red = 255;
        int green = 255;
        if (para.qnt < 0) {
            green = RND_CCMP(255 - (int)((-para.qnt)*DIFF_COL));
        } else {
            red = RND_CCMP(255 - (int)((para.qnt)*DIFF_COL));
        }


        l->setStyleSheet(QString::fromStdString("QLabel { background-color : rgba(" + std::to_string(red) + ", "
                         + std::to_string(green) + ", 100, 255); color : black; }"));
    } else {
        l->setText(QString::fromStdString(""));
        l->setStyleSheet("QLabel { background-color : grey; color : black; }");
    }
    l->setFixedSize(__WID * width, __HEI * height);
    layout->addWidget(l, row, col, height, width);
}
//void handleSelectionChanged(int index)
/*{
    QMessageBox* msg = new QMessageBox();
    msg->setWindowTitle("Hello !");
    msg->setText("Selected Index is :"+QString::number(index));
    msg->show();
};*/


QuantitativeAnalysisDisplay::~QuantitativeAnalysisDisplay()
{
    delete ui;
    for (std::ParamSet pSet : analysisData) pSet.releaseAllAnalysisData();
}


void QuantitativeAnalysisDisplay::setAnalysis(std::vector<std::ParamSet> analysisData, std::vector<std::string> strategies) {
    if (setAnalysisCalled) {
        ERR_FATAL("QuantitativeAnalysisDisplay: setAnalysis called more then once!");
    }
    setAnalysisCalled = true;
    this->analysisData = analysisData;
    this->strategies = strategies;
    this->currentDisplayOption = -1;
    this->buildAnalysis(this->analysisData, this->strategies, 0);
    this->buildAnalysis(this->analysisData, this->strategies, -1);
    //this->buildAnalysis(this->analysisData, this->strategies, 0);
}

void QuantitativeAnalysisDisplay::buildAnalysis(std::vector<std::ParamSet> analysisData, std::vector<std::string> strategies, int displayOption) {
    //accesses the param for the first row, the second column (strategy), and the return param (out of the three types)
    //analysisData[0].getQuantifiedParameter(std::paraReturns, 1);

    //int extraGap = 1;

    while (ui->gridLayout->count() > 0) {
        ui->gridLayout->takeAt(0)->widget()->deleteLater();
    }

    int strategyIndex = -1;
    for (std::string strategy : strategies) {
        strategyIndex++;
        this->drawTitle(ui->gridLayout, strategy, 0, __WID_TITLES_EQUITY + strategyIndex*__WID_TITLES_STRATS, __WID_TITLES_STRATS, 1);

        if (displayOption == -1) {
            this->drawTitle(ui->gridLayout, "Returns", 1, __WID_TITLES_EQUITY +
                        strategyIndex*__WID_TITLES_STRATS + 0, 1, 1);
            this->drawTitle(ui->gridLayout, "Granality", 1, __WID_TITLES_EQUITY +
                        strategyIndex*__WID_TITLES_STRATS + 1, 1, 1);
            this->drawTitle(ui->gridLayout, "Volatility", 1, __WID_TITLES_EQUITY +
                        strategyIndex*__WID_TITLES_STRATS + 2, 1, 1);
        } else if (displayOption == 0) {
            this->drawTitle(ui->gridLayout, "Returns", 1, __WID_TITLES_EQUITY +
                        strategyIndex*__WID_TITLES_STRATS, 3, 1);
        } else if (displayOption == 1) {
            this->drawTitle(ui->gridLayout, "Granality", 1, __WID_TITLES_EQUITY +
                        strategyIndex*__WID_TITLES_STRATS, 3, 1);
        } else if (displayOption == 2) {
            this->drawTitle(ui->gridLayout, "Volatility", 1, __WID_TITLES_EQUITY +
                        strategyIndex*__WID_TITLES_STRATS, 3, 1);
        } else if (displayOption == 3) {
            this->drawTitle(ui->gridLayout, "RGV Sum", 1, __WID_TITLES_EQUITY +
                        strategyIndex*__WID_TITLES_STRATS, 3, 1);
        }

    }

    int startY = 2;

    int rowIndex = -1;
    for (std::ParamSet paramSet : analysisData) {
        rowIndex++;
        this->drawTitle(ui->gridLayout, paramSet.getEquityType() +
                        " \n(" + paramSet.getStartDate() + " to "
                        + paramSet.getEndDate() + ")", startY + rowIndex,
                        0, __WID_TITLES_EQUITY, 1);

        for (int i = 0; i < paramSet.getNumberOfStrategies(); ++i) {
            std::Para r = paramSet.getQuantifiedParameter(std::paraReturns, i);
            std::Para g = paramSet.getQuantifiedParameter(std::paraGranality, i);
            std::Para v = paramSet.getQuantifiedParameter(std::paraVolatility, i);

            if (displayOption == -1) {
                this->drawQuantValue(ui->gridLayout, r, rowIndex + startY,
                                     __WID_TITLES_EQUITY + i*__WID_TITLES_STRATS + 0, 1, 1);
                this->drawQuantValue(ui->gridLayout, g, rowIndex + startY,
                                     __WID_TITLES_EQUITY + i*__WID_TITLES_STRATS + 1, 1, 1);
                this->drawQuantValue(ui->gridLayout, v, rowIndex + startY,
                                     __WID_TITLES_EQUITY + i*__WID_TITLES_STRATS + 2, 1, 1);
            } else if (displayOption == 0) {
                this->drawQuantValue(ui->gridLayout, r, rowIndex + startY,
                                     __WID_TITLES_EQUITY + i*__WID_TITLES_STRATS + 0, 3, 1);
            } else if (displayOption == 1) {
                this->drawQuantValue(ui->gridLayout, g, rowIndex + startY,
                                     __WID_TITLES_EQUITY + i*__WID_TITLES_STRATS + 0, 3, 1);
            } else if (displayOption == 2) {
                this->drawQuantValue(ui->gridLayout, v, rowIndex + startY,
                                     __WID_TITLES_EQUITY + i*__WID_TITLES_STRATS + 0, 3, 1);
            } else if (displayOption == 3) {
                this->drawQuantValue(ui->gridLayout, v + g + r, rowIndex + startY,
                                     __WID_TITLES_EQUITY + i*__WID_TITLES_STRATS + 0, 3, 1);
            }

            //add button of elaboration and analysis, using the CamelPushButton :)
            CamelPushButton *button = new CamelPushButton();
            button->setText("Elab.");
            button->hump = paramSet.getAnalysisDataForStrat(i);
            QObject::connect(button, SIGNAL(clicked()),this, SLOT(clickedSlot()));
            ui->gridLayout->addWidget(button, rowIndex + startY, __WID_TITLES_EQUITY + i*__WID_TITLES_STRATS + 3, 1, 1);
        }

        //paramSet.getEquityType()
    }

    /*int strategyIndex = -1;
    for (std::string strategy : strategies) {
        strategyIndex++;
        this->drawTitle(ui->gridLayout, strategy, 0, __WID_TITLES_EQUITY + strategyIndex*__WID_TITLES_STRATS, __WID_TITLES_STRATS, 1);

        this->drawTitle(ui->gridLayout, "Returns", 1, __WID_TITLES_EQUITY +
                        strategyIndex*__WID_TITLES_STRATS + 0, 1, 1);
        this->drawTitle(ui->gridLayout, "Granality", 1, __WID_TITLES_EQUITY +
                        strategyIndex*__WID_TITLES_STRATS + 1, 1, 1);
        this->drawTitle(ui->gridLayout, "Volatility", 1, __WID_TITLES_EQUITY +
                        strategyIndex*__WID_TITLES_STRATS + 2, 1, 1);

    }

    int startY = 2;

    int rowIndex = -1;
    for (std::ParamSet paramSet : analysisData) {
        rowIndex++;
        this->drawTitle(ui->gridLayout, paramSet.getEquityType() +
                        " \n(" + paramSet.getStartDate() + " to "
                        + paramSet.getEndDate() + ")", startY + rowIndex,
                        0, __WID_TITLES_EQUITY, 1);

        for (int i = 0; i < paramSet.getNumberOfStrategies(); ++i) {
            std::Para r = paramSet.getQuantifiedParameter(std::paraReturns, i);
            std::Para g = paramSet.getQuantifiedParameter(std::paraGranality, i);
            std::Para v = paramSet.getQuantifiedParameter(std::paraVolatility, i);

            this->drawQuantValue(ui->gridLayout, r, rowIndex + startY,
                                 __WID_TITLES_EQUITY + i*__WID_TITLES_STRATS + 0, 1, 1);
            this->drawQuantValue(ui->gridLayout, g, rowIndex + startY,
                                 __WID_TITLES_EQUITY + i*__WID_TITLES_STRATS + 1, 1, 1);
            this->drawQuantValue(ui->gridLayout, v, rowIndex + startY,
                                 __WID_TITLES_EQUITY + i*__WID_TITLES_STRATS + 2, 1, 1);
        }

        //paramSet.getEquityType()
    }*/


    /*QLabel *l = new QLabel();
    l->setText("Test");
    l->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    l->setStyleSheet("QLabel { background-color : #FF5555; color : black; }");
    l->setFixedSize(100, 40);
    ui->gridLayout->addWidget(l, 1, 1, 1, 1);

    l = new QLabel();
    l->setText("Text");
    l->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    l->setStyleSheet("QLabel { background-color : #FF5555; color : black; }");
    l->setFixedSize(100, 40);
    ui->gridLayout->addWidget(l, 0, 0, 1, 2);*/

}


