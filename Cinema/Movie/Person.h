#ifndef OOPS_PROJECT_PERSON_H
#define OOPS_PROJECT_PERSON_H

#include <iostream>
#include <cstring>
using namespace std;

class Person {
protected:
    string name;
    string gender;
    int age;
public:
    Person() {
        name = " ";
        gender = " ";
        age = 0;
    }

    Person(string name, string gender, int age) {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }

    void displayDetails();

    string getName() const {
        return name;
    }

    void setName(const string name) {
        Person::name = name;
    }

    friend ostream &operator<<(ostream &os, const Person &person) {
        os << "name: " << person.name << " gender: " << person.gender << " age: " << person.age;
        return os;
    }

    string getGender() const {
        return gender;
    }

    void setGender(const string gender) {
        Person::gender = gender;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Person::age = age;
    }
};

#endif //OOPS_PROJECT_PERSON_H
