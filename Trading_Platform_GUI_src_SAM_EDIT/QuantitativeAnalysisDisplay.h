#ifndef QUANTITATIVEANALYSISDISPLAY_H
#define QUANTITATIVEANALYSISDISPLAY_H

#include <QWidget>

namespace Ui {
class QuantitativeAnalysisDisplay;
}

class QuantitativeAnalysisDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit QuantitativeAnalysisDisplay(QWidget *parent = 0);
    ~QuantitativeAnalysisDisplay();

private:
    Ui::QuantitativeAnalysisDisplay *ui;
};

#endif // QUANTITATIVEANALYSISDISPLAY_H
