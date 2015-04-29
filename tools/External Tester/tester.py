# 
# TrockAT External Testing Application
#
# This tool is designed to analyse the output from the trockAT algorithmic application
# with an expected output over a serious of tests. It makes use of a random equity trading data
# application to provide its input.
#
# usage: tester.py [module application] [TrockEquityDataGen]
#
# or (if required applications trockAT and TrockEquityDataGen are in current script directory)
#
# usage: teser.py
#
# Additional flags
#
# tester.py --clean   #cleans all test files in script directory
#
# Copyright (c) 2015 Trock. All rights reserved.

#! /usr/bin/python
import csv, re, sys, os, subprocess, datetime, itertools, random
from time import sleep

def main(argv):

  # Higher variables
  curDirectoryPath = os.path.dirname(os.path.abspath(__file__)) + "/";
  modulePath = "";
  trockDataGenPath = "";
  
  paramFilePath = curDirectoryPath + "test_ParamFile.param";
  secondParamFilePath = curDirectoryPath + "test_ParamFile2.param";
  testerOrderFile = curDirectoryPath + "test_orders_testerScript.csv"
  trockOrderFile = curDirectoryPath + "orders.csv";
  trockLogFile = curDirectoryPath + "test_logfile.txt";
  genPathOutPut = curDirectoryPath + "test_input.csv";
  wosLogFile = curDirectoryPath + "log.txt";
  
  #Auto detect required executables () if in current directory
  if os.path.isfile(curDirectoryPath + "trockAT.exe"):
    modulePath = curDirectoryPath + "trockAT.exe";
  elif os.path.isfile(curDirectoryPath + "trockAT"):
    modulePath = curDirectoryPath + "trockAT";

  if os.path.isfile(curDirectoryPath + "TrockEquityDataGen.exe"):
    trockDataGenPath = curDirectoryPath + "TrockEquityDataGen.exe";
  elif os.path.isfile(curDirectoryPath + "TrockEquityDataGen"):
    trockDataGenPath = curDirectoryPath + "TrockEquityDataGen";
  
  #Add clean command to remove files
  if len(sys.argv) == 2 and sys.argv[1] == "--clean":
    removemaybe(trockOrderFile);
    removemaybe(testerOrderFile);
    removemaybe(trockLogFile);
    removemaybe(genPathOutPut);
    removemaybe(paramFilePath);
    removemaybe(secondParamFilePath);
    removemaybe(wosLogFile);
    sys.exit(1);
  
  if (not modulePath and not modulePath):
    if len(sys.argv) != 3:
      print 'usage:', sys.argv[0], '[module application] [TrockEquityDataGen]';
      sys.exit(1);
    else:
      modulePath = sys.argv[1];
      trockDataGenPath = sys.argv[2]; 
  

  testNumber = 30;
  
  for test in range(1, testNumber + 1):
    genNumTrades = random.randint(1,500);

    # Create valid date range by choosing a date between init date and yesterday ( 1 day before now() time)
    # Then simply choose a valid start start anytime between this period
    initDate = datetime.datetime(1980, 1, 1);
    initDateToday = datetime.datetime.now() - datetime.timedelta(days = 1);
    dayDifference = (initDateToday - initDate).days;
    randOffset = random.randint(0, dayDifference - genNumTrades); #we want our random start date to have enough days for all trades
    step = datetime.timedelta(days = randOffset);
    genStartDate = initDate + step;

    #Get datetime components
    genStartDay = genStartDate.day;
    genStartMonth = genStartDate.month;
    genStartYear = genStartDate.year;

    #Generate the test input for this round
    subprocess.call([trockDataGenPath, str(genNumTrades), str(genStartDay), str(genStartMonth), str(genStartYear), genPathOutPut])

    #Generate param file to use with TrockAT
    startDate = datetime.datetime(genStartYear, genStartMonth, genStartDay);
    step = datetime.timedelta(days= genNumTrades - 1); #our end date is exclusive, no trade day generated
    endDate = startDate + step;
    
    #Generate returnsInCalculations and threshold
    genReturnsInCalc = random.randint(1, genNumTrades - 1);
    genThreshold = random.uniform(0.0, 0.001);
    
    genParamFile(paramFilePath, secondParamFilePath, genPathOutPut, trockOrderFile, trockLogFile, genReturnsInCalc, genThreshold, startDate, endDate);

    # Call module application to parse input
    subprocess.call([modulePath, genPathOutPut, secondParamFilePath, paramFilePath])

    #Call MSM analyser
    MSMAnalyser(genPathOutPut, testerOrderFile, genReturnsInCalc, genThreshold);

    #Print current test num
    sys.stdout.write("Test #" + str(test) + ": ");
    
    #Compare analyser output with module application output
    diffNum = diffOrderCSV(testerOrderFile, trockOrderFile);
  
    #Testing failed, terminate now
    if (diffNum > 0):
      print "FAILED!";
      print "\t Found in files:", testerOrderFile, trockOrderFile, "\n", "Test number was " + str(test), ", testing", str(genNumTrades), "trade days.";
      sys.exit(1);
    else:
      #Delete files from succesful test
      removemaybe(trockOrderFile);
      removemaybe(testerOrderFile);
      removemaybe(trockLogFile);
      removemaybe(genPathOutPut);
      removemaybe(paramFilePath);
      removemaybe(secondParamFilePath);
      removemaybe(wosLogFile);
      print "PASSED";
    
    sleep(0.5); #small pause to allow applications to read/write files
    
  #After all tests are passed print out results
  print "\nPassed all " + str(testNumber) + " tests successfully.";
  

# Given required parameters, generated a valid paramfile
def genParamFile(outputParamFilePath, outputSecondParamFilePath, inputCSVPath, outputCSVPath, outputLogFilePath, returnsInCalculation, threshold, startDate, endDate):
  f = open(outputParamFilePath, 'w');
  
  # Generate proper date formats
  startDateStr = startDate.strftime('%d-%b-%Y').upper();
  endDateStr = endDate.strftime('%d-%b-%Y').upper();
  
  f.write(":input_csvFile:" + inputCSVPath.replace('\\', '/') + "\\\n" +
          ":output_csvFile:" + outputCSVPath.replace('\\', '/') + "\\\n" +
          ":output_logFile:" + outputLogFilePath.replace('\\', '/') + "\\\n" +
          ":returnsInCalculation:" + str(returnsInCalculation) + "\\\n" +
          ":threshold:" + str(threshold) + "\\\n" +
          ":startDate:" + startDateStr + "\\\n" +
          ":startDate:" + endDateStr + "\\\n"
         );
  f.close();
  
  f2 = open(outputSecondParamFilePath, 'w');
  f2.write("N,TH,DateRange\n" +
          str(returnsInCalculation) + "," + str(threshold) + "," + str(startDate.year) + "-" + str(endDate.year) + "\n"
          );
  f2.close();

# Given an input CSV file, applies MSM to generate the correct, expected output
def MSMAnalyser(inputCSVFile, outputOrderFile, returnsInCalculation, threshhold):
  f = open(inputCSVFile, 'rb');
  dataList = list( csv.reader(f, delimiter = ',') ); #convert to scriptable list
  dataList.pop(0); #dont need first header row
  f.close();
  
  #output file stub
  f = open(outputOrderFile, 'wb');
  f.write("#Company, Date, Price, Volume, Value, Signal\n");
  
  previousPrice = 0.0;
  rt = [];
  fixedTradeVolume = "100";
  lastMovingAverage = 0;
  hadMovingAverage = False;
  
  Signal = enum(BUY='B', SELL='S', DEFAULT=0);
  previousSignal = Signal.DEFAULT;
  
  #For each trade day
  for row in dataList:
    tradeCompany = row[0];
    tradeDate = row[1];
    tradeQualifier = row[4];
    lastPrice = row[8];
    tradeVolume = row[9];
    
    #Calculate return
    if (previousPrice == 0):
      if tradeQualifier != "No Trades":
        previousPrice = float(lastPrice);
      continue;
    else:
      if tradeQualifier == "No Trades":
        continue;
      else:
        rtVal = (( float(lastPrice) - previousPrice) / previousPrice);
        rt.append(rtVal);
        previousPrice = float(lastPrice);
    
    if (len(rt) < returnsInCalculation):
      continue;

    #Generate new moving average
    movingAverage = 0.0;
    
    for i in range(len(rt) - returnsInCalculation, len(rt)):
      movingAverage += rt[i];
    
    movingAverage /= returnsInCalculation;
    
    if (not hadMovingAverage):
      hadMovingAverage = True;
      lastMovingAverage = movingAverage;
      continue;
    
    #Get diff between averages
    diff = movingAverage - lastMovingAverage;
    lastMovingAverage = movingAverage;
    
    if diff > threshhold:
      #Check for double bug signals
      if (previousSignal == Signal.BUY):
        continue;
      
      previousSignal = Signal.BUY;
      
    elif diff < -threshhold:
      #Check for double sell signals
      if (previousSignal == Signal.SELL):
        continue;
      
      previousSignal = Signal.SELL;
    #otherwise ignore signal
    else:
      continue;
    
    #generate line to write
    orderLine = tradeCompany, tradeDate, regRound(float(lastPrice)), fixedTradeVolume, regRound(float(lastPrice) * float(fixedTradeVolume)), previousSignal + "\n";
    
    #write order line
    f.write(','.join(orderLine));
    
  f.close();
  
#remove if exists
def removemaybe(filename):
  try:
    os.remove(filename)
  except OSError:
    pass  

#Compares two CSV files and compares critical values to ensure they are the same
#First parameter should be tester generated CSV file
def diffOrderCSV(first, second):
  f1 = open(first, 'rb')
  f2 = open(second, 'rb')
  reader1 = csv.reader(f1)
  reader2 = csv.reader(f2)
  
  differencesFound = 0;
  lineNum = 0;
  
  # Uses itertools to get array components for each line
  for lhs, rhs in itertools.izip(reader1, reader2):
    lineNum += 1;

    #Ignore header
    if (lineNum == 1):
      continue;
      
    #Compare critical components
    diff = False;
    
    #company name
    if lhs[0] != rhs[0]:
      diff = True;
      
    #Check dates  
    if lhs[1] != rhs[1]:
      diff = True;
    
    #Check prices  
    lSignal = lhs[5];
    rSignal = rhs[5];
    
    if rSignal == "Buy":
      rSignal = "B";
    elif rSignal == "Sell":
      rSignal = "S"; 
    
    if lSignal != rSignal:
      diff = True;

    if diff:
      differencesFound += 1;
      print "diff #" + str(differencesFound) + ": ", lhs, rhs
      
  f1.close();
  f2.close();
  
  return differencesFound;

# Round function that behaves in same manner as c++ std::setprecision(2)
def regRound(value):
  return "{:.2f}".format(value);
  
def enum(**enums):
  return type('Enum', (), enums)
    
if __name__ == "__main__":
  main(sys.argv[1:])