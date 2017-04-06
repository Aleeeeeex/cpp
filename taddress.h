#ifndef taddress_h
#define taddress_h

class TAddress {
    const char *street;
    const char *houseNR;
    const char *zipcode;
    const char *city;

    public:
        TAddress(const char *street, const char *houseNR, const char *zipcode, const char *city);
        void print();
        const char * getStreet();
        void setStreet(char *street);
        const char * getHouseNR();
        void setHouseNR(char *houseNR);
        const char * getZipcode();
        void setZipcode(char *zipcode);
        const char * getCity();
        void setCity(char *city);
};

#endif

