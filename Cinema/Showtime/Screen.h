#ifndef OOPS_PROJECT_SCREEN_H
#define OOPS_PROJECT_SCREEN_H
#include <iostream>
using namespace std;
#include "./../../nlohmann/json.hpp"

using json = nlohmann :: json;

class Screen {
    string screenName;
    string resolution;
    string size;
    string type;

public:

    //Parameterized and Default Constructor
    Screen(const string &screenName = " ", const string &resolution = " ", const string &size = " ", const string &type = " ") {
        this->screenName=screenName;
        this->resolution=resolution;
        this->type=type;
        this->size=size;
    }

    //getter
    string getScreenName() const;

    //setter
    void setScreenName(const string screenName1);

    //getter
    string getResolution() const;

    //setter
    void setResolution(const string resolution1);

    //getter
    string getSize() const;

    //setter
    void setSize(const string size1);

    //getter
    string getType() const;

    //setter
    void setType(const string type1);

    //display Screen details
    void displayScreenDetails();

    //overloaded Output Operator
    friend ostream &operator<<(ostream &os, const Screen &screen);

    //write screen Data to JSON
    json writeScreenToJSON();

    // read Screen Data from JSON
    void readScreenFromJSON(json & readScreen);
};



#endif //OOPS_PROJECT_SCREEN_H
