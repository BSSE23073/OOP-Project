//
// Created by Dell on 27/04/2024.
//

#ifndef OOPS_PROJECT_BOOKINGMANAGEMENT_H
#define OOPS_PROJECT_BOOKINGMANAGEMENT_H

#include "OnlineUser.h"
#include "./../Showtime/ShowtimeManagement.h"
#include "./../HelpBot/HelpBot.h"
class BookingManagement {
    static BookingManagement *instance;
    static int userCount;
    vector<Booking> booking;
    vector<Customer>customer;
    vector<OnlineUser>onlineUser;

    //private constructor
    BookingManagement(){}

public:

    //getter
    static BookingManagement* getInstance();

    // Adds a new customer to the system.
    void addCustomer(Customer &customer1);

    // Registers a new customer with basic details.
    void signUp(string name,string gender,int age);

    // Creates a booking for a specified customer.
    void makeBooking(Customer& customer1);

    // Authenticates a user with their email and password.
    bool login(string email,string password);

    // Creates a booking for a user identified by userID.
    void makeBookingForUser(string userID);

    // Displays membership details for a specified user.
    void userMembershipDetails(string userID);

    // Activates membership for a specified user.
    void membershipForUser(string userID);

    // Cancels the membership for a specified user.
    void cancelMembershipForUser(string userID);

    // Generates an invoice for a customer based on their name and age.
    void generateInvoiceForCustomer(string name,int age);

    // Generates an invoice for a user identified by userID.
    void generateInvoiceForUser(string userID);

    // Cancels a booking based on the booking ID.
    void cancelBooking(string bookingID);

    // Displays details for a specified user.
    void displayUserDetails(string userID);

    // Displays all bookings across the cinema.
    void displayBookingsOfCinema();

    // Displays the management menu
    void menuForManagement();

    // Displays the login menu.
    void menuForLogin();

    // Reads customer information from file.
    void readCustomerFromFile();

    // Writes customer information to file.
    void writeCustomerToFile();

    // Reads online user data from file.
    void readOnlineUserFromFile();

    //Writes online user data to file.
    void writeOnlineUserToFile();

    // Reads booking information from file.
    void readBookingsFromFile();

    // Writes booking information to a file.
    void writeBookingsToFile();

    void addOrderToCustomer(string name,int age,Order& order);

};


#endif //OOPS_PROJECT_BOOKINGMANAGEMENT_H
