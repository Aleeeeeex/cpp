#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "tlocation.h"

using namespace std;

TLocation::TLocation() {
    this->section = "Buero";
    this->rack = "Fach zum Einsortieren";
}

TLocation::TLocation(const char *section, const char *rack) {
    this->section = section;
    this->rack = rack;
}

void TLocation::print() {
    printf("Abt: %s; Regal:  %s\n",
            this->section, this->rack);
}

const char * TLocation::getSection() {
    return this->section;
}

void TLocation::setSection(char *section) {
    this->section = section;
}

const char * TLocation::getRack() {
    return this->rack;
}

void TLocation::setRack(char *rack) {
    this->rack = rack;
}

