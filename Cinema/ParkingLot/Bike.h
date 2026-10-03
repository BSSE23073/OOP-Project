//
// Created by saleha bilal on 25/04/2024.
//

#ifndef CURRENTLY_WORKING_ON_BIKE_H
#define CURRENTLY_WORKING_ON_BIKE_H
#include "Vehicle.h"

class Bike : public Vehicle{
public:
    Bike(string license, string model, string s, int x);
    Bike(string license, string model, string space);
    void removeVehicleFromParking(const string& license) override;
    friend ostream& operator << (ostream& os, const Bike& b);
};


#endif //CURRENTLY_WORKING_ON_BIKE_H
