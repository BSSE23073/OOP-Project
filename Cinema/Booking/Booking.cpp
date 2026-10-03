#include "Booking.h"

void Booking::addTicketToBooking(VIPTicket &vipTicket1) {
//    cout<<"HI!!!\n";
//    cout.flush();
    vipTicket->push_back(vipTicket1);
//    cout<<"HI!!!\n";
//    cout.flush();
}

// Adds a regular ticket to the booking.
void Booking::addTicketToBooking(Ticket &ticket1) {
    ticket->push_back(ticket1);
}

// Calculates the total transaction amount for the booking.
double Booking::calculateTransaction() {
    double sum;
    for (int i = 0; i < ticket->size(); ++i) {
       sum = sum + ticket->at(i).getPrice();
    }
    for (int i = 0; i < vipTicket->size(); ++i) {
        sum = sum + vipTicket->at(i).calculateTicketPrice();
    }
    transactionAmount = sum;
    return transactionAmount;
}

// Removes a ticket from the booking based on the ticket ID and movie name.
void Booking::removeTicketFromBooking(string ticketID, string movieName) {
    for (int i = 0; i < ticket->size(); ++i) {
        if (ticket->at(i).getTicketId()==ticketID&&ticket->at(i).movie->getName()==movieName){
            ticket->erase(ticket->begin()+i);
        }
    }
    for (int i = 0; i < vipTicket->size(); ++i) {
        if (vipTicket->at(i).getTicketId()==ticketID&&vipTicket->at(i).movie->getName()==movieName){
            vipTicket->erase(vipTicket->begin()+i);
        }
    }
}

// Generates a standard invoice for the booking.
void Booking::generateInvoice() {
    cout<<"---------------------------------\n"
    <<"----------Booking ID "<<bookingID<<"---\n"
    <<"----------Invoice For Tickets ---------\n"
    <<"Tickets Bought:\n";
    for (int i = 0; i < ticket->size(); ++i) {
        ticket->at(i).displayTicket();
    }
    for (int i = 0; i < vipTicket->size(); ++i) {
        vipTicket->at(i).displayTicket();
    }
    cout<<"---------Total Amount Due-----------\n"
    <<calculateTransaction()<<endl;
}

// Displays the details of the booking.
void Booking::bookingDetails() {
cout<<"Booking ID: "<<bookingID<<"\nTickets In Booking:\n";
    for (int i = 0; i < ticket->size(); ++i) {
        ticket->at(i).displayTicket();
    }
    for (int i = 0; i < vipTicket->size(); ++i) {
        vipTicket->at(i).displayTicket();
    }
    cout<<"Payment Status For Booking: ";
    if(paymentStatus){
        cout<<"Dues Cleared!!\n";
    }
    else{
        cout<<"Payment is Due For Booking\n";
    }
}

// Generates an invoice for the booking with a discounted price.
void Booking::generateInvoice(double discountedPrice) {
    cout<<"---------------------------------\n"
        <<"----------Booking ID "<<bookingID<<"---\n"
        <<"----------Invoice For Tickets ---------\n"
        <<"Tickets Bought:\n";
    for (int i = 0; i < ticket->size(); ++i) {
        ticket->at(i).displayTicket();
    }
    for (int i = 0; i < vipTicket->size(); ++i) {
        vipTicket->at(i).displayTicket();
    }
    cout<<"---------Total Amount Due-----------\n"
        <<calculateTransaction()-discountedPrice<<endl;
    cout<<"Payment Status For Booking: ";
    if(paymentStatus){
        cout<<"Dues Cleared!!\n";
    }
    else{
        cout<<"Payment is Due For Booking\n";
    }
}

//write booking data to json
json Booking::writeBookingToJSON() {
    json bookingData;
    bookingData["Booking ID"] = bookingID;
    bookingData["Payment Status"] = paymentStatus;
    bookingData["Transaction Amount"] = transactionAmount;

    json ticketData;
    for (int i = 0; i < ticket->size(); ++i) {
        ticketData.push_back(ticket->at(i).writeTicketToJSON());
    }
    bookingData["Tickets"] = ticketData;

    json vipTicketData;
    for (int i = 0; i < vipTicket->size(); ++i) {
        vipTicketData.push_back(vipTicket->at(i).writeVIPTicketToJSON());
    }
    bookingData["VIP Tickets"] = vipTicketData;

    return bookingData;
}

//read booking data from json
Booking Booking::readBookingFromJSON(json &readBooking) {
    Booking bookingData;
    bookingData.bookingID = readBooking["Booking ID"];
    bookingData.paymentStatus =  readBooking["Payment Status"];
    bookingData.transactionAmount = readBooking["Transaction Amount"];

    for (int i = 0; i < readBooking["Tickets"].size(); ++i) {
        bookingData.ticket->push_back(Ticket ::readTicketFromJSON(readBooking["Tickets"].at(i)));
    }

    for (int i = 0; i < readBooking["VIP Tickets"].size(); ++i) {
        bookingData.vipTicket->push_back(VIPTicket ::readVIPTicketFromJSON(readBooking["VIP Tickets"].at(i)));
    }

    return bookingData;
}



