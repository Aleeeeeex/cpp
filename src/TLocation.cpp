#include "TLocation.h"
#include "TTools.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
using namespace std;

TLocation::TLocation()
{
    this->Section = "Büro";
    this->Rack = "Fach rum Einsortieren";
}

TLocation::TLocation(string section, string rack){
    this->Section = section;
    this->Rack = rack;
}

void TLocation::print() {
    cout << "Abt.: " << this->Section << "; Regal: " << this->Rack << endl;
}

TLocation * TLocation::load(ifstream &fileStream) {
    string line, tag, tagContent;
    string section, rack;

    while (getline(fileStream, line)) {
        GETTAG(line, tag, tagContent);

        if ("Location" == tag) {
            continue;
        } else if ("Section" == tag) {
            section = tagContent;
        } else if ("Rack" == tag) {
            rack = tagContent;
        } else if ("/Location" == tag) {
            break;
        }
    }

    TLocation *location = new TLocation(section, rack);
    return location;
}

void TLocation::setSection(string section){
    this->Section = section;
}
string TLocation::getSection(){
    return this->Section;
}
void TLocation::setRack(string rack){
    this->Rack = rack;
}
string TLocation::getRack(){
    return this->Rack;
}
