//
// Created by attam on 20/04/2024.
//

#ifndef UNTITLED2_EMPLOYEE_H
#define UNTITLED2_EMPLOYEE_H


#include "./../Movie/Person.h"
#include<vector>
#include <ostream>
#include "Attendence.h"

// Inherited from class Person
// Base class for Staff and Manager
class Employee : public Person {
protected:
    // Protected attributes so that can be easily inherited
    string Id;
    string department;
    double salary;
    int attendanceCount;
public:
    // Vector of attendance
    vector<Attendance> attendances;


    // Default Constructor
    Employee();

    // Parameterized Constructor
    Employee(string id, string name, string gender, int age, string dep, double salary);

    // Getters
    string getId();

    string getDepartment();

    int getAttendanceCount() {
        return attendanceCount;
    }

    double getSalary();

    // Setters
    void setAttendanceCount(int count) {
        attendanceCount = count;
    }

    void setSalary(double salary);

    // Functions
    // Calculate Salary by multiplying attendance count with this day hours
    double calculateSalary();

    void displayEmployeeAttendance();

    // Run-time Polymorphism
    virtual void display();

    // Function to convert Employee object to JSON
    json writeToJson() {
        json j;
        j["Id"] = Id;
        j["name"] = name;
        j["gender"] = gender;
        j["age"] = age;
        j["department"] = department;
        j["salary"] = salary;
        j["attendanceCount"] = attendanceCount;
        j["department"] = department;

        // Convert attendances vector to JSON array
        json attendancesArray;
        int count = 0;
        for (auto &attendance: attendances) {
            if (count == attendanceCount) {
                break;
            }

            attendancesArray.push_back(attendance.toJson());
            count++;

        }
        j["attendances"] = attendancesArray;

        return j;
    }

    // Function to parse JSON and create Employee object
    void readFromJson(const json &j) {

        Id = j["Id"];
        name = j["name"];
        gender = j["gender"];
        age = j["age"];
        department = j["department"];
        salary = j["salary"];
        attendanceCount = j["attendanceCount"];
        // Parse attendances JSON array
        int index = 0;
        for (const auto &attendanceJson: j["attendances"]) {
            Attendance temp = Attendance(Attendance::fromJson(attendanceJson));
            //temp.displayAttendance();
            attendances.at(index) = temp;
            index++;
        }
    }


};


#endif //UNTITLED2_EMPLOYEE_H
