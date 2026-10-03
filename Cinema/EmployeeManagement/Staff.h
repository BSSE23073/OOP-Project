//
// Created by attam on 20/04/2024.
//

#ifndef UNTITLED2_STAFF_H
#define UNTITLED2_STAFF_H

#include "Employee.h"

// Inherited from Employee
class Staff : public Employee {
private:
    string duty;
public:

    Staff()= default;
    // Parameterized Constructor
    Staff(string id, string name,string gender, int age, string dep, string duty, double salary);

    // Getters
    string getDuty();


    // Setters
    void setName(const string &name);

    void setAge(int age);

    void setDuty(const string &duty);

    void setDepartment(const string &department);

    // Overriden function
    void display() override ;

    json writeStaffToJson() {
        json j;
        j = writeToJson();
        j["duty"] = duty;
        return j;
    }

    void readStaffFromJson(json &j) {

        readFromJson(j);
        duty=j["duty"];


    }

};


#endif //UNTITLED2_STAFF_H
