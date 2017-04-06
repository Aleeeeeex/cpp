#ifndef TPERSON_H
#define TPERSON_H
#include "TAddress.h"
#include "TDate.h"
#include <string>
using namespace std;
class TPerson {
    public:
        TPerson();
        ~TPerson();
        TPerson(string name, TAddress *address, TDate *birthday);
        void print();
        void setName(string name);
        string getName();
        TAddress * getAddress();
        void setAddress(TAddress *address);
        TDate * getBirthday();
        void setBirthday(TDate *birthday);
        void load(ifstream &fileStream);

    protected:
        bool readData(ifstream &fileStream, string line);
        string Name;
        TAddress *Address;
        TDate *Birthday;
    private:

};

#endif // TPERSON_H


