#include<iostream>
#include "TableManagement.h"


TableManagement* TableManagement::instance = nullptr;

TableManagement::TableManagement (){
    //Creating tables dynamically
    for (int i = 0; i < MAX_TABLES; ++i) {
        tables[i] = new Table(i + 1, i + 2); // example: Table ID starts from 1, seating capacity increases by 1
    }
}

TableManagement* TableManagement::getInstance()
{
    if(!instance)
        instance = new TableManagement;
    return instance;
}

void TableManagement::TableMenu() {

    int choice;
    do {
        cout << "1. Reserve Table\n";
        cout << "2. Release Table\n";
        cout << "3. Check Table Status\n";
        cout << "4. Display Tables Status\n";
        cout << "5. Seat Customer(s) At Table\n"; 
        cout << "6. Check orders on table\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int tableID;
                cout << "Enter Table ID to reserve: ";
                cin >> tableID;
                if (tableID >= 1 && tableID <= MAX_TABLES) {
                    Table* table = tables[tableID];
                    if (!table->getStatus()) {
                        table->setStatus(1);
                        cout << "Table " << table->getTableId() << " reserved successfully.\n";
                    } else {
                        cout << "Table " << table->getTableId() << " is already reserved.\n";
                    }
                } else {
                    cout << "Invalid Table ID.\n";
                }
                break;
            }
            case 2: {
                int tableID;
                cout << "Enter Table ID to release: ";
                cin >> tableID;
                if (tableID >= 1 && tableID <= MAX_TABLES) {
                    Table* table = tables[tableID];
                    if (table->getStatus()) {
                        table->setStatus(0);
                        table->clearTable();
                        cout << "Table " << table->getTableId() << " released successfully.\n";
                    } else {
                        cout << "Table " << table->getTableId() << " is already available.\n";
                    }
                } else {
                    cout << "Invalid Table ID.\n";
                }
                break;
            }
            case 3: {
                int tableID;
                cout << "Enter Table ID to check status: ";
                cin >> tableID;
                if (tableID >= 1 && tableID <= MAX_TABLES) {
                    Table* table = tables[tableID];
                    if (table->getStatus()) {
                        cout << "Table " << table->getTableId() << " is reserved.\n";
                    } else {
                        cout << "Table " << table->getTableId() << " is available.\n";
                    }
                } else {
                    cout << "Invalid Table ID.\n";
                }
                break;
            }
            case 4: {
                cout << "Table Status:\n";
                for (int i = 0; i < MAX_TABLES; ++i) {
                    int status = tables[i]->getStatus();
                    const string statuses[3] = {"Available", "Reserved", "Seated"};

                    cout << "Table " << tables[i]->getTableId() << ": " << statuses[status] << endl; 
                    vector<string> seats = tables[i]->getSeat();
                    cout << "{ ";
                    for(string name: seats)
                        cout << name << " ";
                    cout << " }" << endl;
                }
                break;
            }
            case 5:
                {
                    bool canSeat = true;
                    int customersAmount, tableID;
                    do 
                    {
                        cout << "How many customers: ";
                        cin >> customersAmount;
                        cout << "Enter Table ID: ";
                        cin >> tableID;
                        if(customersAmount > tables[tableID]->getSeatingCapacity())
                        {
                            canSeat = false;
                            cout << "Table capacity is not enough\n";
                        }             
                    }while(!canSeat);

                    vector<string> customers;
                    string customerName;
                    for(int i = 0; i < customersAmount; i++)
                    {
                        cin.ignore();
                        cout << "Enter Customer " << i + 1 << " Name: ";
                        getline(cin, customerName);
                        customers.push_back(customerName);
                    }

                    tables[tableID]->setSeat(customers);
                    tables[tableID]->setStatus(2);
                    break;
                }
            case 6:
                {
                    int tableID;
                    cout << "Enter table ID to check: ";
                    cin >> tableID;
                    tables[tableID]->getOrders();
                    break;
                }
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

void TableManagement::addOrderToTable(string customerName, Order order)
{
    for(Table* table: tables)
    {
        vector<string> customers;
        customers = table->getSeat();
        for(string name: customers)
        {
            if(name == customerName)
            {
                table->addOrder(order);
                return;
            }
        }
    }
}

TableManagement::~TableManagement()
{
    // Deallocating memory for tables
    for (int i = 0; i < MAX_TABLES; ++i) {
        delete tables[i];
    }
}