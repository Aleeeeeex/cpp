#ifndef TDATE_H
#define TDATE_H
#include <fstream>
#include <ostream>
using namespace std;


class TDate
{
    public:
        TDate();
        TDate(short day, short month, short year);
        void print();
        void load(ifstream &fileStream);
        friend TDate operator+ (TDate date, int days);
        short day;
        short month;
        short year;
    protected:
        bool readData(ifstream &fileStream, string line);

    private:

};

#endif // TDATE_H
