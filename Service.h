#pragma once
#include<iostream>
using namespace std;

class Service
{
private:
	int service_id;
	string service_name;
public:
#include "Service.h"
#include"string"
    // Default constructor
    Service()
    {
        service_id = 0;
        service_name = "n/a";
    }
    // Parameterized constructor
    Service(int service_id, string service_name)
    {
        this->service_id = service_id;
        this->service_name = service_name;
    }
    // Copy constructor
    Service(const Service& obj)
    {
        service_id = obj.service_id;
        service_name = obj.service_name;
    }
    string tostring() {
        return to_string(service_id) + "\t" + service_name;
    }
    // Setter for service_id
    void set_service_id(int service_id)
    {
        this->service_id = service_id;
    }
    void set_service_name(string service_name)
    {
        this->service_name = service_name;
    }
    // Getter for service_id
    int get_service_id()const
    {
        return service_id;
    }
    void view_from_file()
    {
        ifstream fin("service.txt");
        if (fin.is_open()) {
            cout << "\n-------------------";
            cout << "\n----ALL RECORDS----";
            cout << "\n-------------------";
            while (fin >> service_id >> service_name) {
                cout << "\n----------------------------" << endl;
                cout << "\nService id : " << service_id << "\nService Name : " << service_name << endl;
            }
            fin.close();
        }
        else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
    }
   
    string get_service_name()const
    {
        return service_name;
    }
};