#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "tperson.h"
#include "taddress.h"
#include "tdate.h"

using namespace std;

TPerson::TPerson(const char *name, TAddress &Address, TDate &Birthday) {
    this->name = name;
    this->address = &Address;
    this->birthday = &Birthday;
}

void TPerson::print() {
    printf("%s\n%s %s\n%s %s\n* ",
            this->name,
            this->address->getStreet(),
            this->address->getHouseNR(),
            this->address->getZipcode(),
            this->address->getCity());
    this->birthday->print();
}

const char * TPerson::getName() {
    return this->name;
}

void TPerson::setName(char *name) {
    this->name = name;
}

TAddress * TPerson::getAddress() {
    return this->address;
}

void TPerson::setAddress(TAddress &Address) {
    this->address = &Address;
}

TDate * TPerson::getBirthday() {
    return this->birthday;
}

void TPerson::setBirthday(TDate &Birthday) {
    this->birthday = &Birthday;
}
