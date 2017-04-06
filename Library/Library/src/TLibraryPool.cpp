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
#include "TLoan.h"

using namespace std;

TLibraryPool::TLibraryPool(string name, TEmployee *chairman){
    this->Name = name;
    this->Chairman = chairman;
}

TLibraryPool::TLibraryPool(string fname){
    ifstream XMLFile;
    string line, tag;
    cout << "Datei " << fname << " wird geoeffnet - ";

    XMLFile.open(fname.data(), ios::in);
    if (!XMLFile.is_open()) {
        cout << "nicht ok" << endl;
        perror("Error while opening file");
        return;
    } else {
        cout << "ok" << endl;
    }

    cout << "Datei " << fname << " wird eingelesen - ";

    while (getline(XMLFile, line)) {
        tag = readData(line);

        if ("Employee" == tag) {
            this->Chairman = new TEmployee();
            this->Chairman->load(XMLFile);
        } else if ("Library" == tag) {
            TLibrary *library = new TLibrary();
            library->load(XMLFile);
            add(library);
        } else if ("Customer" == tag) {
            TCustomer *customer = new TCustomer();
            customer->load(XMLFile);
            add(customer);
            //copyLoanToCustomer(LoanList);
        }
        else if ("Loan" == tag) {
            TLoan *loan = new TLoan();
            loan->load(XMLFile);
            loan->Customer = searchCustomerNr(loan->customernr);
            loan->Medium = searchMediumSignature(loan->signature);
            loan->Medium->setStatus(2);
//            Customer.add(loan);
            add(loan);
           // copyLoanToCustomer(LoanList);
            //for(unsigned i = 0; i <= Customer.size(); i++){
            //    Customer.at(i)->add(loan);
            //}
            //auch in customer gleich einfügen
        }
    }

    if (XMLFile.bad()) {
        perror("Error while reading file");
    } else {
        cout << "ok" << endl << endl;
    }
    copyLoanToCustomer(LoanList);

}

TLibraryPool::~TLibraryPool(){

    for (vector<TLibrary*>::iterator it = LibraryList.begin(); it < LibraryList.end(); it++) {
        delete *it;
    }

    for (vector<TCustomer*>::iterator it = Customer.begin(); it < Customer.end(); it++) {
        delete *it;
    }
    for (vector<TLoan*>::iterator it = LoanList.begin(); it < LoanList.end(); it++) {
        delete *it;
    }

    delete this->Chairman;
}

string TLibraryPool::readData(string line) {
    string tag, tagContent;
    GETTAG(line, tag, tagContent)

    if (tag == "Name") {
        this->Name = tagContent;
    } else {
        return tag;
    }

    return "";
}

void TLibraryPool::add(TLibrary* library){
    this->LibraryList.push_back(library);
    //copyLoanToCustomer(this->LoanList);
}


void TLibraryPool::add(TCustomer* customer){
    this->Customer.push_back(customer);
}

void TLibraryPool::add(TLoan* loan){
    this->LoanList.push_back(loan);

    //copyLoanToCustomer(LoanList);
}

ostream &operator<<(ostream &ostr, TLibraryPool &lp){
   // lp.copyLoanToCustomer(lp.LoanList);
    ostr << lp.Name << endl;
    ostr << "Leitung: "; lp.Chairman->print();
    ostr << "\nZum Buechereiverband gehoeren " << lp.LibraryList.size() << " Filialen:\n" << endl;

    for (unsigned int  i = 0; i < lp.LibraryList.size(); i++){
        (lp.LibraryList.at(i))->print();
        ostr << "Es stehen ";
        ostr << lp.LibraryList.at(i)->getMediumListSize();
        ostr << " Medienn zur Verfügung: \n" << endl;

        for ( int j = 0; j < lp.LibraryList.at(i)->getMediumListSize(); j++){
            ostr << "Medium Nr. " << j+1 << endl;
            TMedium *medium = lp.LibraryList.at(i)->getMedium(j);
            medium->print();
            ostr << endl;
        }
    }
    ostr << "\n\n" << "Der Buecherverband hat " << lp.Customer.size() << " Kunden:" << endl;
    for(unsigned int i= 0; i < lp.Customer.size(); i++){
        ostr << endl;
        lp.Customer.at(i)->print();
        ostr << "Ausleihen:" << endl;
        for(int j= 0; j < lp.Customer.at(i)->LoanList.size() ; j++){ // die größe gibt es nicht, da keine initialisierung  funzt leider nicht, daher statisch mit <=1
            //lp.Customer.at(i)->add(lp.LoanList.at(j));
            ostr << "Ausleihe vom " ;
            lp.Customer.at(i)->LoanList.at(j)->printDate();
            ostr << "Rueckgabe bis zum spaetestens ";
            lp.Customer.at(i)->LoanList.at(j)->printExpiDate();
            //if(lp.Customer.at(i)->CustomerNr == lp.Customer.at(i)->LoanList.at(j)->customernr)
                lp.Customer.at(i)->LoanList.at(j)->Medium->print();
           // ostr << endl;
            ostr << "ausgeliehen von " ;
            if(lp.Customer.at(i)->CustomerNr == lp.Customer.at(i)->LoanList.at(j)->customernr)
                //lp.LoanList.at(i)->Customer->print();
                lp.Customer.at(i)->printName();
            ostr << endl;

          //  ostr << "\n*\n*\n*\n" ;
           //for(unsigned int x = 0; x < lp.LoanList.size(); x++){
            //   lp.LoanList.at(x)->print();
             //ostr << endl;
          // }
          // ostr << "\n*\n*\n*\n" ;

            //lp.Customer.at(i)->getLoanListSize()
            //lp.LoanList.at(j)->Customer->getName(); //funzt leider auch nicht
        }
    }
    ostr << "Es sind ";
    ostr << lp.LoanList.size();
    ostr << " Medienn ausgeliehen: \n" << endl;
    for (unsigned int  i = 0; i < lp.LoanList.size(); i++){
        //lp.LoanList.at(i)->Medium->Status = 2;
        ostr << "Ausleihe vom " ;
        lp.LoanList.at(i)->printDate();
        ostr << "Rueckgabe bis zum spaetestens ";
        lp.LoanList.at(i)->printExpiDate();
        lp.LoanList.at(i)->Medium->print();
        ostr << "ausgeliehen von ";
        lp.LoanList.at(i)->Customer->print(); //funzt
        ostr << endl;
    }
    return ostr;
}

void TLibraryPool::print(){
    cout << this->Name << endl;
    cout << "Leitung: "; this->Chairman->print();

    cout << "\n" << "Zum Buechereiverband gehoeren " << this->LibraryList.size() << " Filialen:\n" << endl;

    for(unsigned int i = 0; i < LibraryList.size(); i++){
        (this->LibraryList.at(i))->print();
        cout << "Es stehen ";
        cout << this->LibraryList.at(i)->getMediumListSize(); //TLibrary.getMediumListSize();
        cout << " Medien zur Verfuegung:\n" << endl;

        for(int j = 0; j < this->LibraryList.at(i)->getMediumListSize(); j++){ //TLibrary.getMediumListSize();
            cout << "Medium Nr. " << j+1 << endl;
            TMedium *medium = LibraryList.at(i)->getMedium(j);
            cout << medium->getTitle();
            medium->print();
            cout << endl;
        }
    }

    cout << "\n\n" << "Der Buecherverband hat " << this->Customer.size() << " Kunden:\n" << endl;

    for(unsigned int i= 0; i < Customer.size(); i++){
        this->Customer.at(i)->print();
        cout << "\n" ;
    }
}

int TLibraryPool::getMediumListSize() {
    return LibraryList.size();
}


TCustomer* TLibraryPool::searchCustomerNr(string customernr){
    for (unsigned int i = 0; i < Customer.size(); i++) {
        if (Customer.at(i)->searchNr(customernr)) {
            //Customer.at(i)->add(*loan);
            return Customer.at(i);
        }
    }

    return NULL;
}

TMedium* TLibraryPool::searchMediumSignature(string signature){
    for (unsigned int i = 0; i < LibraryList.size(); i++) {
        for (int j = 0; j < LibraryList.at(i)->getMediumListSize(); j++) {
            if (LibraryList.at(i)->getMedium(j)->searchSignature(signature)) {
                return LibraryList.at(i)->getMedium(j);
            }
        }
    }

    return NULL;
}

void TLibraryPool::copyLoanToCustomer(vector<TLoan*> loanlist){
    for (unsigned i = 0; i < Customer.size(); i++){
        for(unsigned j = 0; j < loanlist.size(); j++){
            if(Customer.at(i)->CustomerNr == loanlist.at(j)->customernr)
            //Customer.at(i)->LoanList.at(j) = loanlist.at(j);
            Customer.at(i)->LoanList.push_back(loanlist.at(j));
        }
    }
}

//for (vector<TLibrary*>::iterator it = LibraryList.begin(); it < LibraryList.end(); it++)
