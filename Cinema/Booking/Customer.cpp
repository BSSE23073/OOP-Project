// Created by Dell on 27/04/2024.
//

#include "Customer.h"

//add Booking to vector
void Customer::addBooking(Booking &booking) {
    bookings.push_back(booking);
}

//remove booking from vector based on booking id
void Customer::removeBooking(string bookingId) {
    for (int i = 0; i < bookings.size(); ++i) {
        if (bookings[i].getBookingID() == bookingId) {
            bookings.erase(bookings.begin() + i);
        }
    }
}

//display customer details
void Customer::displayDetails() {
    cout << "Name : " << getName() << ", Age: " << getAge() << ", Gender: " << getGender();
    cout << "\n-------------------------------------\n";
    cout << "Bookings of Customer:\n";
    for (auto &i: bookings) {
        i.bookingDetails();
    }
}

//generate invoice based on booking id
void Customer::invoiceForBooking(string BookingId) {
    for (int i = 0; i < bookings.size(); ++i) {
        if (bookings[i].getBookingID()==BookingId){
            bookings[i].generateInvoice();
            cout<<"Pay the Due Amount!!\n";
            bookings[i].setPaymentStatus(true);
        }
    }
}



void Customer::addOrder(Order &order)
{
    order1.push_back(order);
}

void Customer::removeOrder(int orderId)
{
    for (int i = 0; i < order1.size(); ++i) {
        if (order1[i].getOrderID()==orderId)
        {
            order1.erase(order1.begin()+i);
        }
    }
}

void Customer::displayOrderDetails(int orderId)
{
    for (int i = 0; i < order1.size(); ++i) {
        if (order1[i].getOrderID()==orderId)
        {
            cout << "Name : " << getName() << ", Age: " << getAge() << ", Gender: " << getGender();
            cout << "\n-------------------------------------\n";
            cout << "Order of Customer:\n";
            order1[i].displayOrder();
        }
    }
}

void Customer::generateInvoice(int orderId)
{
    for (int i = 0; i < order1.size(); ++i) {
        if (order1[i].getOrderID()==orderId)
        {
            order1[i].makeInvoiceForOrder();
        }
    }
}