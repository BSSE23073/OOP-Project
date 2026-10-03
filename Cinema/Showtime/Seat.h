#ifndef OOPS_PROJECT_SEAT_H
#define OOPS_PROJECT_SEAT_H
#include <iostream>
#include <ostream>
using namespace std;

#include "./../../nlohmann/json.hpp"
using json = nlohmann :: json;

class Seat {
    int seatNumber;
    string seatID;
    char row;
    string seatType;
    bool inBuildSpeaker;
public:

    //parameterized and Default Constructor
    Seat(int seatNumber = 0, const string &seatId = " ", char row = 'A', const string &seatType = " ", bool inBuildSpeaker = true){
        this->seatNumber = seatNumber;
        this->seatID = seatId;
        this->row = row;
        this->seatType = seatType;
        this->inBuildSpeaker = inBuildSpeaker;
    }

    //getter
    int getSeatNumber() const;

    //setter
    void setSeatNumber(int seatNumber);

    //getter
    string getSeatId() const;

    //setter
    void setSeatId(const string seatId);

    //getter
    char getRow() const;

    //setter
    void setRow(const char row);

    //getter
    string getSeatType() const;

    //setter
    void setSeatType(const string &seatType);

    //getter
    bool isInBuildSpeaker() const;

    //setter
    void setInBuildSpeaker(bool inBuildSpeaker);

    //Display Seat Details
    void displayDetails();

    //Overloaded output operator
    friend ostream &operator<<(ostream &os, const Seat &seat);

    //write Seats Data to JSON
    json writeSeatsToJSON();

    // read Seat Data from JSON
    void readSeatsFromJSON(json &readSeats);
};


#endif //OOPS_PROJECT_SEAT_H
