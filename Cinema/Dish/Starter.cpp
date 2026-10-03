//
// Created by APPLE on 07/04/2024.
//
#include "Starter.h"

Starter::Starter(std::string name, std::string description, double price, bool vegetarian)
        : Dish(name, description, price,"Starter"), vegetarian(vegetarian) {}

void Starter::display() {
    cout << "\nStarter: " <<endl;
    Dish::display();
    cout << "Vegetarian: " << (vegetarian ? "Yes" : "No") <<endl;
}

void Starter::makeDish() {
    for(auto i : ingredients){
        Stock::getInstance()->removeIngredient(i.getName(), i.getQuantity(), 2);
    }
}

istream &operator>>(istream &is, Starter &other) {
    cout << "Enter Name : ";
    is.ignore();
    getline(is,other.name);
    cout << "Enter Description :";
    getline(is,other.description);
    cout << "1 for veg / 0 to Not \nEnter :";
    int num;
    cin >> num;
    if (num == 1) {
        other.vegetarian = true;
    } else if (num == 2) {
        other.vegetarian = false;
    }
    cout << "Enter Price :";
    is >> other.price;
    cout << "Enter Number of ingredients added :";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        Ingredients temp;
        cin >> temp;
        other.ingredients.push_back(temp);
    }

    return is;
}

Starter::Starter():Dish("","",0,"Starter") {
}

void Starter::displayMenu() {
    cout << "\nStarter: " <<endl;
    Dish::displayMenu();
    cout << "Vegetarian: " << (vegetarian ? "Yes" : "No") <<endl;

}
