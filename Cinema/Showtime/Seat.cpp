#include "Seat.h"

//getter
int Seat :: getSeatNumber() const {
    return seatNumber;
}

//setter
void Seat :: setSeatNumber(int seatNumber1) {
    seatNumber = seatNumber1;
}

//getter
string Seat :: getSeatId() const {
    return seatID;
}

//setter
void Seat :: setSeatId(const string seatId) {
    seatID = seatId;
}

//getter
char Seat :: getRow() const {
    return row;
}

//setter
void Seat :: setRow(const char row1) {
    row = row1;
}

//getter
string Seat :: getSeatType() const {
    return seatType;
}

//setter
void Seat :: setSeatType(const string &seatType1) {
    seatType = seatType1;
}

//getter
bool Seat :: isInBuildSpeaker() const {
    if (inBuildSpeaker) {
        cout << "Yes!" << endl;
    }
    else{
        cout << "No!" << endl;
    }
    return inBuildSpeaker;
}

//setter
void Seat :: setInBuildSpeaker(bool inBuildSpeaker1) {
    inBuildSpeaker = inBuildSpeaker1;
}

//Display Seat Details
void Seat :: displayDetails() {
    cout << "Seat - SeatNumber: "<< seatNumber << endl
    << "SeatID: " << seatID << endl
    << "Row: " << row << endl
    << "SeatType: " << seatType  << endl
    << "InBuildSpeaker: " << isInBuildSpeaker() << endl;
}

//Overloaded output operator
ostream &operator<<(ostream &os, const Seat &seat) {
    os  << "Seat - SeatNumber: "<< seat.seatNumber << endl
        << "SeatID: " << seat.seatID << endl
        << "Row: " << seat.row << endl
        << "SeatType: " << seat.seatType << endl
        << "InBuildSpeaker: " << seat.isInBuildSpeaker()  << endl;
    return os;
}

//write Seats Data to JSON
json Seat :: writeSeatsToJSON() {
    json seatData;
    seatData["Seat ID"] = seatID;
    seatData["InBuild Speaker"] = inBuildSpeaker;

    return seatData;
}

//read Seat Data from JSON
void Seat :: readSeatsFromJSON(json &readSeats) {
    seatID = readSeats["Seat ID"];
    inBuildSpeaker = readSeats["InBuild Speaker"];
}
