#ifndef TCUSTOMER_H
#define TCUSTOMER_H
#include <string>
#include "TPerson.h"

using namespace std;

class TCustomer : virtual public TPerson
{
    public:
        TCustomer();
        ~TCustomer();
        void load(ifstream &fileStream);
    protected:
        bool readData(ifstream &fileStream, string line);
    private:
        string CustomerNr;
};
#endif
