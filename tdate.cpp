#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "tdate.h"

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

void TDate::print() {
    printf("%02d.%02d.%04d\n", this->day, this->month, this->year);
    /* cout << setiosflags(ios::fixed) << setprecision(2)
        << this->day << "." << this->month << "." << this->year << "\n"; */
}
