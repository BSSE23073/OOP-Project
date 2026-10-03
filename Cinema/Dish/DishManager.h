//
// Created by huzai on 22/04/2024.
//

#ifndef PRIVATE_PROJECT_DISHMANAGER_H
#define PRIVATE_PROJECT_DISHMANAGER_H


#include <iostream>
#include <vector>
#include "MainCourse.h"
#include "Dessert.h"
#include "Drinks.h"
#include <fstream>
#include "Dish.h"
#include "Starter.h"
//#include "./../Order/OrderManagement.h"

class DishManager {
private:
    static DishManager* instance;
    std::vector<Dish*> dishes;
    DishManager() {}

public:
    vector<Dish *> &getDishes()  {
        return dishes;
    }
    static DishManager* getInstance();
    void addDish(Dish* dish);
    void removeDish(string name);
    void addMainCourse(MainCourse* manCourse);
    void addDessert(Dessert* dessert);
    void addDrink(Drinks* drink);
    void addStarter(Starter* starter);
    void makeDish();
    void displayAllDishes();
    void displayProductionCostOfDishes();


    ~DishManager() {
        for (auto dish : dishes) {
            delete dish;
        }
        dishes.clear();
    }


    void sendToJson(){
        json j;
        ofstream off("Cinema/Dish/dish.json", ios::out);
        if (off.is_open()) {

            for (auto i: dishes) {
                j.push_back(i->writeToJson());
            }
            off << j.dump(3);
        } else {
            cerr << "dish.json is not open";
        }
    }


    void readDishFromFile()
        {
            ifstream read("Cinema/Dish/dish.json",ios::in);
            if (!read.is_open()){
                cout<<"File Not Open!";
            } else {
                json readData;
                read >> readData;
                for (auto &i:readData) {
                    Dish *ptr;
                    if(i["dishType"]=="MainCourse"){
                        ptr= new MainCourse();
                    }
                    if(i["dishType"]=="Starter"){
                        ptr= new Starter();
                    }
                    if(i["dishType"]=="Drinks"){
                        ptr= new Drinks();
                    }
                    if(i["dishType"]=="Dessert"){
                        ptr= new Dessert();
                    }
                    ptr->readFromJson(i);
                    dishes.push_back(ptr);
                }
            }
        }



};
void menuDishManagement();
void restaurantManagementSystem();
#endif //PRIVATE_PROJECT_DISHMANAGER_H
