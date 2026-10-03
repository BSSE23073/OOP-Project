//
// Created by attam on 20/04/2024.
//

#include "Employee.h"

Employee::Employee() {
    attendanceCount = 0;
    attendances.resize(31); // ReSize the vector of attendance to the total days of month.
}


Employee::Employee(std::string id,std::string name,string gender, int age,  std::string dep, double salary) {
    this->Id = id;
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->department = dep;
    this->salary = salary;
    attendanceCount = 0;

    // ReSize the vector of attendance to the total days of month.
    attendances.resize(31);
}

string Employee::getId() {
    return Id;
}

string Employee::getDepartment() {
    return department;
}

double Employee::getSalary() {
    return salary;
}

void Employee::display() {
    cout << "Employee ID: " << Id << " | "
         << "Name: " << name << " | "
         << "Gender: " << gender << " | "
         << "Age: " << age << " | "
         << "Department: " << department << " | ";
}

double Employee::calculateSalary() {

    double x = 0.0;
    for (int i = 0; i < attendanceCount; i++) {
        x += attendances[i].calculateThisDayHours();
    }
    attendances.clear();
    attendanceCount = 0;
    return (x * salary);
}

void Employee::displayEmployeeAttendance() {
    cout << "Attendance for " << name << ":" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < attendanceCount; i++) {
        cout << "Day " << i + 1 << "\n";
        attendances[i].displayAttendance();
    }
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}
