//
// Created by attam on 20/04/2024.
//

#ifndef UNTITLED2_MANAGER_H
#define UNTITLED2_MANAGER_H

#include "Employee.h"
#include "Staff.h"
#include<vector>

// Inherited from Employee
class Manager : public Employee {
    string level;
public:

    Manager() = default;
    // Parameterized Constructor
    Manager(string id, string name, string gender, int age, string dep, string level, double salary);

    // Getters
   string  getLevel(){
       return level;
   }
    // Setters
    void setLevel(string level1) {
        Manager::level = level1;
    }

    void setDepartment(const string &department) {
        this->department = department;
    }

    void setName(const string &name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }


    void setId(string Id);

    // Overriden function
    void display() override;

    json writeManagerToJson() {
        json j;
        j = writeToJson();
        j["level"] = level;
        return j;
    }

    void readManagerFromJson(json &j) {
       readFromJson(j);
       level=j["level"];

    }


};


#endif //UNTITLED2_MANAGER_H
