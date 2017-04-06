#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "TBook.h"
#include "TCD.h"
#include "TMedium.h"
#include "TTools.h"
#include "TAudiobook.h"
#include <string.h>
#include <stdlib.h>
#include <sstream>


using namespace std;

TAudiobook::TAudiobook()
{
}

TAudiobook::~TAudiobook()
{
    cout << "Das Audiobuch '" << Title
        << "' mit der Signatur: '" << Signature
        << "' wird vernichtet!" << endl;
}

void TAudiobook::load(ifstream& fileStream)
{
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TAudiobook::readData(ifstream& fileStream, string line)
{
    bool readStatus = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Audiobook" == tag) {
        readStatus = true;
    } else if ("countCDs" == tag) {
        istringstream(tagContent) >> countCDs;
        readStatus = true;
    } else if ("/Audiobook" == tag) {
        readStatus = false;
    } else {
        readStatus = TBook::readData(fileStream, line);
        if (readStatus == false) {
            readStatus = TCD::readData(fileStream, line);
        }
    }
    return readStatus;
}

void TAudiobook::print(){
    cout << "Interpret:   " << Interpret << endl;
    cout << "Anz. Tracks: " << Tracks << endl;
    cout << "Anz. CDs:    " << countCDs << endl;
    cout << "Author:      " << Author << endl;
    cout << "Anz. Seiten: " << Pages << endl;
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

ostream &operator<<(ostream &ostr, TAudiobook &audiobook){
    ostr << "Interpret:   " << audiobook.Interpret << endl;
    ostr << "Anz. Tracks: " << audiobook.Tracks << endl;
    ostr << "Anz. CDs:    " << audiobook.countCDs << endl;
    ostr << "Author:      " << audiobook.Author << endl;
    ostr << "Anz. Seiten: " << audiobook.Pages << endl;
    ostr << "Titel:       " << audiobook.Title << endl;
    ostr << "Signatur:    " << audiobook.Signature << endl;
    ostr << "Ort:         ";
    audiobook.Location->print();
    ostr << "FSK:         " << "freigegeben ab " << audiobook.FSK << " Jahren" << endl;

    if (audiobook.Status == 1)
       ostr << "Status:      " << "verfuegbar" <<  "\n" << endl;
    if (audiobook.Status == 2)
       ostr << "Status:      " << "ausgeliehen" <<  "\n" << endl;
    if (audiobook.Status == 3)
       ostr << "Status:      " << "reserviert" <<  "\n" << endl;
    if (audiobook.Status == 4)
       ostr << "Status:      " << "bestellt" <<  "\n" << endl;

    return ostr;
}
