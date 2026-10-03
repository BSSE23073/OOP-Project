#ifndef OOPS_PROJECT_CAST_H
#define OOPS_PROJECT_CAST_H
#include <ostream>
#include "Person.h"
#include "./../../nlohmann/json.hpp"
using json = nlohmann::json;
class Cast : public Person {
    string role;
    string nationality;
public:

    //Default Constructor
    Cast() : Person() {
        role = " ";
        nationality = " ";
    }

    //Parameterized Constructor
    Cast(string name, string gender, int age, string role, string nationality) : Person(name, gender, age) {
        this->role = role;
        this->nationality = nationality;
    }

    //read Cast data from json
    static Cast readCastfromJson(json &readCast);

    //getter
    string getRole() const;

    //setter
    void setRole(const string role);

    //getter
    string getNationality() const;

    //setter
    void setNationality(const string nationality);

    //display cast Function
    void displayCast();

    //write Cast data to json
    json getCastJson();

    //Overload output Operator
    friend ostream &operator<<(ostream &os, const Cast &cast) {
        os << "Name: " << cast.getName() << " Gender: " << cast.getGender() << " Age: " << cast.getAge() << " Role: "
           << cast.role << " Nationality: " << cast.nationality << "\n";
        return os;
    }
};


#endif //OOPS_PROJECT_CAST_H
