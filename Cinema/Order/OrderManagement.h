#include "Order.h"
#include <unordered_map>
#include "./../Booking/BookingManagement.h"
#include "TableManagement.h"
#ifndef ROUGHH_SHEET_2_ORDERMANAGEMENT_H
#define ROUGHH_SHEET_2_ORDERMANAGEMENT_H
class OrderManagement {
    vector<Order*>orders;
    unordered_map<int,bool > orderIDs;
    static OrderManagement *instance;
    OrderManagement();
public:
    static OrderManagement* getInstance(){
        if (!instance){instance = new OrderManagement;

        }
        return instance;
    }
    string getName1()
    {
        Dish* d;
        return d->getName();
    }
     vector<Order*>& getOrders(); {
        return orders;
    }
    void display();
    double calculateTotalPrice();
    bool assignID(int id);
    void addOrder();
    void serveOrderToTable(int id);
    ~OrderManagement()
    {
        for(auto i : orders)
        {
            delete i;
        }
    }
    void writeOrderToJson();

    void readFromJson();
};
void OrderMenu();

#endif //ROUGHH_SHEET_2_ORDERMANAGEMENT_H
