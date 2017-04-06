#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "TCustomer.h"
#include "TPerson.h"
#include "TDate.h"
#include "TAddress.h"
#include "TCustomer.h"
#include "TTools.h"

using namespace std;

TCustomer::TCustomer() {
}

TCustomer::~TCustomer() {
    cout << "Der Kunde '" << Name << "' wird vernichtet!" << endl;
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
    bool readStatus = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Customer" == tag) {
        readStatus = true;
    } else if ("CustomerNr" == tag) {
        CustomerNr = tagContent;
        readStatus = true;
    } else if ("/Customer" == tag) {
        readStatus = false;
    } else {
        readStatus = TPerson::readData(fileStream, line);
    }

    return readStatus;
}

void TCustomer::print() {
    cout << this->Name << " (Kundennr.: " << this->CustomerNr << ")\n" ;
    cout << this->Address->getStreet() << " " << this->Address->getHouseNr() << "\n" << this->Address->getZipcode() << " " << this->Address->getCity() << "\n";
    this->Birthday->print();
}


void TCustomer::add(TLoan* loan){
    this->LoanList.push_back(loan);
}

bool TCustomer::searchNr(string nr){
    return (this->CustomerNr == nr);
}

int TCustomer::getLoanListSize(){
    return this->LoanList.size();
}
void TCustomer::printName(){
    cout << this->Name;
}


