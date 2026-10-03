//
// Created by saleha bilal on 21/04/2024.
//

#include "ParkingCharges.h"

ParkingCharges::ParkingCharges(){

}

ParkingCharges::ParkingCharges(double bike, double car){
    bikeCharges = bike;
    carCharges = car;
    parkingChargesFile();
}

void ParkingCharges::parkingChargesFile(){

    string filename = "parking_charges.json";
    fstream file(filename);

    if(!file){
        ofstream writeFile(filename);

        nlohmann::json details;
        nlohmann::json block;

        block["car Charges"] = carCharges;
        block["bike Charges"] = bikeCharges;
        details["Parking Charges"] = block;

        writeFile << setw(4) << details << endl;

        writeFile.close();
    }
    else {
        file.close();
    }
}

void ParkingCharges::updateParkingCharges(string n, double w){
    string filename = "parking_charges.json";
    fstream file(filename);

    if(file){

        nlohmann::json details;
        file >> details;

        file.close();

        details["Parking Charges"][n + " Charges"] = w;

        if(n == "car")
            carCharges = w;
        else if(n == "bike")
            bikeCharges = w;

        file.open(filename,ios::trunc);
        file << setw(4) << details << endl;
        file.close();
    }
}

double ParkingCharges::getBikeCharges() {
    return bikeCharges;
}

double ParkingCharges::getCarCharges() {
    return carCharges;
}