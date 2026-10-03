

#ifndef INC_2024_SPRING_SE102LB_WEEK9_BSSE23047_DISH_H
#define INC_2024_SPRING_SE102LB_WEEK9_BSSE23047_DISH_H

#include <iostream>
#include <vector>
#include "./../stock/Ingredients.h"
#include "./../stock/Stock.h"
#include "./../../nlohmann/json.hpp"


using namespace std;
using json = nlohmann::json;
class Dish {
protected:
    std::string name;
    std::string description;
    double price;
    string dishType;
    std::vector<Ingredients> ingredients;

public:

    std::string getName(){return name;}
    Dish(std::string name, std::string description, double price, string dishType);
    void  addIngredient(Ingredients ingredient);
    virtual void makeDish()=0;
    virtual void display();
    virtual void displayMenu();
    virtual double calculateCost();



     json writeDishToJson() {
         json j, v , l;
         j["name"] = name;
         j["Description"] = description;
         j["price"] = price;
         j["dishType"]=dishType;
         for (auto &i: ingredients) {
             for (auto &k: Stock::getInstance()->getIngredients())
                 if (i.getName() == k->getName()) {
                     l["name"] = k->getName();
                     l["unit"] = k->getUnit();
                     l["price"] = k->getPrice();
                     l["quantity"] = i.getQuantity();
                     l["organic"] = k->isOrganic();
                     v.push_back(l);
                 }
         }
         j["ingredients"] = v;
         return j;
     }


    virtual json writeToJson()=0;


     void readDishToJson(json &j) {
        name = j["name"];
        description = j["Description"];
        price = j["price"];
        dishType=j["dishType"];
        for (auto &i: j["ingredients"]) {
            ingredients.push_back(Ingredients::readFromJson(i));
        }
    }

    virtual void readFromJson(json& j)=0;


    virtual ~Dish() {
        ingredients.clear();
    }

    double calculateProductionCost();

    double getPrice(){
        return price;
    }

};


#endif //INC_2024_SPRING_SE102LB_WEEK9_BSSE23047_DISH_H
