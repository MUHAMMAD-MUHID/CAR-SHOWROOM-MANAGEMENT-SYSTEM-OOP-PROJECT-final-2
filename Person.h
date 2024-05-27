#ifndef PERSON_H
#define PERSON_H
#include"Person.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Person {
private:
    int person_id;
    string person_name;
public:
    Person()
    {
        person_id = 0;
        person_name = "N/A";
    }
    Person(int person_id, string person_name)
    {
        this->person_id = person_id;
        this->person_name = person_name;
    }
    Person(const Person& obj)
    {
        this->person_id = obj.person_id;
        this->person_name = obj.person_name;
    }
    //Setter methods
    void set_person_id(int person_id) { this->person_id = person_id; }
    void set_person_name(string person_name) { this->person_name = person_name; }
    // Getter methods
    int get_person_id() const
    {
        return person_id;
    }
    string get_person_name() const
    {
        return person_name;
    }
    string tostring()const {
        return  "\n" + to_string(person_id) + "\t" + person_name + "\t";
    }
    friend istream& operator>>(istream& in, Person& obj) {
        cout << "\nID : ";
        in >> obj.person_id;
        cout << "\nName : ";
        in.ignore();
        getline(in, obj.person_name);
        return in;
    }
};

#endif PERSON_H

