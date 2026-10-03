#include "./../Dish/DishManager.h"
#ifndef ROUGHH_SHEET_2_ORDER_H
#define ROUGHH_SHEET_2_ORDER_H
class Order {
    int orderID;
    double price;
    string customerName;
    vector<Dish*> orderedDishes ;
public:
    Order();
    void setPrice(double price){
    this->price = price;
}
    void displayOrder();
    bool takeOrder(const std::string& dishName);
    double calculatePrice();
    void deleteDish(const std::string& dishName);
    void setOrderID(int id){orderID=id;}
    int getOrderID()const{return orderID;}
    void makeInvoiceForOrder();
    json getOrderToJson();
    static Order getOrderFromJson(json &orderData);
    void setCustomer(string name)
    {
        this->customerName = name;
    }
    string getCustomer()
    {
        return customerName;
    }
};

#endif //ROUGHH_SHEET_2_ORDER_H
