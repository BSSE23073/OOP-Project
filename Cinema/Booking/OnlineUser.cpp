//
// Created by Dell on 27/04/2024.
//

#include "OnlineUser.h"

//activate a person membership
void OnlineUser::activateMembership(Membership &membership1) {
    membership = membership1;
}

//cancel a person membership
void OnlineUser::cancelMembership() {
    membership.setMembershipStatus(false);
}

//display online user func
void OnlineUser::displayDetails() {
    cout << "Name : " << getName() << ", Age: " << getAge() << ", Gender: " << getGender();
    cout << "\n-------------------------------------\n";
    cout<<"Username : "<<userName
    <<"\n-----------------------------\n"
    <<"Email Address: "<<emailAddress
    <<"\n-------------------\n";
}

//display online user membership details func
void OnlineUser::displayUserMemberShipDetails() {
    cout << "\n--------------------------------------\n"
         << "\n---------User " << getName() << "-------------\n";
    membership.displayMemberShipDetails();
}

//Displays User Bookings
void OnlineUser::displayUserBooking() {
    for (auto &i: bookings) {
        i.bookingDetails();
    }
}

//generate invoice for online user based on booking id
void OnlineUser::invoiceForBooking(string BookingId) {
    for (int i = 0; i < bookings.size(); ++i) {
        if (bookings[i].getBookingID()==BookingId){
            if (membership.isStatus()) {
                bookings[i].generateInvoice(membership.getMembershipDiscount());
                cout<<"Pay the Due Amount!!\n";
                bookings[i].setPaymentStatus(true);
            }
            else{
                bookings[i].generateInvoice();
                cout<<"Pay the Due Amount!!\n";
                bookings[i].setPaymentStatus(true);
            }
        }
    }
}
