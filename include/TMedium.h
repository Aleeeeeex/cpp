#ifndef TMEDIUM_H
#define TMEDIUM_H
#include "TLocation.h"
#include <string>
#include <vector>

using namespace std;


class TMedium
{
    public:
        static int verfuegba, ausgeliehe, bestell, reservier;
        TMedium();
        TMedium(string title, string signature, TLocation *location, int fsk, int status);
        ~TMedium();
        void print();
        void load(ifstream &fileStream);
        void setTitle(string title);
        string getTitle();
        void setSignature(string signature);
        string getSignature();
        void setFSK(int fsk);
        int getFSK();
        TLocation * getLocation();
        void setLocation(TLocation *location);
        static int verfuegbar(), ausgeliehen(), bestellt(), reserviert();
    protected:
        bool readData(ifstream &fileStream, string line);
    private:
        string Title;
        string Signature;
        TLocation *Location;
        int FSK;
        int Status;

};

#endif // TMEDIUM_H
