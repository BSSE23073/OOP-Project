//
// Created by saleha bilal on 25/04/2024.
//

#include "ParkingLotFinance.h"

ParkingLotFinance *ParkingLotFinance::instance = nullptr;

ParkingLotFinance *ParkingLotFinance::getInstance() {
    if(instance == NULL)
        instance = new ParkingLotFinance;
    return instance;
}

ParkingLotFinance::ParkingLotFinance(){

}

void ParkingLotFinance::setCleaningCost(double c){
    totalCleaningCost = c;

    addToFile("Cleaning Cost", c);
}

void ParkingLotFinance::setRepairmentCost(double c){
    totalRepairmentCost = c;

    addToFile("Repairment Cost", c);
}

void ParkingLotFinance::setElectricityBill(double c){
    totalElectricityBill = c;

    addToFile("Electricity Bill", c);
}

void ParkingLotFinance::setMaintenanceCost(double c){
    totalMaintenanceCost = c;

    addToFile("Maintenance Cost", c);
}

void ParkingLotFinance::addToFile(const string& n, double c){
    string fileName = month + "_" + year + "_parking_lot_finance_file.json";
    fstream file(fileName);

    if(file){

        json details;
        file >> details;

        details[n] = c;

        file.close();

        ofstream f(fileName,ios::app);
        f << setw(4) << details << endl;
        f.close();
    }
    else {
        createFile();

        fileName = month + "_" + year + "_parking_lot_finance_file.json";
        fstream ff(fileName);

        json details;
        ff >> details;

        details[n] = c;

        ff.close();

        ofstream f(fileName, ios::app);
        f << setw(4) << details << endl;
        f.close();
    }
}

void ParkingLotFinance::openFile(){
    string fileName = month + "_" + year + "_parking_lot_finance_file.json";
    fstream file(fileName);

    if(file){
        json details;
        file >> details;

        for (auto it = details.begin(); it != details.end(); ++it) {
            const auto& key = it.key();
            const auto& value = it.value();

            totalCleaningCost = value["Cleaning Cost"];
            totalMaintenanceCost = value["Maintenance Cost"];
            totalRepairmentCost = value["Repairment Cost"];
            totalElectricityBill = value["Electricity Bill"];

            carTotal =  value["Car Total"];
            bikeTotal = value["Bike Total"];
        }

    }
}

void ParkingLotFinance::addCar(double cost) {
    string fileName = month + "_" + year + "_parking_lot_finance_file.json";
    fstream file(fileName);

    if (file) {
        json details;
        file >> details;
        file.close();

        carTotal += cost;
        details["Car Total"] = carTotal;

        ofstream writeFile(fileName,ios::app);
        writeFile << setw(4) << details << endl;
    } else {
        createFile();
    }
}
void ParkingLotFinance::addBike(double cost) {
    string fileName = month + "_" + year + "_parking_lot_finance_file.json";
    fstream file(fileName);

    if (file) {
        json details;
        file >> details;
        file.close();

        bikeTotal += cost;
        details["Bike Total"] = bikeTotal;

        ofstream writeFile(fileName,ios::app);
        writeFile << setw(4) << details << endl;
    } else {
        createFile();
    }
}

void ParkingLotFinance::createFile(){

    string fn =month + "_" + year + "_parking_lot_finance_file.json";
    fstream f(fn);

    if(!f) {

        json d;

        d["Cleaning Cost"] = 0.0;
        d["Maintenance Cost"] = 0.0;
        d["Repairment Cost"] = 0.0;
        d["Electricity Bill"] = 0.0;

        d["Car Total"] = 0.0;
        d["Bike Total"] = 0.0;

        ofstream createFile(fn);
        createFile << setw(4) << d << endl;
        createFile.close();
    }
    else
        openFile();
}

double ParkingLotFinance::getCarTotal() const{return carTotal;}
double ParkingLotFinance::getBikeTotal() const{return bikeTotal;}

void ParkingLotFinance::setMonth(string m){month = m;}
void ParkingLotFinance::setYear(string y){year = y;}

ostream& operator << (ostream& os, const ParkingLotFinance& f){
    cout << "Cleaning Cost: " << f.totalCleaningCost << endl;
    cout << "Maintenance Cost" << f.totalMaintenanceCost << endl;
    cout << "Repairment Cost" << f.totalRepairmentCost << endl;
    cout << "Electricity Bill" << f.totalElectricityBill << endl;
    cout << "Car Total" << f.carTotal << endl;
    cout << "Bike Total" << f.bikeTotal << endl;
    return os;
}