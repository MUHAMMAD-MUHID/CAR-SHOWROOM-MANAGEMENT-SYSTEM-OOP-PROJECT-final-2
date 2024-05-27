#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
#include<limits>
void main_menu();
using namespace std;
class Customer : public Person {
private:
    string customer_vehicle_status;
    string customer_payment_status;
    string membership;
public:
    Customer() : Person() {
        customer_vehicle_status = "n/a";
        customer_payment_status = "n/a";
        membership = "n/a";
    }
    Customer(int person_id, string person_name, string customer_vehicle_status, string customer_payment_status, string membership)
        : Person(person_id, person_name) {
        this->customer_vehicle_status = customer_vehicle_status;
        this->customer_payment_status = customer_payment_status;
        this->membership = membership;
    }
    Customer(const Customer& obj) : Person(obj) {
        this->customer_vehicle_status = obj.customer_vehicle_status;
        this->customer_payment_status = obj.customer_payment_status;
        this->membership = obj.membership;
    }
    void set_customer_vehicle_status(string customer_vehicle_status) {
        this->customer_vehicle_status = customer_vehicle_status;
    }
    void set_customer_payment_status(string customer_payment_status) {
        this->customer_payment_status = customer_payment_status;
    }
    void set_customer_membership(string membership) {
        this->membership = membership;
    }
    string get_customer_vehicle_status() const {
        return customer_vehicle_status;
    }
    string get_customer_payment_status() const {
        return customer_payment_status;
    }
    string get_customer_membership() const {
        return membership;
    }
    
    string tostring() const {
        return Person::tostring() + "\t" + customer_vehicle_status + "\t" + customer_payment_status + "\t" + membership;
    }
    void store_to_file() const {
        ofstream fout("Customer.txt", ios::app);
        if (fout.is_open()) {
            fout << tostring();
            fout.close();
            cout << "\nData Stored To Employee File" << endl;
        }
        else {
            cerr << "Error: Unable to open file for writing." << endl;
        }
    }
    void view_from_file() const {
        ifstream fin("Customer.txt");
        if (fin.is_open()) {
            cout << "\n-------------------";
            cout << "\n----ALL RECORDS----";
            cout << "\n-------------------";
            Customer customer;
            while (fin >> customer) {
                cout << "\n----------------------------" << endl;
                cout << customer << endl;
            }
            fin.close();
        }
        else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
    }

    void search() const {
        int id;
        cout << "Enter the ID of the Customer to search: ";
        cin >> id;
        ifstream fin("Customer.txt");
        if (fin.is_open()) {
            bool found = false;
            int temp_id;
            string temp_name, temp_vehicle_status, temp_payment_status, temp_membership;

            while (fin >> temp_id >> temp_name >> temp_vehicle_status >> temp_payment_status >> temp_membership) {
                if (temp_id == id) {
                    found = true;
                    cout << "\nCustomer ID: " << temp_id;
                    cout << "\nCustomer Name: " << temp_name;
                    cout << "\nCustomer Vehicle Status: " << temp_vehicle_status;
                    cout << "\nCustomer Payment Status: " << temp_payment_status;
                    cout << "\nCustomer Membership: " << temp_membership;
                    break;
                }
            }
            fin.close();
            if (!found) {
                cout << "Customer with ID " << id << " not found." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
    }
    void update() {
        int id;
        cout << "Enter the ID of the Customer to update: ";
        cin >> id;
        cin.ignore(); // To consume the newline character left in the buffer
        ifstream fin("Customer.txt");
        ofstream fout("temp.txt");
        if (fin.is_open() && fout.is_open()) {
            bool found = false;
            int temp_id;
            string temp_name, temp_vehicle_status, temp_payment_status, temp_membership;

            while (fin >> temp_id >> temp_name >> temp_vehicle_status >> temp_payment_status >> temp_membership) {
                if (temp_id == id) {
                    found = true;
                    cout << "Enter Customer Name: ";
                    getline(cin, temp_name);
                    cout << "Enter Customer Vehicle Status: ";
                    getline(cin, temp_vehicle_status);
                    cout << "Enter Customer Payment Status: ";
                    getline(cin, temp_payment_status);
                    cout << "Enter Customer Membership: ";
                    getline(cin, temp_membership);
                    fout << temp_id << "\t" << temp_name << "\t" << temp_vehicle_status << "\t" << temp_payment_status << "\t" << temp_membership << endl;
                }
                else {
                    fout << temp_id << "\t" << temp_name << "\t" << temp_vehicle_status << "\t" << temp_payment_status << "\t" << temp_membership << endl;
                }
            }
            fin.close();
            fout.close();
            remove("Customer.txt");
            rename("temp.txt", "Customer.txt");
            if (!found) {
                cout << "Customer with ID " << id << " not found." << endl;
            }
            else {
                cout << "Customer updated successfully." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading or writing." << endl;
        }
    }
    void del() {
        int id;
        cout << "Enter the ID of the Customer to delete: ";
        cin >> id;
        ifstream fin("Customer.txt");
        ofstream fout("temp.txt");
        if (fin.is_open() && fout.is_open()) {
            bool found = false;
            int temp_id;
            string temp_name, temp_vehicle_status, temp_payment_status, temp_membership;

            while (fin >> temp_id >> temp_name >> temp_vehicle_status >> temp_payment_status >> temp_membership) {
                if (temp_id == id) {
                    found = true;
                }
                else {
                    fout << temp_id << "\t" << temp_name << "\t" << temp_vehicle_status << "\t" << temp_payment_status << "\t" << temp_membership << endl;
                }
            }
            fin.close();
            fout.close();
            remove("Customer.txt");
            rename("temp.txt", "Customer.txt");
            if (!found) {
                cout << "Customer with ID " << id << " not found." << endl;
            }
            else {
                cout << "Customer with ID " << id << " deleted successfully." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading or writing." << endl;
        }
    }
    void menu(Customer& obj) {
        int choice;
        do {
            cout << "\n<--Customer Menu-->\n1 - Add Customer\n2 - View Customers\n3 - Update Customer\n4 - Search Customer\n5 - Delete Customer\n6 - Return To Main Menu: ";
            cin >> choice;
            cin.ignore(); // To consume the newline character left in the buffer
            switch (choice) {
            case 1: {
                cout << "\n--------------------------";
                cout << "\n-----ADD DATA TO FILE-----";
                cout << "\n--------------------------";
                cin >> obj;
                obj.store_to_file();
                break;
            }
            case 2: {
                obj.view_from_file();
                break;
            }
            case 3: {
                cout << "\n--------------------------";
                cout << "\n---UPDATE DATA TO FILE----";
                cout << "\n--------------------------";
                obj.update();
                break;
            }
            case 4: {
                cout << "\n--------------------------";
                cout << "\n---SEARCH DATA TO FILE----";
                cout << "\n--------------------------";
                obj.search();
                break;
            }
            case 5: {
                cout << "\n--------------------------";
                cout << "\n---DELETE DATA TO FILE----";
                cout << "\n--------------------------";
                obj.del();
                break;
            }
            case 6: {
                main_menu();
                break;
            }
            default: {
                cout << "\nInvalid Choice" << endl;
                break;
            }
            }
        } while (choice != 6);
    }
    friend ostream& operator<<(ostream& cout, const Customer& obj) {
        cout << "\nCustomer ID: " << obj.get_person_id();
        cout << "\nCustomer Name: " << obj.get_person_name();
        cout << "\nCustomer Vehicle Status: " << obj.customer_vehicle_status;
        cout << "\nCustomer Payment Status: " << obj.customer_payment_status;
        cout << "\nCustomer Membership: " << obj.membership;
        return cout;
    }
    friend istream& operator>>(istream& is, Customer& obj) {
        int person_id;
        string person_name, customer_vehicle_status, customer_payment_status, membership;

     
        if (typeid(is) != typeid(cin)) {
            is >> person_id >> person_name >> customer_vehicle_status >> customer_payment_status >> membership;
        }
        else {
            cout << "Enter Customer ID: ";
            is >> person_id;
            is.ignore(); 
            cout << "Enter Customer Name: ";
            getline(is, person_name);
            cout << "Enter Customer Vehicle Status: ";
            getline(is, customer_vehicle_status);
            cout << "Enter Customer Payment Status: ";
            getline(is, customer_payment_status);
            cout << "Enter Customer Membership: ";
            getline(is, membership);
        }

        obj.set_person_id(person_id);
        obj.set_person_name(person_name);
        obj.set_customer_vehicle_status(customer_vehicle_status);
        obj.set_customer_payment_status(customer_payment_status);
        obj.set_customer_membership(membership);

        return is;
    }

};


#endif // CUSTOMER_H
