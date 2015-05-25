#ifndef QUANTITATIVEANALYSISDISPLAY_H
#define QUANTITATIVEANALYSISDISPLAY_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
//#include <Alignment>

#include <vector>

#include "ParamSet.h"

namespace Ui {
class QuantitativeAnalysisDisplay;
}

class QuantitativeAnalysisDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit QuantitativeAnalysisDisplay(QWidget *parent = 0);
    ~QuantitativeAnalysisDisplay();

    void setAnalysis(std::vector<std::ParamSet> analysisData, std::vector<std::string> strategies);

public slots:
    void handleSelectionChanged(int index)
    {
        this->buildAnalysis(this->analysisData, this->strategies, index - 1);
    };

private:
    Ui::QuantitativeAnalysisDisplay *ui;

    void drawTitle(QGridLayout *layout, std::string text, int row, int col, int width, int height);
    void drawQuantValue(QGridLayout *layout, std::Para para, int row, int col, int width, int height);

    //displayOption = -1 normal, 0 = returns, 1 = granality, 2 = volatility
    std::vector<std::ParamSet> analysisData;
    std::vector<std::string> strategies;
    int currentDisplayOption;
    void buildAnalysis(std::vector<std::ParamSet> analysisData, std::vector<std::string> strategies, int displayOption);

};

#endif // QUANTITATIVEANALYSISDISPLAY_H
