//
// Created by Dell on 02/04/2024.
//

#ifndef INC_2024_SPRING_SE102LB_WEEK9_BSSE23047_STOCK_H
#define INC_2024_SPRING_SE102LB_WEEK9_BSSE23047_STOCK_H


#include <vector>
#include <string>
#include "Ingredients.h"
#include <fstream>
#include "Cutlery.h"
using namespace std;
class Stock {
private:
    static Stock* instance;
    std::vector<Ingredients*> ingredients;
    vector<Cutlery*>cutlery;
    Stock() = default;

public:
    static Stock* getInstance();
    void addIngredient(const Ingredients& ingredient);
    void removeIngredient( std::string name, double quantity,int which);
    void updateIngredient( std::string name,  std::string& field);
    void displayStock();
    Ingredients findIngredient(string name);

    const vector<Ingredients *> &getIngredients() const {
        return ingredients;
    }

    ~Stock() {

        for (auto ingredient : ingredients) {
            delete ingredient;
        }
        ingredients.clear();
    }

//    void sendIngredientsToJson() {
//        json j;
//        ofstream off("ingredients.json", ios::out);
//        try {
//            if (!off.is_open()) {
//                throw runtime_error("Failed to open ingredients.json");
//            }
//
//            for (auto i : ingredients) {
//                j.push_back(i->writeToJson());
//            }
//
//            off << j.dump(3);
//            off.close();
//        } catch (const exception& e) {
//            cerr << "Error: " << e.what() << endl;
//        }
//    }

    void sendIngredientsToJson(){
        json j;
        ofstream off("Cinema/stock/ingreidents.json",ios::out);
        if(off.is_open()){

            for(auto i : ingredients){
                j.push_back(i->writeToJson());
             }

            off << j.dump(3);
        }else{
            cerr << "ingreidents.json is not open";
        }
    }

    void readIngredientsFromFile(){
        ifstream read("Cinema/stock/ingreidents.json",ios::in);
        if (!read.is_open()){
            cout<<"File Not Open!";
        } else {
            json readData;
            read >> readData;
            for (auto &i:readData) {
                auto *ptr = new Ingredients;
                *ptr = Ingredients::readFromJson(i);
                ingredients.push_back(ptr);
            }
        }
    }
    void addCutlery(Cutlery cutlery1);
    void removeCutlery(string type,int quantity);
    void displayCutlery();
};

void CutleryMenu();
void menuStock();
#endif //INC_2024_SPRING_SE102LB_WEEK9_BSSE23047_STOCK_H


