#include "mainwindow.h"
#include "QuantitativeAnalysisDisplay.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QuantitativeAnalysisDisplay *qad = new QuantitativeAnalysisDisplay();
    qad->show();

    return a.exec();
}
