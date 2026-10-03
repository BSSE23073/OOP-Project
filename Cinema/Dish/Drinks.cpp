//
// Created by APPLE on 07/04/2024.
//

#include "Drinks.h"
Drinks::Drinks(std::string name, std::string description, double price, std::string type)
        : Dish(name, description, price,"Drinks"), type(type) {}

void Drinks::display() {
    std::cout << "\nDrink: " << std::endl;
    Dish::display();
    std::cout << "Type: " << type << std::endl;
}

void Drinks::makeDish(){
    for (auto i: ingredients) {
        Stock::getInstance()->removeIngredient(i.getName(), i.getQuantity(), 2);
    }
}


istream &operator>>(istream &is, Drinks &other) {
    cout << "Enter Name : ";
    is.ignore();
    getline(is,other.name);
    cout << "Enter Description :";
    getline(is,other.description);
    cout << "Enter Type of Drink :";
    getline(is,other.type);
    cout << "Enter Price :";
    is >> other.price;

    cout << "Enter Number of ingredients added :";
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        Ingredients temp;
        cin >> temp;
        other.ingredients.push_back(temp);
    }return is;
}


Drinks::Drinks():Dish("","",0,"Drinks") {

}

void Drinks::displayMenu() {
    std::cout << "\nDrink: " << std::endl;
    Dish::displayMenu();
}
