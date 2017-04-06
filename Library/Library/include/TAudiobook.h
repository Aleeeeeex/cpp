#ifndef TAUDIOBOOK_H
#define TAUDIOBOOK_H
#include "TBook.h"
#include "TCD.h"
#include "TMedium.h"
#include <iostream>
using namespace std;

class TAudiobook : virtual public TBook, virtual public TCD
{
    public:
        TAudiobook();
        ~TAudiobook();
        void load(ifstream &fileStream);
        void print();        friend ostream &operator<< (ostream &ostr, TAudiobook &audiobook);
    protected:
        bool readData(ifstream &fileStream, string line);
    private:
        int countCDs;

};
#endif // TAUDIOBOOK_H
