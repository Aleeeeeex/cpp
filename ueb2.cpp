#include <iostream>

using namespace std;

#include "TAddress.h"
#include "TDate.h"
#include "TLocation.h"
#include "TPerson.h"
#include "TTime.h"

int main()
{
    TLocation L1, L2("Technik", "Computer"); // Technik-Abteilung im Computer-Regal
    TDate Geburtstag(17, 11, 1984);
    TAddress A1("Luxemburger Str.", "10", "D-13351", "Berlin");
    TAddress Adresse("Berliner Str.", "21-23", "10876", "Berlin");
    TPerson Egon("Egon Mustermann", Adresse, Geburtstag);

    cout << "\nKlasse TLocation:" << endl;
    cout << "Standardkonstruktor fuer neue Buecher: "; L1.print(); cout << endl;
    cout << "Konstruktor Technik-Abt., Computer-Regal: "; L2.print(); cout << endl;

    cout << "\nKlasse TAddress:" << endl;
    cout << "Konstruktor Adresse der Beuth Hochschule:\n"; A1.print(); cout << endl;

    cout << "\nKlasse TPerson:" << endl;
    cout << "Konstruktor Egon Mustermann:\n"; Egon.print(); cout << endl;

    return 0;
}
