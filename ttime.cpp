#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include "ttime.h"

using namespace std;

TTime::TTime() {
    time_t curtime;
    struct tm *loctime;

    curtime = time(NULL);
    loctime = localtime(&curtime);
    this->hour = loctime->tm_hour;
    this->minute = loctime->tm_min;
    this->second = loctime->tm_sec;
}

TTime::TTime(short hour, short minute, short second) {
   this->hour = hour;
   this->minute = minute;
   this->second = second;
}

void TTime::print() {
    printf("%02d:%02d:%02d\n", this->hour, this->minute, this->second);
    /* cout << setiosflags(ios::fixed) << setw(3) << setfill('0')
        << this->hour << ":" << this->minute << ":" << this->second << "\n"; */
}

