#ifndef TTIME_H
#define TTIME_H


class TTime
{
    public:
        TTime();
        TTime(short hour, short minute, short second = 0);
        void print();
    protected:
    private:
        short hour;
        short minute;
        short second;
};

#endif // TTIME_H
