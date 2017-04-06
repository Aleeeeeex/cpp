#include "TLoan.h"
#include "TDate.h"
#include "TLibraryPool.h"
#include "TLibrary.h"
#include "TPerson.h"
#include "TEmployee.h"
#include "TMedium.h"
#include "TCustomer.h"
#include "TTools.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;
TLoan::TLoan(){
}

TLoan::TLoan(TMedium* medium, TPerson* customer, TDate* loandate, TDate* expiration){
    this->Medium = medium;
    this->Customer = customer;
    this->LoanDate = *loandate;
    this->Expiration = *expiration;
}

TLoan::~TLoan(){
    //cout << "TLoan wird vernichtet!" ;
}

void TLoan::print(){
    cout << "Titel:     " << Medium->getTitle() << endl;
    cout << "Signatur:  " << Medium->getSignature() << endl;
    cout << "Ort:       ";
    Medium->getLocation()->print();
    cout << "FSK:       " << "freigegeben ab " << Medium->getFSK() << " Jahren" << endl;

    if (Medium->verfuegbar() == 1)
        cout << "Status:      " << "verfuegbar" <<  "\n" << endl;
    if (Medium->ausgeliehen() == 2)
        cout << "Status:      " << "ausgeliehen" <<  "\n" << endl;
    if (Medium->reserviert() == 3)
        cout << "Status:      " << "reserviert" <<  "\n" << endl;
    if (Medium->bestellt() == 4)
        cout << "Status:      " << "bestellt" <<  "\n" << endl;

}

void TLoan::load(ifstream& fileStream){
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TLoan::readData(ifstream& fileStream, string line){
    bool readStatus = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Loan" == tag) {
        readStatus = true;
    } else if ("Signature" == tag) {
        signature = tagContent;
        readStatus = true;
    } else if ("CustomerNr" == tag) {
        customernr = tagContent;
        readStatus = true;
    } else if ("LoanDate" == tag) {
        TDate *ldate = new TDate();
        ldate->load(fileStream);
        this->LoanDate = *ldate;
        readStatus = true;
    } else if ("/LoanDate" == tag) {
        readStatus = true;
    } else if ("LoanDays" == tag) {
        this->Expiration = this->LoanDate+atoi(tagContent.c_str());
        readStatus = true;
    } else if ("/Loan" == tag) {
        readStatus = false;
    }

    return readStatus;
}

//TDate operator+(TDate date, const int days){
//    TDate Expiration = date;
//    Expiration.day += days;
//
//    if (Expiration.day >=31 ){
//        Expiration.month++;
//        Expiration.day -= 31;
//        if (Expiration.month >= 12)
//            Expiration.month = 1;
//            Expiration.year++;
//    }
//    return Expiration;
//}

void TLoan::printDate(){
    cout << LoanDate.day << "." << LoanDate.month << "." << LoanDate.year << endl;
}
void TLoan::printExpiDate(){
    cout << Expiration.day << "." << Expiration.month << "." << Expiration.year << endl;
}


