#ifndef DISPLAYANALYSIS_H
#define DISPLAYANALYSIS_H

#include "GlobalIncludes.h"

#include "AnalysisData.h"

#include <cmath>

#include <QMainWindow>

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScrollBar>

using namespace std;

namespace Ui {
class DisplayAnalysis;
}

class DisplayAnalysis : public QMainWindow
{
    Q_OBJECT

public:
    explicit DisplayAnalysis(QWidget *parent = 0);
    ~DisplayAnalysis();

    void setDisplayId(long displayId);
    void displayAnalysis(std::AnalysisData *data);

    void displayGraphAnalysis(std::AnalysisData *data);
    void displayReturnsAnalysis(std::AnalysisData *data);

    virtual void closeEvent(QCloseEvent *event);

private:
    Ui::DisplayAnalysis *ui;
    QGraphicsScene *scene;
    long displayId;
};

#endif // DISPLAYANALYSIS_H
