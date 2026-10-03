#ifndef OOPS_PROJECT_TIMESLOT_H
#define OOPS_PROJECT_TIMESLOT_H
#include <iostream>
using namespace std;

#include "./../../nlohmann/json.hpp"
using json = nlohmann :: json;

class TimeSlot {
    string start;
    string end;
    bool available;

public:

    //parameterized and Default constructor
    TimeSlot(const string &start = " ", const string &end = " ", bool available = true) {
        this-> start = start;
        this-> end = end;
        this-> available = available;
    }

    //getter
    string getStart() const;

    //setter
    void setStart(const string &start);

    //getter
    string getEnd() const;

    //setter
    void setEnd(const string &end);

    //getter
    bool isAvailable() const;

    //setter
    void setAvailable(bool available);

    //display TimeSlots Func
    void displayTimeSlots();

    //json write Func
    json writeTimeSlotToJSON();

    //json Read func
    static TimeSlot readTimeSlotFromJSON(json & readTimeSlot);

};

#endif //OOPS_PROJECT_TIMESLOT_H