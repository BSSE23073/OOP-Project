//
// Created by APPLE on 07/04/2024.
//

#ifndef PRIVATE_PROJECT_MAINCOURSE_H
#define PRIVATE_PROJECT_MAINCOURSE_H
#include "Dish.h"
#include "./../stock/Stock.h"
#include <iostream>



using namespace std;

class MainCourse : public Dish {
private:
    bool spicy;

public:
    MainCourse();

    MainCourse(std::string name, std::string description, double price, bool spicy);

    void display() override;

    void makeDish() override;

    void displayMenu() override;

    friend istream &operator>>(istream &is, MainCourse &other);


    json writeToJson() override
    {   json j;
        j=Dish::writeDishToJson();
        j["spicy"]=spicy;
        return j;
    }

    void readFromJson(json& j) override
    {
        readDishToJson(j);
        spicy=j["spicy"];
    }

};

istream &operator>>(istream &is, MainCourse &other);;

#endif //PRIVATE_PROJECT_MAINCOURSE_H
