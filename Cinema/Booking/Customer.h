//
// Created by Dell on 27/04/2024.
//

#ifndef OOPS_PROJECT_CUSTOMER_H
#define OOPS_PROJECT_CUSTOMER_H

#include "./../Movie/Person.h"
#include "Booking.h"
#include <vector>
#include "./../../nlohmann/json.hpp"
#include "./../Order/Order.h"

using json = nlohmann::json;
class Customer : public Person {
protected:
    vector<Booking> bookings;
    vector<Order> order1;
public:

    //default constructor
    Customer() {}

    //parameterized constructor
    Customer(string name, string gender, int age) : Person(name, gender, age) {}

    //generate invoice based on booking id
    virtual void invoiceForBooking(string BookingId);

    //add Booking to vector
    void addBooking(Booking &booking);

    //remove booking from vector based on booking id
    void removeBooking(string bookingId);

    //display customer details
    virtual void displayDetails();

    //write customer data to json
    json writeCustomerToJSON() {
        json customerData;
        customerData["Name"] = getName();
        customerData["Gender"] = getGender();
        customerData["Age"] = getAge();

        json bookingData;
        for (int i = 0; i < bookings.size(); ++i) {
            bookingData.push_back(bookings[i].writeBookingToJSON());
        }
        customerData["Bookings"] = bookingData;
        return customerData;
    }

    //read customer data from json
    static Customer readCustomerFromJSON(json &readCustomer) {
        Customer customerData;
        customerData.setName(readCustomer["Name"]);
        customerData.setGender(readCustomer["Gender"]);
        customerData.setAge(readCustomer["Age"]);

        for (int i = 0; i < readCustomer["Bookings"].size(); ++i) {
            customerData.bookings.push_back(Booking :: readBookingFromJSON(readCustomer["Bookings"][i]));
        }

        return customerData;
    }

    void addOrder(Order& order);

    void removeOrder(int orderId);

    void displayOrderDetails(int orderId) ;

    void generateInvoice(int orderId);

};


#endif //OOPS_PROJECT_CUSTOMER_H
