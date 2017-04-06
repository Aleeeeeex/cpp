#ifndef TCUSTOMER_H
#define TCUSTOMER_H
#include <string>
#include "TPerson.h"
#include "TLoan.h"
#include <vector>
#include <iostream>

using namespace std;

class TCustomer : virtual public TPerson
{
    public:
        TCustomer();
        ~TCustomer();
        void load(ifstream &fileStream);
        void print();
        void add(TLoan* loan);
        void printName();
        bool searchNr(string nr);
        int getLoanListSize();
        string CustomerNr;
        vector<TLoan*> LoanList;

    protected:
        bool readData(ifstream &fileStream, string line);



    private:
};
#endif
