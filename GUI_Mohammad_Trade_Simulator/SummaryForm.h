#ifndef SUMMARYFORM_H
#define SUMMARYFORM_H

#include "GlobalIncludes.h"

#include "ParseCSVData.h"
#include "AnalysisData.h"

#include <QWidget>

using namespace std; //for vectors

namespace Ui {
class SummaryForm;
}

class SummaryForm : public QWidget
{
    Q_OBJECT

public:
    explicit SummaryForm(QWidget *parent = 0);
    void setTotalNetReturns(ParseCSVData * pCSVdata, vector<string> eqTypes);

private:
    Ui::SummaryForm *ui;
};

#endif // SUMMARYFORM_H
