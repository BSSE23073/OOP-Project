#ifndef OOPS_PROJECT_SHOWTIMEMANAGMENT_H
#define OOPS_PROJECT_SHOWTIMEMANAGMENT_H
#include"Showtime.h"
#include <fstream>
#include "../Movie/MovieRoaster.h"
#include "./../../nlohmann/json.hpp"

using json = nlohmann :: json;

class ShowtimeManagement {
    static ShowtimeManagement *instance;

    ShowtimeManagement() {}

    vector<Showtime> showtime;
    vector<Lounge> lounge;

public:
    static ShowtimeManagement *getInstance() {
        if (!instance) {
            instance = new ShowtimeManagement;
        }
        return instance;
    }

    // getter.
    vector<Showtime> getShowtime() const;

    // setter.
    vector<Lounge> getLounge() const;

    // Adds a new lounge to the cinema.
    void addLounge(Lounge &lounge1);

    // Schedules a new time slot for a given lounge.
    void addTimeToDayForLounge(string loungeName);

    // Adds a new showtime to the cinema schedule.
    void addShowtime(Showtime &showtime1);

    // Adds a movie to a specific showtime.
    void addMovieToShowtime(string &day, string &id);

    // Allows selection of a lounge from available options.
    Lounge selectLounge();

    // Updates details for an existing showtime.
    void updateShowtime();

    // Displays details of all lounges in the cinema.
    void displayCinemaLoungeDetails();

    // Displays all showtime available in the cinema.
    void displayAllShowtime();

    // Displays showtime for a specific day.
    void displayShowtimeForDay(string &day);

    // Books a ticket for a specific showtime on a specific day.
    Ticket *bookTicketInShowtime(string &day, string &id);

    // Filters and shows movies for a specific showtime on a specific Day.
    void showMoviesByFilterInShowtime(string &day, string &id);

    // Removes a movie from a showtime.
    void removeMovieFromShowtime(string &day, string &id);

    // Removes an entire showtime.
    void removeShowtime(string &day, string &id);

    // Recommends a movie for a specific showtime.
    void recommendMovieInShowtime(string &day, string &id);

    // Books a lounge for a specific showtime slot.
    void bookLoungeForShowtimeAtSlot(Lounge &lounge1, string day, TimeSlot &t1);

    // Frees up a lounge that was booked for a specific showtime slot.
    void freeLoungeForShowtimeAtSlot(Lounge &lounge1, string day, TimeSlot &t1);

    // Displays menu options of showtime.
    void menuForShowtime();

    // Writes the current state of lounges to a file.
    void writeLoungeToFile();

    // Reads lounge details from a file.
    void readLoungeFromFile();

    // Removes a specific lounge from the cinema.
    void removeLounge(string &loungeName);

    // Writes the current state of showtime to a file.
    void writeShowtimeToFile();

    // Reads showtime details from Json file.
    void readShowtimeFromFile();

    // Reads showtime details from JSON.
    void readShowtimeFromJson(json &readShowtime);

    // Refresh Ticket of a specific showtime at a specific Day
    void refreshTicketForAShowtimeAtADay(string &day, string &id);

    // Refresh Tickets for all showtime
    void refreshTicketForAllShowtime();

    void removeMovieFromShowtime(string movieName1);

    // Retrieves a specific lounge by name, For showtime.
    Lounge &getLoungeForShowtime(string LoungeName);

};

#endif //OOPS_PROJECT_SHOWTIMEMANAGMENT_H