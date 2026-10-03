#ifndef OOPS_PROJECT_GENRE_H
#define OOPS_PROJECT_GENRE_H
#include <iostream>
#include "./../../nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;
class Genre {
    string name;
public:

    //Default Constructor
    Genre() = default;

    //Parameterized Constructor
    Genre(const string &name);

    //Overloaded Output Operator
    friend ostream &operator<<(ostream &os, const Genre &genre);

    //getter
    string getName() const;

    //setter
    void setName(const string name);

    //display Genre Function
    void displayGenre();

    //read Genre Data from Json
    static Genre readFromJson(json &readGenre);

    //write Genre Data to Json
    json getGenreJson();
};


#endif //OOPS_PROJECT_GENRE_H
