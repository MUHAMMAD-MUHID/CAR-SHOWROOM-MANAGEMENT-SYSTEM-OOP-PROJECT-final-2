#ifndef SEDAN_H
#define SEDAN_H
#include "Car.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class Sedan : public Car {
private:
    float fuel_efficiency, trunk_capacity;
public:
    Sedan() : Car() {
        trunk_capacity = 0.0;
        fuel_efficiency = 0.0;
    }
    Sedan(int car_id, string car_make, string car_model, float car_price, int car_seating_capacity, int car_ground_clearance, 
        string is_car_available, float trunk_capacity, float fuel_efficiency) : Car(car_id, car_make, car_model, car_price, 
            car_seating_capacity, car_ground_clearance, is_car_available) {
        this->trunk_capacity = trunk_capacity;
        this->fuel_efficiency = fuel_efficiency;
    }
    Sedan(const Sedan& obj) : Car(obj) {
        this->trunk_capacity = obj.trunk_capacity;
        this->fuel_efficiency = obj.fuel_efficiency;
    }
    void set_trunk_capacity(float trunk_capacity) {
        this->trunk_capacity = trunk_capacity;
    }
    void set_fuel_efficiency(float fuel_efficiency) {
        this->fuel_efficiency = fuel_efficiency;
    }
    float get_trunk_capacity()const {
        return trunk_capacity;
    }
    float get_fuel_efficiency()const {
        return fuel_efficiency;
    }
    string toString() {
        return Car::tostring() + "\t" + to_string(trunk_capacity) + "\t" + to_string(fuel_efficiency);
    }
    void store_to_file() {
        ofstream fout("Sedan.txt", ios::app);
        if (fout.is_open()) {
            fout << toString() << endl;
            fout.close();
            cout << "\nData Stored To Sedan File";
        }
        else {
            cerr << "Error: Unable to open file for writing." << endl;
        }
    }
    void view_from_file() const {
        cout << "\n----------------------------";
        cout << "\n---------ALL RECORDS--------";
        cout << "\n----------------------------";
        ifstream fin("Sedan.txt");
        if (fin.is_open()) {
            Sedan line;
            while (fin >> line) {
                cout << "\n----------------------------" << endl;
                cout << line << endl;
            }
            fin.close();
        }
        else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
    }

    void search() {
        int id;
        cout << "Enter the ID of the Sedan to search: ";
        cin >> id;

        ifstream fin("Sedan.txt");
        if (fin.is_open()) {
            bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
            while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> trunk_capacity >> fuel_efficiency) {
                if (car_id == id) {
                    found = true;
                    cout << "\nCar ID : " << car_id;
                    cout << "\nCar Make : " << car_make;
                    cout << "\nCar Model : " << car_model;
                    cout << "\nCar Price : " << car_price;
                    cout << "\nCar Seating Capacity : " << car_seating_capacity;
                    cout << "\nCar Availability : " << availability;
                    cout << "\nCar Trunk Capacity : " << trunk_capacity;
                    cout << "\nCar Fuel Efficiency : " << fuel_efficiency;
                }
                fin.close();
                if (!found) {
                    cout << "Sedan with ID " << id << " not found." << endl;
                }
            }
        }
        else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
    }
    void update() {
        int id;
        cout << "Enter the ID of the Sedan to update: ";
        cin >> id;
        ifstream fin("Sedan.txt");
        ofstream fout("temp.txt");
        if (fin.is_open() && fout.is_open()) {
            bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
            while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> trunk_capacity >> fuel_efficiency) {
                if (car_id == id) {
                    found = true;
                    cout << "Enter Car ID : ";
                    cin >> car_id;
                    cin.ignore();
                    cout << "Enter Car Make : ";
                    getline(cin, car_make);
                    cout << "Enter Car Model : ";
                    getline(cin, car_model);
                    cout << "Enter Car Price : ";
                    cin >> car_price;
                    cout << "Enter Car Seating Capacity : ";
                    cin >> car_seating_capacity;
                    cout << "Enter Car Ground Clearance : ";
                    cin >> car_ground_clearance;
                    cin.ignore();
                    getline(cin, availability);
                    cout << "Enter Car Availability(yes/no) : ";
                    cin >> availability;
                    cout << "Enter Trunk Capacity : ";
                    cin >> trunk_capacity;
                    cout << "Enter Fuel Efficiency : ";
                    cin >> fuel_efficiency;
                    set_car_id(car_id);
                    set_car_make(car_make);
                    set_car_model(car_model);
                    set_car_price(car_price);
                    set_car_seating_capacity(car_seating_capacity);
                    set_car_ground_clearance(car_ground_clearance);
                    set_car_availability(availability);
                    set_trunk_capacity(trunk_capacity);
                    set_fuel_efficiency(fuel_efficiency);
                }
                fout << toString() << endl;
            }
            fin.close();
            fout.close();
            remove("Sedan.txt");
            rename("temp.txt", "Sedan.txt");
            if (!found) {
                cout << "Sedan with ID " << id << " not found." << endl;
            }
            else {
                cout << "Sedan updated successfully." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading or writing." << endl;
        }
    }
    void del() {
        int id;
        cout << "Enter the ID of the Sedan to delete : ";
        cin >> id;
        ifstream fin("Sedan.txt");
        ofstream fout("temp.txt");
        if (fin.is_open() && fout.is_open()) {
            bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
            while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> trunk_capacity >> fuel_efficiency) {
                if (car_id == id) {
                    found = true;
                }
                else {
                    fout << car_id << "\t" << car_make << "\t" << car_model << "\t" << car_price << "\t" << car_seating_capacity << "\t" << car_ground_clearance << "\t" << availability << "\t" << trunk_capacity << "\t" << fuel_efficiency << endl;
                }
            }
            fin.close();
            fout.close();
            remove("Sedan.txt");
            rename("temp.txt", "Sedan.txt");
            if (!found) {
                cout << "Sedan with ID " << id << " not found." << endl;
            }
            else {
                cout << "Sedan with ID " << id << " deleted successfully." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading or writing." << endl;
        }
    }
    void menu(Sedan& obj) {
        int choice;
        do{
            cout << "\nMenu \n1.Add \n2.View \n3.Update \n4.Search \n5.Delete \n6.Return to Main menu";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                cout << "\n--------------------------";
                cout << "\n-----ADD DATA TO FILE-----";
                cout << "\n--------------------------";
                cin >> obj;
                store_to_file();
                break;
            }
            case 2:
            {
                obj.view_from_file();
                break;
            }
            case 3:
            {
                cout << "\n--------------------------";
                cout << "\n-----UPDATE DATA TO FILE-----";
                cout << "\n--------------------------";
                obj.update();
                break;
            }
            case 4:
            {
                cout << "\n--------------------------";
                cout << "\n-----SEARCH DATA TO FILE-----";
                cout << "\n--------------------------";
                obj.search();
                break;
            }
            case 5:
            {
                cout << "\n--------------------------";
                cout << "\n-----DELETE DATA TO FILE-----";
                cout << "\n--------------------------";
                obj.del();
                break;
            }
            case 6:
            {
                main_menu();
            }
            default:
            {
                cout << "\nInvalid Choice";
                break;
            }
            }
        } while (choice != 6);
    }

    bool check_availability(int temp_id) {
        ifstream fin("Sedan.txt");
        if (!fin) {
            cerr << "Error: Unable to open Sedan file." << endl;
            return false;
        }

        bool available = false;
        int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
        while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> trunk_capacity >> fuel_efficiency) {
            if (temp_id == car_id) {
                fin.close();
                return available;
            }
        }

        fin.close();
        return false;
    }

    friend ostream& operator<<(ostream& os, const Sedan& obj) {
        os << "Car ID : " << obj.get_car_id() << endl;
        os << "Car Make : " << obj.get_car_make() << endl;
        os << "Car Model : " << obj.get_car_model() << endl;
        os << "Car Price : " << obj.get_car_price() << endl;
        os << "Car Seating Capacity : " << obj.get_car_seating_capacity() << endl;
        os << "Car Ground Clearance : " << obj.get_car_ground_clearance() << endl;
        os << "Car Availability : " << obj.get_car_availability() << endl;
        os << "Car Trunk Capacity : " << obj.get_trunk_capacity() << endl;
        os << "Car Fuel Efficiency : " << obj.get_fuel_efficiency() << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Sedan& obj) {
        int car_id, car_seating_capacity, car_ground_clearance, trunk_capacity;
        string car_make, car_model, availability;
        float car_price, fuel_efficiency;

        // Check if the input stream is associated with a file
        if (typeid(is) != typeid(cin)) {
            is >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> trunk_capacity >> fuel_efficiency;
        }
        else {
            // Loop until valid Car ID is entered
            while (true) {
                cout << "\nEnter Car ID: ";
                if (is >> car_id) break;
                cerr << "\nError: Invalid input for Car ID. Please enter a valid integer." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            is.ignore();

            cout << "\nEnter Car Make: ";
            getline(is, car_make);

            cout << "\nEnter Car Model: ";
            getline(is, car_model);

            // Loop until valid Car Price is entered
            while (true) {
                cout << "\nEnter Car Price: ";
                if (is >> car_price) break;
                cerr << "\nError: Invalid input for Car Price. Please enter a valid float." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // Loop until valid Seating Capacity is entered
            while (true) {
                cout << "\nEnter Car Seating Capacity: ";
                if (is >> car_seating_capacity) break;
                cerr << "\nError: Invalid input for Seating Capacity. Please enter a valid integer." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // Loop until valid Ground Clearance is entered
            while (true) {
                cout << "\nEnter Car Ground Clearance: ";
                if (is >> car_ground_clearance) break;
                cerr << "\nError: Invalid input for Ground Clearance. Please enter a valid integer." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            is.ignore();

            cout << "\nEnter Car Availability: ";
            getline(is, availability);

            // Loop until valid Trunk Capacity is entered
            while (true) {
                cout << "\nEnter Trunk Capacity: ";
                if (is >> trunk_capacity) break;
                cerr << "\nError: Invalid input for Trunk Capacity. Please enter a valid integer." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // Loop until valid Fuel Efficiency is entered
            while (true) {
                cout << "\nEnter Fuel Efficiency: ";
                if (is >> fuel_efficiency) break;
                cerr << "\nError: Invalid input for Fuel Efficiency. Please enter a valid integer." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        obj.set_car_id(car_id);
        obj.set_car_make(car_make);
        obj.set_car_model(car_model);
        obj.set_car_price(car_price);
        obj.set_car_seating_capacity(car_seating_capacity);
        obj.set_car_ground_clearance(car_ground_clearance);
        obj.set_car_availability(availability);
        obj.set_trunk_capacity(trunk_capacity);
        obj.set_fuel_efficiency(fuel_efficiency);

        return is;
    }
};

#endif