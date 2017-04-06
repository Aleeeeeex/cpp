#ifndef tdate_h
#define tdate_h

class TDate {
    short day;
    short month;
    short year;

    public:
        TDate();
        TDate(short day, short month, short year);
        void print();
};

#endif
