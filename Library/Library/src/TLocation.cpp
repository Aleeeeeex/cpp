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

void TLocation::load(ifstream& fileStream)
{
    string line;

    while (getline(fileStream, line)) {
        if (! readData(fileStream, line)) {
            break;
        }
    }
}

bool TLocation::readData(ifstream& fileStream, string line) {
    bool readStatus = false;
    string tag, tagContent;
    GETTAG(line, tag, tagContent);

    if ("Location" == tag) {
        readStatus = true;
    } else if ("Section" == tag) {
        Section = tagContent;
        readStatus = true;
    } else if ("Rack" == tag) {
        Rack = tagContent;
        readStatus = true;
    } else if ("/Location" == tag) {
        readStatus = false;
    }

    return readStatus;
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
