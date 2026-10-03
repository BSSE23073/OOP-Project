//
// Created by Dell on 02/04/2024.
//
#include "Ingredients.h"
#include "Stock.h"


Ingredients::Ingredients() {
    unit = "";
    price = 0.0;
    organic = false;
}

Ingredients::Ingredients(std::string name, std::string unit, double price, double quantity, bool organic)
        : name(name), unit(unit), price(price), quantity(quantity), organic(organic) {}

double Ingredients::getPrice() const {
    return price;
}

std::string Ingredients::getName() const {
    return name;
}

std::string Ingredients::getUnit() const {
    return unit;
}

bool Ingredients::isOrganic() const {
    return organic;
}

void Ingredients::add(double num) {
    quantity += num;
    std::cout << "Added " << num << " " << unit << " of " << name << std::endl;
}

void Ingredients::remove(double num) {
    if (quantity >= num) {
        quantity -= num;
        std::cout << "Removed " << num << " " << unit << " of " << name << std::endl;
    } else {
        std::cout << "Insufficient quantity of " << name << " available" << std::endl;
    }
}

void Ingredients::displayIngredient() const {
    std::cout << "Name: " << name << ", Quantity: " << quantity << " " << unit << ", Price: $" << price;
    if (organic) {
        std::cout << " (Organic)";
    }
    std::cout << std::endl;
}

double Ingredients::calculateCost() const {
    return price * quantity;
}

istream &operator>>(istream &is, Ingredients &other) {
    is.ignore();
    while (true) {
        cout << "Enter name: ";
        getline(is, other.name);
        bool check = false;

        for (auto& i : Stock::getInstance()->getIngredients()) {
            if (other.name == i->getName()) {
                check = true;
                break;
            }
        }

        if (!check) {
            cout << "\nIngredient is not defined" << endl;
        } else {
            break;
        }
    }
    cout << "Enter Quantity : ";
    is >> other.quantity;

    //   cout << "Enter Price :";
    //   is >> other.price;

    //   cout << "Enter unit to measure :";
    //  is >> other.unit;

    //   cout << "(1 to organic / 0 to null) :";
    //   int num;
    //    cin >> num;
    //    if (num == 1) {
    //        other.organic = true;
    //    } else if (num == 2) {
    //        other.organic = false;

    //    }
    return is;
}











//void Ingredients::addAllergy(const std::string& allergy) {
//    allergies.push_back(allergy);
//}
//
//void Ingredients::removeAllegy(const std::string& allergy) {
//    for (auto it = allergies.begin(); it != allergies.end(); ++it) {
//        if (*it == allergy) {
//            allergies.erase(it);
//            break;
//        }
//    }
//}
//
//void Ingredients::displayAllergies() const {
//    std::cout << "Allergies for " << name << ": ";
//    for (const auto& allergy : allergies) {
//        std::cout << allergy << ", ";
//    }
//    std::cout << std::endl;
//}
//
//void allergyMenu(){
//    std::string ingredientName;
//    std::string unit;
//    float price = 0;
//    double quantity=0;
//
//
//    std::cout << "Enter ingredient name: ";
//    std::cin >> ingredientName;
//    std::cout << "Enter unit: ";
//    std::cin >> unit;
//    std::cout << "Enter price: ";
//    std::cin >> price;
//    std::cout << "Enter quantity: ";
//    std::cin >> quantity;
//
//    Ingredients ingredient(ingredientName, unit, price, quantity);
//
//    int operation;
//    do {
//        std::cout << "\n=============================" << std::endl;
//        std::cout << "          Ingredient         " << std::endl;
//        std::cout << "=============================" << std::endl;
//        std::cout << "1. Calculate Cost" << std::endl;
//        std::cout << "2. Add Allergy" << std::endl;
//        std::cout << "3. Remove Allergy" << std::endl;
//        std::cout << "4. Display Allergies" << std::endl;
//        std::cout << "5. Back to Main Menu" << std::endl;
//        std::cout << "=============================" << std::endl;
//        std::cout << "Enter your choice: ";
//        std::cin >> operation;
//
//        switch (operation) {
//            case 1: {
//                float cost = ingredient.calculateCost();
//                std::cout << "Cost of " << ingredient.getName() << ": $" << cost << std::endl;
//                break;
//            }
//            case 2: {
//                std::string allergy;
//                std::cout << "Enter allergy to add: ";
//                std::cin >> allergy;
//                ingredient.addAllergy(allergy);
//                std::cout << "Allergy added successfully!" << std::endl;
//                break;
//            }
//            case 3: {
//                std::string allergy;
//                std::cout << "Enter allergy to remove: ";
//                std::cin >> allergy;
//                ingredient.removeAllegy(allergy);
//                std::cout << "Allergy removed successfully!" << std::endl;
//                break;
//            }
//            case 4: {
//                ingredient.displayAllergies();
//                break;
//            }
//            case 5:
//                std::cout << "Returning to main menu..." << std::endl;
//                break;
//            default:
//                std::cout << "Invalid choice" << std::endl;
//                break;
//        }
//
//
//    } while (operation != 5);
//
//}