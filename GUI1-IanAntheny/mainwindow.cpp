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
    int invalidities_size = invalidities.size();
    if (invalidities_size != 0) {
        //There are errors - return the appropriate messages corresponding to each message
        for (int i = 0; i < invalidities_size; i++) {
            if (invalidities[i] == INPUTCSV_EQ_OUTPUTCSV) {
                //ui->inputcsv_valid->setText("Please select a different CSV file.");
            } else if (invalidities[i] == ENDDATE_BEFORE_STARTDATE) {
                //ui->date_valid->setText("End date has to be after start date.");
            }
        }
        return 0; //early exit
    }

    //Construct the date strings
    string start_date_str = construct_date_string(ui->start_date->date().day(),ui->start_date->date().month(),ui->start_date->date().year());
    string end_date_str = construct_date_string(ui->end_date->date().day(),ui->end_date->date().month(),ui->end_date->date().year());

    //Generate the params file from fields
    //NOTE: Output csv is the same directory as this executable path

    ofstream outputFile;
    outputFile.open ("params.param");
    outputFile << (":input_csvFile:" + ui->input_csv_location->text().toStdString() + "\\\n");
    outputFile << (":output_csvFile:"+ curr_path +"/output.csv\\\n");
    outputFile << (":output_logFile:"+curr_path+"/AlgorithmicTrading.log\\\n");
    outputFile << (":returnsInCalculation:" + to_string(ui->returnsInCalculation->value()) + "\\\n");
    outputFile << (":threshold:" + to_string(ui->threshold->value()) + "\\\n");
    outputFile << (":startDate:" + start_date_str + "\\\n");
    outputFile << (":endDate:" + end_date_str + "\\\n");
    outputFile.close();

    //Run the program by feeding param file
    //Construct location of params file
    string params_location = curr_path + "/params.param";

    //Construct the command string
    string command_str = ui->strategy_module_location->text().toStdString(); //program location
    command_str.append(" ");
    command_str.append(params_location); //params file location

    system(command_str.c_str()); //windows way of executing file
    ui->execution_status->setText("Execution Complete");

    return EXIT_SUCCESS;
}

vector<int> MainWindow::check_params(void) {
    vector<int> invalidities;
    //Get path of current directory
    string curr_path = QDir::currentPath().toStdString();

    //Check that input csv file is NOT the output csv
    string input_csv_path = ui->input_csv_location->text().toStdString();
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
