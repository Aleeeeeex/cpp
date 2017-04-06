#ifndef TLOAN_H
#define TLOAN_H


#include "TPerson.h"
#include "TDate.h"
#include "TMedium.h"
#include <iostream>
using namespace std;

class TLoan
{
    public:
        TLoan();
        TLoan(TMedium *medium, TPerson *customer, TDate *loaddate, TDate *expiration);
        ~TLoan();
        void print();
        void load(ifstream &fileStream);
        void printDate();
        void printExpiDate();
        //friend TDate operator+ (TDate &date, const int &days);
        string customernr;
        string signature;
        TMedium* Medium;
        TPerson* Customer;
        TDate LoanDate;
        TDate Expiration;
    protected:
        bool readData(ifstream &fileStream, string line);
    private:
};

#endif // TLOAN_H
