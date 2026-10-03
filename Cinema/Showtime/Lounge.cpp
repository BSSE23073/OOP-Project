#include "Lounge.h"

// Getter.
string Lounge :: getName() const {
    return name;
}

// Setter.
void Lounge :: setName(const string name1) {
    name = name1;
}

// Getter.
string Lounge :: getSpeakerType() const {
    return speakerType;
}

// Setter.
void Lounge :: setSpeakerType(const string speakerType1) {
    speakerType = speakerType1;
}

// Generates seat layout for the lounge.
void Lounge :: generateSeats() {
    char A = 'A';
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < SeatsInRow; ++j) {
            seats[i][j].setRow(A);
            seats[i][j].setSeatNumber(j+1);
            string seat_id (1 ,seats[i][j].getRow());
            seat_id += to_string(seats[i][j].getSeatNumber());
            seats[i][j].setSeatId(seat_id);
            if (name=="VIP"||name=="Platinum"){
                seats[i][j].setSeatType("Luxury");
            }
            else{
                seats[i][j].setSeatType("Normal");
            }
        }
        A++;
    }
}

// Getter.
Screen Lounge :: getScreen() const {
    return screen;
}

// Setter.
void Lounge :: setScreen(const Screen screen1) {
    screen = screen1;
}

// Adds a screen to the lounge setup.
void Lounge :: addScreen(Screen &screen1) {
    screen = screen1;
}

// Displays details about the lounge.
void Lounge :: displayLoungeDetails() {
    cout << "Lounge details: Name " << name << endl;
    screen.displayScreenDetails();
    cout << "Speaker Type: " << speakerType << endl
         << "Number of Seats in Lounge: " << numOfSeats << endl
         << "Number of Rows: 10" << endl;
}

// Getter.
int Lounge :: getNumOfSeats() const {
    return numOfSeats;
}

// Getter.
int Lounge :: getSeatsInRow() const {
    return SeatsInRow;
}

// Setter.
void Lounge :: setSeatsInRow(int seatsInRow) {
    SeatsInRow = seatsInRow;
}

// Generates scheduling days for the lounge.
void Lounge :: generateDays() {
    Day day1("Monday");Day day2("Tuesday"); Day day3("Wednesday");
    Day day4("Thursday"); Day day5("Friday");Day day6("Saturday");
    Day day7("Sunday");
    day.push_back(day1);
    day.push_back(day2);
    day.push_back(day3);
    day.push_back(day4);
    day.push_back(day5);
    day.push_back(day6);
    day.push_back(day7);
}

// Adds a time slot to a specific day.
void Lounge :: addTimeSlotToDay(string &day1) {
    string time1, time2;
    for (int i = 0; i < day.size(); ++i) {
        if(day[i].getDay() == day1){
            cout << "Enter Start time: ";
            cin >> time1;
            cout << "Enter End Time: ";
            cin >> time2;
            TimeSlot timeSlot(time1,time2);
            day[i].addTimeSlotsToDay(timeSlot);
            return;
        }
    }
    cout << "Day not Found" << endl;
}

// Changes the availability of the lounge at a specific time slot on a specific day.
void Lounge :: changeAvailabilityOfLoungeAtTimeSlotOfADay(string &day2,TimeSlot t1) {

    for (int i = 0; i < day.size(); ++i) {
        if (day[i].getDay() == day2) {
            day[i].changeAvailability(t1.getStart(), t1.getEnd());
            return;
        }
    }
    cout << "Day not Found" << endl;
}

// Sets the lounge as available for a specific time slot on a specific day.
void Lounge :: makeAvailabilityOfLoungeAtTimeSlotOfADay(std::string &day2,TimeSlot t1) {
    for (int i = 0; i < day.size(); ++i) {
        if (day[i].getDay() == day2) {
            day[i].makeAvailability(t1.getStart(), t1.getEnd());
            return;
        }
    }
    cout << "Day Not Found" << endl;
}

// Displays scheduling details of the lounge.
void Lounge :: schedulingDetailsOfLounge() {
    for (int i = 0; i < day.size(); ++i) {
        day[i].displayDetails();
    }
}

// Copy constructor.
Lounge :: Lounge(const Lounge &other) {
    name = other.name;
    screen = other.screen;
    speakerType = other.speakerType;
    numOfSeats = other.numOfSeats;
    SeatsInRow = other.SeatsInRow;
    seats = new Seat *[MAX];
    for (int i = 0; i < MAX; ++i) {
        seats[i] = new Seat[other.SeatsInRow];
    }

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < other.SeatsInRow; j++) {
            seats[i][j] = other.seats[i][j];
        }
    }
    day = other.day;
}

// write lounge data to a JSON.
json Lounge :: writeLoungeToJSON() {
    json loungeData;
    loungeData["Lounge Name"] = name;
    loungeData["Speaker Type"] = speakerType;
    loungeData["Number Of Seats"] = numOfSeats;
    loungeData["Number of Seats In a Row"] = SeatsInRow;

    json screenDataOfLounge;
    screenDataOfLounge = screen.writeScreenToJSON();
    loungeData["Screen"] = screenDataOfLounge;

    json dayDataOfLounge;
    loungeData["Days"].clear();
    for (int i = 0; i < day.size(); ++i) {
        dayDataOfLounge.push_back(day[i].writeDayToJSON());
    }
    loungeData["Days"] = dayDataOfLounge;

    json seatDataOfLounge;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < SeatsInRow; ++j) {
            seatDataOfLounge.push_back(seats[i][j].writeSeatsToJSON());
        }
    }
    loungeData["Seats Data"] = seatDataOfLounge;

    return loungeData;
}

// read JSON data of Lounge.
Lounge Lounge :: readLoungeFromJSON(json &readLounge) {
    Lounge loungeData;
    loungeData.name = readLounge["Lounge Name"];
    loungeData.speakerType = readLounge["Speaker Type"];
    loungeData.numOfSeats = readLounge["Number Of Seats"];
    loungeData.SeatsInRow = readLounge["Number of Seats In a Row"];
    loungeData.screen.readScreenFromJSON(readLounge["Screen"]);

    for (int i = 0; i < readLounge["Days"].size(); ++i) {
        loungeData.day.push_back(Day :: readDayFromJSON(readLounge["Days"][i]));
    }
    loungeData.generateSeatsAfterFileReading();

    int index = 0;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < loungeData.SeatsInRow; ++j) {
            loungeData.seats[i][j].readSeatsFromJSON(readLounge["Seats Data"].at(index));
            index++;
        }
    }

    return loungeData;
}

// Generates seats based on data read from a file.
void Lounge :: generateSeatsAfterFileReading() {
    seats = new Seat*[MAX];
    for (int i = 0; i < MAX; ++i) {
        seats[i] = new Seat[SeatsInRow];
    }

    char A = 'A';
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < SeatsInRow; ++j) {
            seats[i][j].setRow(A);
            seats[i][j].setSeatNumber(j+1);
            string seat_id (1 ,seats[i][j].getRow());
            seat_id += to_string(seats[i][j].getSeatNumber());
            seats[i][j].setSeatId(seat_id);

            if (name=="VIP"||name=="Platinum"){
                seats[i][j].setSeatType("Luxury");
            }
            else{
                seats[i][j].setSeatType("Normal");
            }
        }
        A++;
    }
}

// Checks and updates the seat status based on the speaker type.
void Lounge :: checkSeatStatusForSpeaker(Seat &seats1) {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < SeatsInRow; ++j) {
            if (seats[i][j].getSeatId()==seats1.getSeatId()){
                seats[i][j].setInBuildSpeaker(false);
                return;
            }
        }
    }
    cout << "Seat Not Found" << endl;
}

// Writes lounge data to JSON for showtime.
json Lounge :: writeLoungeToJSONForShowtime() {
    json loungeData;
    loungeData["Lounge Name"] = name;

    return loungeData;
}

// Reads lounge data from JSON for showtime.
void Lounge :: readLoungeFromJSONForShowTime(json &readLounge) {
    name = readLounge["Lounge Name"];
}