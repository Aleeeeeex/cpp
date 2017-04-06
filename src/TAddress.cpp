#include "TAddress.h"
#include "TTools.h"
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

TAddress::TAddress(){
}

TAddress::TAddress(string street, string housenr, string zipcode, string city){
    this->Street = street;
    this->HouseNr = housenr;
    this->Zipcode = zipcode;
    this->City = city;
}

void TAddress::load(ifstream &fileStream) {
    string line;
    string street, housenr, zipcode, city;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TAddress::readData(ifstream &fileStream, string line){
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Address" == tag) {
        return true;
    } else if ("Street" == tag) {
        //printf("name found\n");
        setStreet(tagContent);
    } else if ("HouseNr" == tag) {
        setHouseNr(tagContent);
    } else if ("Zipcode" == tag) {
        setZipcode(tagContent);
    } else if ("City" == tag) {
        setCity(tagContent);
    } else if ("/Address" == tag) {
        return false;
    }

    return true;
}

void TAddress::print() {
  //  printf("%s %s\n%s %s\n", this->Street, this->HouseNr, this->Zipcode, this->City);
    cout << this->Street << " " <<this->HouseNr << "\n" << this->Zipcode << " " << this->City <<"\n" << endl;
}

void TAddress::setStreet(string street){
    this->Street = street;
}
void TAddress::setHouseNr(string housenr){
    this->HouseNr = housenr;
}
void TAddress::setZipcode(string zipcode){
    this->Zipcode = zipcode;
}
void TAddress::setCity(string city){
    this->City = city;
}

string TAddress::getStreet(){
    return this->Street;
}
string TAddress::getHouseNr(){
    return this->HouseNr;
}
string TAddress::getZipcode(){
    return this->Zipcode;
}
string TAddress::getCity(){
    return this->City;
}
