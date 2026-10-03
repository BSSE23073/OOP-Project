//
// Created by saleha bilal on 08/04/2024.
//

#ifndef INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_PARKINGSPACE_H
#define INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_PARKINGSPACE_H
using namespace std;
#include <iostream>
#include "./../../nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

class ParkingSpace {
    string **coordinate;
    int length;
    int width;
    int countWidth;
    int countLength;
public:
    ParkingSpace();
    ParkingSpace(int length, int width, int x, int y, string name);
    void createCoordinatesFile(string &name);
    static int getSpacesLeft();

    ~ParkingSpace();
};



#endif //INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_PARKINGSPACE_H
