//
// Created by attam on 20/04/2024.
//

#include "Manager.h"

Manager::Manager(std::string id, std::string name, string gender, int age, std::string dep, string level,
                 double salary) {
    this->Id = id;
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->department = dep;
    this->level = level;
    this->salary = salary;
}

void Manager::setId(std::string Id) {
    this->Id = Id;
}

void Manager::display() {
    cout << "Employee ID: " << Id << " | "
         << "Name: " << name << " | "
         << "Gender: " << gender << " | "
         << "Age: " << age << " | "
         << "Department: " << department << " | "
         << "Level: " << level << " | "
         << "Salary: " << salary << " | \n";
}