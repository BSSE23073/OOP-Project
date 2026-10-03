//
// Created by saleha bilal on 25/04/2024.
//

#ifndef CURRENTLY_WORKING_ON_CAR_H
#define CURRENTLY_WORKING_ON_CAR_H
#include "Vehicle.h"


class Car : public Vehicle {
public:
    Car(string license, string model, string s, int x);
    Car(string license, string model, string space);
    void removeVehicleFromParking(const string& license) override;
    friend ostream& operator << (ostream& os, const Car& c);
};



#endif //CURRENTLY_WORKING_ON_CAR_H
