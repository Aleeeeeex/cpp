#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "TBook.h"
#include "TMedium.h"
#include "TComic.h"
#include "TDate.h"
#include "TTools.h"
#include <sstream>
using namespace std;

TComic::TComic()
{
}

TComic::~TComic()
{
    cout << "Das Comic '" << Title
        << "' mit der Signatur: '" << Signature
        << "' wird vernichtet!" << endl;
}

void TComic::load(ifstream& fileStream)
{
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TComic::readData(ifstream& fileStream, string line)
{
    bool readStatus = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Comic" == tag) {
        readStatus = true;
    } else if ("Designer" == tag) {
        Designer = tagContent;
        readStatus = true;
    } else if ("/Comic" == tag) {
        readStatus = false;
    } else {
        readStatus = TBook::readData(fileStream, line);
    }

    return readStatus;
}

void TComic::print() {
    cout << "Designer:    " << Designer << endl;
    cout << "Author:      " << Author << endl;
    cout << "Anz. Seiten: " << Pages << endl;
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

ostream &operator<<(ostream &ostr, TComic &comic){
    ostr << "Designer:    " << comic.Designer << endl;
    ostr << "Author:      " << comic.Author << endl;
    ostr << "Anz. Seiten: " << comic.Pages << endl;
    ostr << "Titel:       " << comic.Title << endl;
    ostr << "Signatur:    " << comic.Signature << endl;
    ostr << "Ort:         ";
    comic.Location->print();
    ostr << "FSK:         " << "freigegeben ab " << comic.FSK << " Jahren" << endl;

    if (comic.Status == 1)
       ostr << "Status:      " << "verfuegbar" <<  "\n" << endl;
    if (comic.Status == 2)
       ostr << "Status:      " << "ausgeliehen" <<  "\n" << endl;
    if (comic.Status == 3)
       ostr << "Status:      " << "reserviert" <<  "\n" << endl;
    if (comic.Status == 4)
       ostr << "Status:      " << "bestellt" <<  "\n" << endl;

    return ostr;

}
