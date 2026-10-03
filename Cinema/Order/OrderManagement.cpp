//
// Created by APPLE on 28/04/2024.
//

#include "OrderManagement.h"
OrderManagement* OrderManagement::instance= nullptr;

OrderManagement::OrderManagement()
{

}

bool OrderManagement::assignID(int id)
{
    if (orderIDs[id])
    {
        cout<<"ID already exist.. Add another ID\n ";
        return false;
    }
    else
    {
        orderIDs[id] = true;
        return true;
    }
}

void OrderManagement::display()
{
    for (int i = 0; i < orders.size(); ++i) {
        cout<<"Order ID: "<<orders[i]->getOrderID();
        orders[i]->displayOrder();
    }
}
double OrderManagement::calculateTotalPrice() {
    double totalPrice = 0.0;
    for (int i = 0; i < orders.size(); ++i) {
        totalPrice += orders[i]->calculatePrice();
    }
    return totalPrice;
}

void OrderManagement::serveOrderToTable(int id)
{
    for (int i = 0; i < orders.size(); ++i) {
        if (orders[i]->getOrderID()==id)
        {
            orders.erase(orders.begin()+i);
            TableManagement* tableManager = TableManagement::getInstance();
            tableManager->addOrderToTable(orders[i]->getCustomer(), *orders[i]);
        }
    }
}


void OrderManagement::addOrder()
{
    string name;
    int age;
    cin.ignore();
    cout<<"Enter Name of the Customer: \n";
    getline(cin,name);
    cout<<"Enter Age of Customer: \n";
    cin>>age;
    Order* order = new Order;       //   DMA
    order->setCustomer(name);
    int num;
    int orderID;
    do
    {
        cout<<"Enter Order ID: "<<endl;
        cin>>orderID;
    } while (!assignID(orderID));
    
    cout<<"Enter number of dishes to add: " << endl;
    cin>>num;
    cin.ignore();
    for (int i = 0; i < num; ++i) {
        string line;
        do
        {
            cout<<"Enter the dish Name: "<<endl;
            getline(cin,line);
        } while (!order->takeOrder(line));
        
    }
    order->setOrderID(orderID);
    int choice1=0;
    while (choice1!=1)
    {
        cout<<"1.Confirm dish"<<endl;
        cout<<"2.Edit dish"<<endl;
        cin>>choice1;
        if (choice1==1)
        {
            cout<<"Order Confirmed\n"<<endl;
            order->setPrice(order->calculatePrice());
            break;
        }
        else if (choice1==2)
        {
            string name1;
            cin.ignore();
            cout<<"Enter Name to delete Dish: "<<endl;
            getline(cin,name1);
            order->deleteDish(name1);
            break;
        }
    }
    BookingManagement::getInstance()->addOrderToCustomer(name,age,*order);
    orders.push_back(order);
}

void OrderManagement::writeOrderToJson()
{
    json dishes;
    for(auto i: orders) {
        dishes.push_back(i->getOrderToJson());
    }
    cout<<dishes;
    ofstream write("Cinema/Order/Orders.json", ios::out);
    if (write.is_open()) {
        // function return json then store it nto file
        write << dishes.dump(2);
    } else {
        cerr << "file is not open" << endl;
    }
}
void OrderManagement::readFromJson(){
    ifstream readOrders("Cinema/Order/Orders.json", ios :: in);
    if (!readOrders.is_open()) {
        cerr << "Failed to open JSON file." << endl;
        return;
    }
    json ordersData;
    readOrders >> ordersData;
    readOrders.close();
    for(auto &i:ordersData){
        auto *ptr = new Order;
        *ptr = Order::getOrderFromJson(i);
        orders.push_back(ptr);
    }
}

void OrderMenu() {
    OrderManagement* orderManagement = OrderManagement::getInstance();
    int choice1;
    while (choice1 != 6) {
        cout << "1.Order Dish" << endl;
        cout << "2.Display order" << endl;
        cout << "3.Generate Invoice" << endl;
        cout << "4. Serve Order"<< endl;
        cout <<"5. Table Menu"<< endl;
        cout <<"6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice1;
        switch (choice1) {
            case 1: {
                orderManagement->addOrder();
                break;
            }
            case 2: {
                orderManagement->display();
                break;
            }
            case 3: {
                // Calculate the total price
                double totalPrice = orderManagement->calculateTotalPrice();

                // Display the total price
                cout << "Total price of all dishes: $" << totalPrice << endl;
                break;
            }
            case 4: {
                int id;
                cout<<"Enter Order ID: "<<endl;
                cin>>id;
                orderManagement->serveOrderToTable(id);
                break;
            }
            case 5:
            {
                TableManagement::getInstance()->TableMenu();
                break;
            }
            case 6:
            {
                cout<<"Exiting\n";
                break;
            }
            default:
                cout << "Invalid Choice.." << endl;
                break;
        }
    }
}