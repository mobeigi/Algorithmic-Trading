#ifndef QUANTITATIVEANALYSISDISPLAY_H
#define QUANTITATIVEANALYSISDISPLAY_H

#include <QWidget>

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

    void buildAnalysis(std::vector<std::ParamSet> analysisData);

private:
    Ui::QuantitativeAnalysisDisplay *ui;
};

#endif // QUANTITATIVEANALYSISDISPLAY_H
