#ifndef OOPS_PROJECT_TICKET_H
#define OOPS_PROJECT_TICKET_H
#include "Seat.h"
#include "../Movie/Movie.h"
#include "./../Movie/MovieRoaster.h"

#include "./../../nlohmann/json.hpp"
using json = nlohmann :: json;

class Ticket {

protected:
    double price;
    string TicketID;
    bool status;

public:
    Seat *seat;
    Movie *movie;
    bool vipTicketStatus;

    // Parameterized and Default constructor
    Ticket(double price = 0, const string &ticketId = " ", Seat *seat = nullptr, Movie *movie = nullptr) {
        this->price = price;
        TicketID = ticketId;
        this->seat = seat;
        this->movie = movie;
        status = true;
        vipTicketStatus = false;
    }

    //getter
    double getPrice() const;

    //setter
    void setPrice(double price);

    //getter
    string getTicketId() const;

    //setter
    void setTicketId(const string ticketId);

    //getter
    bool isStatus() const;

    //setter
    void setStatus(bool status);

    //getter
    bool isVipTicketStatus() const;

    //setter
    void setVipTicketStatus(bool vipTicketStatus1);

    //virtual Display Ticket func then override in VIPTicket
    virtual void displayTicket();

    //virtual CalculatePrice func then override in VIPTicket
    virtual double calculateTicketPrice();

    //output operator overloaded
    friend ostream &operator<<(ostream &out, const Ticket &ticket);

    //json write Func
    json writeTicketToJSON();

    //json read Func
    static Ticket readTicketFromJSON(json &readTicket);
};


#endif //OOPS_PROJECT_TICKET_H
