//
// Created by APPLE on 07/04/2024.
//
#ifndef PRIVATE_PROJECT_DRINKS_H
#define PRIVATE_PROJECT_DRINKS_H


#include "Dish.h"
#include "./../stock/Stock.h"
class Drinks : public Dish {
private:
    std::string type;

public:

    Drinks();
    Drinks(std::string name, std::string description, double price, std::string type);
    void display() override;
    void makeDish() override;
    void displayMenu() override;

    friend istream &operator>>(istream &is, Drinks &other);

    json writeToJson() override
    {   json j;
        j=Dish::writeDishToJson();
        j["type"]=type;
        return j;
    }

    void readFromJson(json& j) override
    {
        readDishToJson(j);
        type=j["type"];
    }


};


#endif //PRIVATE_PROJECT_DRINKS_H
