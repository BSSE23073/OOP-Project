#include <iostream>
#include "Order.h"
using namespace std;
#ifndef PRIVATE_PROJECT_3_TABLE_H
#define PRIVATE_PROJECT_3_TABLE_H
class Table {
    int tableID;
    int status;
    vector<string> seat;
    int seatingCapacity;
    vector<Order> orders;
public:
    Table();
    Table(int tableID, int seatingCapacity);
    int getTableId() const;
    void setTableId(int tableID);
    int getStatus() const;
    void setStatus(int status);
    vector<string> getSeat() const;
    void setSeat(vector<string> seat);
    int getSeatingCapacity() const;
    void setSeatingCapacity(int seatingCapacity);
    void addOrder(Order order);
    void getOrders();
    void clearTable()
    {
        seat.clear();
        orders.clear();
    }
    ~Table();
};

#endif //PRIVATE_PROJECT_3_TABLE_H
