#pragma once
#include<iostream>
#include "Insurance.h"
#include "string"
using namespace std;
class Insurance
{
private:
	int Insurance_id;
	string Insurance_type;
public:
    Insurance()
    {
        Insurance_id = 0;
        Insurance_type = "";
    }
    // Parameterized constructor
    Insurance(int Insurance_id, string Insurance_type)
    {
        this->Insurance_id = Insurance_id;
        this->Insurance_type = Insurance_type;
    }
    // Copy constructor
    Insurance(const Insurance& obj)
    {
        Insurance_id = obj.Insurance_id;
        Insurance_type = obj.Insurance_type;
    }
    string tostring() {
        return to_string(Insurance_id) + "\t" + Insurance_type;
    }
    // Setter for Insurance_id
    void set_Insurance_id(int Insurance_id)
    {
        this->Insurance_id = Insurance_id;
    }
    void set_Insurance_type(string Insurance_type)
    {
        this->Insurance_type = Insurance_type;
    }
    // Getter for Insurance_id
    int get_Insurance_id()const
    {
        return Insurance_id;
    }
    string get_Insurance_type()const
    {
        return Insurance_type;
    }
    void view_from_file()
    {
        ifstream fin("insurance.txt");
        if (fin.is_open()) {
            cout << "\n-------------------";
            cout << "\n----ALL RECORDS----";
            cout << "\n-------------------";
            while (fin >> Insurance_id >> Insurance_type) {
                cout << "\n----------------------------" << endl;
                cout << "\nInsurance id : " << Insurance_id << "\nInsurance Name : " << Insurance_type << endl;
            }
            fin.close();
        }
        else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
    }
};