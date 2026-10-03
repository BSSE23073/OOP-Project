//
// Created by saleha bilal on 08/04/2024.
//

#include "ParkingLot.h"

ParkingLot *ParkingLot::instance = nullptr;

ParkingLot::ParkingLot(){
    finance = ParkingLotFinance::getInstance();
}

ParkingLot *ParkingLot::getInstance(){
    if(instance == nullptr)
        instance = new ParkingLot;
    return instance;
}

void ParkingLot::createBikeParkingSpace() {
    bikeSpacesLeft = 0;

    string bikeFileName = "bike_parking_space_details.json";

    fstream bikeFile(bikeFileName);

    if(bikeFile){

        nlohmann::json details;
        bikeFile >> details;

        bikeFile.close();

        string license;
        string model;

        for(auto& i: details){
            bikeSpacesLeft++;
        }

        for (auto it = details.begin(); it != details.end(); ++it) {

            nlohmann::json& block = it.value();

            bikeParkingSpaces.push_back(it.key());
            bikeParkingAvailable.push_back(true);

        }

        int count = 0;

        for(auto& i: details){

            if(i["license_plate"] != ""){
                license = i["license_plate"];
                model = i["model"];

                bikeSpacesLeft--;

                Bike b(license,model,bikeParkingSpaces[count],0);
                bikeParkingAvailable[count] = false;
                bikes.push_back(b);
            }
            count++;
        }

    }
    else {

        int len, wid, start, a = 1;
        string name;

        name = "bike";
        start = 97;

        cout << "Enter length and width of capacity of bikes" << endl;

        cin >> len;
        cin >> wid;

        ParkingSpace parkingSpace(len,wid,start,a,name);
    }
}

void ParkingLot::createCarParkingSpace(){
    carSpacesLeft = 0;

    string carFileName = "car_parking_space_details.json";

    fstream carFile(carFileName);

    if(carFile){

        nlohmann::json details;
        carFile >> details;

        carFile.close();

        string license;
        string model;

        for(auto& i: details){
            carSpacesLeft++;
        }

        for (auto it = details.begin(); it != details.end(); ++it) {
            nlohmann::json& block = it.value();

            carParkingSpaces.push_back(it.key());
            carParkingAvailable.push_back(true);
        }

        int count = 0;

        for(auto& i: details){
            if(i["license_plate"] != ""){

                license = i["license_plate"];
                model = i["model"];

                carSpacesLeft--;

                Car c(license,model,carParkingSpaces[count],0);
                carParkingAvailable[count] = false;

                cars.push_back(c);
            }
            count++;
        }
    }
    else{
        cout << "create parking space for cars" << endl;

        int len, wid, start, a = 1;
        string name;

        name = "car";
        start = 65;

        cout << "Enter length and width of capacity of cars" << endl;

        cin >> len;
        cin >> wid;

        ParkingSpace parkingSpace(len,wid,start,a,name);
    }
}

void ParkingLot::createParkingCharges(){
    string chargesFileName = "parking_charges.json";

    fstream chargesFile(chargesFileName);

    if(chargesFile){

        nlohmann::json details;
        chargesFile >> details;

        chargesFile.close();

        double b, c;

        c = details["Parking Charges"]["car Charges"];
        b = details["Parking Charges"]["bike Charges"];

        ParkingCharges z(b,c);
        charges = z;

    }
    else{
        cout << "create parking charges for vehicles" << endl;

        double bike, car;

        cout << "Enter Bike charges and Car charges" << endl;
        cin >> bike;
        cin >> car;

        ParkingCharges c(bike,car);
        charges = c;
    }
}

void ParkingLot::addCar(const Car& c){
    cars.push_back(c);
    int count = 0;
    for(auto& i: carParkingSpaces) {
        if(cars[cars.size() - 1].getParkingSpace() == i)
            carParkingAvailable[count] = false;
        count++;
    }
    carSpacesLeft--;
    finance->addCar(charges.getCarCharges());
}

void ParkingLot::deleteCar(const string& license){
    int q = -1;

    for(int i = 0; i < cars.size(); i++){

        if(cars[i].getLicensePlate() == license){
            cars[i].removeVehicleFromParking(license);
            q = i;
            carSpacesLeft--;
        }
    }

    if(q != -1){
        for(int i = 0; i < carParkingAvailable.size(); i++){

            if(cars[q].getParkingSpace() == carParkingSpaces[i])
                carParkingAvailable[i] = true;
        }

        for(int i = q; i < cars.size() - 1; i++){

            cars[i] = cars[i + 1];
        }
    }
    else
        cerr << "No such car present" << endl;
}

void ParkingLot::addBike(const Bike& z){
    bikes.push_back(z);
    int count = 0;

    for(auto& i: carParkingSpaces) {

        if(bikes[bikes.size() - 1].getParkingSpace() == i)
            bikeParkingAvailable[count] = false;
        count++;
    }
    bikeSpacesLeft--;
    finance->addBike(charges.getBikeCharges());
}

void ParkingLot::deleteBike(const string& license){
    int q = -1;

    for(int i = 0; i < bikes.size(); i++){

        if(bikes[i].getLicensePlate() == license){
            bikes[i].removeVehicleFromParking(license);
            q = i;
            bikeSpacesLeft--;
        }
    }
    if(q != -1){
        for(int i = 0; i < bikeParkingAvailable.size(); i++){

            if(bikes[q].getParkingSpace() == bikeParkingSpaces[i])
                bikeParkingAvailable[i] = true;
        }

        for(int i = q; i < bikes.size() - 1; i++){

            bikes[i] = bikes[i + 1];
        }
    }
    else
        cerr << "no such bike present" << endl;
}

int ParkingLot::getCarSpacesLeft() const{return carSpacesLeft; }

int ParkingLot::getBikeSpacesLeft() const{return bikeSpacesLeft; }

string ParkingLot::getModel(const string& license){
    bool found = false;
    string m;
    for(auto & car : cars){
        if(car.getLicensePlate() == license){
            found = true;
            m = car.getModel();
        }
    }
    if(!found){
        for(auto & bike : bikes){
            if(bike.getLicensePlate() == license){
                m = bike.getModel();
            }
        }
    }
    return m;
}

string ParkingLot::getLicensePlate(const string& id){
    bool found = false;
    string m;
    for(auto & car : cars){
        if(car.getParkingSpace() == id){
            found = true;
            m = car.getLicensePlate();
        }
    }
    if(!found){
        for(auto & bike : bikes){
            if(bike.getParkingSpace() == id){
                m = bike.getLicensePlate();
            }
        }
    }
    return m;
}
bool ParkingLot::vehicleIs(const string& license){
    bool f = false;
    for(auto& i: cars){
        if(i.getLicensePlate() == license)
            f = true;
    }
    if(!f) {
        for (auto &i: bikes) {
            if (i.getLicensePlate() == license)
                f = true;
        }
    }
    return f;
}

double ParkingLot::bikeCharge(){return charges.getBikeCharges();}

double ParkingLot::CarCharge(){return charges.getCarCharges();}

string ParkingLot::getParkingId(const string& license){
    bool f = false;
    string c;
    for(auto& i: cars){
        if(i.getLicensePlate() == license) {
            f = true;
            c = i.getParkingSpace();
        }
    }
    if(!f) {
        for (auto &i: bikes) {
            if (i.getLicensePlate() == license) {
                c = i.getParkingSpace();
            }
        }
    }
    return c;
}

void ParkingLot::updateCharges(string c, double d){
    charges.updateParkingCharges(c,d);
}

void ParkingLot::printAllCars(){
    for(auto& i : cars){
        cout << i;
    }
}

void ParkingLot::printAllBikes(){
    for(auto& i : bikes){
        cout << i;
    }
}

void ParkingLot::printBike(const string& l){
    for(auto& i : bikes){
        if(i.getLicensePlate() == l)
            cout << i;
    }
}

void ParkingLot::printCar(const string& l){
    for(auto& i : cars){
        if(i.getLicensePlate() == l)
            cout << i;
    }
}

ParkingLotFinance *ParkingLot::getFinance(){
    return finance;
}

void ParkingLot::setMonth(string m){
    finance->setMonth(m);
}

void ParkingLot::setYear(string y){
    finance->setYear(y);
}

void ParkingLot::printBikeSpaces() {
    int c = 0;
    string green = "\033[32m";
    string red = "\033[31m";
    string reset = "\033[0m";
    for(int i = 0; i < bikeParkingAvailable.size(); i++){

        if(c % 10 == 0){
            cout << endl;
        }

        if(bikeParkingAvailable[i])
            cout << green << bikeParkingSpaces[i] << "   " << reset;
        else
            cout << red << bikeParkingSpaces[i] << "   " << reset;

        c++;
    }
}

void ParkingLot::printCarSpaces() {
    int c = 0;
    string green = "\033[32m";
    string red = "\033[31m";
    string reset = "\033[0m";
    for(int i = 0; i < carParkingAvailable.size(); i++){

        if(c % 9 == 0){
            cout << endl;
        }

        if(carParkingAvailable[i])
            cout << green << carParkingSpaces[i] << "   " << reset;
        else
            cout << red << carParkingSpaces[i] << "   " << reset;

        c++;
    }
}

bool ParkingLot::carSpaceIs(string x){
    bool found = false;
    int w = 0;
    for(auto& i: carParkingSpaces){
        if(i == x) {
            if(carParkingAvailable[w])
                found = true;
        }
        w++;
    }
    return found;
}

bool ParkingLot::bikeSpaceIs(string x){
    bool found = false;
    int w = 0;
    for(auto& i: bikeParkingSpaces){
        if(i == x) {
            if(bikeParkingAvailable[w])
                found = true;
        }
        w++;
    }
    return found;
}

void ParkingLot::parkingLotMenu(){
    cout << "===== Parking Lot Management System =====" << endl;
    cout << "1. Add a car" << endl;
    cout << "2. Remove a car" << endl;
    cout << "3. Add a bike" << endl;
    cout << "4. Remove a bike" << endl;
    cout << "5. View available car spaces" << endl;
    cout << "6. View available bike spaces" << endl;
    cout << "7. View model of a Vehicle" << endl;
    cout << "8. View license plate of a vehicle" << endl;
    cout << "9. Check if a vehicle is in the parking lot" << endl;
    cout << "10. View total earnings from cars" << endl;
    cout << "11. View total earnings from bikes" << endl;
    cout << "12. View charge for a bike" << endl;
    cout << "13. View charge for a car" << endl;
    cout << "14. Get parking ID of a vehicle" << endl;
    cout << "15. Update parking charges" << endl;
    cout << "16. Print all cars" << endl;
    cout << "17. Print all bikes" << endl;
    cout << "18. Print details of a bike" << endl;
    cout << "19. Print details of a car" << endl;
    cout << "20. Add maintenance cost" << endl;
    cout << "21. Add cleaning cost" << endl;
    cout << "22. Add repairment cost" << endl;
    cout << "23. Add electricity cost" << endl;
    cout << "24. View finance report" << endl;
    cout << "0. Exit" << endl;
    cout << "=========================================" << endl;
}

void ParkingLot::parkingLotMain(){
    int choice;

    createCarParkingSpace();
    createBikeParkingSpace();
    createParkingCharges();

    cout << "enter month: ";
    string m;
    cin >> m;
    cout << "enter year: ";
    string yy;
    cin >> yy;
    setYear(yy);
    setMonth(m);

    do {
        parkingLotMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                // Add a car
                if(getCarSpacesLeft() >= 1) {
                    printCarSpaces();
                    cout << endl;
                    string reset = "\033[0m";
                    cout << reset << "enter car license plate and model" << endl;
                    string l;
                    cin.ignore();
                    getline(cin, l);
                    getline(cin, m);

                    string space;
                    cout << "enter parking space: ";
                    getline(cin, space);

                    while (!carSpaceIs(space)) {
                        cerr << "enter parking space: ";
                        getline(cin, space);
                    }
                    Car car(l, m, space);
                    addCar(car);
                }
                else
                    cerr << "Parking Lot full" << endl;
                break;
            }
            case 2: {
                // Remove a car
                cout << "enter license plate: ";
                string l;
                cin.ignore();
                getline(cin,l);
                deleteCar(l);
                break;
            }
            case 3: {
                // Add a bike
                if(getBikeSpacesLeft() >= 1) {
                    printBikeSpaces();
                    cout << endl;
                    string reset = "\033[0m";
                    cout << reset << "enter bike license plate and model" << endl;
                    string l;
                    cin.ignore();
                    getline(cin, l);
                    getline(cin, m);

                    string space;
                    cout << "enter parking space: ";
                    getline(cin, space);

                    while (!bikeSpaceIs(space)) {
                        cerr << "enter parking space: ";
                        getline(cin, space);
                    }

                    Bike c(l, m, space);
                    addBike(c);
                }
                else
                    cerr << "Parking lot is full" << endl;
                break;
            }
            case 4: {
                // Remove a bike
                cout << "enter license plate: ";
                string l;
                getline(cin,l);
                deleteBike(l);
                break;
            }
            case 5: {
                // View available car spaces
                printCarSpaces();
                cout << "Spaces left: " << getCarSpacesLeft() << endl;
                break;
            }
            case 6: {
                // View available bike spaces
                printBikeSpaces();
                cout << "Spaces left: " << getBikeSpacesLeft() << endl;
                break;
            }
            case 7: {
                // View model of a car
                cout << "enter license plate: ";
                string l;
                cin.ignore();
                getline(cin,l);
                cout << "Model: " << getModel(l) << endl;
                break;
            }
            case 8: {
                // View license plate of a vehicle
                cout << "Enter Parking Space ID: ";
                string l;
                cin.ignore();
                getline(cin,l);
                cout << "License Plate: " << getLicensePlate(l) << endl;
                break;
            }
            case 9: {
                // Check if a vehicle is in the parking lot
                cout << "enter license plate: ";
                string l;
                cin.ignore();
                getline(cin,l);
                if(vehicleIs(l))
                    cout << "The vehicle is present" << endl;
                else
                    cout << "The vehicle is not present" << endl;
                break;
            }
            case 10: {
                // View total earnings from cars
                cout << "Total Earning: " << getFinance()->getCarTotal() << endl;
                break;
            }
            case 11: {
                // View total earnings from bikes
                cout << "Total Earning: " << getFinance()->getBikeTotal() << endl;
                break;
            }
            case 12: {
                // View charge for a bike
                cout <<"Bike Parking Charges: " << bikeCharge() << endl;
                break;
            }
            case 13: {
                // View charge for a car
                cout <<"Car Parking Charges: " << CarCharge() << endl;
                break;
            }
            case 14: {
                // Get parking ID of a vehicle
                cout << "enter the license plate number: ";
                string x;
                cin.ignore();
                getline(cin,x);
                cout << "Parking Id: " << getParkingId(x) << endl;
                break;
            }
            case 15: {
                // Update parking charges
                string x;
                double y;
                int z;
                cout << "Enter: \n"
                        "1: Car charges\n"
                        "2: Bike charges\n";
                cin >> z;
                while(z < 1 || z > 2){
                    cerr << "wrong choice" << endl;
                    cout << "Enter: \n"
                            "1: Car charges\n"
                            "2: Bike charges\n";
                    cin >> z;
                }
                if(z == 1)
                    x ="car";
                if(z == 2)
                    x = "bike";
                cout << "enter updated cost: ";
                cin >> y;
                updateCharges(x,y);
                break;
            }
            case 16: {
                // Print all cars
                printAllCars();
                break;
            }
            case 17: {
                // Print all bikes
                printAllBikes();
                break;
            }
            case 18: {
                // Print details of a bike
                cout << "enter license plate number: ";
                string x;
                cin.ignore();
                getline(cin,x);
                printBike(x);
                break;
            }
            case 19: {
                // Print details of a car
                cout << "enter license plate number: ";
                string x;
                cin.ignore();
                getline(cin,x);
                printCar(x);
                break;
            }
            case 20:{
                // Add maintenance cost
                cout << "Enter the cost" << endl;
                double w;
                cin >> w;
                finance->setMaintenanceCost(w);
                break;
            }
            case 21:{
                // Add cleaning cost
                cout << "Enter the cost" << endl;
                double w;
                cin >> w;
                finance->setCleaningCost(w);
                break;
            }
            case 22:{
                // Add repairment cost
                cout << "Enter the cost" << endl;
                double w;
                cin >> w;
                finance->setRepairmentCost(w);
                break;
            }
            case 23:{
                // Add electricity cost
                cout << "Enter the cost" << endl;
                double w;
                cin >> w;
                finance->setElectricityBill(w);
                break;
            }
            case 24:{
                // View finance report
                cout << "Finance Report: " << endl;
                cout << *finance << endl;
                break;
            }
            case 0: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a number from the menu." << endl;
                break;
            }
        }
    } while(choice != 0);
}

void ParkingLot::addMaintenanceCost(double x){
    finance->setMaintenanceCost(x);
}

void ParkingLot::addRepairmentCost(double y){
    finance->setRepairmentCost(y);
}

void ParkingLot::addCleaningCost(double z){
    finance->setCleaningCost(z);
}

void ParkingLot::addElectricityCost(double a){
    finance->setElectricityBill(a);
}
