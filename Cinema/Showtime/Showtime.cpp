#include "Showtime.h"

// getter.
string Showtime :: getStartTime() const {
    return startTime;
}

// setter.
void Showtime :: setStartTime(const string startTime1) {
    startTime = startTime1;
}

// getter.
string Showtime :: getEndTime() const {
    return endTime;
}

// setter.
void Showtime :: setEndTime(const string endTime1) {
    endTime = endTime1;
}

// getter.
string Showtime :: getShowtimeId() const {
    return showtimeID;
}

// setter.
void Showtime :: setShowtimeId(const string showtimeId) {
    showtimeID = showtimeId;
}

// getter.
int Showtime :: getLoungeCount() const {
    return loungeCount;
}

// setter.
void Showtime :: setLoungeCount(int loungeCount1) {
    loungeCount = loungeCount1;
}

// Adds a movie along with a lounge to the schedule with optional VIP charges.
void Showtime :: addLoungeAndMovie(Lounge &lounge1, Movie &movie1, double price, double VIPCharges) {
    if (loungeCount < 6) {
        lounge.push_back(&lounge1);
        movie.push_back(&movie1);
        generateTicketOfEachLounge(lounge1, movie1, price, VIPCharges);
        loungeCount++;
    } else {
        cout << "Lounges are full!!" << endl;
    }
}

// Removes a movie from a specified showtime at a given lounge.
void Showtime :: removeMovieFromShowtime(std::string movieName, string loungeName) {
    for (int i = 0; i < movie.size(); ++i) {
        if (movie[i]->getName() == movieName && lounge[i]->getName() == loungeName) {
            movie.erase(movie.begin() + i);
            if (lounge[i]->getName() == "VIP" || lounge[i]->getName() == "Platinum") {
                for (int j = 0; j < vipTicket.size(); ++j) {
                    if (vipTicket[j].movie->getName() == movie[i]->getName()) {
                        vipTicket.erase(vipTicket.begin() + j);
                    }
                }
            } else {
                for (int j = 0; j < tickets.size(); ++j) {
                    if (tickets[j].movie->getName() == movie[i]->getName()) {
                        tickets.erase(tickets.begin() + j);
                    }
                }
            }
            lounge.erase(lounge.begin() + i);
            return;
        }
    }
    cout << "Movie or Lounge not Found" << endl;
}

// Generates a ticket for a movie in a specific lounge, with optional VIP charges.
void Showtime :: generateTicketOfEachLounge(Lounge &lounge1, Movie &movie1, double price, double VIPCharges) {
    int x = 1111;
    string y;
    if (lounge1.getName() == "Platinum" || lounge1.getName() == "VIP") {
        for (int i = 0; i < MAX; ++i) {
            for (int j = 0; j < lounge1.getSeatsInRow(); ++j) {
                y = to_string(x);
                VIPTicket VipTicket(price, y, &lounge1.seats[i][j], &movie1, VIPCharges);
                vipTicket.push_back(VipTicket);
                x++;
            }
        }
        return;
    }

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < lounge1.getSeatsInRow(); ++j) {
            y = to_string(x);
            Ticket regularTicket(price, y, &lounge1.seats[i][j], &movie1);
            tickets.push_back(regularTicket);
            x++;
        }
    }
}

// Displays details about the showtime.
void Showtime :: displayShowTimeDetails() {
    cout << " Showtime Details "
         << "Day: " << day << endl
         << "Time Slot: " << startTime << " - " << endTime << endl
         << "ShowtimeID: " << showtimeID << endl
         << "Movies Being Played : " << loungeCount << endl;
    for (int i = 0; i < loungeCount; ++i) {
        cout << "Lounge " << i + 1 << ". " << lounge[i]->getName() << endl
             << "Movie: " << movie[i]->getName() << endl;
    }
}

// Overloads output operator.
ostream &operator << (ostream &os, const Showtime &showtime) {
    os << " Showtime Details "
       << "Day: " << showtime.day << endl
       << "Time Slot: " << showtime.startTime << " - " << showtime.endTime << endl
       << " ShowtimeID: " << showtime.showtimeID << endl
       << " Movies Being Played : " << showtime.loungeCount << endl;
    for (int i = 0; i < showtime.loungeCount; ++i) {
        os << "Lounge " << i + 1 << ". ";
        showtime.lounge[i]->displayLoungeDetails();
        os << "Movie: ";
        showtime.movie[i]->displayMovieDetails();
        os << endl;
    }
    return os;
}

// Displays all tickets for a specific movie in a specific lounge.
void Showtime :: displayAllTicketsForLounge(string movieName, string loungeName) {
    for (int i = 0; i < movie.size(); ++i) {
        if (movie[i]->getName() == movieName && lounge[i]->getName() == loungeName) {
            if (lounge[i]->getName() == "VIP" || lounge[i]->getName() == "Platinum") {
                cout << "Lounge Name: " << lounge[i]->getName() << endl
                     << "- Movie: " << movie[i]->getName() << endl;
                for (int j = 0; j < vipTicket.size(); ++j) {
                    if (vipTicket[j].movie->getName() == movie[i]->getName()) {
                        if (vipTicket[j].isStatus()) {
                            cout << ANSI_COLOR_LIGHT_BLUE << vipTicket[j].seat->getSeatId() << ANSI_COLOR_RESET << " ";
                        } else {
                            cout << ANSI_COLOR_RED << vipTicket[j].seat->getSeatId() << ANSI_COLOR_RESET << " ";
                        }
                        if ((j + 1) % lounge[i]->getSeatsInRow() == 0) {
                            cout << endl;
                        }
                    }
                }
            } else {
                cout << "Lounge Name: " << lounge[i]->getName() << endl
                     << "- Movie: " << movie[i]->getName() << endl;
                for (int j = 0; j < tickets.size(); ++j) {
                    if (tickets[j].movie->getName() == movie[i]->getName()) {
                        if (tickets[j].isStatus()) {
                            cout << ANSI_COLOR_GREEN << tickets[j].seat->getSeatId() << ANSI_COLOR_RESET << " ";
                        } else {
                            cout << ANSI_COLOR_RED << tickets[j].seat->getSeatId() << ANSI_COLOR_RESET << " ";
                        }
                        if ((j + 1) % lounge[i]->getSeatsInRow() == 0) {
                            cout << endl;
                        }
                    }
                }
            }
            return;
        }
    }
    cout << "Movie or Lounge not Found" << endl;
}

// Books a ticket for a given movie, lounge, and seat.
void Showtime :: TicketBook(string MovieName, string loungeName, string SeatID) {
    for (int i = 0; i < movie.size(); ++i) {
        if (movie[i]->getName() == MovieName && lounge[i]->getName() == loungeName) {
            if (lounge[i]->getName() == "VIP" || lounge[i]->getName() == "Platinum") {
                for (int j = 0; j < vipTicket.size(); ++j) {
                    if (vipTicket[j].seat->getSeatId() == SeatID && vipTicket[j].movie->getName() == MovieName) {
                        if (!vipTicket[j].isStatus()) {
                            cout << "Ticket already sold" << endl;
                            return;
                        } else {
                            vipTicket[j].setStatus(false);
                            return;
                        }
                    }
                }
                cout << "Wrong ID" << endl;
            } else {
                for (int j = 0; j < tickets.size(); ++j) {
                    if (tickets[j].seat->getSeatId() == SeatID && tickets[j].movie->getName() == MovieName) {
                        if (!tickets[j].isStatus()) {
                            cout << "Ticket already sold" << endl;
                            return;
                        } else {
                            tickets[j].setStatus(false);
                            return;
                        }
                    }
                }
                cout << "Wrong ID" << endl;
            }
        }
    }
}

// Filters and displays movies based on genre.
void Showtime :: filterMovieByGenre(string &genre) {
    for (int j = 0; j < movie.size(); j++) {
        for (int k = 0; k < movie[j]->getGenre().size(); k++) {
            if (movie[j]->getGenre()[k].getName() == genre) {
                movie[j]->displayMovieDetails();
                return;
            }
        }
    }
    cout << "No Movie of this Genre Exists " << endl;
}

// Generates a random number within a specified range.
int Showtime :: randomNumber(int start, int end) {
    return start + rand() % (end - start + 1);
}

// Provides movie recommendations.
void Showtime :: movieRecommendation() {
    movie[randomNumber(0, movie.size())]->displayMovieDetails();
}

//getter
string Showtime :: getDay() {
    return day;
}

// write showtime data to a JSON.
json Showtime :: writeShowtimeToJSON() {
    json showtimeData;
    showtimeData["Start Time of Showtime"] = startTime;
    showtimeData["End Time of Showtime"] = endTime;
    showtimeData["Day for Showtime"] = day;
    showtimeData["Showtime ID"] = showtimeID;
    showtimeData["Lounge Count"] = loungeCount;

    json showtimeTicketData;
    for (int i = 0; i < tickets.size(); i++) {
        showtimeTicketData.push_back(tickets[i].writeTicketToJSON());
    }
    showtimeData["Tickets"] = showtimeTicketData;

    json showtimeVIPTicketData;
    for (int i = 0; i < vipTicket.size(); i++) {
        showtimeVIPTicketData.push_back(vipTicket[i].writeVIPTicketToJSON());
    }
    showtimeData["VIP Tickets"] = showtimeVIPTicketData;

    json showtimeLoungeData;
    for (int i = 0; i < lounge.size(); i++) {
        showtimeLoungeData.push_back(lounge[i]->writeLoungeToJSONForShowtime());
    }
    showtimeData["Lounge"] = showtimeLoungeData;

    json showtimeMovieData;
    for (int i = 0; i < movie.size(); i++) {
        showtimeMovieData.push_back(movie[i]->getMovieJsonForShowtime());
    }
    showtimeData["Movie"] = showtimeMovieData;

    return showtimeData;
}

//setter
void Showtime :: setDay(const string &day1) {
    this->day = day1;
}

// Returns a ticket for a specific booking (movie, lounge, seat).
Ticket* Showtime :: returnTicketForBooking(string MovieName, string LoungeName, string SeatID) {
    for (int i = 0; i < movie.size(); ++i) {
        if (movie[i]->getName() == MovieName && lounge[i]->getName() == LoungeName) {
            if (lounge[i]->getName() == "VIP" || lounge[i]->getName() == "Platinum") {
                for (int j = 0; j < vipTicket.size(); ++j) {
                    if (vipTicket[j].seat->getSeatId() == SeatID && vipTicket[j].movie->getName() == MovieName) {
                        VIPTicket *ptr = new VIPTicket(vipTicket[j]);
                        return ptr;
                    }
                }
            } else {
                for (int j = 0; j < tickets.size(); ++j) {
                    if (tickets[j].seat->getSeatId() == SeatID && tickets[j].movie->getName() == MovieName) {
                        Ticket *ptr = new Ticket(tickets[j]);
                        return ptr;
                    }
                }
            }
        }
    }
}

void Showtime::refreshTicketStatus() {
    for (int i = 0; i < movie.size(); ++i) {
        for (int j = 0; j < vipTicket.size(); ++j) {
            vipTicket[j].setStatus(true);
        }
        for (int j = 0; j < tickets.size(); ++j) {
            tickets[j].setStatus(true);
        }
    }
}

void Showtime :: removeMovieFromShowtime(string movieName) {
    for (int i = 0; i < movie.size(); ++i) {
        if (movie[i]->getName() == movieName) {
            movie.erase(movie.begin() + i);
            lounge.erase(lounge.begin() + i);
        }
        for (int j = 0; j < vipTicket.size(); ++j) {
            if (vipTicket[j].movie->getName() == movie[i]->getName()) {
                vipTicket.erase(vipTicket.begin() + j);
            }
        }
        for (int j = 0; j < tickets.size(); ++j) {
            if (tickets[j].movie->getName() == movie[i]->getName()) {
                tickets.erase(tickets.begin() + j);
            }
        }
    }
}