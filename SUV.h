#ifndef SUV_H
#define SUV_H

#include <fstream>
#include <iostream>
#include <string>
#include <limits>
#include "Car.h"

using namespace std;

void main_menu();

class SUV : public Car {
private:
    int offroad_capability;
    int towing_capacity;

public:
    // Constructors
    SUV() : Car()
    {
        offroad_capability = 0;
        towing_capacity = 0;
    }
    SUV(int car_id, string car_make, string car_model, float car_price, int car_seating_capacity, int car_ground_clearance, string is_car_available, int offroad_capability, int towing_capacity)
        : Car(car_id, car_make, car_model, car_price, car_seating_capacity, car_ground_clearance, is_car_available)
    {
        this->offroad_capability = offroad_capability;
        this->towing_capacity = towing_capacity;
    }
    SUV(const SUV& obj) : Car(obj)
    {
        this->offroad_capability = obj.offroad_capability;
        this->towing_capacity = obj.towing_capacity;
    }
    void set_offroad_capability(int offroad_capability) {
        this->offroad_capability = offroad_capability;
    }
    void set_towing_capacity(int towing_capacity) {
        this->towing_capacity = towing_capacity;
    }
    int get_offroad_capability() const {
        return offroad_capability;
    }
    int get_towing_capacity() const {
        return towing_capacity;
    }
    string toString() const {
        return Car::tostring() + "\t" + to_string(offroad_capability) + "\t" + to_string(towing_capacity) + "\n";
    }
    void store_to_file() const {
        ofstream fout("SUV.txt", ios::app);
        if (fout.is_open()) {
            fout << toString();
            fout.close();
            cout << "\nData Stored To SUV File" << endl;
        }
        else {
            cerr << "Error: Unable to open file for writing." << endl;
        }
    }
    void view_from_file() const {
        cout << "\n-------------------";
        cout << "\n----ALL RECORDS----";
        cout << "\n-------------------";
        ifstream fin("SUV.txt");
        if (fin.is_open()) {
            SUV suv;
            while (fin >> suv) {
                cout << "\n----------------------------" << endl;
                cout << suv << endl;
            }
            fin.close();
        }
        else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
    }
    void update() {
        int id;
        cout << "Enter the ID of the SUV to update: ";
        cin >> id;
        cin.ignore();

        ifstream fin("SUV.txt");
        ofstream fout("temp.txt");

        if (fin.is_open() && fout.is_open()) {
            bool found = false;
            int temp_id, temp_seating, temp_clearance, temp_offroad, temp_towing;
            string temp_make, temp_model, temp_avail;
            float temp_price;

            while (fin >> temp_id >> temp_make >> temp_model >> temp_price >> temp_seating >> temp_clearance >> temp_avail >> temp_offroad >> temp_towing) {
                if (temp_id == id) {
                    found = true;
                    cout << "Enter Car Make: ";
                    getline(cin, temp_make);
                    cout << "Enter Car Model: ";
                    getline(cin, temp_model);
                    cout << "Enter Car Price: ";
                    cin >> temp_price;
                    cout << "Enter Car Seating Capacity: ";
                    cin >> temp_seating;
                    cout << "Enter Car Ground Clearance: ";
                    cin >> temp_clearance;
                    cin.ignore();
                    cout << "Enter Car Availability (yes/no): ";
                    getline(cin, temp_avail);
                    cout << "Enter Offroad Capability: ";
                    cin >> temp_offroad;
                    cout << "Enter Towing Capacity: ";
                    cin >> temp_towing;
                    fout << temp_id << "\t" << temp_make << "\t" << temp_model << "\t" << temp_price << "\t" << temp_seating << "\t" << temp_clearance << "\t" << temp_avail << "\t" << temp_offroad << "\t" << temp_towing << endl;
                }
                else {
                    fout << temp_id << "\t" << temp_make << "\t" << temp_model << "\t" << temp_price << "\t" << temp_seating << "\t" << temp_clearance << "\t" << temp_avail << "\t" << temp_offroad << "\t" << temp_towing << endl;
                }
            }
            fin.close();
            fout.close();
            remove("SUV.txt");
            rename("temp.txt", "SUV.txt");

            if (!found) {
                cout << "SUV with ID " << id << " not found." << endl;
            }
            else {
                cout << "SUV updated successfully." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading or writing." << endl;
        }
    }
    void search() const {
        int id;
        cout << "Enter the ID of the SUV to search: ";
        cin >> id;

        ifstream fin("SUV.txt");
        if (fin.is_open()) {
            bool found = false;
            int temp_id, temp_seating, temp_clearance, temp_offroad, temp_towing;
            string temp_make, temp_model, temp_avail;
            float temp_price;

            while (fin >> temp_id >> temp_make >> temp_model >> temp_price >> temp_seating >> temp_clearance >> temp_avail >> temp_offroad >> temp_towing) {
                if (temp_id == id) {
                    found = true;
                    cout << "\nCar ID: " << temp_id;
                    cout << "\nCar Make: " << temp_make;
                    cout << "\nCar Model: " << temp_model;
                    cout << "\nCar Price: " << temp_price;
                    cout << "\nCar Seating Capacity: " << temp_seating;
                    cout << "\nCar Ground Clearance: " << temp_clearance;
                    cout << "\nCar Availability: " << temp_avail;
                    cout << "\nOffroad Capability: " << temp_offroad;
                    cout << "\nTowing Capacity: " << temp_towing << endl;
                }
            }
            fin.close();

            if (!found) {
                cout << "SUV with ID " << id << " not found." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
    }
    void del() {
        int id;
        cout << "Enter the ID of the SUV to delete: ";
        cin >> id;

        ifstream fin("SUV.txt");
        ofstream fout("temp.txt");

        if (fin.is_open() && fout.is_open()) {
            bool found = false;
            int temp_id, temp_seating, temp_clearance, temp_offroad, temp_towing;
            string temp_make, temp_model, temp_avail;
            float temp_price;

            while (fin >> temp_id >> temp_make >> temp_model >> temp_price >> temp_seating >> temp_clearance >> temp_avail >> temp_offroad >> temp_towing) {
                if (temp_id == id) {
                    found = true;
                }
                else {
                    fout << temp_id << "\t" << temp_make << "\t" << temp_model << "\t" << temp_price << "\t" << temp_seating << "\t" << temp_clearance << "\t" << temp_avail << "\t" << temp_offroad << "\t" << temp_towing << endl;
                }
            }
            fin.close();
            fout.close();
            remove("SUV.txt");
            rename("temp.txt", "SUV.txt");

            if (!found) {
                cout << "SUV with ID " << id << " not found." << endl;
            }
            else {
                cout << "SUV with ID " << id << " deleted successfully." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading or writing." << endl;
        }
    }

    void menu(SUV& obj) {
        int choice;
        do {
            cout << "\n**** SUV Menu ****\n1.Add SUV\n2.View SUVs\n3.Update SUV \n4.Search SUV \n5.Delete SUV\n6.Return To Main Menu\nEnter your choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1:
                cout << "\n--------------------------";
                cout << "\n-----ADD DATA TO FILE-----";
                cout << "\n--------------------------";
                cin >> obj;
                obj.store_to_file();
                break;
            case 2:
                obj.view_from_file();
                break;
            case 3:
                cout << "\n-----------------------------";
                cout << "\n-----UPDATE DATA TO FILE-----";
                cout << "\n-----------------------------";
                obj.update();
                break;
            case 4:
                cout << "\n--------------------------";
                cout << "\n---SEARCH DATA TO FILE----";
                cout << "\n--------------------------";
                obj.search();
                break;
            case 5:
                cout << "\n--------------------------";
                cout << "\n----DELETE DATA TO FILE---";
                cout << "\n--------------------------";
                obj.del();
                break;
            case 6:
                main_menu();
                break;
            default:
                cout << "\nInvalid Choice" << endl;
                break;
            }
        } while (choice != 6);
    }
    bool check_availability(int temp_id) {
        ifstream fin("SUV.txt");
        if (!fin) {
            cerr << "Error: Unable to open SUV file." << endl;
            return false;
        }

        //bool available = false;
        int car_id, temp_seating, temp_clearance, temp_offroad, temp_towing;
        string temp_make, temp_model, temp_avail;
        float temp_price;

        while (fin >> car_id >> temp_make >> temp_model >> temp_price >> temp_seating >> temp_clearance >> temp_avail >> temp_offroad >> temp_towing) {
            if (temp_id == car_id) {
                fin.close();
                return true;
            }
            else
                return false;
        }

        fin.close();
    }

    friend ostream& operator<<(ostream& out, const SUV& obj) {
        out << "Car ID: " << obj.get_car_id() << endl;
        out << "Car Make: " << obj.get_car_make() << endl;
        out << "Car Model: " << obj.get_car_model() << endl;
        out << "Car Price: " << obj.get_car_price() << endl;
        out << "Car Seating Capacity: " << obj.get_car_seating_capacity() << endl;
        out << "Car Ground Clearance: " << obj.get_car_ground_clearance() << endl;
        out << "Car Availability: " << obj.get_car_availability() << endl;
        out << "Offroad Capability: " << obj.get_offroad_capability() << endl;
        out << "Towing Capacity: " << obj.get_towing_capacity() << endl;
        return out;
    }
    friend istream& operator>>(istream& in, SUV& obj) {
        int car_id, car_seating_capacity, car_ground_clearance, offroad_capability, towing_capacity;
        string car_make, car_model, availability;
        float car_price;

        if (typeid(in) != typeid(cin)) {
            in >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> offroad_capability >> towing_capacity;
        }
        else {
            cout << "\nEnter Car ID: ";
            while (!(in >> car_id)) {
                cerr << "\nError: Invalid input for Car ID. Please enter a valid integer." << endl;
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nEnter Car ID: ";
            }
            in.ignore();

            cout << "\nEnter Car Make: ";
            getline(in, car_make);

            cout << "\nEnter Car Model: ";
            getline(in, car_model);

            cout << "\nEnter Car Price: ";
            while (!(in >> car_price)) {
                cerr << "\nError: Invalid input for Car Price. Please enter a valid float." << endl;
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nEnter Car Price: ";
            }

            cout << "\nEnter Car Seating Capacity: ";
            while (!(in >> car_seating_capacity)) {
                cerr << "\nError: Invalid input for Car Seating Capacity. Please enter a valid integer." << endl;
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Car Seating Capacity: ";
            }

            cout << "\nEnter Car Ground Clearance: ";
            while (!(in >> car_ground_clearance)) {
                cerr << "\nError: Invalid input for Car Ground Clearance. Please enter a valid integer." << endl;
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nEnter Car Ground Clearance: ";
            }
            in.ignore();

            cout << "\nEnter Car Availability (yes/no): ";
            getline(in, availability);

            cout << "\nEnter Offroad Capability: ";
            while (!(in >> offroad_capability)) {
                cerr << "Error: Invalid input for Offroad Capability. Please enter a valid integer." << endl;
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nEnter Offroad Capability: ";
            }

            cout << "\nEnter Towing Capacity: ";
            while (!(in >> towing_capacity)) {
                cerr << "\nError: Invalid input for Towing Capacity. Please enter a valid integer." << endl;
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nEnter Towing Capacity: ";
            }
        }

        obj.set_car_id(car_id);
        obj.set_car_make(car_make);
        obj.set_car_model(car_model);
        obj.set_car_price(car_price);
        obj.set_car_seating_capacity(car_seating_capacity);
        obj.set_car_ground_clearance(car_ground_clearance);
        obj.set_car_availability(availability);
        obj.set_offroad_capability(offroad_capability);
        obj.set_towing_capacity(towing_capacity);

        return in;
    }

};

#endif
