#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "TMedium.h"
#include "TDVD.h"
#include "TTools.h"
#include "TTime.h"
using namespace std;

TDVD::TDVD()
{
}

TDVD::~TDVD()
{
    delete PlayingTime;
    cout << "Die DVD '" << Title
        << "' mit der Signatur: '" << Signature
        << "' wird vernichtet!" << endl;
}

void TDVD::load(ifstream& fileStream)
{
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TDVD::readData(ifstream& fileStream, string line)
{
    bool readStatus = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("DVD" == tag) {
        readStatus = true;
    } else if ("Actors" == tag) {
        this->Actors = tagContent;
        readStatus = true;
    } else if ("PlayingTime" == tag) {
       TTime *playTime = new TTime();
       playTime->load(fileStream);
       PlayingTime = playTime;
       readStatus = true;
    } else if ("/PlayingTime" == tag) {
        readStatus = true;
    } else if ("/DVD" == tag) {
        readStatus = false;
    } else {
        readStatus = TMedium::readData(fileStream, line);
    }

    return readStatus;
}

void TDVD::print(){
    cout << "Schauspieler:" << Actors << endl;
    cout << "Spieldauer:  ";
    PlayingTime->print();
    cout << "Titel:       " << Title << endl;
    cout << "Signatur:    " << this->Signature << endl;
    cout << "Ort:         ";
    this->Location->print();
    cout << "FSK:         " << "freigegeben ab " << this->FSK << " Jahren" << endl;

    if (this->Status == 1)
       cout << "Status:      " << "verfuegbar" <<  "\n" << endl;
    if (this->Status == 2)
       cout << "Status:      " << "ausgeliehen" <<  "\n" << endl;
    if (this->Status == 3)
       cout << "Status:      " << "reserviert" <<  "\n" << endl;
    if (this->Status == 4)
       cout << "Status:      " << "bestellt" <<  "\n" << endl;
}

ostream &operator<<(ostream &ostr, TDVD &dvd){
    ostr << "Schauspieler:" << dvd.Actors << endl;
    ostr << "Spieldauer:  ";
    dvd.PlayingTime->print();
    ostr << "Titel:       " << dvd.Title << endl;
    ostr << "Signatur:    " << dvd.Signature << endl;
    ostr << "Ort:         ";
    dvd.Location->print();
    ostr << "FSK:         " << "freigegeben ab " << dvd.FSK << " Jahren" << endl;

    if (dvd.Status == 1)
       ostr << "Status:      " << "verfuegbar" <<  "\n" << endl;
    if (dvd.Status == 2)
       ostr << "Status:      " << "ausgeliehen" <<  "\n" << endl;
    if (dvd.Status == 3)
       ostr << "Status:      " << "reserviert" <<  "\n" << endl;
    if (dvd.Status == 4)
       ostr << "Status:      " << "bestellt" <<  "\n" << endl;

    return ostr;
}
