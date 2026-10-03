#ifndef OOPS_PROJECT_BOOKING_H
#define OOPS_PROJECT_BOOKING_H
#include "./../Showtime/Ticket.h"
#include "./../Showtime/VIPTicket.h"
#include "./../../nlohmann/json.hpp"
#include<fstream>
using json = nlohmann::json;
class Booking {
    string bookingID;
    vector<Ticket>* ticket;
    vector<VIPTicket>* vipTicket;
    bool paymentStatus;
    double transactionAmount;
public:

    // Default constructor
    Booking(){
        bookingID = " ";
        transactionAmount = 0.00;
        paymentStatus = false;
        ticket = new vector <Ticket>;
        vipTicket = new vector <VIPTicket>;
    }

    //Parameterized Consructor
    Booking(string bookingID) {
        this->bookingID = bookingID;
        this->transactionAmount = 0.0;
        this->paymentStatus = false;
        ticket = new vector<Ticket>;
        vipTicket = new vector<VIPTicket>;
    }

    // Adds a regular ticket to the booking.
    void addTicketToBooking(Ticket &ticket1);

    // Adds a VIP ticket to the booking.
    void addTicketToBooking(VIPTicket &vipTicket1);

    // Calculates the total transaction amount for the booking.
    double calculateTransaction();

    // Removes a ticket from the booking based on the ticket ID and movie name.
    void removeTicketFromBooking(string ticketID,string movieName);

    // Generates a standard invoice for the booking.
    void generateInvoice();

    // Generates an invoice for the booking with a discounted price.
    void generateInvoice(double discountedPrice);

    // Displays the details of the booking.
    void bookingDetails();

    //write booking data to json
    json writeBookingToJSON();

    //read booking data from json
    static Booking readBookingFromJSON(json &readBooking);

    //setter
    void setPaymentStatus(bool payment){
        paymentStatus = payment;
    }

    //getter
    string getBookingID(){
        return bookingID;
    }



    //destructor
//    ~Booking(){
//        delete ticket;
//        delete vipTicket;
//    }

};


#endif //OOPS_PROJECT_BOOKING_H
