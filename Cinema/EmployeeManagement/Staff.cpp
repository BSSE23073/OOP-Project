//
// Created by attam on 20/04/2024.
//

#include "Staff.h"

Staff::Staff(std::string id, std::string name, string gender, int age, std::string dep, std::string duty,
             double salary) {
    this->Id = id;
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->department = dep;
    this->duty = duty;
    this->salary = salary;
}


void Staff::setDuty(const string &duty) {
    this->duty = duty;
}


void Staff::setName(const string &name) {
    this->name = name;
}

void Staff::setAge(int age) {
    this->age = age;
}

string Staff::getDuty() {
    return duty;
}


void Staff::setDepartment(const string &department) {
    this->department = department;
}

void Staff::display() {
    cout << "Employee ID: " << Id << " | "
         << "Name: " << name << " | "
         << "Age: " << age << " | "
         << "Department: " << department << " | "
         << "Duty: " << duty << " | "
         << "Salary: " << salary <<
         endl;
}