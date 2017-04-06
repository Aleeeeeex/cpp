#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "TMedium.h"
#include "TDate.h"
#include "TCD.h"
#include "TTools.h"
#include <sstream>
#include <stdlib.h>

using namespace std;

TCD::TCD()
{
}

TCD::~TCD()
{
    cout << "Die CD '" << Title
        << "' mit der Signatur: '" << Signature
        << "' wird vernichtet!" << endl;
}

void TCD::load(ifstream& fileStream)
{
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TCD::readData(ifstream& fileStream, string line)
{
    bool readStatus = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("CD" == tag) {
        readStatus = true;
    } else if ("Interpret" == tag) {
        Interpret = tagContent;
        readStatus = true;
    } else if ("Tracks" == tag) {
        Tracks = atoi(tagContent.c_str());
        readStatus = true;
    } else if ("/CD" == tag) {
        readStatus = false;
    } else {
        readStatus = TMedium::readData(fileStream, line);
    }

    return readStatus;
}

void TCD::print() {

    if(this->FSK > 21)
      this->FSK = 0;

    cout << "Interpret:   " << this->Interpret << endl;
    cout << "Anz. Tracks: " << this->Tracks << endl;
    cout << "Titel:       " << Title << endl;
    cout << "Signatur:    " << Signature << endl;
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

ostream &operator<<(ostream &ostr, TCD &cd){
    ostr << "Interpret:   " << cd.Interpret << endl;
    ostr << "Anz. Tracks: " << cd.Tracks << endl;
    ostr << "Titel:       " << cd.Title << endl;
    ostr << "Signatur:    " << cd.Signature << endl;
    ostr << "Ort:         ";
    cd.Location->print();
    ostr << "FSK:         " << "freigegeben ab " << cd.FSK << " Jahren" << endl;

    if (cd.Status == 1)
        ostr << "Status:      " << "verfuegbar" <<  "\n" << endl;
    if (cd.Status == 2)
        ostr << "Status:      " << "ausgeliehen" <<  "\n" << endl;
    if (cd.Status == 3)
        ostr << "Status:      " << "reserviert" <<  "\n" << endl;
    if (cd.Status == 4)
        ostr << "Status:      " << "bestellt" <<  "\n" << endl;

    return ostr;
}
