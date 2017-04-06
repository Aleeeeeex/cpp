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
    cout << "Der Angestellte '" << Name << "' wird vernichtet!" << endl;
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
    bool readStatus = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Employee" == tag) {
        readStatus = true;
    } else if ("EmployeeNr" == tag) {
        EmployeeNr = tagContent;
        readStatus = true;
    } else if ("/Employee" == tag) {
        readStatus = false;
    } else {
        readStatus = TCustomer::readData(fileStream, line);
        //status = TPerson::readData(fileStream, line);
    }

    return readStatus;
}

void TEmployee::print() {
    cout << this->Name << " (Kundennr.: " << this->CustomerNr << " / " << "Personalnr.: " << this->EmployeeNr << ") \n" ;
    cout << this->Address->getStreet() << " " << this->Address->getHouseNr() << "\n" << this->Address->getZipcode() << " " << this->Address->getCity() << "\n";
    this->Birthday->print();
}

