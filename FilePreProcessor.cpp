#include <climits>
//
// Created by Pavan Kumar  Paluri  on 3/20/21.
//
#include <sstream>
#include "FilePreProcessor.h"
#include "DayTrade.h"
using namespace std;
PreProcessor::PreProcessor(const string &input_file) {
    // open the file here..
    streamer.open(input_file, ifstream::in);
    if(!streamer.is_open())
        cout << "Error opening the file" << endl;
}

PreProcessor::~PreProcessor() {
    // Check if file descriptor is still active: if yes, close it in this destructor
    if(streamer.is_open())
        streamer.close();
}


Day_trade PreProcessor::extract_line_info() {
    // Extract the lines of input file into respective fields of Day_trade
    string input_line;
    // cin.ignore();
    getline(streamer, input_line);
    // cout << input_line << endl;
    streamer.clear();
    vector<string>string_slices = split(input_line, ',');
    return Day_trade(stoul(string_slices[0]), string_slices[1], stoul(string_slices[2]),
            stoul(string_slices[3]));

}

vector<string> PreProcessor::split(const string &s, char delimiter) {
    vector<string>slices;
    string slice;
    istringstream StreamSlice(s);
    while(getline(StreamSlice, slice, delimiter))
        slices.push_back(slice);
    return slices;
}