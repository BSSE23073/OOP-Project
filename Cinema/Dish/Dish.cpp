
#include <iostream>
#include "Dish.h"

using namespace std;

Dish::Dish(std::string name, std::string description, double price,string dishType) {
    this->name = name;
    this->description = description;
    this->price = price;
    this->dishType=dishType;

}

void Dish::addIngredient(Ingredients ingredient) {
    ingredients.push_back(ingredient);
}

void Dish::display() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "\tIngredients:" << std::endl;
    for (const auto &ingredient: ingredients) {
        cout << "Name : " << ingredient.getName() << "\tQuantity :" << ingredient.getQuantity() << endl;
    }
}

double Dish::calculateCost() {
    double totalCost = 0.0;
    for (auto &ingredient: ingredients) {
        totalCost += ingredient.calculateCost();
    }
    return totalCost;
}

void Dish::displayMenu() {
    std::cout << "Name: " << name;
    std::cout << " , Description: " << description;
    std::cout << " , Price: " << price;
}

double Dish::calculateProductionCost() {
    double productionCost = 0.0;
    for (auto &ingredient : ingredients) {
        for (auto &k: Stock::getInstance()->getIngredients()) {
            if (ingredient.getName() == k->getName()) {
                productionCost = productionCost + (ingredient.getQuantity() * k->getPrice());
            }
        }
    }
    return productionCost;
}