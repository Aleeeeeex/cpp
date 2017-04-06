#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include "TDate.h"
#include "TTools.h"

using namespace std;

TDate::TDate() {
    time_t curtime;
    struct tm *loctime;

    curtime = time(NULL);
    loctime = localtime(&curtime);
    this->day = loctime->tm_mday;
    this->month = loctime->tm_mon + 1;
    this->year = loctime->tm_year + 1900;
}

TDate::TDate(short day, short month, short year) {
   this->day = day;
   this->month = month;
   this->year = year;
}

void TDate::load(ifstream &fileStream) {
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TDate::readData(ifstream &fileStream, string line) {
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Date" == tag) {
        return true;
    } else if ("Day" == tag) {
        istringstream(tagContent) >> day;
    } else if ("Month" == tag) {
        istringstream(tagContent) >> month;
    } else if ("Year" == tag) {
        istringstream(tagContent) >> year;
    } else if ("/Date" == tag) {
        return false;
    }

    return true;
}

void TDate::print() {
    printf("* %02d.%02d.%04d\n", this->day, this->month, this->year);
}



