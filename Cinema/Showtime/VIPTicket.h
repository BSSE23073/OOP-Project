#ifndef OOPS_PROJECT_VIPTICKET_H
#define OOPS_PROJECT_VIPTICKET_H
#include "Ticket.h"

class VIPTicket : public Ticket{  //Vip Ticket is Part of Ticket
    double extraCharges;

public:
    // parameterized and default constructor
    VIPTicket(double price = 0, const string &ticketId = " ", Seat *seat = nullptr, Movie *movie = nullptr, double extraCharges = 0){
        this->price = price;
        TicketID = ticketId;
        this->status = true;
        this->seat = seat;
        this->movie = movie;
        this->extraCharges = extraCharges;
        vipTicketStatus = true;
    }

    
    // getter
    double getExtraCharges() const;

    // setter
    void setExtraCharges(double extraCharges);

    // display func
    void displayTicket() override;

    //calculatePrice Func
    double calculateTicketPrice() override;

    //json write Func
    json writeVIPTicketToJSON();

    //json read Func
    static VIPTicket readVIPTicketFromJSON(json & readVIPTicket);
};

#endif //OOPS_PROJECT_VIPTICKET_H
