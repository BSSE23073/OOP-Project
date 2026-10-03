//
// Created by saleha bilal on 16/04/2024.
//

#ifndef INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_VEHICLE_H
#define INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_VEHICLE_H
#include <iostream>
using namespace std;
#include "./../../nlohmann/json.hpp"
#include <fstream>
#include <filesystem>
#include "ParkingSpace.h"

class Vehicle {
protected:
    string licensePlate;
    string model;
    string space;
public:
    Vehicle();
    string getLicensePlate();
    string getModel();
    string getParkingSpace();
    virtual void removeVehicleFromParking(const string& license) = 0;

};


#endif //INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_VEHICLE_H
