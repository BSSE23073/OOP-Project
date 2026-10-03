//
// Created by saleha bilal on 08/04/2024.
//

#include "ParkingSpace.h"

ParkingSpace::ParkingSpace(){}

ParkingSpace::ParkingSpace(int l, int w, int x, int y, string name){
    length = l;
    width = w;
    countLength = 0;
    countWidth = 0;

    coordinate = new string*[l];

    for(int i = 0; i < length; i++){
        coordinate[i] = new string[w];
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {

            coordinate[i][j] = static_cast<char>(x) + to_string(y);
            y++;

        }
        y = 1;
        x++;
    }
    createCoordinatesFile(name);
    length--;
    width--;
}

int ParkingSpace::getSpacesLeft(){
    int x = 0;

    ifstream inputFile("parking_space_details.json");

    if (inputFile.is_open()) {

        json parkingDetails;
        inputFile >> parkingDetails;

        for (auto& block : parkingDetails) {
            if (block["license_plate"] == "") {

                x++;
            }
        }
        inputFile.close();
    }
    else
        cerr << "Unable to open file: parking_space_details.json" << endl;

    return x;
}

ParkingSpace::~ParkingSpace() {
    for(int i = 0; i < length; i++) {

        delete[] coordinate[i];
    }
    delete[] coordinate;
}

void ParkingSpace::createCoordinatesFile(string &name){
    string filename = name + "_parking_space_details.json";
    fstream file(filename);

    if (!file) {

        json parkingDetails;

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) {

                json block;
                block["license_plate"] = "";
                block["model"] = "";
                parkingDetails[coordinate[i][j]] = block;

            }
        }
        ofstream filee(filename,ios::app);
        filee << setw(4) << parkingDetails << endl;
        filee.close();
    }
    else
        file.close();
}