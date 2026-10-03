//
// Created by saleha bilal on 25/04/2024.
//

#include "Car.h"

Car::Car(string license, string model, string s, int x){
    this->licensePlate = license;
    this->model = model;
    this->space = s;
}

Car::Car(string license, string model,string space){
    string name = "car";
    this->licensePlate = license;
    this->model = model;
    this->space = space;
    string filename = name + "_parking_space_details.json";
    fstream inputFile(filename);
    if (inputFile.is_open()) {

        nlohmann::json parkingDetails;
        inputFile >> parkingDetails;

        inputFile.close();

        for (auto it = parkingDetails.begin(); it != parkingDetails.end(); ++it) {
            nlohmann::json& block = it.value();

            if (it.key() == space) {
                block["license_plate"] = license;
                block["model"] = model;
                break;
            }
        }
        ofstream writefile(filename,ios::trunc);
        writefile << setw(4) << parkingDetails << endl;

        writefile.close();

        string chargeFileName = "parking_charges.json";

        fstream chargesFile(chargeFileName);

        nlohmann::json charges;
        chargesFile >> charges;

        chargesFile.close();

        double cost;

        cost = charges["Parking Charges"][name + " Charges"];

        cout << name + " parking charges are: " << cost << endl;
        cout << "please pay upfront" << endl;

    }
    else
        cerr << "Unable to open parking space file." << endl;
}

void Car::removeVehicleFromParking(const string& license){
    string name = "car";
    string filename = name + "_parking_space_details.json";
    fstream inputFile(filename);
    if (inputFile.is_open()) {

        nlohmann::json parkingDetails;
        inputFile >> parkingDetails;

        inputFile.close();
        bool found = false;

        for (auto& block : parkingDetails) {

            if ((block["license_plate"] == licensePlate) ) {
                found = true;

                block["license_plate"] = "";
                block["model"] = "";
                cout << "car removed from parkingLot" << endl;
                break;
            }
        }
        ofstream writefile(filename,ios::trunc);
        writefile << setw(4) << parkingDetails << endl;

        writefile.close();

        if(!found)
            cerr << "no such " << name << endl;
    }
    else
        cerr << "no such file exists" << endl;
}

ostream& operator << (ostream& os, const Car& c){
    os << "License Plate: " << c.licensePlate << endl;
    os << "Model: " << c.model << endl;
    os << "Parking ID: " << c.space << endl;
    return os;
}