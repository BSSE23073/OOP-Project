//
// Created by saleha bilal on 25/04/2024.
//

#ifndef CURRENTLY_WORKING_ON_PARKINGLOTFINANCE_H
#define CURRENTLY_WORKING_ON_PARKINGLOTFINANCE_H
using namespace std;
#include <iostream>
#include <fstream>
#include "./../../nlohmann/json.hpp"

using json = nlohmann::json;

class ParkingLotFinance {
    double totalCleaningCost;
    double totalElectricityBill;
    double totalMaintenanceCost;
    double totalRepairmentCost;
    double carTotal;
    double bikeTotal;
    string month;
    string year;
    static ParkingLotFinance* instance;
    ParkingLotFinance();
public:
    static ParkingLotFinance* getInstance();
    void setCleaningCost(double c);
    void setRepairmentCost(double r);
    void setElectricityBill(double c);
    void setMaintenanceCost(double c);
    void addToFile(const string& n, double c);
    void openFile();
    void addCar(double cost);
    void addBike(double cost);
    double getCarTotal() const;
    double getBikeTotal() const;
    void createFile();
    void setMonth(string m);
    void setYear(string y);
    friend ostream& operator << (ostream& os, const ParkingLotFinance& finance);
};


#endif //CURRENTLY_WORKING_ON_PARKINGLOTFINANCE_H
