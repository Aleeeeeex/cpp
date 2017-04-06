#ifndef ttime_h
#define ttime_h

class TTime {
    short hour;
    short minute;
    short second;

    public:
        TTime();
        TTime(short hour, short minute=0, short second=0);
        void print();
};

#endif
