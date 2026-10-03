//
// Created by saleha bilal on 16/04/2024.
//

#include "Vehicle.h"

Vehicle::Vehicle() = default;

string Vehicle::getLicensePlate(){
    return licensePlate;
}

string Vehicle::getModel(){
    return model;
}

string Vehicle::getParkingSpace()
{
    if (!space.empty())
        return space;
    else
        return "empty";
}

