#ifndef OOPS_PROJECT_LOUNGE_H
#define OOPS_PROJECT_LOUNGE_H
#include "Seat.h"
#include "Screen.h"
#include "Day.h"

#include "./../../nlohmann/json.hpp"
using json = nlohmann :: json;

const int MAX = 10;

class Lounge {
protected:
    string name;
    Screen screen;
    string speakerType;
    int numOfSeats;
    int SeatsInRow;

public:
    vector <Day> day;
    Seat **seats;

    //Default Constructor
    Lounge(){
        name = " ";
        speakerType = " ";
        numOfSeats = 0;
    }

    //Parameterized Constructor
    Lounge(const string &name , const string &speakerType, int numOfSeats) {
        this->name = name;
        this->speakerType = speakerType;
        this->numOfSeats = numOfSeats;
        SeatsInRow = this->numOfSeats / MAX;
        seats = new Seat *[MAX];
        for (int i = 0; i < MAX; ++i) {
            seats[i] = new Seat[SeatsInRow];
        }
        generateSeats();
        generateDays();
    }

    // Copy constructor.
    Lounge(const Lounge& other);

    // Getter.
    int getSeatsInRow() const;

    // Setter.
    void setSeatsInRow(int seatsInRow);

    // Getter.
    string getName() const;

    // Setter.
    void setName(const string name);

    // Getter.
    Screen getScreen() const;

    // Setter.
    void setScreen(const Screen screen);

    // Getter.
    string getSpeakerType() const;

    // Setter.
    void setSpeakerType(const string speakerType);

    // Getter.
    int getNumOfSeats() const;

    // Adds a screen to the lounge setup.
    void addScreen(Screen &screen1);

    // Displays details about the lounge.
    void displayLoungeDetails();

    // Generates scheduling days for the lounge.
    void generateDays();

    // Generates seat layout for the lounge.
    void generateSeats();

    // Adds a time slot to a specific day.
    void addTimeSlotToDay(string &day);

    // Changes the availability of the lounge at a specific time slot on a specific day.
    void changeAvailabilityOfLoungeAtTimeSlotOfADay(string &day2, TimeSlot t1);

    // Sets the lounge as available for a specific time slot on a specific day.
    void makeAvailabilityOfLoungeAtTimeSlotOfADay(string &day2, TimeSlot t1);

    // Displays scheduling details of the lounge.
    void schedulingDetailsOfLounge();

    // Generates seats based on data read from a file.
    void generateSeatsAfterFileReading();

    // Checks and updates the seat status based on the speaker type.
    void checkSeatStatusForSpeaker(Seat &seats);

    // write lounge data to a JSON.
    json writeLoungeToJSON();

    // read JSON data of Lounge.
    static Lounge readLoungeFromJSON(json &readLounge);

    // Writes lounge data to JSON for showtime.
    json writeLoungeToJSONForShowtime();

    // Reads lounge data from JSON for showtime.
    void readLoungeFromJSONForShowTime(json &readLounge);

    //Destructor
    ~Lounge(){
        for (int i = 0; i < MAX; ++i) {
            delete []seats[i] ;
        }
        delete[] seats;
    }
};


#endif //OOPS_PROJECT_LOUNGE_H
