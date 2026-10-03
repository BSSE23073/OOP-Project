#include "VIPTicket.h"

//getter
double VIPTicket :: getExtraCharges() const {
    return extraCharges;
}

//setter
void VIPTicket :: setExtraCharges(double extraCharges1) {
    extraCharges = extraCharges1;
}

//display func
void VIPTicket :: displayTicket() {
    cout << "VIP Ticket - TicketID: " << TicketID << endl
         << "Price: " << calculateTicketPrice() << endl
         << "Status: " ;
    if (status) {
        cout << "Ticket is Not Booked " << endl;
    } else {
        cout << "Ticket is Booked " << endl;
    }
       cout << "Seat: " << seat->getSeatId() << endl;
}

//calculatePrice func
double VIPTicket :: calculateTicketPrice() {
    return (Ticket :: calculateTicketPrice() + extraCharges);
}

// json write  func
json VIPTicket :: writeVIPTicketToJSON() {
    json VIPTicketData;
    VIPTicketData["VIPTicket ID"] = TicketID;
    VIPTicketData["VIPTicket Price"] = price;
    VIPTicketData["VIPTicket Extra Charges"] = extraCharges;
    VIPTicketData["VIPTicket Status"] = status;
    VIPTicketData["Movie Name"] = movie->getName();
    VIPTicketData["Seat ID"] = seat->getSeatId();

    return VIPTicketData;

}

//json read Func
VIPTicket VIPTicket :: readVIPTicketFromJSON(json &readVIPTicket) {
    VIPTicket VIPTicketData;
    VIPTicketData.TicketID = readVIPTicket["VIPTicket ID"];
    VIPTicketData.price = readVIPTicket["VIPTicket Price"];
    VIPTicketData.extraCharges = readVIPTicket["VIPTicket Extra Charges"];
    VIPTicketData.status = readVIPTicket["VIPTicket Status"];

    VIPTicketData.movie = new Movie;
    VIPTicketData.movie->setName( readVIPTicket["Movie Name"]);
    VIPTicketData.seat = new Seat;
    VIPTicketData.seat->setSeatId(readVIPTicket["Seat ID"]);

    return VIPTicketData;
}