//
// Created by APPLE on 07/04/2024.
//

#include "MainCourse.h"

MainCourse::MainCourse():Dish("","",0,"MainCourse") {}



MainCourse::MainCourse(std::string name, std::string description, double price, bool spicy)
        : Dish(name, description, price,"MainCourse"), spicy(spicy) {}

void MainCourse::display() {
    std::cout << "\nMain Course: " << std::endl;
    Dish::display();
    std::cout << "Spicy: " << (spicy ? "Yes" : "No") << std::endl;
}

void MainCourse::makeDish() {
    for (const auto i: ingredients) {
        Stock::getInstance()->removeIngredient(i.getName(), i.getQuantity(), 2);
    }
}

istream &operator>>(istream &is, MainCourse &other) {
    cout << "Enter Name : ";
    is.ignore();
    getline(is,other.name);
    cout << "Enter Description :";
    getline(is,other.description);
    cout << "1 to spicy / 0 to Not \nEnter :";
    int num;
    cin >> num;

    if (num == 1) {
        other.spicy = true;
    } else if (num == 2) {
        other.spicy = false;
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

void MainCourse::displayMenu() {
    std::cout << "\nMain Course: " << std::endl;
    Dish::displayMenu();
    std::cout << "Spicy: " << (spicy ? "Yes" : "No") << std::endl;
}

