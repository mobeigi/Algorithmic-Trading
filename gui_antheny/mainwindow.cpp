#include "mainwindow.h"
#include "ui_mainwindow.h"

#define ANALYSIS_TAB 2

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->analysisStrategyList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->analysisListDate->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;



    if (ad != nullptr) delete ad;
}

void MainWindow::on_browseModule_clicked()
{
    ui->strategy_module_location->setText(QFileDialog::getOpenFileName());
    ui->strategy_module_location->displayText();
}

void MainWindow::on_browseCSV_clicked()
{
    ui->input_csv_location->setText(QFileDialog::getOpenFileName(this, tr("Input CSV File"),"/path/to/file/",tr("CSV Files (*.csv)")));
    ui->input_csv_location->displayText();
}

int MainWindow::on_execute_button_clicked()
{
    //Retrieve string of current directory
    string curr_path = QDir::currentPath().toStdString();

    // Ensure params are valid
    vector<int> invalidities = check_params();
    size_t invalidities_size = invalidities.size();
    if (invalidities_size != 0) {
        //There are errors - return the appropriate messages corresponding to each message
        for (size_t i = 0; i < invalidities_size; i++) {
            if (invalidities[i] == INPUTCSV_EQ_OUTPUTCSV) {
                ui->inputcsv_valid->setText("Please select a different CSV file.");
            } else if (invalidities[i] == ENDDATE_BEFORE_STARTDATE) {
                ui->date_valid->setText("End date has to be after start date.");
            } else if (invalidities[i] == NO_INPUTCSV_SELECTED) {
                ui->inputcsv_valid->setText("Please select an input CSV file.");
            }
        }
        return 0; //early exit
    }

    //Remove any error messages that may have occurred beforehand
    ui->inputcsv_valid->setText("");
    ui->date_valid->setText("");

    //Construct the date strings
    string start_date_str = construct_date_string(ui->start_date->date().day(),ui->start_date->date().month(),ui->start_date->date().year());
    string end_date_str = construct_date_string(ui->end_date->date().day(),ui->end_date->date().month(),ui->end_date->date().year());

    //delete old orders file if it exists
    QFile::remove(QString::fromStdString(curr_path + "/orders.csv"));
   // remove((const char *)(curr_path + "/orders.csv"));

    //Generate the params file from fields
    //NOTE: Output csv is the same directory as this executable path

    ofstream outputFile;
    outputFile.open ("params.param");
    outputFile << (":input_csvFile:" + ui->input_csv_location->text().toStdString() + "\\\n");
    outputFile << (":output_csvFile:"+ curr_path +"/orders.csv\\\n");
    outputFile << (":output_logFile:"+curr_path+"/AlgorithmicTrading.log\\\n");
    outputFile << (":returnsInCalculation:" + to_string(ui->returnsInCalculation->value()) + "\\\n");
    outputFile << (":threshold:" + to_string(ui->threshold->value()) + "\\\n");
    outputFile << (":startDate:" + start_date_str + "\\\n");
    outputFile << (":endDate:" + end_date_str + "\\\n");
    outputFile.close();

    ofstream outputFile2;
    outputFile2.open ("params2.param");
    outputFile2 << ("N,TH,DateRange\n");
    outputFile2 << (to_string(ui->returnsInCalculation->value()) + ","
                    + to_string(ui->threshold->value()) + ","
                    + to_string(ui->start_date->date().year())
                    + "-" + to_string(ui->end_date->date().year()) + "\n");
    outputFile2.close();

    //Run the program by feeding param file
    //Construct location of params file
    string params_location = curr_path + "/params.param";

    string csv_input_location = ui->input_csv_location->text().toStdString();
    string params2_location = curr_path + "/params2.param";

    //Construct the command string
    string command_str = ui->strategy_module_location->text().toStdString(); //program location
    command_str.append(" ");
    command_str.append(csv_input_location); //csv location (the wolf of seng support)
    command_str.append(" ");
    command_str.append(params2_location); //params2 file location (the wolf of seng support)
    command_str.append(" ");
    command_str.append(params_location); //params file location

    system(command_str.c_str()); //windows way of executing file
    ui->execution_status->setText("Execution Complete");

    ui->output_csv_location->setText( (curr_path + "/orders.csv").c_str());
    on_loadorder_button_clicked();  //populate analysis tab with checklist
    ui->analysis_prep->setCurrentIndex(ANALYSIS_TAB); //change tab to analysis tab

    return EXIT_SUCCESS;
}
//---------------------- Analyse CSV File -----------------------------------------------------
void MainWindow::on_browse_outputcsv_clicked() {
    ui->output_csv_location->setText(QFileDialog::getOpenFileName(this, tr("Output CSV File"),"/path/to/file/",tr("CSV Files (*.csv)")));
    ui->output_csv_location->displayText();
}

int MainWindow::on_loadorder_button_clicked() {
    //Clear analyse error text
    ui->analysis_error_msg->setText("");

    //Clear old AD info if it exists
    if (ad) {
        ad->getListItems().clear();
        ui->listWidget->clear();
    }

    // Check validity of output_csv
    int output_csv_validity = check_outputcsv();
    if (output_csv_validity != OK) {
        //Print the appropriate error message
        switch (output_csv_validity) {
            case NO_OUTPUTCSV_SELECTED: ui->output_csv_valid->setText("Please select an output file."); break;
        }

        return 0; //early exit
    }

    //Remove any error messages that exist before
    ui->output_csv_valid->setText("");

    //Analyse output file
    if (ad != nullptr) {
        delete ad;
    }
    ad = new AnalysisDisplays();
    ad->showCheckList(ui->output_csv_location->text().toStdString(), ui->listWidget, this);

    //Check for invalid file
    if (ad && ad->getListItems().size() == 0) {
        ui->output_csv_valid->setText("No valid equity trades were found in the provided CSV file.");
        return 0;
    }

    return EXIT_SUCCESS;
}

int MainWindow::on_showanalysis_button_clicked() {
    //Clear analyse error text
    ui->analysis_error_msg->setText("");

    //Ensure the analysis display has been created
    if (!ad) {
        ui->analysis_error_msg->setText("Please load some CSV order data first.");
        return 1;
    }

    //Check that we have at least 1 item
    if (ad->getListItems().size() < 1) {
        ui->analysis_error_msg->setText("There was no Equity types in the provided CSV file");
        return 1;
    }

    //Now ensure we have at least 1 selected item
    int count = 0;

    for (QListWidgetItem *item : ad->getListItems()) {
        if (item->checkState()) {
            ++count; //Increment counter
            break;
        }
    }

    if (count == 0) {
        ui->analysis_error_msg->setText("You must select at least 1 Equity type to analyse.");
    } else {
        //Show analysis data
        ad->showAnalysisDisplays(this);
    }

    return EXIT_SUCCESS;
}

int MainWindow::on_selectall_clicked() {
    if (ad) {
        for (QListWidgetItem *item : ad->getListItems()) {
            item->setCheckState(Qt::Checked);
        }
    }

    return EXIT_SUCCESS;
}

int MainWindow::on_deselectall_clicked() {
    if (ad) {
        for (QListWidgetItem *item : ad->getListItems()) {
            item->setCheckState(Qt::Unchecked);
        }
    }

    return EXIT_SUCCESS;
}

int MainWindow::on_inverseSelection_clicked() {
    if (ad) {
        for (QListWidgetItem *item : ad->getListItems()) {
            if (item->checkState())
                item->setCheckState(Qt::Unchecked);
            else
                item->setCheckState(Qt::Checked);
        }
    }

    return EXIT_SUCCESS;
}

// ------------------ Quantative Analysis -----------------------


void MainWindow::on_analysisInputCSVButton_clicked(){
    ui->analysisInputCSVField->setText(QFileDialog::getOpenFileName());
    ui->analysisInputCSVField->displayText();
}

void MainWindow::on_analysisBrowseStrategyButton_clicked(){
    ui->analysisBrowseStrategyField->setText(QFileDialog::getOpenFileName());
    ui->analysisBrowseStrategyField->displayText();
}

void MainWindow::on_clearStrategyButton_clicked(){
        ui->analysisStrategyList->clearContents();
        ui->analysisStrategyList->setRowCount(0);
}

void MainWindow::on_analysisClearDateButton_clicked(){
        ui->analysisListDate->clearContents();
        ui->analysisListDate->setRowCount(0);
}

void MainWindow::on_addStrategyButton_clicked(){

    int currRows = ui->analysisStrategyList->rowCount();
    ui->analysisStrategyList->setRowCount(currRows + 1);

    QString analysisStrategy = ui->analysisBrowseStrategyField->text();
    QString analysisThreshold = QString::number(ui->analysisThreshold->value()) ;
    QString analysisReturns = QString::number(ui->analysisReturns->value());
    QString inputCSV = ui->analysisInputCSVField->text();

    QTableWidgetItem *analysisStrategyItem = new QTableWidgetItem(analysisStrategy, QTableWidgetItem::Type);
    QTableWidgetItem *analysisThresholdItem = new QTableWidgetItem(analysisThreshold, QTableWidgetItem::Type);
    QTableWidgetItem *analysisReturnsItem = new QTableWidgetItem(analysisReturns, QTableWidgetItem::Type);
    QTableWidgetItem *inputCSVItem = new QTableWidgetItem(inputCSV, QTableWidgetItem::Type);

    ui->analysisStrategyList->setItem(currRows,0,analysisStrategyItem);
    ui->analysisStrategyList->setItem(currRows,1,analysisThresholdItem);
    ui->analysisStrategyList->setItem(currRows,2,analysisReturnsItem);
    ui->analysisStrategyList->setItem(currRows,3,inputCSVItem);
}

void MainWindow::on_analysisAddDateButton_clicked(){
    int currRows = ui->analysisListDate->rowCount();
    ui->analysisListDate->setRowCount(currRows + 1);

    string startDate = construct_date_string(ui->analysisStartDate->date().day(),ui->analysisStartDate->date().month(),ui->analysisStartDate->date().year());
    string endDate = construct_date_string(ui->analysisEndDate->date().day(),ui->analysisEndDate->date().month(),ui->analysisEndDate->date().year());

    QTableWidgetItem *startDateItem = new QTableWidgetItem(QString::fromStdString(startDate), QTableWidgetItem::Type);
    QTableWidgetItem *endDateItem = new QTableWidgetItem(QString::fromStdString(endDate), QTableWidgetItem::Type);

    ui->analysisListDate->setItem(currRows,0,startDateItem);
    ui->analysisListDate->setItem(currRows,1,endDateItem);
}

void MainWindow::on_analysisExecuteButton_clicked(){
    //QString s = getRandomString();
    //cout << s.toStdString() << endl;
    string curr_path = QDir::currentPath().toStdString();
    QVector<QString> outputList;

    int analysisListRows = ui->analysisStrategyList->rowCount();
    int dateListRows = ui->analysisListDate->rowCount();

    int analysisCounter;
    for (analysisCounter=0;analysisCounter<analysisListRows;analysisCounter++) {
        QString analysisStrategy = ui->analysisStrategyList->item(analysisCounter,0)->text();
        QString analysisThreshold = ui->analysisStrategyList->item(analysisCounter,1)->text();
        QString analysisReturns = ui->analysisStrategyList->item(analysisCounter,2)->text();
        QString inputCSV = ui->analysisStrategyList->item(analysisCounter,3)->text();

        int dateCount;
        for(dateCount=0;dateCount<dateListRows;dateCount++){
            QString startDate = ui->analysisListDate->item(dateCount,0)->text();
            QString endDate = ui->analysisListDate->item(dateCount,1)->text();

            if (analysisStrategy.contains(QRegularExpression("wolf"))){

                ofstream outputFile2;
                outputFile2.open ("params.param");
                outputFile2 << ("N,TH,DateRange\n");
                outputFile2 << (analysisReturns.toStdString() + ","
                                + analysisThreshold.toStdString() + ","
                                + startDate.toStdString()
                                + "-" + endDate.toStdString() + "\n");
                outputFile2.close();

                //construct the command string
                string params_location = curr_path + "/params.param"; //location of the params file
                string command_str = analysisStrategy.toStdString(); //program location
                command_str.append(" ");
                command_str.append(inputCSV); //csv location (the wolf of seng support)
                command_str.append(" ");
                command_str.append(params2_location); //params2 file location (the wolf of seng support)

                //execute the file
                system(command_str.c_str());
                cout << "execution complete wolf" << endl;

                QString s = getRandomString();
                QString currOrdersCSV = QDir::currentPath() + "/orders.csv";
                QString newOrdersCSV = QDir::currentPath() + "/" + s + ".csv";
                QFile::rename(currOrdersCSV,newOrdersCSV);
                outputList.append(newOrdersCSV);

            }

        }
    }
}

// -------------------------  HELPER FUNCTIONS ------------------------ //
vector<int> MainWindow::check_params(void) {
    vector<int> invalidities;
    //Get path of current directory
    string curr_path = QDir::currentPath().toStdString();

    //Get path of specified input csv file
    string input_csv_path = ui->input_csv_location->text().toStdString();

    //Check that input csv file is provided
    if (input_csv_path.compare("") == 0) {
        invalidities.push_back(NO_INPUTCSV_SELECTED);
    }
    //Check that input csv file is NOT the output csv
    string output_csv_path = curr_path + "/output.csv";
    if (input_csv_path.compare(output_csv_path) == 0) {
        //Strings are equal"InputCSV   " << inputCSV << "\nanalysis  " << analysisStrategy
        invalidities.push_back(INPUTCSV_EQ_OUTPUTCSV);
    }

    //Check that end date is after start date
    QDate start_date = ui->start_date->date();
    QDate end_date = ui->end_date->date();
    if (end_date < start_date) {
        //End date is before start date
        invalidities.push_back(ENDDATE_BEFORE_STARTDATE);
    }

    return invalidities;
}

string MainWindow::construct_date_string(int day, int month, int year) {
    string date_str;

    //construct the day
    if (day < 10) {
        date_str.append("0" + to_string(day));
    } else {
        date_str.append(to_string(day));
    }
    date_str.append("-");

    //construct the month
    switch (month) {
        case 1: date_str.append("JAN"); break;
        case 2: date_str.append("FEB"); break;
        case 3: date_str.append("MAR"); break;
        case 4: date_str.append("APR"); break;
        case 5: date_str.append("MAY"); break;
        case 6: date_str.append("JUN"); break;
        case 7: date_str.append("JUL"); break;
        case 8: date_str.append("AUG"); break;
        case 9: date_str.append("SEP"); break;
        case 10: date_str.append("OCT"); break;
        case 11: date_str.append("NOV"); break;
        case 12: date_str.append("DEC"); break;
    }
    date_str.append("-");

    //construct the year
    date_str.append(to_string(year));

    return date_str;
}

int MainWindow::check_outputcsv(void) {
    if (ui->output_csv_location->text().compare("") == 0) {
        return NO_OUTPUTCSV_SELECTED;
    }
    return OK;
}

QString MainWindow::getRandomString() const
{
   const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
   const int randomStringLength = 7; // assuming you want random strings of 12 characters

   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = qrand() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}
