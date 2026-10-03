
// Created by huzai on 22/04/2024.
//

#include "DishManager.h"

using namespace std;

DishManager* DishManager::instance = nullptr;

DishManager* DishManager::getInstance() {
    if (!instance) {
        instance = new DishManager();
    }
    return instance;
}

void DishManager::addDish(Dish* dish) {
    dishes.push_back(dish);
}

void DishManager::removeDish(string name) {
     for (size_t i = 0; i < dishes.size(); ++i) {
         if (dishes[i]->getName() == name) {
             delete dishes[i];
             dishes.erase(dishes.begin() + i);

             cout << "Dish " << name << " removed\n";
             return;
         }
     }
       cout<<"Dish not found\n";
}

void DishManager::addStarter(Starter* starter) {
    cin >>(*starter);
    dishes.push_back(starter);
}

void DishManager::addMainCourse(MainCourse* mainCourse) {
    cin >>(*mainCourse);
    dishes.push_back(mainCourse);
}

void DishManager::addDessert(Dessert* dessert) {
    cin >> (*dessert);
    dishes.push_back(dessert);
}

void DishManager::addDrink(Drinks* drink) {
    cin >> (*drink);
    dishes.push_back(drink);
}

void DishManager::makeDish(){

    for (auto dish : dishes) {
        dish->displayMenu();
    }
        string name;
        cout<<"enter name: ";
        cin.ignore();
        getline(cin,name);
    for (auto dish : dishes) {
        if(dish->getName()==name){
        dish->makeDish();
        return;
        }
    }
    cout<<"dish not found\n";
}


void DishManager::displayProductionCostOfDishes() {
    for (auto i : dishes)
        cout << "Production Cost of " << i->getName() << ": $" << i->calculateProductionCost() <<endl;

}

void DishManager::displayAllDishes() {
    for (const auto dish : dishes) {
        dish->display();
    }
}

void menuDishManagement() {
    DishManager* dishManager = DishManager::getInstance();
    //dishManager-> readDishFromFile();
    string name1;
    int choice;
    do {
        cout << "\n=============================" << endl;
        cout << "          Dish Manager         " << endl;
        cout << "===============================" << endl;
        cout << "1. Add Starter" << endl;
        cout << "2. Add Main Course" << endl;
        cout << "3. Add Dessert" << endl;
        cout << "4. Add Drink" << endl;
        cout << "5. Make Dishes" << endl;
        cout << "6. Display All Dishes / Production Cost" << endl;
        cout << "7. Remove Dish" << endl;
        cout << "8. Exit" << endl;
        cout << "=============================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1: {
                Starter * starter=new Starter("", "", 0, false);
                dishManager->addStarter(starter);
                break;
            }
            case 2: {

                MainCourse * mainCourse=new MainCourse("", "", 0, false);
                dishManager->addMainCourse(mainCourse);
                break;
            }
            case 3: {
                Dessert *dessert=new Dessert("", "", 0, false);
                dishManager->addDessert(dessert);
                break;
            }
            case 4: {
                Drinks *drink= new Drinks("", "", 0, "");
                dishManager->addDrink(drink);
                break;
            }
            case 5:
                do {
                    dishManager->makeDish();
                    cout << "Do you want to add more dishes? (1 for Yes, 0 for No): ";
                    int ch;
                    cin >> ch;
                    if (ch != 1) {
                        break;
                    }
                } while (true);
                cout << "All dishes made successfully!" << endl;
                break;
            case 6:
            {
                cout << "\nDisplaying all dishes:\n";
                dishManager->displayAllDishes();
                cout<<"\n___Production Cost___"<<endl;
                dishManager->displayProductionCostOfDishes();
                break;
            }
            case 7:{
                cout<<"Enter name: ";
                cin>>name1;
                dishManager->removeDish(name1);
                break;
            }
            case 8:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 8);
   // dishManager->sendToJson();
}



void restaurantManagementSystem() {
    DishManager* dishManager = DishManager::getInstance();
    Stock *stock = Stock::getInstance();
   // stock->readIngredientsFromFile();
    //dishManager-> readDishFromFile();
    int choice;

    cout << "\tWelcome to the Restaurant Management System" << endl;
    do {

            cout << "\n==============================" << endl;
            cout << "  Stock Management System  " << endl;
            cout << "================================" << endl;
            cout << "1. Ingredient Management" << endl;
            cout << "2. Dish Manager" << endl;
            cout << "3. Exit" << endl;
            cout << "================================" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    menuStock();
                    break;
                }
                case 2: {
                    menuDishManagement();
                    break;
                }
                case 3:
                    cout<<"Back to Main Menu";
                    //stock->sendIngredientsToJson();
                    //dishManager->sendToJson();
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
    }while(choice!=3);
}