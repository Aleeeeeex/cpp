#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "TCustomer.h"
#include "TEmployee.h"
#include "TPerson.h"
#include "TDate.h"
#include "TAddress.h"
#include "TTools.h"

using namespace std;

TEmployee::TEmployee() {
}

TEmployee::~TEmployee() {
}

void TEmployee::load(ifstream &fileStream) {
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TEmployee::readData(ifstream &fileStream, string line) {
    bool status = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Employee" == tag) {
        status = true;
    } else if ("EmployeeNr" == tag) {
        EmployeeNr = tagContent;
        status = true;
    } else if ("/Employee" == tag) {
        status = false;
    } else {
        status = TCustomer::readData(fileStream, line);
    }

    return status;
}

