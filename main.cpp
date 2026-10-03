#include <iostream>
#include "Cinema/Movie/MovieRoaster.h"
#include "Cinema/Movie/Movie.h"
#include "Cinema/Showtime/ShowtimeManagement.h"
#include "Cinema/Booking/BookingManagement.h"
#include "Cinema/EmployeeManagement/EmployeeManagement.h"
#include "Cinema/ParkingLot/ParkingLot.h"
#include "Cinema/stock/Stock.h"
#include "Cinema/Dish/DishManager.h"
#include "Cinema/Order/OrderManagement.h"
#include "Cinema/HelpBot/HelpBot.h"

using namespace std;

int main() {
    DishManager* dishManager = DishManager::getInstance();
    Stock *stock = Stock::getInstance();
    HelpBot *helpBot = HelpBot::getInstance();
    stock->readIngredientsFromFile();
    dishManager-> readDishFromFile();
    helpBot->readFileFromJSON();
    ParkingLot *parkingLot = ParkingLot::getInstance();
    MovieRoaster *movieRoaster = MovieRoaster::getInstance();
    ShowtimeManagement *showtimeManagement = ShowtimeManagement::getInstance();
    BookingManagement *bookingManagement = BookingManagement::getInstance();
    showtimeManagement->readLoungeFromFile();
    movieRoaster->readDataFromFile();
    showtimeManagement->readShowtimeFromFile();
    bookingManagement->readOnlineUserFromFile();
    bookingManagement->readCustomerFromFile();
    bookingManagement->readBookingsFromFile();
    EmployeeManagement *empManagement = EmployeeManagement::getInstance();
    int choice;
    cout << "\tWelcome to the Cinema Management System" << endl;
    do {

        cout << "\n==============================" << endl;
        cout << "  Cinema Management System  " << endl;
        cout << "================================" << endl;
        cout << "1. Employee Management " << endl;
        cout << "2. Cinema Management " << endl;
        cout << "3. Restaurant Management" << endl;
        cout << "4. Parking Lot Management" << endl;
        cout << "5. Exit" << endl;

        cout << "================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                empManagement->displayEmployeeMenu();
                break;
            }
            case 2: {
                int choice1 = 0;
                while (choice1 != 4) {
                    cout << "\n=============================" << std::endl;
                    cout << "            Cinema      " << std::endl;
                    cout << "===============================" << std::endl;
                    cout << "Enter 1. Movie Management\n"
                            "2.Showtime management\n"
                            "3.Booking Management\n"
                            "4.Exit\n";
                    cout << "================================" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice1;
                    if (choice1 == 1) {
                        movieRoaster->menuForRoaster();
                    }
                    if (choice1 == 2) {
                        showtimeManagement->menuForShowtime();
                    }
                    if (choice1 == 3) {
                        bookingManagement->menuForManagement();
                    }
                    if (choice1 == 4) {
                        cout << "Exit...\n";
                    }
                }
                break;
            }
            case 3: {
                int choice1 = 0;
                while (choice1 != 3) {
                cout << "\n==============================" << endl;
                cout << "  Restaurant Management System  " << endl;
                cout << "================================" << endl;
                cout << "1. Stock Management" << endl;
                cout << "2. Order Manager" << endl;
                    cout << "3. Exit" << endl;
                    cout << "================================" << endl;
                    cout << "Enter your choice: ";
                cin>>choice1;
                    if (choice1==1){
                restaurantManagementSystem();
                    }
                    if (choice1==2){
                        OrderMenu();
                    }
                    if (choice1==3){
                        cout<<"Exit......\n";
                    }
                }
                break;
            }
            case 4: {
                parkingLot->parkingLotMain();
                break;
            }
            case 5:
                cout << "Exiting program" << endl;
                bookingManagement->writeBookingsToFile();
                bookingManagement->writeCustomerToFile();
                bookingManagement->writeOnlineUserToFile();
//                movieRoaster->writeDataToJson();
//                showtimeManagement->writeLoungeToFile();
//                showtimeManagement->writeShowtimeToFile();
                stock->sendIngredientsToJson();
                dishManager->sendToJson();
                helpBot->writeToJSON();
                 break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

