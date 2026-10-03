//
// Created by Dell on 27/04/2024.
//

#ifndef OOPS_PROJECT_MEMBERSHIP_H
#define OOPS_PROJECT_MEMBERSHIP_H
#include "iostream"
#include "./../../nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

class Membership {
    string membershipID;
    string expiryDate;
    double membershipDiscount;
    double subscriptionRate;
    bool status;
public:

    //default constructor
    Membership(){
        membershipID = "";
        membershipDiscount = 0;
        expiryDate = "";
        subscriptionRate = 0.00;
        status = false;
    }

    //parameterized constructor
    Membership(string membershipID,string expiryDate,double membershipDiscount){
        this->membershipID = membershipID;
        this->expiryDate = expiryDate;
        this->status = true;
        this->membershipDiscount=membershipDiscount;
    }

    //setter
    void setMembershipStatus(bool membership){
        status = membership;
    }

    //setter
    void setExpiryDate(string date){
        expiryDate = date;
    }

    //setter
    void setSubscriptionRate(double rate){
        subscriptionRate = rate;
    }

    double getSubscriptionRate() const;

    //setter
    void setMembershipID(string ID){
        membershipID = ID;
    }

    //setter
    void setMembershipDiscount(double discount){
        membershipDiscount = discount;
    }

    //display membership details
    void displayMemberShipDetails();

    //Membership invoice
    void membershipInvoice();

    //getter
    const string &getMembershipId() const;

    //getter
    const string &getExpiryDate() const;

    //getter
    double getMembershipDiscount() const;

    //getter
    bool isStatus() const;

    //write membership data to json
    json writeMembershipToJSON() {
        json membershipData;
        membershipData["Membership ID"] = membershipID;
        membershipData["Expiry Date"] = expiryDate;
        membershipData["Membership Discount"] = membershipDiscount;
        membershipData["Status"] = status;
        return membershipData;
    }

    //write membership data from json
    void readMembershipFromJSON(json &readMembership) {
        membershipID = readMembership["Membership ID"];
        expiryDate = readMembership["Expiry Date"];
        membershipDiscount = readMembership["Membership Discount"];
        status = readMembership["Status"];
    }
};


#endif //OOPS_PROJECT_MEMBERSHIP_H
