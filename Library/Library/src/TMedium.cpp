#include "TMedium.h"
#include "TLocation.h"
#include "TPerson.h"
#include "TTools.h"
#include "TLibrary.h"
#include <stdlib.h>
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
    FSK = 0;
    Status = 1;
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
    //delete Location;
    cout << "Das Medium '" << this->Title
        << "' mit der Signatur: '" << this->Signature
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
    bool readStatus = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Medium" == tag) {
        readStatus = true;
    } else if ("Title" == tag) {
        setTitle(tagContent);
        //Status = 1;
        readStatus = true;
    } else if ("Signatur" == tag) {
        setSignature(tagContent);
        readStatus = true;
    } else if ("Location" == tag) {
        TLocation *location = new TLocation();
        location->load(fileStream);
        setLocation(location);
        readStatus = true;
    } else if ("FSK" == tag) {
        //istringstream(tagContent) >> this->FSK;
        FSK = atoi(tagContent.c_str());
        readStatus = true;
        //Status = 1; //ersetzen
    } else if ("Status" == tag) {
        Status = atoi(tagContent.c_str()); //eventuell 1 setzen, damit alle statuse am anfang auf verfügbar sind
        readStatus = true;
    } else if ("/Medium" == tag) {
        readStatus = false;
    }

    return readStatus;
}
/*
* Kempfer meinte, man soll eine methode schreiben, die einen istream und einen ostream übergeben bekommt.
* Habe keinen ansatz. der ausgabeoperator wird nämlich nicht aufgerufen, sondern die print methode
*/
ostream &operator<<(ostream &ostr, TMedium &medium){
    ostr << "Titel:     " << medium.Title << endl;
    ostr << "Signatur:  " << medium.Signature << endl;
    ostr << "Ort:       ";
    medium.Location->print();
    ostr << "FSK:       " << "freigegeben ab " << medium.FSK << " Jahren" << endl;

    if (medium.Status == 1)
        ostr << "Status:      " << "verfuegbar" <<  "\n" << endl;
    if (medium.Status == 2)
        ostr << "Status:      " << "ausgeliehen" <<  "\n" << endl;
    if (medium.Status == 3)
        ostr << "Status:      " << "reserviert" <<  "\n" << endl;
    if (medium.Status == 4)
        ostr << "Status:      " << "bestellt" <<  "\n" << endl;

   // ostr << "Just a test"; //Ausgabe der print-methode übernehmen!!
    return ostr;
}

void TMedium::print(){
    cout << "Titel:     " << this->Title << endl;
    cout << "Signatur:  " << this->Signature << endl;
    cout << "Ort:       ";
    this->Location->print();
    cout << "FSK:       " << "freigegeben ab " << this->FSK << " Jahren" << endl;

    if (this->Status == 1)
        cout << "Status:      " << "verfuegbar" <<  "\n" << endl;
    if (this->Status == 2)
        cout << "Status:      " << "ausgeliehen" <<  "\n" << endl;
    if (this->Status == 3)
        cout << "Status:      " << "reserviert" <<  "\n" << endl;
    if (this->Status == 4)
        cout << "Status:      " << "bestellt" <<  "\n" << endl;
}

bool TMedium::searchSignature(string signature){
    return (this->Signature == signature);
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

void TMedium::setStatus(int status) {
    this->Status = status;
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
