//
// Created by APPLE on 07/04/2024.
//


#ifndef PRIVATE_PROJECT_DESSERT_H
#define PRIVATE_PROJECT_DESSERT_H


#include "Dish.h"
using namespace std;

class Dessert : public Dish {
private:
    bool toppings;

public:
    Dessert();
    Dessert(std::string name, std::string description, double price, bool toppings);
    void display() override;
    void displayMenu() override;
    void makeDish() override;
    friend istream &operator>>(istream &is, Dessert &other);

    json writeToJson() override
    {   json j;
        j=Dish::writeDishToJson();
        j["toppings"]=toppings;
        return j;
    }

    void readFromJson(json& j) override
    {
        readDishToJson(j);
        toppings=j["toppings"];
    }


};


#endif //PRIVATE_PROJECT_DESSERT_H
