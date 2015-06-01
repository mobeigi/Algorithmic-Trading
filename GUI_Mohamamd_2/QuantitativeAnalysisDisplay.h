#ifndef QUANTITATIVEANALYSISDISPLAY_H
#define QUANTITATIVEANALYSISDISPLAY_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
//#include <Alignment>

#include <vector>

#include "ParamSet.h"
#include "CamelPushButton.h"
#include "DisplayAnalysis.h"

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
    void clickedSlot()
    {
        std::AnalysisData *data = static_cast<std::AnalysisData *>(((CamelPushButton*)sender())->hump);
        if (data != nullptr) {
            DisplayAnalysis *disp = new DisplayAnalysis();
            disp->show();
            disp->displayAnalysis(data);
        }
    };

private:
    Ui::QuantitativeAnalysisDisplay *ui;

    bool setAnalysisCalled;

    void drawTitle(QGridLayout *layout, std::string text, int row, int col, int width, int height);
    void drawQuantValue(QGridLayout *layout, std::Para para, int row, int col, int width, int height, bool showRaw);

    //displayOption = -1 normal, 0 = returns, 1 = granularity, 2 = volatility
    std::vector<std::ParamSet> analysisData;
    std::vector<std::string> strategies;
    int currentDisplayOption;
    void buildAnalysis(std::vector<std::ParamSet> analysisData, std::vector<std::string> strategies, int displayOption);

};

#endif // QUANTITATIVEANALYSISDISPLAY_H
