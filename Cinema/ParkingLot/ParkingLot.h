//
// Created by saleha bilal on 08/04/2024.
//

#ifndef INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_PARKINGLOT_H
#define INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_PARKINGLOT_H
using namespace std;
#include <iostream>
#include <vector>
#include "./../../nlohmann/json.hpp"
#include <fstream>
#include "Vehicle.h"
#include "ParkingSpace.h"
#include "ParkingCharges.h"
#include "ParkingLotFinance.h"
#include "Car.h"
#include "Bike.h"

class ParkingLot {
    vector<string> carParkingSpaces;
    vector<string> bikeParkingSpaces;
    vector<bool> carParkingAvailable;
    vector<bool> bikeParkingAvailable;
    ParkingLotFinance *finance;
    vector<Car> cars;
    vector<Bike> bikes;
    static ParkingLot *instance;
    ParkingCharges charges;
    int carSpacesLeft;
    int bikeSpacesLeft;
    ParkingLot();
public:
    void setMonth(string m);
    void setYear(string y);
    static ParkingLot *getInstance();
    void createCarParkingSpace();
    void createBikeParkingSpace();
    void createParkingCharges();
    void addCar(const Car& c);
    void deleteCar(const string& license);
    void addBike(const Bike& z);
    void deleteBike(const string& license);
    int getCarSpacesLeft() const;
    int getBikeSpacesLeft() const;
    string getModel(const string& license);
    string getLicensePlate(const string& id);
    bool vehicleIs(const string& license); // to check if a vehicle is in parking lot
    double bikeCharge();
    double CarCharge();
    string getParkingId(const string& license);
    void updateCharges(string c, double d);
    void printAllCars();
    void printAllBikes();
    void printBike(const string& l);
    void printCar(const string& l);
    ParkingLotFinance* getFinance();
    void printCarSpaces();
    void printBikeSpaces();
    bool carSpaceIs(string x);
    bool bikeSpaceIs(string x);
    void parkingLotMain();
    void parkingLotMenu();
    void addMaintenanceCost(double x);
    void addRepairmentCost(double y);
    void addCleaningCost(double z);
    void addElectricityCost(double a);
};


#endif //INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_PARKINGLOT_H
