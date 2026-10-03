//
// Created by attam on 20/04/2024.
//

#ifndef UNTITLED2_EMPLOYEEMANAGEMENT_H
#define UNTITLED2_EMPLOYEEMANAGEMENT_H

#include "Staff.h"
#include "Manager.h"
#include <vector>
#include <fstream>

// Singleton Class
class EmployeeManagement {
private:
    static EmployeeManagement *instance;
    vector<Staff> staff;
    vector<Manager> managers;

    EmployeeManagement() {} // Private constructor for singleton class. In case of singleton class the instance is created in the constructor.

public:

    static EmployeeManagement *getInstance();

    // Getters
    const vector<Staff> &getStaff() const { return staff; }

    const vector<Manager> &getManager() const { return managers; }


    // Staff functions
    void addStaff(Staff &newStaff);

    void removeStaff(const string &staffId);

    void updateStaffSalary(const string &staffId);

    void displayStaff();


    // Manager functions
    void addManager(Manager &newManager);

    void removeManager(const string &managerId);

    void updateManager(const string &managerId);

    void displayManagers();


    // Mark Attendance
    void reportEmployeeForAttendance(string Id);

    void leaveEmployeeForAttendance(string Id);

    // Calculate Salary Function
    void calculateEmployeeSalary(string Id);

    // Search a specific Employee
    void searchEmployee(string Id);

    // Display Attendance
    void displayAttendance(string id);


    // User defined Menu driven functions to call in main.cpp
    void displayEmployeeMenu();

    void adminMenu();

    void managerMenu();

    void sendManagerToJson(){
        json j;
        ofstream off("Cinema/EmployeeManagement/Manager.json", ios::out);
        if (off.is_open()) {

            for (auto i: managers) {
                j.push_back(i.writeManagerToJson());
            }
            off << j.dump(3);
        } else {
            cerr << "Manager.json is not open";
        }
    }

    void readManagerFromFile() {
        ifstream read("Cinema/EmployeeManagement/Manager.json",ios::in);
        if (!read.is_open()){
            cout<<"File Not Open!";
        } else {
            json readData;
            read >> readData;
            for (auto& i:readData){
                Manager temp;
                temp.readManagerFromJson(i);
                managers.push_back(temp);
            }
        }
    }

    void sendStaffToJson(){
        json j;
        ofstream off("Cinema/EmployeeManagement/Staff.json", ios::out);
        if (off.is_open()) {

            for (auto i: staff) {
                j.push_back(i.writeStaffToJson());
            }
            off << j.dump(3);
        } else {
            cerr << "Staff.json is not open";
        }
    }


    void readStaffFromFile(){
        ifstream read("Cinema/EmployeeManagement/Staff.json",ios::in);
        if (!read.is_open()){
            cout<<"File Not Open!";
        } else {
            json readData;
            read >> readData;
            for (auto& i:readData){
                Staff temp;
                temp.readStaffFromJson(i);
                staff.push_back(temp);
            }
        }
    }



};


#endif //UNTITLED2_EMPLOYEEMANAGEMENT_H