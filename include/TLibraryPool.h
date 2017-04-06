#ifndef TLIBRARYPOOL_H
#define TLIBRARYPOOL_H
#include "TLibrary.h"
#include "TPerson.h"
#include "TCustomer.h"
#include "TEmployee.h"
#include <string>
#include <vector>
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
        void getMediumListSize();
    protected:
        string readData(string line);
    private:
        string Name;
        TEmployee *Chairman;
        vector<TCustomer*> Customer;
        vector<TLibrary*> LibraryList;
};

#endif // TLIBRARYPOOL_H
