#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "TCustomer.h"
#include "TPerson.h"
#include "TDate.h"
#include "TAddress.h"
#include "TTools.h"

using namespace std;

TCustomer::TCustomer() {
}

TCustomer::~TCustomer() {
}

void TCustomer::load(ifstream &fileStream) {
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TCustomer::readData(ifstream &fileStream, string line) {
    bool status = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Customer" == tag) {
        status = true;
    } else if ("CustomerNr" == tag) {
        CustomerNr = tagContent;
        status = true;
    } else if ("/Customer" == tag) {
        status = false;
    } else {
        status = TPerson::readData(fileStream, line);
    }

    return status;
}
