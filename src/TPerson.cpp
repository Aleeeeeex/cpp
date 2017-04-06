#include "TPerson.h"
#include "TDate.h"
#include "TAddress.h"
#include "TTools.h"
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

TPerson::TPerson(string name, TAddress *address, TDate *birthday){
    this->Name = name;
    this->Address = address;
    this->Birthday = birthday;
}

TPerson::TPerson() {

}

TPerson::~TPerson(){
    //Fehlersuche
    cout << "Die Person '" << this->Name << "' wird vernichtet!" << endl;
    delete this->Address;
    delete this->Birthday;
}

void TPerson::load(ifstream &fileStream) {
    string line;
    string name;
    //TDate *birthday;
    //TAddress *address;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }

    //TPerson *person = new TPerson(name, *address, *birthday);
}


bool TPerson::readData(ifstream &fileStream, string line) {
    bool status = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Person" == tag) {
        status = true;
    } else if ("Name" == tag) {
        setName(tagContent);
        status = true;
    } else if ("Birthday" == tag) {
        TDate *birthday = new TDate();
        birthday->load(fileStream);
        setBirthday(birthday);
        status = true;
    } else if ("/Birthday" == tag) {
        status = true;
    } else if ("Address" == tag) {
        TAddress *address = new TAddress();
        address->load(fileStream);
        this->setAddress(address);
        status = true;
    } else if ("/Address" == tag) {
        status = true;
    } else if ("/Person" == tag) {
        status = false;
    }

    return status;
}

void TPerson::print(){
    // printf("%s\n%s %s\n%s %s\n* ",this->Name, this->Address->getStreet(),this->Address->getHouseNr(),this->Address->getZipcode(), this->Address->getCity()); this->Birthday->print();
    cout << this->Name << "\n" << this->Address->getStreet() << " " << this->Address->getHouseNr() << "\n" << this->Address->getZipcode() << " " << this->Address->getCity() << "\n";
    this->Birthday->print();
}


string TPerson::getName(){
    return this->Name;
}
TAddress * TPerson::getAddress(){
    return this->Address;
}
TDate * TPerson::getBirthday(){
    return this->Birthday;
}

void TPerson::setName(string name){
    this->Name = name;
}
void TPerson::setAddress(TAddress *address){
    this->Address = address;
}
void TPerson::setBirthday(TDate *birthday){
    this->Birthday = birthday;
}
