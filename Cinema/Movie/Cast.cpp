#include "Cast.h"

//getter
string Cast::getRole() const {
    return role;
}

//setter
void Cast::setRole(const string role) {
    this->role = role;
}

//getter
string Cast::getNationality() const {
    return nationality;
}

//setter
void Cast::setNationality(const string nationality) {
    this->nationality = nationality;
}

//display cast Function
void Cast::displayCast() {
    cout<<"Name: " << this->getName() << " Gender: " << this->getGender() << " Age: " << this->getAge() << " Role: "
                      << this->role << " Nationality: " << this->nationality << "\n";
}

//read Cast data from json
Cast Cast::readCastfromJson(json &readCast) {
    Cast temp;
    temp.setName(readCast["Name"]);
    temp.setGender(readCast["Gender"]);
    temp.setAge(readCast["Age"]);
    temp.role = readCast["Role"];
    temp.nationality = readCast["Nationality"];
    return temp;
}

//write Cast data to json
json Cast::getCastJson() {
    json castData;
    castData["Name"] = getName();
    castData["Gender"] = getGender();
    castData["Age"] = getAge();
    castData["Role"] = role;
    castData["Nationality"] = nationality;
    return castData;
}
