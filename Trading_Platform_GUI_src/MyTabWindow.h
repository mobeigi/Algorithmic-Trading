//myTabWidget.h File

#ifndef MYTABWIDGET_H
#define MYTABWIDGET_H
 
#include <QTabWidget> 
#include <QMessageBox>
#include <QString>
#include "ParseCSVData.h"
#include "DisplayAnalysis.h"
#include <set>

class MyTabWidget: public QTabWidget
{
  Q_OBJECT
  public:    
    MyTabWidget(QWidget* parent, std::ParseCSVData *pCSVdata)
	{
      this->setParent(parent);
      this->pCSVdata = pCSVdata;
      connect(this , SIGNAL(currentChanged(int)),this,SLOT(currentChangedSlot(int)));
	};

    void addEqType(std::string &eqType) { eqTypeVec.push_back(eqType); }

	~ MyTabWidget(){};	

  private:
    std::ParseCSVData *pCSVdata;
    std::vector<std::string> eqTypeVec;
    std::set<int> isCached;

  public slots:
	//Slot that is called when Tab selection changes
	void currentChangedSlot(int index)
    {
        //If the tab has not already been loaded then load it
        if (isCached.find(index) == isCached.end()) {
            DisplayAnalysis *dw = qobject_cast<DisplayAnalysis *>(this->widget(index));
            dw->displayAnalysis(this->pCSVdata->getDataForEquityType(this->eqTypeVec[index]));
            isCached.insert(index);
        }
	};
  
};
#endif
