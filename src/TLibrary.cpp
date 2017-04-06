#include "TAddress.h"
#include "TLibrary.h"
#include "TMedium.h"
#include "TAddress.h"
#include "TTools.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

TLibrary::TLibrary(string name, TAddress *address){
    this->Name = name;
    this->Address = address;
}

TLibrary::TLibrary() {
}

TLibrary::~TLibrary(){
    //Fehlersuche
    //cout << this->Name << " wird vernichtet!" << endl;

    for (vector<TMedium*>::iterator it = MediumList.begin(); it < MediumList.end(); it++) {
        delete *it;
    }
    delete this->Address;
}


void TLibrary::load(ifstream &fileStream) {
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TLibrary::readData(ifstream &fileStream, string line) {
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Library" == tag) {
        return true;
    } else if ("Name" == tag) {
        setName(tagContent);
    } else if ("Address" == tag) {
        TAddress *address = new TAddress();
        address->load(fileStream);
        setAddress(address);
    }  else if ("Medium" == tag) {
        TMedium *medium = new TMedium();
        medium->load(fileStream);
        add(medium);
    } else if ("/Library" == tag) {
        return false;
    }
    return true;
}

void TLibrary::print(){
    cout << "Buecherei Filiale " << this->Name << endl;
    this->Address->print();
}

void TLibrary::add(TMedium* medium){
    this->MediumList.push_back(medium);
}

string TLibrary::getName(){
    return this->Name;
}

void TLibrary::setName(string name){
    this->Name = name;
}

TAddress * TLibrary::getAddress(){
    return this->Address;
}

void TLibrary::setAddress(TAddress *address){
    this->Address = address;
}
int TLibrary::getMediumListSize(){
    return this->MediumList.size();
}

TMedium * TLibrary::getMedium(int i){
    return this->MediumList.at(i);
}


