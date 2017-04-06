#ifndef TDVD_H
#define TDVD_H
#include <iostream>
#include <string>

using namespace std;

#include "TTime.h"
#include "TMedium.h"

class TDVD : virtual public TMedium
{
    public:
        TDVD();
        virtual ~TDVD();
        void load(ifstream &fileStream);
        void print();
        friend ostream &operator<< (ostream &ostr, TDVD &dvd);
    protected:
        bool readData(ifstream &fileStream, string line);
    private:
        string Actors;
        TTime *PlayingTime;
};
#endif // TDVD_H
