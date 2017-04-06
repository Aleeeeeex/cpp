#ifndef tlocation_h
#define tlocation_h

class TLocation {
    const char *section;
    const char *rack;

    public:
        TLocation();
        TLocation(const char *section, const char *rack);
        void print();
        const char * getSection();
        void setSection(char *section);
        const char * getRack();
        void setRack(char *rack);

};

#endif


