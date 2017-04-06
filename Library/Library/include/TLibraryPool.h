#ifndef TLIBRARYPOOL_H
#define TLIBRARYPOOL_H
#include "TLibrary.h"
#include "TCustomer.h"
#include "TMedium.h"
#include "TEmployee.h"
#include "TLoan.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class TLibraryPool
{
    public:
        TLibraryPool(string name, TEmployee* chairman);
        TLibraryPool(string fname);
        ~TLibraryPool();
        void print();
        void add(TLibrary* library);
        void add(TCustomer* customer);
        void add(TLoan* loan);
        int getMediumListSize();
        friend ostream &operator<< (ostream &ostr, TLibraryPool &lp);
        TCustomer* searchCustomerNr(string customernr);
        void copyLoanToCustomer(vector<TLoan*> loanlist);
        TMedium* searchMediumSignature(string signature);
    protected:
        string readData(string line);
    private:
        string Name;
        TEmployee *Chairman;
        vector<TCustomer*> Customer;
        vector<TLibrary*> LibraryList;
        vector<TLoan*> LoanList;
};

#endif // TLIBRARYPOOL_H
