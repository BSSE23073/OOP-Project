#include "ShowtimeManagement.h"

ShowtimeManagement *ShowtimeManagement :: instance = nullptr;

// getter.
vector<Showtime> ShowtimeManagement :: getShowtime() const {
    return showtime;
}

// setter.
vector<Lounge> ShowtimeManagement :: getLounge() const {
    return lounge;
}

// Adds a new lounge to the cinema.
void ShowtimeManagement :: addLounge(Lounge &lounge1) {
    for (int i = 0; i < lounge.size(); ++i) {
        if (lounge[i].getName() == lounge1.getName()){
            cout<<"Lounge Already Exists!!!" << endl;
            return;
        }
    }
    lounge.push_back(lounge1);
    cout<<"Lounge Added Successfully!!!" << endl;

}

// Adds a new showtime to the cinema schedule.
void ShowtimeManagement :: addShowtime(Showtime &showtime1) {
    for (int i = 0; i < showtime.size(); ++i) {
        if (showtime[i].getDay()==showtime1.getDay() && showtime[i].getStartTime()==showtime1.getStartTime() && showtime[i].getEndTime()==showtime1.getEndTime()){
            cout<<"Showtime already Exists" << endl;
            return;
        }
    }
    showtime.push_back(showtime1);
    cout << "Showtime added successfully!" << endl;
}

// Adds a movie to a specific showtime.
void ShowtimeManagement :: addMovieToShowtime(string &day, string &id) {
    for (int i = 0; i < showtime.size(); ++i) {
        if (showtime[i].getShowtimeId() == id && showtime[i].getDay() == day) {
            Movie *movie = new Movie(MovieRoaster::getInstance()->selectMovie());
            Lounge *lounge1 = new Lounge(ShowtimeManagement::getInstance()->selectLounge());
            for (int k = 0; k < lounge1->day.size(); ++k) {
                if (lounge1->day[k].getDay() == showtime[i].getDay()) {
                    for (int j = 0; j < lounge1->day[k].getTimeSlot().size(); ++j) {
                        if (lounge1->day[k].getTimeSlot()[j].getStart() == showtime[i].getStartTime() &&
                            lounge1->day[k].getTimeSlot()[j].getEnd() == showtime[i].getEndTime()) {
                            if (lounge1->day[k].getTimeSlot()[j].isAvailable()) {
                                TimeSlot t1(showtime[i].getStartTime(), showtime[i].getEndTime());
                                ShowtimeManagement::getInstance()->bookLoungeForShowtimeAtSlot(*lounge1,
                                                                                               showtime[i].getDay(),
                                                                                               t1);
                                double priceTicket, VipCharges;
                                cout << "Enter Price For Tickets: ";
                                cin >> priceTicket;
                                if (lounge1->getName() == "VIP" || lounge1->getName() == "Platinum") {
                                    cout << "Enter Vip Charges For Tickets: ";
                                    cin >> VipCharges;
                                    showtime[i].addLoungeAndMovie(*lounge1, *movie, priceTicket, VipCharges);
                                } else {
                                    showtime[i].addLoungeAndMovie(*lounge1, *movie, priceTicket);
                                }
                            } else {
                                cout << "Time Slot not available!!" << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

// Allows selection of a lounge from available options.
Lounge ShowtimeManagement :: selectLounge() {
    int index = 0;
    loop:
    cout << "Select Lounge Index: " << endl;
    for (int i = 0; i < lounge.size(); ++i) {
        lounge[i].displayLoungeDetails();
    }
    cin >> index;
    if (index - 1 >= lounge.size()) {
        cout << "Index Not Found" << endl;
        goto loop;
    } else {
        return lounge[index - 1];
    }
}

// Displays all showtime available in the cinema.
void ShowtimeManagement :: displayAllShowtime() {
    for (int i = 0; i < showtime.size(); ++i) {
        showtime[i].displayShowTimeDetails();
    }
}

// Updates details for an existing showtime.
void ShowtimeManagement :: updateShowtime() {
    string id;
    displayAllShowtime();
    cout << "Enter the ID of Showtime: ";
    cin >> id;
    for (int i = 0; i < showtime.size(); ++i) {
        if (showtime[i].getShowtimeId() == id) {
            cout << "Enter Starting Time : ";
            string start, end;
            cin >> start;
            cout << "Enter Ending Time : ";
            cin >> end;
            showtime[i].setStartTime(start);
            showtime[i].setEndTime(end);
            showtime[i].displayShowTimeDetails();
            return;
        }
    }
    cout << "Showtime not found" << endl;
}

// Displays showtime for a specific day.
void ShowtimeManagement :: displayShowtimeForDay(string &day) {
    for (int i = 0; i < showtime.size(); ++i) {
        if (showtime[i].getDay() == day) {
            showtime[i].displayShowTimeDetails();
        }
    }
}

// Books a ticket for a specific showtime on a specific day.
Ticket* ShowtimeManagement :: bookTicketInShowtime(string &day, string &id) {
    for (int i = 0; i < showtime.size(); ++i) {
        if (showtime[i].getShowtimeId() == id && showtime[i].getDay() == day) {
            string name;
            cout << "Enter Movie Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter the Lounge Name: ";
            string name1;
            cin >> name1;
            showtime[i].displayAllTicketsForLounge(name, name1);
            string ticketID;
            cout << "Enter the Seat ID you want to Book: ";
            cin >> ticketID;
            showtime[i].TicketBook(name, name1, ticketID);
            return (showtime[i].returnTicketForBooking(name,name1,ticketID));
        }
    }
    cout << "Showtime not found" << endl;
}

// Filters and shows movies for a specific showtime on a specific Day.
void ShowtimeManagement :: showMoviesByFilterInShowtime(string &day, std::string &id) {
    for (int i = 0; i < showtime.size(); ++i) {
        if (showtime[i].getShowtimeId() == id && showtime[i].getDay() == day) {
            showtime[i].displayShowTimeDetails();
            string name;
            cout << "Enter Genre you want to filter movies by: ";
            cin.ignore();
            getline(cin, name);
            showtime[i].filterMovieByGenre(name);
            return;
        }
    }
    cout << "Showtime not found" << endl;
}

// Recommends a movie for a specific showtime.
void ShowtimeManagement :: recommendMovieInShowtime(string &day, string &id) {
    for (int i = 0; i < showtime.size(); ++i) {
        if (showtime[i].getShowtimeId() == id && showtime[i].getDay() == day) {
            showtime[i].movieRecommendation();
            return;
        }
    }
    cout << "Showtime not found" << endl;
}

// Schedules a new time slot for a given lounge.
void ShowtimeManagement :: addTimeToDayForLounge(string loungeName) {
    for (int i = 0; i < lounge.size(); ++i) {
        if (lounge[i].getName() == loungeName) {
            string day;
            cout << "Enter Day Name you want to add Time Slot to :";
            cin >> day;
            lounge[i].addTimeSlotToDay(day);
            return;
        }
    }
    cout << "Lounge not found" << endl;
}

// Books a lounge for a specific showtime slot.
void ShowtimeManagement :: bookLoungeForShowtimeAtSlot(Lounge &lounge1, string day, TimeSlot &t1) {
    for (int i = 0; i < lounge.size(); ++i) {
        if (lounge[i].getName() == lounge1.getName()) {
            lounge[i].changeAvailabilityOfLoungeAtTimeSlotOfADay(day, t1);
            return;
        }
    }
    cout << "Lounge not found" << endl;
}

// Frees up a lounge that was booked for a specific showtime slot.
void ShowtimeManagement :: freeLoungeForShowtimeAtSlot(Lounge &lounge1, string day, TimeSlot &t1) {
    for (int i = 0; i < lounge.size(); ++i) {
        if (lounge[i].getName() == lounge1.getName()) {
            lounge[i].makeAvailabilityOfLoungeAtTimeSlotOfADay(day, t1);
            return;
        }
    }
    cout << "Lounge not found" << endl;
}

// Removes a movie from a showtime.
void ShowtimeManagement :: removeMovieFromShowtime(string &day, string &id) {
    for (int i = 0; i < showtime.size(); ++i) {
        if (showtime[i].getShowtimeId() == id && showtime[i].getDay() == day) {
            showtime[i].displayShowTimeDetails();
            string movieName;
            cout << "Enter movie name you want to remove from this showtime:";
            cin >> movieName;
            string loungeName;
            cout << "Enter Lounge name you want to remove from this showtime:";
            cin >> loungeName;
            showtime[i].removeMovieFromShowtime(movieName, loungeName);
            for (int j = 0; j < lounge.size(); ++j) {
                if (lounge[j].getName() == loungeName) {
                    TimeSlot t1(showtime[i].getStartTime(), showtime[i].getEndTime());
                    ShowtimeManagement :: freeLoungeForShowtimeAtSlot(lounge[j], showtime[i].getDay(), t1);
                }
            }
            return;
        }
    }
    cout << "Showtime not Found on the Given Day" << endl;
}

// Removes an entire showtime.
void ShowtimeManagement :: removeShowtime(string &day, string &id) {
    for (int i = 0; i < showtime.size(); ++i) {
        if (showtime[i].getShowtimeId() == id && showtime[i].getDay() == day) {
            TimeSlot t1(showtime[i].getStartTime(), showtime[i].getEndTime());
            for (int j = 0; j < showtime[i].lounge.size(); ++j) {
                for (int k = 0; k < lounge.size(); ++k) {
                    if (showtime[i].lounge[j]->getName() == lounge[k].getName()) {
                        ShowtimeManagement::freeLoungeForShowtimeAtSlot(lounge[k], showtime[i].getDay(), t1);
                    }
                }
            }
            showtime.erase(showtime.begin() + i);
            return;
        }
    }
    cout << "Showtime not Found on the Given Day" << endl;
}

// Displays details of all lounges in the cinema.
void ShowtimeManagement :: displayCinemaLoungeDetails() {
    for (auto &i: lounge) {
        i.displayLoungeDetails();
    }
}

// Writes the current state of lounges to a file.
void ShowtimeManagement :: writeLoungeToFile() {
    json loungeDataOfShowtime;
    for (auto &i: lounge) {
        loungeDataOfShowtime.push_back(i.writeLoungeToJSON());
    }
    ofstream writeLounge("Cinema/Showtime/LoungeData.json", ios::out);
    if (writeLounge.is_open()) {
        writeLounge << loungeDataOfShowtime.dump(2);
    } else {
        cerr << "file is not open" << endl;
    }
}

// Reads lounge details from a file.
void ShowtimeManagement :: readLoungeFromFile() {
    ifstream read("Cinema/Showtime/LoungeData.json", ios::in);
    if (!read.is_open()) {
        cerr << "Failed to open JSON file." << endl;
        return;
    }
    json loungeData;
    read >> loungeData;
    for(auto &i : loungeData){
        lounge.push_back(Lounge :: readLoungeFromJSON(i));
    }
}

// Removes a specific lounge from the cinema.
void ShowtimeManagement :: removeLounge(string &loungeName) {
    for (int i = 0; i < lounge.size(); ++i) {
        if (lounge[i].getName() == loungeName){
            lounge.erase(lounge.begin()+i);
            return;
        }
    }
    cout << "Lounge not Found" << endl;
}

// Writes the current state of showtime to a file.
void ShowtimeManagement :: writeShowtimeToFile() {
    json showtimeData;
    for (auto &i : showtime) {
        showtimeData.push_back(i.writeShowtimeToJSON());
    }
    ofstream writeShowtime("Cinema/Showtime/ShowtimeData.json", ios :: out);
    if (writeShowtime.is_open()) {
        writeShowtime << showtimeData.dump(2);
    } else {
        cerr << "File is not open" << endl;
    }
}

// Reads showtime details from Json file.
void ShowtimeManagement :: readShowtimeFromFile() {
    ifstream readShowtime("Cinema/Showtime/ShowtimeData.json", ios :: in);
    if (!readShowtime.is_open()) {
        cerr << "Failed to open JSON file." << endl;
        return;
    }
    json showtimeData;
    readShowtime >> showtimeData;

    readShowtimeFromJson(showtimeData);
}

// Retrieves a specific lounge by name, For showtime.
Lounge& ShowtimeManagement :: getLoungeForShowtime(string LoungeName) {
    for (int i = 0; i < lounge.size(); ++i) {
        if (lounge[i].getName()==LoungeName){
            return lounge[i];
        }
    }
    cout << "Lounge Not Found" << endl;
}

// Reads showtime details from JSON.
void ShowtimeManagement :: readShowtimeFromJson(json &readShowtime) {
    for(auto &j:readShowtime) {
        Showtime showtimeData;
        string startTime = j["Start Time of Showtime"];
        showtimeData.setStartTime(startTime);
        showtimeData.setEndTime(j["End Time of Showtime"]);
        showtimeData.setDay(j["Day for Showtime"]);
        showtimeData.setShowtimeId(j["Showtime ID"]);
        showtimeData.setLoungeCount(j["Lounge Count"]);


        for (int i = 0; i < j["Tickets"].size(); ++i) {
            showtimeData.tickets.push_back(Ticket::readTicketFromJSON(j["Tickets"][i]));
        }

        for (int i = 0; i < j["VIP Tickets"].size(); ++i) {
            showtimeData.vipTicket.push_back(VIPTicket::readVIPTicketFromJSON(j["VIP Tickets"][i]));
        }

        for (auto &i: j["Lounge"]) {
            Lounge *ptr = new Lounge ;
            ptr->readLoungeFromJSONForShowTime(i);
            string loungeName = ptr->getName();
            *ptr = getLoungeForShowtime(loungeName);
            showtimeData.lounge.push_back(ptr);
        }

        for (int i = 0; i < j["Movie"].size(); ++i) {
            Movie movie1;
            Movie *ptr = new Movie;
            string movieName;
            movie1 = Movie::readFromJsonForShowtime(j["Movie"][i]);
            movieName = movie1.getName();
            *ptr = MovieRoaster::getInstance()->getMovieForShowtime(movieName);
            showtimeData.movie.push_back(ptr);
        }
        showtime.push_back(showtimeData);
    }
}

// Displays menu options of showtime.
void ShowtimeManagement :: menuForShowtime() {
    int choice = 0;
    while (true) {
        cout << "\n--- Showtime Management Menu ---" << endl;
        cout << "1. Add Showtime" << endl;
        cout << "2. Add Lounge" << endl;
        cout << "3. Add Time Slot to a Lounge" << endl;
        cout << "4. Add Movie to Showtime" << endl;
        cout << "5. Remove Movie from Showtime" << endl;
        cout << "6. Remove Showtime from cinema" << endl;
        cout << "7. Display All Showtime" << endl;
        cout << "8. Display All Lounges Cinema Schedule" << endl;
        cout << "9. To Update Showtime TimeSlot" << endl;
        cout << "10. Remove Lounge From Cinema" << endl;
        cout << "11. Refresh Weekly Tickets" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {

            string day, startTime, endTime, showtimeID;
            cout << "Enter Day of the week for Showtime:";
            cin >> day;
            cout << "Enter start time (HH:MM 24-Hour Clock): ";
            cin.ignore();
            getline(cin, startTime);
            cout << "Enter end time (HH:MM 24-Hour Clock): ";
            getline(cin, endTime);
            cout << "Enter showtime ID: ";
            getline(cin, showtimeID);
            Showtime showtime1(startTime, endTime, day, showtimeID);
            addShowtime(showtime1);
        }
        if (choice == 2) {
//            Lounge lounge1 ("Gold", "dolby", 100);
//            Screen screen ("IMAX", "4K", "120 inch", "3D");
//            lounge1.setScreen(screen);
//            addLounge(lounge1);
            string loungeName, screenName, resolution, size, type, speakerType;
            int numOfSeats;
            cout << "Enter Lounge Name: ";
            cin.ignore();
            getline(cin, loungeName);
            cout << "Enter Number of seats in lounge: ";
            cin >> numOfSeats;
            cout << "Enter Screen Name: ";
            cin.ignore();
            getline(cin, screenName);
            cout << "Enter Resolution: ";

            getline(cin, resolution);
            cout << "Enter Size (in inches): ";

            getline(cin, size);
            cout << "Enter Type: ";

            getline(cin, type);
            Screen screen(screenName, resolution, size, type);

            cout << "Enter Speaker Type: ";

            getline(cin, speakerType);
            Lounge lounge1(loungeName, speakerType, numOfSeats);
            lounge1.addScreen(screen);
            addLounge(lounge1);
        }
        if (choice == 3) {
            string loungeName;
            cout << "Enter Lounge Name you want to add time slot to:";
            cin >> loungeName;
            addTimeToDayForLounge(loungeName);
        }
        if (choice == 4) {
            string id, day;
            displayAllShowtime();
            cout << "Enter The Showtime Id :";
            cin >> id;
            cout << "and Day for Which you want to add movie for playing: ";
            cin >> day;
            addMovieToShowtime(day, id);
        }
        if (choice == 5) {
            string id, day;
            displayAllShowtime();
            cout << "Enter The Showtime Id :";
            cin >> id;
            cout << "and Day for Which you want to remove movie from playing: ";
            cin >> day;
            removeMovieFromShowtime(day, id);
        }
        if (choice == 6) {
            string id, day;
            displayAllShowtime();
            cout << "Enter The Showtime Id :";
            cin >> id;
            cout << "and Day for Which you want to remove Showtime: ";
            cin >> day;
            removeShowtime(day, id);
        }
        if (choice == 7) {
            displayAllShowtime();
        }
        if (choice == 8) {
            displayCinemaLoungeDetails();
        }
        if (choice == 9) {
            updateShowtime();
        }
        if (choice == 10) {
            string loungeName;
            cout << "Enter Lounge Name: ";
            cin >> loungeName;
            removeLounge(loungeName);
        }
        if (choice == 11) {
            refreshTicketForAllShowtime();
        }
        if (choice == 12) {
            cout << "Exit...\n";
            writeShowtimeToFile();
            writeLoungeToFile();
            break;
        }
    }
}

// Refresh Ticket of a specific showtime at a specific Day
void ShowtimeManagement :: refreshTicketForAShowtimeAtADay(string &day, string &id) {
    for (int i = 0; i < showtime.size(); ++i) {
        if (showtime[i].getDay() == day && showtime[i].getShowtimeId() == id){
            showtime[i].refreshTicketStatus();
            return;
        }
    }
    cout << "Showtime Not Found" << endl;
}

// Refresh Tickets for all showtime
void ShowtimeManagement :: refreshTicketForAllShowtime() {
    for (int i = 0; i < showtime.size(); ++i) {
        showtime[i].refreshTicketStatus();
    }
}

void ShowtimeManagement :: removeMovieFromShowtime(string movieName1) {
    for (int i = 0; i < showtime.size(); ++i) {
        for (int j = 0; j < showtime[i].movie.size(); ++j) {
            if (showtime[i].movie[j]->getName() == movieName1) {
                for (int k = 0; k < lounge.size(); ++k) {
                    if (lounge[j].getName() == showtime[i].lounge[j]->getName()) {
                        TimeSlot t1(showtime[i].getStartTime(), showtime[i].getEndTime());
                        ShowtimeManagement :: freeLoungeForShowtimeAtSlot(lounge[j], showtime[i].getDay(), t1);
                    }
                }
                showtime[i].removeMovieFromShowtime(movieName1);
            }
        }
    }
}