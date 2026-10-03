#ifndef OOPS_PROJECT_SHOWTIME_H
#define OOPS_PROJECT_SHOWTIME_H
#include "Ticket.h"
#include "VIPTicket.h"
#include "Lounge.h"
#include "..\Movie\Movie.h"
#include <vector>
#include <ostream>
#include <cstdlib>

const string ANSI_COLOR_RESET = "\033[0m";
const string ANSI_COLOR_RED = "\033[31m";
const string ANSI_COLOR_GREEN = "\033[32m";
const string ANSI_COLOR_BLUE = "\033[34m";
const string ANSI_COLOR_LIGHT_BLUE = "\033[1;36m"; // Light blue
const string ANSI_COLOR_PURPLE = "\033[1;34m";    // Purple

class Showtime {
    string startTime;
    string endTime;
    string day;
    string showtimeID;
    int loungeCount;

public:
    vector <Ticket> tickets;
    vector <VIPTicket> vipTicket;
    vector <Lounge*> lounge;
    vector <Movie*> movie;

    //parameterized and Default Constructor
    Showtime(const string &startTime = " ", const string &endTime = " ",const string &day =" ", const string &showtimeId = " ", int loungeCount = 0) {
        this->startTime = startTime;
        this->endTime = endTime;
        this->day = day;
        showtimeID = showtimeId;
        this->loungeCount = loungeCount;
    }

    // getter.
    string getStartTime() const;

    // setter.
    void setStartTime(const string startTime);

    // getter.
    string getEndTime() const;

    // setter.
    void setEndTime(const string endTime);

    // getter.
    string getShowtimeId() const;

    // setter.
    void setShowtimeId(const string showtimeId);

    // Removes a movie from a specified showtime at a given lounge.
    void removeMovieFromShowtime(string movieName, string loungeName);

    // getter.
    int getLoungeCount() const;

    // setter.
    void setLoungeCount(int loungeCount);

    // getter.
    string getDay();

    // setter.
    void setDay(const string &day1);

    // Adds a movie along with a lounge to the schedule with optional VIP charges.
    void addLoungeAndMovie(Lounge &lounge1, Movie &movie1, double price, double VIPCharges = 0);

    // Generates a ticket for a movie in a specific lounge, with optional VIP charges.
    void generateTicketOfEachLounge(Lounge &lounge1, Movie &movie1, double price, double VIPCharges = 0);

    // Displays details about the showtime.
    void displayShowTimeDetails();

    // Filters and displays movies based on genre.
    void filterMovieByGenre(string &genre);

    // Displays all tickets for a specific movie in a specific lounge.
    void displayAllTicketsForLounge(string movieName, string loungeName);

    // Returns a ticket for a specific booking (movie, lounge, seat).
    Ticket* returnTicketForBooking(string MovieName, string LoungeName, string SeatID);

    // Overloads output operator.
    friend ostream &operator<<(ostream &os, const Showtime &showtime);

    // Books a ticket for a given movie, lounge, and seat.
    void TicketBook(string MovieName, string LoungeName, string SeatID);

    // Generates a random number within a specified range.
    int randomNumber(int start, int end);

    // Provides movie recommendations.
    void movieRecommendation();

    // write showtime data to a JSON.
    json writeShowtimeToJSON();

    void refreshTicketStatus();

    void removeMovieFromShowtime(string movieName);

};

#endif //OOPS_PROJECT_SHOWTIME_H