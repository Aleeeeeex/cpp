#include "TMedium.h"
#include "TLocation.h"
#include "TPerson.h"
#include "TTools.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int TMedium::verfuegba       =  1;
int TMedium::ausgeliehe      =  2;
int TMedium::bestell         =  3;
int TMedium::reservier       =  4;

TMedium::TMedium(){
}

TMedium::TMedium(string title, string signature, TLocation *location, int fsk, int status){
    this->Title = title;
    this->Signature = signature;
    this->Location = location;
    this->FSK = fsk;
    this->Status = status;
}

TMedium::~TMedium(){
    // Fehlersuche
    cout << "Das Medium '" << this->Title
        << "'' mit der Signatur: '" << this->Signature
        << "' wird vernichtet!" << endl;
}

void TMedium::load(ifstream &fileStream) {
    string line;
    string title, signatur;
    //int fsk, status; //TODO status korrekt
    //TLocation *location;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TMedium::readData(ifstream &fileStream, string line) {
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Medium" == tag) {
        return true;
    } else if ("Title" == tag) {
        setTitle(tagContent);
    } else if ("Signatur" == tag) {
        setSignature(tagContent);
    }  else if ("Location" == tag) {
        TLocation *location = new TLocation();
        location->load(fileStream);
        setLocation(location);
    }  else if ("FSK" == tag) {
        istringstream(tagContent) >> this->FSK;
    }   else if ("status" == tag) {
        istringstream(tagContent) >> this->Status;
    } else if ("/Medium" == tag) {
        return false;
    }

    return true;
}

void TMedium::print(){
    cout << "Titel:     " << this->Title << endl;
    cout << "Signatur:  " << this->Signature << endl;
    cout << "Ort:       ";
    this->Location->print();
    cout << "FSK:       " << "freigegeben ab " << this->FSK << " Jahren" << endl;

    if (this->Status == 1)
       cout << "Status:    " << "verfuegbar" <<  "\n" << endl;
    if (this->Status == 2)
       cout << "Status:    " << "ausgeliehen" <<  "\n" << endl;
    if (this->Status == 3)
       cout << "Status:    " << "reserviert" <<  "\n" << endl;
    if (this->Status == 4)
       cout << "Status:    " << "bestellt" <<  "\n" << endl;
}

void TMedium::setTitle(string title){
    this->Title = title;
}

string TMedium::getTitle(){
    return this->Title;
}

void TMedium::setSignature(string signature){
    this->Signature = signature;
}

string TMedium::getSignature(){
    return Signature;
}

void TMedium::setFSK(int fsk){
    this->FSK = fsk;
}

int TMedium::getFSK(){
    return FSK;
}

TLocation * TMedium::getLocation(){
    return this->Location;
}

void TMedium::setLocation(TLocation *location){
    this->Location = location;
}

int TMedium::verfuegbar()
{
   return verfuegba;
}
int TMedium::ausgeliehen()
{
   return ausgeliehe;
}
int TMedium::bestellt()
{
   return bestell;
}
int TMedium::reserviert()
{
   return reservier;
}
