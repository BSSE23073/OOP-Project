#include "Genre.h"

//Default Constructor
Genre::Genre(const string &name) : name(name) {}

//getter
string Genre::getName() const {
    return name;
}

//setter
void Genre::setName(const string name) {
    Genre::name = name;
}

//Overloaded Output Operator
ostream &operator<<(ostream &os, const Genre &genre) {
    os << genre.name;
    return os;
}

//display Genre Function
void Genre::displayGenre() {
    cout<<"\t"<<name;
}

//read Genre Data from Json
Genre Genre::readFromJson(json &readGenre) {
    Genre temp;
    temp.name = readGenre["Genre Name"];
    return temp;
}

//write Genre Data to Json
json Genre::getGenreJson() {
    json writeGenre;
    writeGenre["Genre Name"] = name;
    return writeGenre;
}
