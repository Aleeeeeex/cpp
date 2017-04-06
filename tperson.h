#ifndef tperson_h
#define tperson_h

#include "taddress.h"
#include "tdate.h"

class TPerson {
    const char *name;
    TAddress *address;
    TDate *birthday;

    public:
        TPerson(const char *name, TAddress &Address, TDate &Birthday);
        void print();
        const char * getName();
        void setName(char *name);
        TAddress * getAddress();
        void setAddress(TAddress &Address);
        TDate * getBirthday();
        void setBirthday(TDate &Birthday);
};

#endif



