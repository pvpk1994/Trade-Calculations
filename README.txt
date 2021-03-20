# Author: Pavan Kumar Paluri
Files:
=====
1. {DayTrade.cpp, DayTrade.h} Contain class definitions for Symbols along with their params Quantity, Price, TimeStamp.
2. {FilePreProcessor.cpp, FilePreProcessor.h} Contain class definitions for Reading in the file and store params into a DayTrade instance.
3. {Integrator.cpp} uses concept of nested hashmaps to compute the values of Weighted Average Price, Max Price, Volume, Max Time Gap per symbol.
4. {run.sh} Generates executables for all aforementioned programs and returns a "successful compilation" message if input file is properly provided with its proper path.
5. {test.py} A quick python implementation to verify the approach.

Time Taken for Completion:
=========================
Effective Time Taken: 2hr 30 mins.
1. The input.txt initially built had numerous garbage characters. Lot of time went into figuring out this problem.
2. A simple python verification program took < 20 mins.

Time and Space Complexity Analysis:
==================================
1. Time Complexity:: Linear time to read in the whole input and process it simultaneously => O(N)
2. Space Complexity:: Vector to store params of DayTrade: O(N) + HashMap to store every symbol: O(Number of unique Symbols)
