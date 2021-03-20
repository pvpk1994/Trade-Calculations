//
// Created by Pavan Kumar  Paluri  on 3/20/21.
//
#include <string>
#include <fstream>
#include <vector>
#include "DayTrade.h"
using namespace  std;
#ifndef QUANTLAB_INTERVIEW_FILEPREPROCESSOR_H
#define QUANTLAB_INTERVIEW_FILEPREPROCESSOR_H
class PreProcessor {
private:
    // to return vector of sliced strings

    ifstream streamer;
public:
    // Constructor - For opening the file.
    explicit PreProcessor(const string&);
    ~PreProcessor();
    static vector<string>split(const string& s, char delimiter);
    bool is_line_valid() {return (streamer.peek() != EOF);}
    Day_trade extract_line_info();
};
#endif //QUANTLAB_INTERVIEW_FILEPREPROCESSOR_H
