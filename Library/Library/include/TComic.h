#ifndef TCOMIC_H
#define TCOMIC_H
#include "TBook.h"
#include "TMedium.h"
#include <string>
#include <iostream>

using namespace std;

class TComic : public TBook
{
    public:
        TComic();
        virtual ~TComic();
        void load(ifstream &fileStream);
        void print();
        friend ostream &operator<< (ostream &ostr, TComic &comic);
    protected:
        bool readData(ifstream &fileStream, string line);
    private:
        string Designer;
};
#endif // TCOMIC_H
