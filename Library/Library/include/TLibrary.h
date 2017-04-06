#ifndef TLIBRARY_H
#define TLIBRARY_H
#include "TMedium.h"
#include "TAddress.h"
#include "TLoan.h"
#include <string>
#include <vector>
#include "tlist.h"

using namespace std;

class TLibrary
{
    public:
        TLibrary(string name, TAddress *address);
        TLibrary();
        ~TLibrary();

        void print();

        void add(TMedium* medium);
        void load(ifstream &fileStream);

        string getName();
        void setName(string name);
        TAddress * getAddress();
        void setAddress(TAddress *address);
        int getMediumListSize();
        TMedium * getMedium(int i);

    protected:
        bool readData(ifstream &fileStream, string line);
    private:
        string Name;
        TAddress *Address;
        TList<TMedium*> MediumList;
};

#endif // TLIBRARY_H
