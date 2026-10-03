
//
// Created by APPLE on 07/04/2024.
//

#include "Dessert.h"

Dessert::Dessert(std::string name, std::string description, double price, bool toppings)
        : Dish(name, description, price,"Dessert"), toppings(toppings) {}

void Dessert::display() {
    std::cout << "\nDessert: " << std::endl;
    Dish::display();
    std::cout << "Toppings: " << (toppings ? "Yes" : "No") << std::endl;
}

void Dessert::makeDish() {
    for(auto i : ingredients){
        Stock::getInstance()->removeIngredient(i.getName(), i.getQuantity(), 2);
    }
}

istream &operator>>(istream &is, Dessert &other) {
    cout << "Enter Name : ";
    is.ignore();
    getline(is,other.name);
    cout << "Enter Description :";
    getline(is,other.description);
    cout << "do you want toppings?(1 for yes):";
    int num;
    cin >> num;
    if (num == 1) {
        other.toppings = true;
    } else if (num == 2) {
        other.toppings = false;
    }
    cout << "Enter Price :";
    is >> other.price;
    cout << "Enter Number of ingredients added :";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        Ingredients temp;
        cin >> temp;
        other.ingredients.push_back(temp);
    }return is;
}

Dessert::Dessert():Dish("","",0,"Dessert") {
}

void Dessert::displayMenu() {
    std::cout << "\nDessert: " << std::endl;
    Dish::displayMenu();
    std::cout << "Toppings: " << (toppings ? "Yes" : "No") << std::endl;
}
