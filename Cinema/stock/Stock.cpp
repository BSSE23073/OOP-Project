#include "Stock.h"
using namespace std;
Stock *Stock::instance = nullptr;

Stock *Stock::getInstance() {
    if (!instance) {
        instance = new Stock;
    }
    return instance;
}

//void Stock::addIngredient(const Ingredients &ingredient) {
//    Ingredients *newIngredient = new Ingredients(ingredient);
//    ingredients.push_back(newIngredient);
//    std::cout << "Added ingredient: " << ingredient.getName() << std::endl;
//}
void Stock::addIngredient(const Ingredients &ingredient) {

    for (const auto& existingIngredient : ingredients) {
        if (existingIngredient->getName() == ingredient.getName()) {
            std::cout << "Ingredient '" << ingredient.getName() << "' already exists. Not added. Please update it" << std::endl;
            return;
        }
    }
    Ingredients *newIngredient = new Ingredients(ingredient);
    ingredients.push_back(newIngredient);
    std::cout << "Added ingredient: " << ingredient.getName() << std::endl;
}


void Stock::removeIngredient(string name, double quantity, int which) {
    bool found = false;
    for (size_t i = 0; i < ingredients.size(); ++i) {
        if (ingredients[i]->getName() == name) {
            found = true;
            if (which == 1) {
                delete ingredients[i];
                ingredients.erase(ingredients.begin() + i);
                std::cout << "Ingredient " << name << " completely removed from stock" << std::endl;
            } else if (which == 2) {
                ingredients[i]->remove(quantity);
                std::cout << "Quantity " << quantity << " of ingredient " << name << " removed from stock" << std::endl;
            } else {
                std::cout << "Wrong entry. Please enter 1 or 2 next time." << std::endl;
            }
            break;
        }
    }
    if (!found) {
        std::cout << "Ingredient " << name << " not found in stock" << std::endl;
    }
}

void Stock::updateIngredient(std::string name, std::string &field) {
    for (auto ingredient: ingredients) {
        if (ingredient->getName() == name) {
            if (field == "price") {
                double price;
                cout << "Enter new price for ingredient " << name << ": ";
                cin >> price;
                ingredient->setPrice(price);
                cout << "Updated price for ingredient " << name << endl;
            } else if (field == "quantity") {
                double quantity;
                cout << "Enter quantity to add for ingredient " << name << ": ";
                cin >> quantity;
                ingredient->add(quantity);
                cout << "Updated quantity for ingredient " << name << endl;
            } else {
                cout << "Invalid field name" << endl;
            }
            return;
        }
    }
    std::cout << "Ingredient " << name << " not found in stock" << std::endl;
}

void Stock::displayStock() {
    if (ingredients.empty()) {
        cout << "Stock is empty" <<endl;
    } else {
        cout << "Current stock:"<<endl;
        for (auto ingredient: ingredients) {
            ingredient->displayIngredient();
        }
    }
}

Ingredients Stock::findIngredient(string name) {
    for (auto i: ingredients) {
        if (i->getName() == name) {
            return *i;
        }
    }
    return Ingredients();
}

void Stock::addCutlery(Cutlery cutlery1)
{
    bool found = false;
    for (int i = 0; i < cutlery.size(); ++i) {
        if (cutlery[i]->getType() == cutlery1.getType()) {
            cutlery[i]->add(cutlery1.getQuantity());
            found = true;
            break;
        }
    }
    if (!found) {
        Cutlery* newCutlery = new Cutlery(cutlery1);
        cutlery.push_back(newCutlery);
    }
    cout << "Added successfully." << endl;
}

void Stock::removeCutlery(string type, int quantity)
{
    bool found = false;
    for (int i = 0; i < cutlery.size(); ++i) {
        if (cutlery[i]->getType() == type) {
            cutlery[i]->remove(quantity);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << type << " not found in inventory." << endl;
    }
}

void Stock::displayCutlery()
{
    for (int i = 0; i < cutlery.size(); ++i) {
        cout<<cutlery[i]->getType()<<"\t"<<cutlery[i]->getQuantity()<<endl;
    }
}

void menuStock() {
    Stock *stock = Stock::getInstance();
    //stock->readIngredientsFromFile();
    int choice;
    std::string name, field ;
    std::string unit;
    double price = 0;
    double quantity = 0;
    bool organic = false;
    std::cout << "\tWelcome to the Stock Management System" << std::endl;

    do {
        cout << "\n=============================" << std::endl;
        cout << "            Stock Manager      " << std::endl;
        cout << "===============================" << std::endl;
        cout << "1. Add Ingredient" << std::endl;
        cout << "2. Remove Ingredient" <<std::endl;
        cout << "3. Update Ingredient" << endl;
        cout << "4. Display Stock" << endl;
        cout << "5. Calculate Cost" << endl;
        cout << "6. Cutlery Drawer" << endl;
        cout << "0. Exit" << endl;

        std::cout << "=============================" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Add this line to get user choice


        switch (choice) {
            case 1: {
                char addMore;
                do {
                    cout << "\nEnter Name: ";
                    cin.ignore();
                    getline(cin,name);
                    //cin>>name;
                    cout << "Enter Quantity: ";
                    cin >> quantity;
                    cin.ignore();
                    cout << "Enter ingredient unit: ";
                    getline(cin,unit);
                    //cin>>unit;


                    cout << "Enter ingredient price: ";
                    cin>>price;
                    static_cast<double>(price);
                    cout << "(1 to organic / 0 to null) :";
                    int num;
                    cin >> num;
                    cin.ignore();
                    if (num == 1) {
                        organic = true;
                    } else if (num == 2) {
                        organic = false;
                    }
                    // Add ingredient to stock
                 Ingredients ingredients(name , unit , price , quantity , organic);
                    stock->addIngredient(ingredients);
                    std::cout << "Do you want to add another ingredient? (y/n): ";
                    std::cin >> addMore;
                } while (addMore == 'y' || addMore == 'Y');
                break;
            }
            case 2: {
                int x;
                cout << "Enter ingredient name: ";
                cin.ignore();
                getline(cin,name);


                 cout << "Do you want to remove the product (press 1) or the quantity (press 2): ";
                 cin >> x;
                if (x == 1) {
                    stock->removeIngredient(name, 0, x);
                } else if (x == 2) {
                    cout << "Enter quantity to remove: ";
                    cin >> quantity;
                    // Remove ingredient from stock
                    stock->removeIngredient(name, quantity, x);
                }
                break;
            }
            case 3: {
                cout << "Enter ingredient name: ";
                cin.ignore();
                getline(cin,name);

                cout << "Enter field to update (price/quantity): ";
                cin >> field;
                // Update ingredient in stock
                stock->updateIngredient(name, field);
                break;
            }
            case 4:
                // Display stock
                stock->displayStock();
                break;
            case 5: {
                // Calculate cost of ingredient
                vector<Ingredients *> inventory = stock->getIngredients();
                for (auto i : inventory)
                    cout << "Cost of " << i->getName() << ": $" << i->calculateCost() <<endl;
                break;
            }
            case 6:
            {
                CutleryMenu();
                break;
            }
            case 0:
               cout << "Exiting program" <<endl;
                break;
            default:
                cout << "Invalid choice" <<endl;
                break;
        }
    } while (choice != 0);
    // Keep looping until the user chooses to exit
   // stock->sendIngredientsToJson();
}



void CutleryMenu() {
    Stock* stock = Stock::getInstance();
    int choice;
    string type;
    int quantity;

    do {
        cout << "===== Menu =====" << endl;
        cout << "1. Add Cutlery" << endl;
        cout << "2. Display All Cutlery" << endl;
        cout << "3. Remove Cutlery" << endl;
        cout << "0. Exit" << endl;
        cout << "================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter type of cutlery: ";
                cin >> type;
                cout << "Enter quantity: ";
                cin >> quantity;
                stock->addCutlery(Cutlery(type, quantity));
                cout << "Cutlery added successfully." << endl;
                break;
            case 2:
                cout << "Displaying all cutlery:" << endl;
                stock->displayCutlery();
                break;
            case 3:
                cout << "Enter type of cutlery to remove: ";
                cin >> type;
                cout << "Enter quantity to remove: ";
                cin >> quantity;
                stock->removeCutlery(type, quantity);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    } while(choice != 0);
}



