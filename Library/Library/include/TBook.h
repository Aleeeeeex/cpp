#ifndef TBOOK_H
#define TBOOK_H
#include <string>
#include "TMedium.h"
#include <iostream>
using namespace std;

class TBook : virtual public TMedium
{
    public:
        TBook();
        virtual ~TBook();
        void load(ifstream &fileStream);
        virtual void print();
        friend ostream &operator<< (ostream &ostr, TBook &book);
    protected:
        bool readData(ifstream &fileStream, string line);
        string Author;
        int Pages;
    private:
};
#endif // TBOOK_H
