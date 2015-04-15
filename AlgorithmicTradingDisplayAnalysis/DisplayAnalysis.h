#ifndef DISPLAYANALYSIS_H
#define DISPLAYANALYSIS_H

#include "AnalysisData.h"

#include <QMainWindow>

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>


namespace Ui {
class DisplayAnalysis;
}

class DisplayAnalysis : public QMainWindow
{
    Q_OBJECT

public:
    explicit DisplayAnalysis(QWidget *parent = 0);
    ~DisplayAnalysis();

    void displayAnalysis(std::AnalysisData *data);

private:
    Ui::DisplayAnalysis *ui;
};

#endif // DISPLAYANALYSIS_H
