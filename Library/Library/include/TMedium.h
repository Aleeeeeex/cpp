#ifndef TMEDIUM_H
#define TMEDIUM_H
#include "TLocation.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class TMedium
{
    public:
        static int verfuegba, ausgeliehe, bestell, reservier;
        TMedium();
        TMedium(string title, string signature, TLocation *location, int fsk, int status);
        virtual ~TMedium();
        virtual void print();
        void load(ifstream &fileStream);
        void setTitle(string title);
        string getTitle();
        void setSignature(string signature);
        virtual string getSignature();
        void setFSK(int fsk);
        virtual int getFSK();
        virtual TLocation * getLocation();
        void setLocation(TLocation *location);
        void setStatus(int status);
        static int verfuegbar(), ausgeliehen(), bestellt(), reserviert();
        friend ostream &operator<< (ostream &ostr, TMedium &medium);
        bool searchSignature(string signature);
    protected:
        bool readData(ifstream &fileStream, string line);
        string Title;
        string Signature;
        TLocation *Location;
        int FSK;
        int Status;
    private:

};

#endif // TMEDIUM_H
