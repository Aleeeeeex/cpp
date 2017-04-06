#ifndef TDATE_H
#define TDATE_H
#include <fstream>

using namespace std;


class TDate
{
    public:
        TDate();
        TDate(short day, short month, short year);
        void print();
        void load(ifstream &fileStream);
    protected:
        bool readData(ifstream &fileStream, string line);
    private:
        short day;
        short month;
        short year;
};

#endif // TDATE_H
