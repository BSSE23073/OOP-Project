#ifndef OOPS_PROJECT_DAY_H
#define OOPS_PROJECT_DAY_H
#include "TimeSlot.h"
#include <vector>

#include "./../../nlohmann/json.hpp"
using json = nlohmann :: json;

class Day {
    string day;
    vector <TimeSlot> timeSlot;

public:

    //Parameterized and Deafult
    Day(const string &day = " ") {
        this-> day = day;
    }

    //getter
    string getDay() const;

    //setter
    void setDay(const string &day);

    //getter
    vector<TimeSlot> getTimeSlot() const;

    //Display Details of Day with its TimeSlots
    void displayDetails();

    //Add Timeslots to Day
    void addTimeSlotsToDay(TimeSlot &timeSlot1);

    //Changing availability at a specific timeslot
    void changeAvailability(string start, string end);

    //make availability at a specific timeslot
    void makeAvailability(string start, string end);

    //write Day data to JSON
    json writeDayToJSON();

    //read Day data from JSON
    static Day readDayFromJSON(json & readDay);
};


#endif //OOPS_PROJECT_DAY_H
