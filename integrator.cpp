// Author: Pavan Kumar Paluri
#include <iostream>
#include <memory>
#include<map>
#include<algorithm>
#include <fstream>
#include "FilePreProcessor.h"
// #include "DayTrade.h"
using namespace std;
int main() {
    // NOTE: Complete Path to the file has to be provided...
    PreProcessor pp("/Users/pavankumarpaluri/Documents/QuantLab_Interview/large_input.csv");
    // cout << pp.is_line_valid() << endl;
    map<string, map<string, unsigned long>> hash_map;
    map<string, map<string, unsigned long>>::iterator itr, itr_2; // outer iterator
    map<string, unsigned long>::iterator ptr; // inner iterator
    while(pp.is_line_valid()) {
        Day_trade dt = pp.extract_line_info();
        // Sanity-checks
        /*
        cout << dt.get_symbol() << endl;
        cout << dt.get_timeStamp() << endl;
        cout << dt.get_price() << endl;
        cout << dt.get_qty() << endl;
         */
        if (hash_map.find(dt.get_symbol()) == hash_map.end()) {
            // symbol not found
            // VOLUME- CALCULATION
            hash_map.insert(make_pair(dt.get_symbol(), map<string, unsigned long>()));
            hash_map[dt.get_symbol()].insert(make_pair("Quantity", dt.get_qty()));
            // TIMESTAMP
            hash_map.insert(make_pair(dt.get_symbol(), map<string, unsigned long>()));
            hash_map[dt.get_symbol()].insert(make_pair("TimeStamp", dt.get_timeStamp()));
            // MAX PRICE
            hash_map.insert(make_pair(dt.get_symbol(), map<string, unsigned long>()));
            hash_map[dt.get_symbol()].insert(make_pair("MaxPrice", dt.get_price()));
            // MAXIMUM TIME GAP
            hash_map.insert(make_pair(dt.get_symbol(), map<string, unsigned long>()));
            hash_map[dt.get_symbol()].insert(make_pair("MaxTimeGap", 0));
            //WEIGHTED AVERAGE PRICE
            hash_map.insert(make_pair(dt.get_symbol(), map<string, unsigned long>()));
            hash_map[dt.get_symbol()].insert(make_pair("WAP", dt.get_price() * dt.get_qty()));
        } else {// symbol found in hash_map
            hash_map[dt.get_symbol()]["Quantity"] += dt.get_qty();
            hash_map[dt.get_symbol()]["WAP"] += dt.get_qty() * dt.get_price();
            hash_map[dt.get_symbol()]["MaxTimeGap"] = max(hash_map[dt.get_symbol()]["MaxTimeGap"], dt.get_timeStamp()-hash_map[dt.get_symbol()]["TimeStamp"]);
            hash_map[dt.get_symbol()]["TimeStamp"] = dt.get_timeStamp();
            hash_map[dt.get_symbol()]["MaxPrice"] = max(dt.get_price(), hash_map[dt.get_symbol()]["MaxPrice"]);
        }
    }

        for(itr = hash_map.begin(); itr != hash_map.end(); itr++){
            // cout << "Symbol:" << itr->first << " ";
            for(ptr = itr->second.begin(); ptr != itr->second.end(); ptr++)
            {
                if(ptr->first=="WAP")
                    hash_map[itr->first][ptr->first] /= hash_map[itr->first]["Quantity"];
                // cout << ptr->first << " " << ptr->second << endl;
            }
        }

        // Loading the output to an output.csv
        // NOTE: Complete Path to the file has to be provided...
        ofstream output_streamer("/Users/pavankumarpaluri/Documents/QuantLab_Interview/output.csv");
        for(itr_2 = hash_map.begin(); itr_2!=hash_map.end(); itr_2++)
        {
            output_streamer << itr_2->first << "," << hash_map[itr_2->first]["MaxTimeGap"] << "," << hash_map[itr_2->first]["Quantity"] << ","\
            << hash_map[itr_2->first]["WAP"] << "," << hash_map[itr_2->first]["MaxPrice"];
            output_streamer << "\n";
        }

        // close the file descriptor in case it is open.
        if(output_streamer.is_open())
            output_streamer.close();

    return 0;
}
