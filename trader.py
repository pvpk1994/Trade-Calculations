import sys
from csv import reader, writer, DictWriter
import math
# import pandas as pd
from collections import OrderedDict
'''
Input Format: <timestamp>,<Symbol>,<Quantity>,<Price>
Output Format: <Symbol>, <MaxTimeGap>, <Volume>, <WeightedAvgPrice>, <MaxPrice>

Input:
The input file represents a very simplified stream of trades on an exchange.  
Each row represents a trade.  If you don't know what that means don't worry.  
The data can be thought of as a time series of values in columns: 

<TimeStamp>,<Symbol>,<Quantity>,<Price>

Although the provided input file is small, the solution should be able to handle 
a source dataset well beyond the amount memory and hard disk space on your machine.

Definitions
- TimeStamp is value indicating the microseconds since midnight.
- Symbol is the 3 character unique identifier for a financial 
  instrument (Stock, future etc.)
- Quantity is the amount traded
- Price is the price of the trade for that financial instrument.

Safe Assumptions:
- TimeStamp is always for the same day and won't roll over midnight.
- TimeStamp is increasing or same as previous tick (time gap will never be < 0).
- Price - our currency is an integer based currency.  No decimal points.
- Price - Price is always > 0.

Example: here is a row for a trade of 10 shares of aaa stock at a price of 12 
1234567,aaa,10,12

Problem:
Find the following on a per symbol basis:
- Maximum time gap
  (time gap = Amount of time that passes between consecutive trades of a symbol)
  if only 1 trade is in the file then the gap is 0.
- Total Volume traded (Sum of the quantity for all trades in a symbol).
- Max Trade Price.
- Weighted Average Price.  Average price per unit traded not per trade.
  Result should be truncated to whole numbers.

  Example: the following trades
	20 shares of aaa @ 18
	5 shares of aaa @ 7
	Weighted Average Price = ((20 * 18) + (5 * 7)) / (20 + 5) = 15

Output:
Your solution should produce a file called 'output.csv'.
file should be a comma separate file with this format:
<symbol>,<MaxTimeGap>,<Volume>,<WeightedAveragePrice>,<MaxPrice>

The output should be sorted by symbol ascending ('aaa' should be first).

Sample Input:
52924702,aaa,13,1136
52924702,aac,20,477
52925641,aab,31,907
52927350,aab,29,724
52927783,aac,21,638
52930489,aaa,18,1222
52931654,aaa,9,1077
52933453,aab,9,756

Sample Output:
aaa,5787,40,1161,1222
aab,6103,69,810,907
aac,3081,41,559,638

Send your source code and output.csv in a zipped git repo back for evaluation when complete.
Include the amount of time you spent working on the solution.
'''
hash_map = {}
max_price = -math.inf

def mergedict(a, b):
	a.update(b)
	return a
# Start gatehring the data
with open('input.csv', 'r') as read_csv:
	csv_reader = reader(read_csv, delimiter=',')
	# iterate thru every row of the data
	for row in csv_reader:
		symbol = row[1]
		timeStamp = int(row[0])
		qty = int(row[2])
		price = int(row[3])
		# If obtained symbol not in hash_map already: Time to create new entries into the hashmap
		if symbol not in hash_map.keys():
			hash_map[symbol] = {}
			hash_map[symbol]['vol'] = qty
			hash_map[symbol]['wap'] = qty*price 
			hash_map[symbol]['mtg'] = 0
			hash_map[symbol]['time'] = timeStamp
			hash_map[symbol]['MaxPrice'] = price
			# default mtg in case of unique occurrence is 0 anyways.. so init to 0
			'''
			hash_map[symbol]['mtg'] = 0
			hash_map[symbol]['wap'] = 0
			hash_map[symbol]['price'] = price
			hash_map[symbol][]
			'''

		elif symbol in hash_map.keys():
			hash_map[symbol]['vol'] += qty
			hash_map[symbol]['wap'] += qty*price
			hash_map[symbol]['mtg'] = max(hash_map[symbol]['mtg'], timeStamp - hash_map[symbol]['time'])
			hash_map[symbol]['time'] = timeStamp
			hash_map[symbol]['MaxPrice'] = max(price, hash_map[symbol]['MaxPrice'])
	for key in hash_map.keys():
		hash_map[key]['wap'] = int(hash_map[key]['wap']/hash_map[key]['vol'])
		del hash_map[key]['time']

dict_final = dict(OrderedDict(sorted(hash_map.items())))
print(dict(OrderedDict(sorted(hash_map.items()))))
# export the dict to a CSV
fields = ['symbol', 'vol', 'wap', 'mtg', 'MaxPrice']
with open("output.csv", "w") as f_ptr:
	w = DictWriter(f_ptr, fields)
	w.writeheader()
	for k,d in dict_final.items():
		w.writerow(mergedict({'symbol':k}, d))






