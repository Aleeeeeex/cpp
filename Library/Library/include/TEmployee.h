#ifndef TEMPLOYEE_H
#define TEMPLOYEE_H
#include <string>
#include "TPerson.h"
#include "TCustomer.h"

using namespace std;

class TEmployee : virtual public TCustomer, virtual public TPerson
{
    public:
        TEmployee();
        ~TEmployee();
        void load(ifstream &fileStream);
        void print();
    protected:
        bool readData(ifstream &fileStream, string line);
    private:
        string EmployeeNr;
};
#endif

