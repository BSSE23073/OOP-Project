#include <iostream>
#include "Table.h"
using namespace std;
#ifndef PRIVATE_PROJECT_3_TABLEMANAGEMENT_H
#define PRIVATE_PROJECT_3_TABLEMANAGEMENT_H
#define MAX_TABLES 10

class TableManagement {
    //const int maxTables = 10;
    static TableManagement* instance;
    Table* tables[MAX_TABLES];
    TableManagement();

public:
    static TableManagement* getInstance();
    void TableMenu();
    void addOrderToTable(string customerName, Order order);
    ~TableManagement();
};

#endif 