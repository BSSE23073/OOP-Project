//
// Created by APPLE on 26/04/2024.
//
#include <iostream>
#include "Table.h"

using namespace std;

Table::Table()
{
    tableID=0;
    status = true;
    seatingCapacity=0;
}

Table::Table(int tableId, int seatingCapacity)
{
    this->tableID=tableId;
    this->seatingCapacity=seatingCapacity;
    this->status= false;
}
Table::~Table()
{
    cout<<"Destructor of seat.."<<endl;
}

int Table::getTableId() const {
    return tableID;
}

void Table::setTableId(int tableID) {
    this->tableID = tableID;
}

int Table::getStatus() const {
    return status;
}

void Table::setStatus(int status) {
    this->status = status;
}

vector<string> Table::getSeat() const {
    return seat;
}

void Table::setSeat(vector<string> seat) {
    this->seat = seat;
}

int Table::getSeatingCapacity() const {
    return seatingCapacity;
}

void Table::setSeatingCapacity(int seatingCapacity) {
    this->seatingCapacity = seatingCapacity;
}

void Table::addOrder(Order order)
{
    orders.push_back(order);
}

void Table::getOrders()
{
    for(Order order: orders)
    {
        order.displayOrder();
        cout << endl;
    }
}

