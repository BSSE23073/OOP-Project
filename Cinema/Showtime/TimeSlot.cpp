#include "TimeSlot.h"

//getter
string TimeSlot :: getStart() const {
    return start;
}

//setter
void TimeSlot :: setStart(const string &start1) {
    start = start1;
}

//getter
string TimeSlot :: getEnd() const {
    return end;
}

//setter
void TimeSlot :: setEnd(const string &end1) {
    end = end1;
}

//getter
bool TimeSlot :: isAvailable() const {
    return available;
}

//setter
void TimeSlot :: setAvailable(bool available1) {
    available = available1;
}

//display TimeSlot Func
void TimeSlot :: displayTimeSlots() {
    cout << "Start Time: " << start << endl
         << "End Time: " << end << endl
         << "Status: " ;
    if (available){
        cout<<"TimeSlot is Available" << endl;
    } else{
        cout<<"TimeSlot is Not Available" << endl;
    }
}

//json write Func
json TimeSlot :: writeTimeSlotToJSON() {
    json timeSlotData;
    timeSlotData["Start Time"] = start;
    timeSlotData["End Time"] = end;
    timeSlotData["Availability of TimeSlot"] = available;

    return timeSlotData;
}

//json read Func
TimeSlot TimeSlot :: readTimeSlotFromJSON(json &readTimeSlot) {
    TimeSlot timeSlotData1;
    timeSlotData1.start = readTimeSlot["Start Time"];
    timeSlotData1.end = readTimeSlot["End Time"];
    timeSlotData1.available = readTimeSlot["Availability of TimeSlot"];

    return timeSlotData1;
}
