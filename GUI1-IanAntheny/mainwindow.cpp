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
    printf("%s\n",curr_path.c_str());

    // Ensure params are valid

    //TODO
    //Check that input csv file is NOT the output csv
    //Check that threshold is > 0
    //Check that end date is after start date

    //Generate the params file from fields
    //NOTE: Output csv is the same directory as this executable path

    ofstream outputFile;
    outputFile.open ("params.param");
    outputFile << (":input_csvFile:" + ui->input_csv_location->text().toStdString() + "\\\n");
    outputFile << (":output_csvFile:"+ curr_path +"/output.csv\\\n");
    outputFile << (":output_logFile:"+curr_path+"/AlgorithmicTrading.log\\\n");
    outputFile << (":returnsInCalculation:" + to_string(ui->returnsInCalculation->value()) + "\\\n");
    outputFile << (":threshold:" + to_string(ui->threshold->value()) + "\\\n");
    outputFile << (":startDate:" + ui->start_date->date().toString().toStdString() + "\\\n");
    outputFile << (":endDate:" + ui->end_date->date().toString().toStdString() + "\\\n");
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

//Return a string of the current exe path
/*
string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH ); //Windows way of retrieving path of executable
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}
*/
