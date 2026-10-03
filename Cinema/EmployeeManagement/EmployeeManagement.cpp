//
// Created by attam on 20/04/2024.
//
#include "EmployeeManagement.h"

EmployeeManagement *EmployeeManagement::instance = nullptr;


EmployeeManagement *EmployeeManagement::getInstance() {
    if (!instance) {
        instance = new EmployeeManagement;
    }
    return instance;
}


void EmployeeManagement::addStaff(Staff &newStaff) {
    staff.push_back(newStaff);
    cout << newStaff.getName() << " has been added to the staff. " << endl;
}


void EmployeeManagement::removeStaff(const string &staffId) {
    for (int i = 0; i < staff.size(); i++) {
        if (staff[i].getId() == staffId) {
            cout << staff[i].getName() << " has been removed from team." << endl;
            staff.erase(staff.begin() + i);
            return;
        }
    }
    cout << "Staff with ID " << staffId << " not found in team." << endl;
}


void EmployeeManagement::updateStaffSalary(const string &staffId) {
    for (int i = 0; i < staff.size(); i++) {
        if (staff[i].getId() == staffId) {
            double newSalary;
            cout << "Enter updated salary for staff: ";
            cin >> newSalary;
            staff[i].setSalary(newSalary);
            cout << "Staff member with ID " << staffId << " has been updated." << endl;
            return;
        }
    }
    cout << "Staff member with ID " << staffId << " not found." << endl;
}


void EmployeeManagement::displayStaff() {
    cout << "\nStaff Information:" << endl;
    cout << "-----------------------------------------" << endl;
    for (auto &i: staff) {
        i.display();
    }
    cout << "-----------------------------------------" << endl;
}


void EmployeeManagement::addManager(Manager &newManager) {
    managers.push_back(newManager);
    cout << "Manager " << newManager.getName() << " has been added." << endl;
}


void EmployeeManagement::removeManager(const string &managerId) {
    for (int i = 0; i < managers.size(); i++) {
        if (managers[i].getId() == managerId) {
            cout << "Manager " << managers[i].getName() << " has been removed from team." << endl;
            managers.erase(managers.begin() + i);
            return;
        }
    }
    cout << "Manager with ID " << managerId << " not found." << endl;
}


void EmployeeManagement::displayManagers() {
    cout << "\nManager Information:" << endl;
    cout << "-----------------------------------------" << endl;

    for (auto &i: managers) {
        i.display();

    }
    cout << "-----------------------------------------" << endl;
}


void EmployeeManagement::reportEmployeeForAttendance(std::string Id) {
    bool check = false;

    for (int i = 0; i < managers.size(); i++) {
        if (managers[i].getId() == Id) {

            Time start;
            managers[i].attendances[managers[i].getAttendanceCount()].setReportingTime(start);
            managers[i].setAttendanceCount(managers[i].getAttendanceCount() + 1);
            check = true;
        }
    }


    for (int i = 0; i < staff.size(); i++) {
        if (staff[i].getId() == Id) {
            Time start;
            staff[i].attendances[staff[i].getAttendanceCount()].setReportingTime(start);
            staff[i].setAttendanceCount(staff[i].getAttendanceCount() + 1);
            check = true;
        }

    }
    if (!check)
        cout << "Employee with Id " << Id << " not found." << endl;
}


void EmployeeManagement::leaveEmployeeForAttendance(std::string Id) {
    bool check = false;

    for (int i = 0; i < managers.size(); i++) {
        if (managers[i].getId() == Id) {
            Time leave;
            managers[i].attendances[managers[i].getAttendanceCount()].setLeavingTime(leave);
            managers[i].setAttendanceCount(managers[i].getAttendanceCount() + 1);
            check = true;
        }
    }
    for (int i = 0; i < staff.size(); i++) {
        if (staff[i].getId() == Id) {
            Time leave;
            staff[i].attendances[staff[i].getAttendanceCount()].setLeavingTime(leave);
            staff[i].setAttendanceCount(staff[i].getAttendanceCount() + 1);
            check = true;
        }
    }
    if (!check)
        cout << "Employee with Id " << Id << " not found." << endl;
}


void EmployeeManagement::updateManager(const string &managerId) {
    for (int i = 0; i < managers.size(); i++) {
        if (managers[i].getId() == managerId) {
            double newSalary;
            cout << "Enter updated salary for  Manager: ";
            cin >> newSalary;
            managers[i].setSalary(newSalary);
            cout << "Manager with ID " << managerId << " has been updated." << endl;
            return;
        }
    }
    cout << "Manager with ID " << managerId << " not found." << endl;
}


void EmployeeManagement::displayAttendance(string Id) {
    bool check = false;

    for (int i = 0; i < managers.size(); i++) {
        if (managers[i].getId() == Id) {
            managers[i].displayEmployeeAttendance();
            check = true;
        }
    }
    for (int i = 0; i < staff.size(); i++) {
        if (staff[i].getId() == Id) {
            staff[i].displayEmployeeAttendance();
            check = true;
        }
    }
    if (!check)
        cout << "Employee with Id " << Id << " not found." << endl;
}


void EmployeeManagement::calculateEmployeeSalary(string Id) {

    bool check = false;
    for (int i = 0; i < managers.size(); i++) {
        if (managers[i].getId() == Id) {

            cout << "Salary for Manager " << managers[i].getName() << " is " <<
                 managers[i].calculateSalary();
            check = true;

        }
    }
    for (int i = 0; i < staff.size(); i++) {
        if (staff[i].getId() == Id) {
            cout << "Salary for Staff " << staff[i].getName() << " is " <<
                 staff[i].calculateSalary() << endl;
            check = true;
        }
    }
    if (!check)
        cout << "Employee with Id " << Id << " not found." << endl;
}


void EmployeeManagement::searchEmployee(string Id) {
    bool check = false;
    for (int i = 0; i < managers.size(); i++) {
        if (managers[i].getId() == Id) {
            managers[i].display();
            check = true;

        }
    }
    for (int i = 0; i < staff.size(); i++) {
        if (staff[i].getId() == Id) {
            staff[i].display();
            check = true;

        }

    }
    if (!check)
        cout << "Employee with Id " << Id << " not found." << endl;
}

void EmployeeManagement::adminMenu() {

    int choice;
    string name, id, dep, role;
    int age;
    string level;
    string gender;
    double salary1;
    bool repeat = true;
    // If logged in as admin
    while (repeat) {
        cout << "\nAdmin Menu:" << endl;
        cout << "-----------" << endl;
        cout << "1. Add Manager" << endl;
        cout << "2. Remove Manager" << endl;
        cout << "3. Update Manager" << endl;
        cout << "4. Display Managers" << endl;
        cout << "5. Update Staff" << endl;
        cout << "6. Display Staff" << endl;
        cout << "7. Display Attendance " << endl;
        cout << "8. Search a specific Employee " << endl;
        cout << "9. Calculate Salary " << endl;
        cout << "10. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                // Add Manager
                cout << "Enter manager's name: ";
                cin >> name;
                cout << "Enter manager's gender: ";
                cin >> gender;
                cout << "Enter manager's age: ";
                cin >> age;
                cout << "Enter manager's ID: ";
                cin >> id;
                cout << "Enter manager's department: ";
                cin >> dep;
                cout << "Enter manager's level: ";
                cin >> level;
                cout << "Enter manager's hourly salary: ";
                cin >> salary1;

                Manager manager(id, name, gender, age, dep, level, salary1);
                addManager(manager);
                break;
            }
            case 2: {
                // Remove Manager
                cout << "Enter manager ID to remove: ";
                cin >> id;
                removeManager(id);
                break;
            }
            case 3: {
                // Update Managers
                cout << "Enter manager's id that you want to update: ";
                cin >> id;
                updateManager(id);
            }
            case 4: {
                // Display Managers
                displayManagers();
                break;
            }
            case 5: {
                // Update Staff
                cout << "Enter staff's id that you want to update: ";
                cin >> id;
                updateStaffSalary(id);
                break;
            }
            case 6: {
                displayStaff();
                break;
            }
            case 7: {
                // Display Attendance
                cout << "Enter employee's id: ";
                cin >> id;
                displayAttendance(id);
                break;
            }
            case 8: {
                // Search Employee
                cout << "Enter employee's id to search: ";
                cin >> id;
                searchEmployee(id);
                break;

            }
            case 9: {
                // Calculate Salary
                cout << "Enter employee's id to calculate salary: ";
                cin >> id;
                calculateEmployeeSalary(id);
                break;
            }
            case 10: {
                repeat = false;
                break;
            }
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }

    }
}

void EmployeeManagement::managerMenu() {

    int choice;
    string name, id, dep, role, gen;
    int age;
    double salary;
    // If logged in as manager
    bool repeat1 = true;
    while (repeat1) {
        cout << "\nManager Menu:" << endl;
        cout << "-------------" << endl;
        cout << "1. Add Staff" << endl;
        cout << "2. Remove Staff" << endl;
        cout << "3. Update Staff" << endl;
        cout << "4. Display Staff" << endl;
        cout << "5. Search a specific Employee " << endl;
        cout << "6. Mark Attendance" << endl;
        cout << "7. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add Staff
                string duty;
                cout << "Enter staff's name: ";
                cin >> name;
                cout << "Enter staff's gender: ";
                cin >> gen;
                cout << "Enter staff's age: ";
                cin >> age;
                cout << "Enter staff's ID: ";
                cin >> id;
                cout << "Enter staff's department: ";
                cin >> dep;
                cout << "Enter staff's duty: ";
                cin >> duty;
                cout << "Enter staff's hourly salary: ";
                cin >> salary;

                Staff staff(id, name, gen, age, dep, duty, salary);
                addStaff(staff);
                break;
            }
            case 2: {
                // Remove Staff
                cout << "Enter staff's ID: ";
                cin >> id;
                removeStaff(id);
                break;
            }
            case 3: {
                cout << "Enter staff's id that you want to update: ";
                cin >> id;
                updateStaffSalary(id);
                break;
            }
            case 4: {
                // Display Staff
                displayStaff();
                break;
            }
            case 5: {
                // Search Employee
                cout << "Enter employee's id to search: ";
                cin >> id;
                searchEmployee(id);
                break;
            }
            case 6: {
                // Attendance
                cout << "Enter Employee id: ";
                cin >> id;
                cout << "Reporting or Leaving?" << endl;
                cout << "1. Reporting" << endl;
                cout << "2. Leaving" << endl;
                int x;
                cin >> x;
                switch (x) {
                    case 1: {
                        Time start;
                        reportEmployeeForAttendance(id);
                        start.display();
                        break;
                    }
                    case 2: {
                        Time leave;

                        leaveEmployeeForAttendance(id);
                        leave.display();
                        break;
                    }
                }
                break;
            }
            case 7: {
                // Logout
                repeat1 = false;
                break;
            }
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
}


void EmployeeManagement::displayEmployeeMenu() {

    EmployeeManagement::readManagerFromFile();
    EmployeeManagement::readStaffFromFile();
    // Admin passcode
    const string adminPasscode = "admin123";
    // Manager passcode
    const string managerPasscode = "manager123";

    while (true) {
        cout << "\nEmployee Management System" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Manager Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string passcode;
                cout << "Enter Admin Passcode: ";
                cin >> passcode;
                if (passcode == adminPasscode) {
                    cout << "\nAdmin login successful!" << endl;
                    adminMenu();
                } else {
                    cout << "Incorrect passcode! Please try again." << endl;
                }
                break;
            }
            case 2: {
                string passcode;
                cout << "Enter Manager Passcode: ";
                cin >> passcode;
                if (passcode == managerPasscode) {
                    cout << "\nManager login successful!" << endl;
                    managerMenu();
                } else {
                    cout << "Incorrect passcode! Please try again." << endl;
                }
                break;
            }
            case 3: {
                cout << "Exiting... Thank you!" << endl;
                return;
            }
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
        EmployeeManagement::sendManagerToJson();

        EmployeeManagement::sendStaffToJson();
    }
}