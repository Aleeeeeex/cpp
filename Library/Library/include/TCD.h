#ifndef TCD_H
#define TCD_H
#include "TMedium.h"
#include <string>
#include <iostream>
using namespace std;

class TCD : virtual public TMedium
{
    public:
        TCD();
        virtual ~TCD();
        void load(ifstream &fileStream);
        void print();
        friend ostream &operator<< (ostream &ostr, TCD &cd);
    protected:
        bool readData(ifstream &fileStream, string line);
        string Interpret;
        int Tracks;
    private:
};
#endif // TCD_H
