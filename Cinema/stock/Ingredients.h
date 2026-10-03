//
// Created by Dell on 02/04/2024.
//

#ifndef INC_2024_SPRING_SE102LB_WEEK9_BSSE23047_INGREDIENTS_H
#define INC_2024_SPRING_SE102LB_WEEK9_BSSE23047_INGREDIENTS_H

#include "iostream"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "./../../nlohmann/json.hpp"


using namespace std;
using json = nlohmann::json;
class Ingredients {
private:
    std::string name;
    std::string unit;
    double price;
    double quantity;
    bool organic;

public:
    Ingredients();

    Ingredients(std::string name, std::string unit, double price, double quantity, bool organic = false);

    double getPrice() const;

    std::string getName() const;

    std::string getUnit() const;

    double getQuantity() const{ return quantity; }

    bool isOrganic() const;

    void setPrice(double price1) {
        this->price = price1;
    }

    void add(double num);

    void remove(double num);

    void displayIngredient() const;

    double calculateCost() const;

//    void addAllergy(const std::string &allergy);
//
//    void removeAllegy(const std::string &allergy);
//
//    void displayAllergies() const;



    static Ingredients readFromJson(json& j) {
        Ingredients ingredients;
        ingredients.name=j["name"];
        ingredients.unit=j["unit"];
        ingredients.price=j["price"];
        ingredients.quantity=j["quantity"];
        ingredients.organic=j["organic"];
               return ingredients;
    }


    json writeToJson() const {
        json j;
        j["name"] = name;
        j["unit"] = unit;
        j["price"] = price;
        j["quantity"] = quantity;
        j["organic"] = organic;

        return j;
    }

    friend istream& operator >>(istream& is , Ingredients & other);

};

void allergyMenu();

istream& operator >>(istream & is , Ingredients & other);

#endif //INC_2024_SPRING_SE102LB_WEEK9_BSSE23047_INGREDIENTS_H
