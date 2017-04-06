#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "TMedium.h"
#include "TDate.h"
#include "TBook.h"
#include "TTools.h"
#include <sstream>
using namespace std;

TBook::TBook()
{
}

TBook::~TBook()
{
    cout << "Das Buch '" << Title
        << "' mit der Signatur: '" << Signature
        << "' wird vernichtet!" << endl;
}

void TBook::load(ifstream& fileStream)
{
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TBook::readData(ifstream& fileStream, string line)
{
    bool readStatus = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Book" == tag) {
        readStatus = true;
    } else if ("Author" == tag) {
        Author = tagContent;
        readStatus = true;
    } else if ("Pages" == tag) {
        istringstream(tagContent) >> Pages;
        readStatus = true;
    } else if ("/Book" == tag) {
        readStatus = false;
    } else {
        readStatus = TMedium::readData(fileStream, line);
    }

    return readStatus;
}

void TBook::print(){
    cout << "Autor:       " << Author << endl;
    cout << "Anz. Seiten: " << Pages << endl;
    cout << "Titel:       " << Title << endl;
    cout << "Signatur:    " << Signature << endl;
    cout << "Ort:         ";
    this->Location->print();
    cout << "FSK:         " << "freigegeben ab " << FSK << " Jahren" << endl;

    if (this->Status == 1)
       cout << "Status:      " << "verfuegbar" <<  "\n" << endl;
    if (this->Status == 2)
       cout << "Status:      " << "ausgeliehen" <<  "\n" << endl;
    if (this->Status == 3)
       cout << "Status:      " << "reserviert" <<  "\n" << endl;
    if (this->Status == 4)
       cout << "Status:      " << "bestellt" <<  "\n" << endl;
}

ostream &operator<<(ostream &ostr, TBook &book){
    ostr << "Autor:       " << book.Author << endl;
    ostr << "Anz. Seiten: " << book.Pages << endl;
    ostr << "Titel:       " << book.Title << endl;
    ostr << "Signatur:    " << book.Signature << endl;
    ostr << "Ort:         ";
    book.Location->print();
    ostr << "FSK:         " << "freigegeben ab " << book.FSK << " Jahren" << endl;

    if (book.Status == 1)
       ostr << "Status:      " << "verfuegbar" <<  "\n" << endl;
    if (book.Status == 2)
       ostr << "Status:      " << "ausgeliehen" <<  "\n" << endl;
    if (book.Status == 3)
       ostr << "Status:      " << "reserviert" <<  "\n" << endl;
    if (book.Status == 4)
       ostr << "Status:      " << "bestellt" <<  "\n" << endl;

    return ostr;
}
