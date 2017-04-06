#include "TLibraryPool.h"
#include "TLibrary.h"
#include "TPerson.h"
#include "TEmployee.h"
#include "TCustomer.h"
#include "TTools.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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

        if ("Chairman" == tag) {
            this->Chairman = new TEmployee();
            this->Chairman->load(XMLFile);
        } else if ("Library" == tag) {
            TLibrary *library = new TLibrary();
            library->load(XMLFile);
            add(library);
        } else if ("Person" == tag) {
            TCustomer *customer = new TCustomer();
            customer->load(XMLFile);
            add(customer);
        } else if ("Employee" == tag) {
            this->Chairman = new TEmployee();
            this->Chairman->load(XMLFile);
        } else if ("Customer" == tag) {
            TCustomer *customer = new TCustomer();
            customer->load(XMLFile);
            add(customer);
        }
    }

    if (XMLFile.bad()) {
        perror("Error while reading file");
    } else {
        cout << "ok" << endl << endl;
    }

}

TLibraryPool::~TLibraryPool(){
    //cout << this->Name << " wird vernichtet!" << endl;
    //this->Customer.clear;
    //cout << this->Chairman << " wird vernichtet!" << endl;
    //this->Chairman.clear;
    for (vector<TLibrary*>::iterator it = LibraryList.begin(); it < LibraryList.end(); it++) {
        delete *it;
    }

    for (vector<TCustomer*>::iterator it = Customer.begin(); it < Customer.end(); it++) {
        delete *it;
    }

    delete this->Chairman;
}

string TLibraryPool::readData(string line) {
    string tag, tagContent;
    GETTAG(line, tag, tagContent)

    //cout << tag << endl;
    //cout << tagContent << endl;
    //cout << line << endl;

    if (tag == "Name") {
        this->Name = tagContent;
    } else {
        return tag;
    }

    return "";
}

void TLibraryPool::add(TLibrary* library){
    this->LibraryList.push_back(library);
}

void TLibraryPool::add(TCustomer* customer){
    this->Customer.push_back(customer);
}

void TLibraryPool::print(){
    cout << this->Name << endl;
    cout << "Leitung: "; this ->Chairman->print();

    cout << "\n" << "Zum Buechereiverband gehoeren " << this->LibraryList.size() << " Filialen:\n" << endl;

    for(unsigned int i = 0; i < LibraryList.size(); i++){
        (this->LibraryList.at(i))->print();
        cout << "Es stehen ";
        cout << this->LibraryList.at(i)->getMediumListSize(); //TLibrary.getMediumListSize();
        cout << " Medien zur Verfuegung:\n" << endl;

        for(int j = 0; j < this->LibraryList.at(i)->getMediumListSize(); j++){ //TLibrary.getMediumListSize();
            cout << "Medium Nr. " << j+1 << endl;
            this->LibraryList.at(i)->getMedium(j)->print();
            cout << endl;
        }
    }

    cout << "\n\n" << "Der Buecherverband hat " << this->Customer.size() << " Kunden:\n" << endl;

    for(unsigned int i= 0; i < Customer.size(); i++){
        this->Customer.at(i)->print();
        cout << "\n" ;
    }
}

void TLibraryPool::getMediumListSize() {
}
