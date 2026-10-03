//
// Created by Dell on 27/04/2024.
//

#ifndef OOPS_PROJECT_ONLINEUSER_H
#define OOPS_PROJECT_ONLINEUSER_H
#include "Customer.h"
#include "Membership.h"
class OnlineUser :public Customer {
    string userName;
    string emailAddress;
    string password;
    Membership membership;
public:

    //default constructor
    OnlineUser() {
        emailAddress = " ";
        password = " ";
    }

    //parameterized constructor
    OnlineUser(string name, string gender, int age, string userName, string emailAddress = " ", string password = " ")
            : Customer(name, gender, age) {
        this->userName = userName;
        this->emailAddress = emailAddress;
        this->password = password;
    }

    //setter
    void setUserName(string name) {
        userName = name;
    }

    //setter
    void setPassword(string pass) {
        password = pass;
    }

    //getter
    string getEmailId() {
        return emailAddress;
    }

    //getter
    string getPassword() {
        return password;
    }

    //getter
    string getUserName() {
        return userName;
    }

    //activate a person membership
    void activateMembership(Membership &membership1);

    //cancel a person membership
    void cancelMembership();

    //display online user func
    void displayDetails();

    //display online user membership details func
    void displayUserMemberShipDetails();

    //generate invoice for online user based on booking id
    void invoiceForBooking(string BookingId);

    //Displays User Bookings
    void displayUserBooking();

    //Writes online user data to JSON
    json writeOnlineUserToJSON() {
        json onlineUserData;
        onlineUserData["Name"] = getName();
        onlineUserData["Gender"] = getGender();
        onlineUserData["Age"] = getAge();
        onlineUserData["UserName"] = userName;
        onlineUserData["Email Address"] = emailAddress;
        onlineUserData["Password"] = password;

        json bookingData;
        for (int i = 0; i < bookings.size(); ++i) {
            bookingData.push_back(bookings[i].writeBookingToJSON());
        }
        onlineUserData["Bookings"] = bookingData;
        json membershipData;
        membershipData = membership.writeMembershipToJSON();
        onlineUserData["MemberShip"] = membershipData;

        return onlineUserData;
    }

    //read online user data from JSON
    static OnlineUser readOnlineUserFromJSON(json &readOnlineUser) {
        OnlineUser onlineUserData;
        onlineUserData.setName(readOnlineUser["Name"]);
        onlineUserData.setGender(readOnlineUser["Gender"]);
        onlineUserData.setAge(readOnlineUser["Age"]);
        onlineUserData.userName = readOnlineUser["UserName"];
        onlineUserData.emailAddress = readOnlineUser["Email Address"];
        onlineUserData.password = readOnlineUser["Password"];

        for (auto & i : readOnlineUser["Bookings"]) {
            onlineUserData.bookings.push_back(Booking :: readBookingFromJSON(i));
        }

        return onlineUserData;
    }

};


#endif //OOPS_PROJECT_ONLINEUSER_H
