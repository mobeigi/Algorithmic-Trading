#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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

    AnalysisDisplays::instance()->analyzeCSVOutput(curr_path +"/orders.csv", this);

    return EXIT_SUCCESS;
}

void MainWindow::on_browse_outputcsv_clicked() {
    ui->output_csv_location->setText(QFileDialog::getOpenFileName(this, tr("Output CSV File"),"/path/to/file/",tr("CSV Files (*.csv)")));
    ui->output_csv_location->displayText();
}

int MainWindow::on_analyse_button_clicked() {
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
    AnalysisDisplays::instance()->analyzeCSVOutput(ui->output_csv_location->text().toStdString(), this);
    return EXIT_SUCCESS;
}


// ----  HELPER FUNCTIONS ---- //
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
        //Strings are equal
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
