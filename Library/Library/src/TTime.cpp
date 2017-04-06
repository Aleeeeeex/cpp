#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <time.h>
#include "TTime.h"
#include "TTools.h"

using namespace std;

TTime::TTime() {
    time_t curtime;
    struct tm *loctime;

    curtime = time(NULL);
    loctime = localtime(&curtime);
    this->hour = loctime->tm_hour;
    this->minute = loctime->tm_min;
    this->second = loctime->tm_sec; //ohne die null nimmt er die aktuelle sekunde und gibt sie aus
}

void TTime::load(ifstream& fileStream)
{
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TTime::readData(ifstream& fileStream, string line)
{
    bool readStatus = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Time" == tag) {
        second = 0;
        readStatus = true;
    } else if ("Hour" == tag) {
        istringstream(tagContent) >> hour;
        readStatus = true;
    } else if ("Minute" == tag) {
        istringstream(tagContent) >> minute;
        readStatus = true;
    } else if ("Second" == tag) {
        istringstream(tagContent) >> second;
        readStatus = true;
    } else if ("/Time" == tag) {
        readStatus = false;
    }
    return readStatus;
}

TTime::TTime(short hour, short minute, short second = 0) {
   this->hour = hour;
   this->minute = minute;
   this->second = second;
}

void TTime::print() {
    printf("%02d:%02d:%02d\n", this->hour, this->minute, this->second);
}
