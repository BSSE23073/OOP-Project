//
// Created by Dell on 27/04/2024.
//

#include "Membership.h"

//display membership details
void Membership::displayMemberShipDetails() {
    cout<<"\n-------------Membership Details-----------------\n"
        <<"\nMemberShip ID: "<<membershipID
        <<"\nExpiry Date: "<<expiryDate
        <<"\nMembership Discount: "<<membershipDiscount;
    if (isStatus()){
        cout<<"\n Membership Active";
    }
    else{
        cout<<"\n Membership Expired or Not Active";
    }
    cout<<"\n-------------------------------------------\n";
}

//getter
const string &Membership::getMembershipId() const {
    return membershipID;
}

//getter
const string &Membership::getExpiryDate() const {
    return expiryDate;
}

//getter
double Membership::getMembershipDiscount() const {
    return membershipDiscount;
}

//getter
bool Membership::isStatus() const {
    return status;
}

double Membership::getSubscriptionRate() const {
    return subscriptionRate;
}

void Membership::membershipInvoice() {
    cout<<"\n------------------------\n"
    <<"\n-----------Membership Invoice--------------\n"
    <<"Membership Price "<<subscriptionRate
    <<"\n-------------------------------------\n";
}
