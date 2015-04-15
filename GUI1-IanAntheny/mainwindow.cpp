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
    // Ensure params are valid

    //TODO
    //Check that input csv file is NOT the output csv
/*
    char *output_csv_file = new char[ExePath().length() + 1];
    strcpy(output_csv_file, ExePath().c_str());
    strcat(output_csv_file, "/output.csv");
    QString output_csvFile(output_csv_file);

    if (ui->input_csv_location->text().compare(output_csvFile) == 0) {
        return 0;
    }
*/
    //Generate the params file from fields
    //NOTE: Output csv is the same directory as this

    ofstream outputFile;
    outputFile.open ("params.param");
    outputFile << (":input_csvFile:" + ui->input_csv_location->text().toStdString() + "\\\n");
    outputFile << (":output_csvFile:output.csv\\\n");
    outputFile << (":output_logFile:AlgorithmicTrading.log\\\n");
    outputFile << (":returnsInCalculation:" + to_string(ui->returnsInCalculation->value()) + "\\\n");
    outputFile << (":threshold:" + to_string(ui->threshold->value()) + "\\\n");
    outputFile.close();

    //Run the program by feeding param file

    //Retrieve location of param file
    string params_location = "";

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
