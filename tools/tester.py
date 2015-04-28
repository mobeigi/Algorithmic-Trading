#! /usr/bin/python
import csv, re, sys
with open(sys.argv[1], 'rb') as b:
	data = csv.reader(b, delimiter = ',')
	for c in data:
		print c
