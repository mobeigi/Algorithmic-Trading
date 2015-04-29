# 
# TrockAT Mass Input Data Test File Generator
#
# This tool is designed to mass generate test files.
#
# usage: generator.py [Gen File Number] [TrockEquityDataGen]
#
# Copyright (c) 2015 Trock. All rights reserved.

#! /usr/bin/python
import re, sys, os, subprocess, datetime, random

def main(argv):

  # Higher variables
  curDirectoryPath = os.path.dirname(os.path.abspath(__file__)) + "/";
  trockDataGenPath = "";
  testNumber = 0;
  
  if os.path.isfile(curDirectoryPath + "TrockEquityDataGen.exe"):
    trockDataGenPath = curDirectoryPath + "TrockEquityDataGen.exe";
  elif os.path.isfile(curDirectoryPath + "TrockEquityDataGen"):
    trockDataGenPath = curDirectoryPath + "TrockEquityDataGen";

  if (not trockDataGenPath):
    if len(sys.argv) != 3:
      print 'usage:', sys.argv[0], '[Gen File Number] [TrockEquityDataGen]';
      sys.exit(1);
    else:
      testNumber = int(sys.argv[1]);
      trockDataGenPath = sys.argv[2];
  else:
    if len(sys.argv) != 2:
      print 'usage:', sys.argv[0], '[Gen File Number] [TrockEquityDataGen]';
      sys.exit(1);
    else:
      testNumber = int(sys.argv[1]);
  
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

    outputFile = genStartDate.strftime('%d-%b-%Y').upper() + "_" + str(genNumTrades) + "_" + str(test) + ".csv";
    
    #Generate the test input for this round
    subprocess.call([trockDataGenPath, str(genNumTrades), str(genStartDay), str(genStartMonth), str(genStartYear), outputFile])

    
  #After all tests are passed print out results
  print "\nGenerated " + str(testNumber) + " files successfully.";
  

 
if __name__ == "__main__":
  main(sys.argv[1:])