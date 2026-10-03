//
// Created by APPLE on 27/04/2024.
//
#include <iostream>
#include "Order.h"

using namespace std;

Order :: Order() {
    orderID = 0;
    price = 0;
}

void Order :: displayOrder() {
    for (int i = 0; i < orderedDishes.size(); ++i) {

        orderedDishes[i]->display();
    }
}

void Order :: deleteDish(const std::string &dishName) {
    int index = 0;
    bool check = false;
    for (auto it: DishManager::getInstance()->getDishes()) {

        if (it->getName() == dishName) {
            check = true;
            orderedDishes.erase(DishManager::getInstance()->getDishes().begin() + index);
            std::cout << "Dish '" << dishName << "' deleted from order." << std::endl;
        }
        index++;
    }
    if (!check) {
        cout << "Dish '" << dishName << "' not found in available dishes." << endl;
    }
}



double Order::calculatePrice() {
    double totalPrice = 0.0;
    for (int i = 0; i < orderedDishes.size(); ++i) {
        totalPrice += orderedDishes[i]->getPrice();
    }
    return totalPrice;
}

bool Order::takeOrder(const std::string &dishName) {
   
    for (auto it: DishManager::getInstance()->getDishes()) {
        if (it->getName() == dishName) {
            orderedDishes.push_back(it);
            std::cout << "Dish '" << dishName << "' added to the order." << std::endl;
            return true;
        }
    }
    
    cout << "Dish '" << dishName << "' not found in available dishes." << endl;
    return false;
}

void Order::makeInvoiceForOrder()
{
    cout<<"Bill for Order ID: "<<orderID<<endl;
    calculatePrice();
}

json Order::getOrderToJson()
{
    json orderData;
    orderData["Order Id"] = orderID;
    orderData["Order Price"] = price;
    json dishData;
    for (int k = 0; k < orderedDishes.size(); ++k) {
        dishData.push_back(orderedDishes[k]->writeDishToJson());
    }
    orderData["Dishes"] = dishData;
    return orderData;
}

//Order Order::getOrderFromJson(json &orderData) {
//    Order order;
//    order.orderID = orderData["Order Id"];
//    order.price = orderData["Order Price"];
//    for (auto &i: orderData["Dishes"]){
//        Dish *ptr;
//        ptr->readDishToJson(i);
//        order.orderedDishes.push_back(ptr);
//    }
//    return order;
//}

Order Order::getOrderFromJson(json &orderData) {
    Order order;
    order.orderID = orderData["Order Id"];
    order.price = orderData["Order Price"];
    for (auto &i:orderData["Dishes"]) {
        Dish *ptr;
        if(i["dishType"]=="MainCourse"){
            ptr= new MainCourse();
        }
        if(i["dishType"]=="Starter"){
            ptr= new Starter();
        }
        if(i["dishType"]=="Drinks"){
            ptr= new Drinks();
        }
        if(i["dishType"]=="Dessert"){
            ptr= new Dessert();
        }
        ptr->readFromJson(i);
        order.orderedDishes.push_back(ptr);
    }
    return order;
}
