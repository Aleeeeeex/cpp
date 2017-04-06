#ifndef TTIME_H
#define TTIME_H
#include <string>
using namespace std;

class TTime
{
    public:
        TTime();
        TTime(short hour, short minute, short second );
        void print();
        void load(ifstream &fileStream);
    protected:
        bool readData(ifstream &fileStream, string line);
    private:
        short hour;
        short minute;
        short second;
};

#endif // TTIME_H
