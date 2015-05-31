#include "SummaryForm.h"
#include "ui_summaryform.h"
#include "MyTableWidgetItem.h"

SummaryForm::SummaryForm(QWidget *parent) :
    QWidget(parent), ui(new Ui::SummaryForm)
{
    this->ui->setupUi(this);
}

void SummaryForm::setTotalNetReturns(ParseCSVData * pCSVdata, vector<string> eqTypes) {
    double runningNetValue = 0;
    double runningNetPerc = 0;

    double mostProfitableReturns = 0;
    double leastProfitableReturns = 0;
    double mostProfitableReturnsPerc = -1000000;
    double leastProfitableReturnsPerc = 1000000;
    string mostProfitableCompany;
    string leastProfitableCompany;

    //Loop through provided list of companies
    for (auto eqType = eqTypes.begin(); eqType != eqTypes.end(); ++eqType) {
        AnalysisData *ad = pCSVdata->getDataForEquityType(*eqType);

        //maintain queues of trades, one for buy and one for sell
        // int is for maintaining which one came first
        vector<tuple<TradeData, int>> buy_trades;
        vector<tuple<TradeData, int>> sell_trades;

        //maintain total return percentage
        double net_return_value = 0;
        double net_return_perc = 0;

        //read the trade orders line by line
        for (int i = 0; i < ad->tradeDataAvailable(); i++) {

            //load the vectors as appropriate
            if (ad->getData(i).tradeSignal == BUY) {
                buy_trades.push_back(tuple<TradeData,int>(ad->getData(i),i));
            } else {
                sell_trades.push_back(tuple<TradeData,int>(ad->getData(i),i));
            }

            //Determine whether there is a buy-sell / sell-buy pair
            if (buy_trades.size() > 0 && sell_trades.size() > 0) {
                tuple<TradeData,int> buy_trade = buy_trades.front();
                tuple<TradeData,int> sell_trade = sell_trades.front();

                //Calculate and construct return value string
                double return_value =(get<0>(sell_trade).price - get<0>(buy_trade).price);


                //Calculate and construct return percentage string
                double return_perc = (get<0>(sell_trade).price - get<0>(buy_trade).price) * 100 / get<0>(buy_trade).price;

                //update total return value and percentage
                net_return_value += return_value;
                net_return_perc += return_perc;

                //Remove the first trades from both queues
                buy_trades.erase(buy_trades.begin(),buy_trades.begin()+1);
                sell_trades.erase(sell_trades.begin(),sell_trades.begin()+1);
            }
        }

        //Update running net returns
        runningNetValue += net_return_value;
        runningNetPerc += net_return_perc;

        //Check profitibility
        if (net_return_perc > mostProfitableReturnsPerc) {
            mostProfitableReturns = net_return_value;
            mostProfitableReturnsPerc = net_return_perc;
            mostProfitableCompany = *eqType;
        }

        if (net_return_perc < leastProfitableReturnsPerc) {
            leastProfitableReturns = net_return_value;
            leastProfitableReturnsPerc = net_return_perc;
            leastProfitableCompany = *eqType;
        }

        //Add Returns for this company to table

        //increase table rows by 1
        int currRows = ui->summary_returnsTable->rowCount();
        ui->summary_returnsTable->setRowCount(currRows + 1);


        QTableWidgetItem* col0 = new QTableWidgetItem(QString::fromStdString(*eqType), QTableWidgetItem::Type);
        col0->setFlags(col0->flags() ^ Qt::ItemIsEditable);
        col0->setTextAlignment(Qt::AlignHCenter);
        ui->summary_returnsTable->setItem(currRows, 0, col0);

        //Use custom int type for this column
        MyTableWidgetItem* col1 = new MyTableWidgetItem(QString::number(net_return_perc));
        col1->setFlags(col1->flags() ^ Qt::ItemIsEditable);
        col1->setTextAlignment(Qt::AlignHCenter);
        ui->summary_returnsTable->setItem(currRows, 1, col1);
    }

    //Display cummalative net returns
    QString net_return_perc_str;

    if (runningNetPerc < 0) {
        ui->summary_totalnetreturns->setStyleSheet("color:red;font: 14pt \"Verdana\";");
    } else {
        ui->summary_totalnetreturns->setStyleSheet("color:green;font: 14pt \"Verdana\";");
    }

    net_return_perc_str.append(QString::number(runningNetPerc));
    net_return_perc_str.append("%");
    ui->summary_totalnetreturns->setText(net_return_perc_str);

    //Display most/least profitable companies

    //Most profitable
    QString mp_net_return_perc_str;

    if (mostProfitableReturnsPerc < 0) {
        ui->summary_mostprofitableequity->setStyleSheet("color:red;font: 14pt \"MS Shell Dlg 2\";");
    } else {
        ui->summary_mostprofitableequity->setStyleSheet("color:green;font: 14pt \"MS Shell Dlg 2\";");
    }

    mp_net_return_perc_str.append(mostProfitableCompany.c_str());
    mp_net_return_perc_str.append(" (" + QString::number(mostProfitableReturnsPerc) + "%)");
    ui->summary_mostprofitableequity->setText(mp_net_return_perc_str);

    //Least Profitable
    QString lp_net_return_perc_str;

    if (leastProfitableReturnsPerc < 0) {
        ui->summary_leastprofitableequity->setStyleSheet("color:red;font: 14pt \"MS Shell Dlg 2\";");
    } else {
        ui->summary_leastprofitableequity->setStyleSheet("color:green;font: 14pt \"MS Shell Dlg 2\";");
    }

    lp_net_return_perc_str.append(leastProfitableCompany.c_str());
    lp_net_return_perc_str.append(" (" + QString::number(leastProfitableReturnsPerc) + "%)");
    ui->summary_leastprofitableequity->setText(lp_net_return_perc_str);
}
