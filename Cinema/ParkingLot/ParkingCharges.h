//
// Created by saleha bilal on 21/04/2024.
//

#ifndef INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_PARKINGCHARGES_H
#define INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_PARKINGCHARGES_H
#include <iostream>
using namespace std;
#include <fstream>
#include "./../../nlohmann/json.hpp"

class ParkingCharges {
    double bikeCharges;
    double carCharges;
public:
    ParkingCharges();
    ParkingCharges(double bike, double car);
    void parkingChargesFile();
    void updateParkingCharges(string n, double w);
    double getBikeCharges();
    double getCarCharges();
};



#endif //INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_PARKINGCHARGES_H
