#include "TAddress.h"
#include "TLibrary.h"
#include "TMedium.h"
#include "TAddress.h"
#include "TBook.h"
#include "TComic.h"
#include "TDVD.h"
#include "TCD.h"
#include "TAudiobook.h"
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

    for (TList<TMedium*>::Iterator it = MediumList.begin(); it != MediumList.end(); it++) {
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
    }  else if ("Book" == tag) {
        TBook *book = new TBook();
        book->load(fileStream);
        add(book);
    }  else if ("Comic" == tag) {
        TComic *comic = new TComic();
        comic->load(fileStream);
        add(comic);
    }  else if ("DVD" == tag) {
        TDVD *dvd = new TDVD();
        dvd->load(fileStream);
        add(dvd);
    }  else if ("CD" == tag) {
        TCD *cd = new TCD();
        cd->load(fileStream);
        add(cd);
    }  else if ("Audiobook" == tag) {
        TAudiobook *audiobook = new TAudiobook();
        audiobook->load(fileStream);
        add(audiobook);
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
    int count = 0;
    TList<TMedium*>::Iterator it = MediumList.begin();
    while (it != MediumList.end()) {
        if (count == i) {
            return *it;
        }
        count++;
        it++;
    }
    //for (TList<TMedium*>::Iterator it = MediumList.begin();
    //        count < MediumList.size(); it++) {
    //    if (count == i) {
    //        return *it;
    //    }
    //    count++;
    //}

    return NULL;
    //return this->MediumList.at(i);
}


