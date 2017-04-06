#ifndef TLOCATION_H
#define TLOCATION_H

#include <string>
using namespace std;

class TLocation
{
    public:
        TLocation();
        TLocation(string section, string rack);
        void print();
        void load(ifstream &fileStream);
        void setSection(string section);
        void setRack(string rack);
        string getSection();
        string getRack();
    protected:
        bool readData(ifstream &fileStream, string line);
    private:
        string Section; //Abteilung
        string Rack; //Regal
};

#endif // TLOCATION_H
