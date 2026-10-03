//
// Created by APPLE on 07/04/2024.
//


#ifndef PRIVATE_PROJECT_STARTER_H
#define PRIVATE_PROJECT_STARTER_H

#include "Dish.h"

using namespace std;
class Starter : public Dish {
private:
    bool vegetarian;

public:
    Starter();

    Starter(std::string name, std::string description, double price, bool vegetarian);
    void display() override;
    void makeDish()override;
    void displayMenu() override;

    friend istream &operator>>(istream &is, Starter &other);

    json writeToJson() override
    {   json j;
        j=Dish::writeDishToJson();
        j["vegetarian"]=vegetarian;
        return j;
    }

    void readFromJson(json& j) override
    {
        readDishToJson(j);
        vegetarian=j["vegetarian"];

    }

};


#endif //PRIVATE_PROJECT_STARTER_H
