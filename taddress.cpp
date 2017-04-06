#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "taddress.h"

using namespace std;

TAddress::TAddress(const char *street, const char *houseNR, const char *zipcode, const char *city) {
    this->street = street;
    this->houseNR = houseNR;
    this->zipcode = zipcode;
    this->city = city;
}

void TAddress::print() {
    printf("%s %s\n%s %s\n",
            this->street, this->houseNR, this->zipcode, this->city);
    /* cout << setiosflags(ios::fixed) << setprecision(2)
        << this->day << "." << this->month << "." << this->year << "\n"; */
}

const char * TAddress::getStreet() {
    return this->street;
}

void TAddress::setStreet(char *street) {
    this->street = street;
}

const char * TAddress::getHouseNR() {
    return this->houseNR;
}

void TAddress::setHouseNR(char *houseNR) {
    this->houseNR = houseNR;
}

const char * TAddress::getZipcode() {
    return this->zipcode;
}
void TAddress::setZipcode(char *zipcode) {
    this->zipcode = zipcode;
}
const char * TAddress::getCity() {
    return this->city;
}

void TAddress::setCity(char *city) {
    this->city = city;
}
