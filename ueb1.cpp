#include <iostream>

using namespace std;

#include "tdate.h"
#include "ttime.h"

int main(int argc, char const* argv[])
{
    TDate D1, D2(3, 10, 2015);
    TTime T1, T2(14, 15);

    cout << "\nKlasse TDate:" << endl;
    cout << "Standardkonstruktor Heutiges Datum (D1): ";
    D1.print(); cout << endl;

    cout << "Konstruktor    Tag der dt. Einheit (D2): ";
    D2.print(); cout << endl;

    cout << "\nKlasse TTime:" << endl;
    cout << "Standardkonstruktor Aktuelle Uhrzeit (T1): ";
    T1.print(); cout << endl;

    cout << "Konstruktor         Vorlesungsbeginn (T2): ";
    T2.print(); cout << endl;

    return 0;
}
