#ifndef TADDRESS_H
#define TADDRESS_H

#include <string>
using namespace std;

class TAddress
{
    public:
        TAddress();
        TAddress(string street,string housenr,string zipcode,string city);
        void print();
        void setStreet(string street);
        void setHouseNr(string housenr);
        void setZipcode(string zipcode);
        void setCity(string city);
        void load(ifstream &fileStream);
        string getStreet();
        string getHouseNr();
        string getZipcode();
        string getCity();
    protected:
        bool readData(ifstream &fileStream, string line);
        string Street;
        string HouseNr;
        string Zipcode;
        string City;
    private:
};

#endif // TADDRESS_H
