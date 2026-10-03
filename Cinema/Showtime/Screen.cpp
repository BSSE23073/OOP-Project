#include "Screen.h"

//getter
string Screen :: getScreenName() const {
    return screenName;
}

//setter
void Screen :: setScreenName(const string screenName1){
    screenName = screenName1;
}

//getter
string Screen :: getResolution() const {
    return resolution;
}

//setter
void Screen :: setResolution(const string resolution1) {
    resolution = resolution1;
}

//getter
string Screen :: getSize() const {
    return size;
}

//setter
void Screen :: setSize(const string size1) {
    size = size1;
}

//getter
string Screen :: getType() const {
    return type;
}

//setter
void Screen :: setType(const string type1) {
    type = type1;
}

//display Screen details
void Screen :: displayScreenDetails() {
    cout << "Screen - Name: " << screenName << endl
         << "Resolution: " << resolution << endl
         << "Size: " << size << endl
         << "Type: " << type << endl;
}

//overloaded Output Operator
ostream &operator << (ostream &os, const Screen &screen) {
    os << "Screen - Name: " << screen.screenName << endl
       << "Resolution: " << screen.resolution << endl
       << "Size: " << screen.size << endl
       << "Type: " << screen.type << endl;
    return os;
}

//write screen Data to JSON
json Screen :: writeScreenToJSON() {
    json screenData;
    screenData["Screen Name"] = screenName;
    screenData["Screen Resolution"] = resolution;
    screenData["Screen Size"] = size;
    screenData["Screen Type"] = type;

    return screenData;
}

// read Screen Data from JSON
void Screen :: readScreenFromJSON(json &readScreen) {
    screenName = readScreen["Screen Name"];
    resolution = readScreen["Screen Resolution"];
    size = readScreen["Screen Size"];
    type = readScreen["Screen Type"];
}
