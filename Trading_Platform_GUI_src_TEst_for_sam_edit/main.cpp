#include "mainwindow.h"
#include "ParamSet.h"
#include "QuantitativeAnalysisDisplay.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    vector<ParamSet> pset = ParamSet::generateTestAnalysis();
    //Para p_r1 = pset[0].getQuantifiedParameter(paraReturns, 1);

    QuantitativeAnalysisDisplay *qad = new QuantitativeAnalysisDisplay();
    qad->show();

    qad->buildAnalysis(pset);




    return a.exec();
}
