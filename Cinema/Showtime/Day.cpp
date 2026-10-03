#include "Day.h"

//getter
string Day :: getDay() const {
    return day;
}

//setter
void Day :: setDay(const string &day1) {
    day = day1;
}

//getter
vector<TimeSlot> Day :: getTimeSlot() const {
    return timeSlot;
}

//Display Details of Day with its TimeSlots
void Day :: displayDetails() {
    cout << "Day: " << day << endl;
    cout << "TimeSlots: ";
    for (int i = 0; i < timeSlot.size(); ++i) {
        timeSlot[i].displayTimeSlots();
    }
}

//Add Timeslots to Day
void Day :: addTimeSlotsToDay(TimeSlot &timeSlot1) {
    timeSlot.push_back(timeSlot1);
}

//Changing availability at a specific timeslot
void Day :: changeAvailability(string start, string end) {
    for (int i = 0; i < timeSlot.size(); ++i) {
        if (timeSlot[i].getStart() == start && timeSlot[i].getEnd() == end) {
            timeSlot[i].setAvailable(false);
            cout << "Availability Changed" << endl;
            return;
        }
    }
    cout << "TimeSlot not Found!!" << endl;
}

//make availability at a specific timeslot
void Day :: makeAvailability(std::string start, std::string end) {
    for (int i = 0; i < timeSlot.size(); ++i) {
        if (timeSlot[i].getStart() == start && timeSlot[i].getEnd() == end) {
            timeSlot[i].setAvailable(true);
            cout << "Availability Changed" << endl;
            return;
        }
    }
    cout << "TimeSlot not Found!!" << endl;
}

//write Day data to JSON
json Day :: writeDayToJSON() {
    json dayData;
    dayData["Day"] = day;

    json timeSlotForDay;
    for (int i = 0; i < timeSlot.size(); ++i) {
        timeSlotForDay.push_back(timeSlot[i].writeTimeSlotToJSON());
    }
    dayData["TimeSlots"] = timeSlotForDay;

    return dayData;
}

//read Day data from JSON
Day Day :: readDayFromJSON(json &readDay) {
    Day dayData;
    dayData.day = readDay["Day"];
    for (int i = 0; i < readDay["TimeSlots"].size(); ++i) {
        dayData.timeSlot.push_back(TimeSlot :: readTimeSlotFromJSON(readDay["TimeSlots"][i]));
    }

    return dayData;
}
