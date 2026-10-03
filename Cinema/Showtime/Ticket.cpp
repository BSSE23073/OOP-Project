#include "Ticket.h"

//getter
double Ticket :: getPrice() const {
    return price;
}

//setter
void Ticket :: setPrice(double price1) {
    price = price1;
}

//getter
string Ticket :: getTicketId() const {
    return TicketID;
}

//setter
void Ticket :: setTicketId(const string ticketId) {
    TicketID = ticketId;
}

//getter
bool Ticket :: isStatus() const {
    return status;
}

//setter
void Ticket :: setStatus(bool status1) {
    status = status1;
}

//getter
bool Ticket ::  isVipTicketStatus() const{
    return vipTicketStatus;
}

//setter
void Ticket ::  setVipTicketStatus(bool vipTicketStatus1) {
    vipTicketStatus = vipTicketStatus1;
}

//virtual Display Ticket func then override in VIPTicket
void Ticket :: displayTicket() {
    cout << "Ticket - TicketID: " << TicketID << endl
         << "Price: " << price << endl
         << "Status: " ;
    if(status){
        cout << "Ticket is Not Booked " << endl;
    }
    else {
        cout << "Ticket is Booked " << endl;
    }
         cout<< "Movie Name: " << movie->getName() << endl
         << "Seat: " << seat->getSeatId() << endl;
}

//output operator overloaded
ostream &operator << (ostream &out, const Ticket &ticket) {
    out << "Ticket - TicketID: " << ticket.TicketID << endl
        << "Price: " << ticket.price << endl
        << "Status: ";
    if (ticket.status) {
        cout << "Ticket is Not Booked " << endl;
    } else {
        cout << "Ticket is Booked " << endl;
    }
    cout << "Movie Name: " << ticket.movie->getName() << endl
         << "Seat: " << ticket.seat->getSeatId() << endl;
    return out;
}

//virtual CalculatePrice func then override in VIPTicket
double Ticket :: calculateTicketPrice() {
    return price;
}

//json write ticket data Func
json Ticket :: writeTicketToJSON() {
    json ticketData;
    ticketData["Ticket ID"] = TicketID;
    ticketData["Ticket Price"] = price;
    ticketData["Ticket Status"] = status;
    ticketData["Movie Name"] = movie->getName();
    ticketData["Seat ID"] = seat->getSeatId();

    return ticketData;
}

//json read ticket data Func
Ticket Ticket :: readTicketFromJSON(json &readTicket) {
    Ticket ticketData;
    ticketData.TicketID = readTicket["Ticket ID"];
    ticketData.price = readTicket["Ticket Price"];
    ticketData.status = readTicket["Ticket Status"];

    ticketData.movie = new Movie;
    ticketData.movie->setName( readTicket["Movie Name"]);
    ticketData.seat = new Seat;
    ticketData.seat->setSeatId(readTicket["Seat ID"]);

    return ticketData;
}