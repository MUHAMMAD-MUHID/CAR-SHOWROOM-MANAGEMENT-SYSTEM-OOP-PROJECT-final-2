#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Person.h"
#include "Customer.h"
#include "SUV.h"
#include "Sedan.h"
#include "Hatchback.h"
#include "Insurance.h"
#include "Service.h"

void main_menu();

using namespace std;

class Transaction {
private:
    int transaction_id;
    float transaction_amount;
    string car_type;
    int car_id;
    Customer customer;

public:
    Transaction()
    {
        transaction_id = 0;
        transaction_amount = 0.0;
        car_id = 0;
    }
    Transaction(int transaction_id, float transaction_amount, const string car_type, int car_id, const Customer& customer)
    {
        this->transaction_id = transaction_id;
        this->transaction_amount = transaction_amount;
        this->car_type = car_type;
        this->car_id = car_id;
        this->customer = customer;
    }

    // Setters
    void set_transaction_id(int transaction_id) { this->transaction_id = transaction_id; }
    void set_transaction_amount(float transaction_amount) { this->transaction_amount = transaction_amount; }
    void set_car_type(const string car_type) { this->car_type = car_type; }
    void set_car_id(int car_id) { this->car_id = car_id; }
    void set_customer(const Customer& customer) { this->customer = customer; }

    // Getters
    int get_transaction_id() const { return transaction_id; }
    float get_transaction_amount() const { return transaction_amount; }
    const string get_car_type() const { return car_type; }
    int get_car_id() const { return car_id; }
    const Customer& get_customer() const { return customer; }

    string tostring_t() const {
        return to_string(transaction_id) + "\t" + to_string(transaction_amount) + "\t" + car_type + "\t" + to_string(car_id) + "\t" + customer.get_person_name();
    }
    void store_to_file() {
        ofstream fout("Transaction.txt", ios::app);
        if (!fout) {
            cerr << "Error: Unable to open transactions file." << endl;
            return;
        }
        fout << transaction_id << "\t" << transaction_amount << "\t" << car_type << "\t" << car_id << "\t" << customer.get_person_id() << "\t" << customer.get_person_name() << endl;
        fout.close();
        cout << "\nTransaction Stored To File" << endl;
    }
    void view_from_file() {
        ifstream fin("Transaction.txt");
        if (!fin) {
            cerr << "Error: Unable to open transactions file." << endl;
            return;
        }
        int id, cid, cust_id; float amount; string type, name;
        cout << "\n----------------------------";
        cout << "\n---------ALL RECORDS--------";
        cout << "\n----------------------------";
        while (fin >> id >> amount >> type >> cid >> cust_id >> ws) {
            getline(fin, name);
            cout << "\n\nTransaction ID: " << id << "\nAmount: " << amount << "\nCar Type: " << type << "\nCar ID: " << cid << "\nCustomer ID: " << cust_id << "\nCustomer Name: " << name << endl;
            cout << "\n----------------------------";
        }
        fin.close();
    }
    void search() {
        int search_id;
        cout << "Enter the Transaction ID to search: ";
        cin >> search_id;

        ifstream fin("Transaction.txt");
        if (!fin) {
            cerr << "Error: Unable to open transactions file." << endl;
            return;
        }

        bool found = false;
        int id;
        float amount;
        string type, name;
        int cid, cust_id;
        while (fin >> id >> amount >> type >> cid >> cust_id >> ws) {
            getline(fin, name);
            if (id == search_id) {
                found = true;
                cout << "Transaction ID: " << id << "\nAmount: " << amount << "\nCar Type: " << type << "\nCar ID: " << cid << "\nCustomer ID: " << cust_id << "\nCustomer Name: " << name << endl;
                break;
            }
        }

        if (!found) {
            cout << "Transaction with ID " << search_id << " not found." << endl;
        }

        fin.close();
    }
    void update() {
        int update_id;
        cout << "Enter the Transaction ID to update: ";
        cin >> update_id;

        ifstream fin("Transaction.txt");
        ofstream fout("temp.txt");
        if (!fin || !fout) {
            cerr << "Error: Unable to open transactions file." << endl;
            return;
        }

        bool found = false;
        int id;
        float amount;
        string type, name;
        int cid, cust_id;
        while (fin >> id >> amount >> type >> cid >> cust_id >> ws) {
            getline(fin, name);
            if (id == update_id) {
                found = true;
                cout << "Enter New Transaction Amount: ";
                cin >> amount;
                cout << "Enter New Car Type: ";
                cin >> type;
                cout << "Enter New Car ID: ";
                cin >> cid;
                cout << "Enter New Customer ID: ";
                cin >> cust_id;
                cin.ignore(); // To consume newline character left in the buffer
                cout << "Enter New Customer Name: ";
                getline(cin, name);
            }
            fout << id << "\t" << amount << "\t" << type << "\t" << cid << "\t" << cust_id << "\t" << name << endl;
        }

        fin.close();
        fout.close();
        remove("Transaction.txt");
        rename("temp.txt", "Transaction.txt");

        if (!found) {
            cout << "Transaction with ID " << update_id << " not found." << endl;
        }
        else {
            cout << "Transaction updated successfully." << endl;
        }
    }
    void del() {
        int delete_id;
        cout << "Enter the Transaction ID to delete: ";
        cin >> delete_id;

        ifstream fin("Transaction.txt");
        ofstream fout("temp.txt");
        if (!fin || !fout) {
            cerr << "Error: Unable to open transactions file." << endl;
            return;
        }

        bool found = false;
        int id;
        float amount;
        string type, name;
        int cid, cust_id;
        while (fin >> id >> amount >> type >> cid >> cust_id >> ws) {
            getline(fin, name);
            if (id == delete_id) {
                found = true;
            }
            else {
                fout << id << "\t" << amount << "\t" << type << "\t" << cid << "\t" << cust_id << "\t" << name << endl;
            }
        }

        fin.close();
        fout.close();
        remove("Transaction.txt");
        rename("temp.txt", "Transaction.txt");

        if (!found) {
            cout << "Transaction with ID " << delete_id << " not found." << endl;
        }
        else {
            cout << "Transaction deleted successfully." << endl;
        }
    }
    void check_availability_and_enter_data() {
        string car_type;
        int car_id;
        bool is_available = false;

        cout << "\nEnter Info to Check Availabilty Of Car";
        cout << "\nEnter Car Type (SUV/Sedan/Hatchback): ";
        cin >> car_type;
        cout << "\nEnter Car ID: ";
        cin >> car_id;

        if (car_type == "suv") {
            SUV suv;
            is_available = suv.check_availability(car_id);
        }
        else if (car_type == "sedan") {
            Sedan sedan;
            is_available = sedan.check_availability(car_id);
        }
        else if (car_type == "hatchback") {
            Hatchback hatchback;
            is_available = hatchback.check_availability(car_id);
        }
        else {
            cerr << "\nInvalid Input Entered." << endl;
            return;
        }

        if (is_available == true) {
            cout << "\nYour Lucky Car Is Available In Our Showroom";
            Transaction transaction;
            cin >> transaction;
            transaction.store_to_file();
        }
        else {
            cout << "Car with ID " << car_id << " is not available." << endl;
        }
    }

    void menu(Transaction& obj) {
        int choice;
        do {
            cout << "\n**** Transaction Menu ****\n1. ADD Transaction\n2. View Transactions\n3. Update Transaction\n4. Search Transaction\n5. Delete Transaction\n6. Return To Main Menu: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1: {
                cout << "\n--------------------------";
                cout << "\n-----ADD DATA TO FILE-----";
                cout << "\n--------------------------";
                //cin >> obj;
                obj.check_availability_and_enter_data();
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
        } while (choice != 7);
    }
    friend ostream& operator<<(ostream& os, const Transaction& obj) {
        os << "Transaction ID: " << obj.get_transaction_id() << "\n"
            << "Transaction Amount: " << obj.get_transaction_amount() << "\n"
            << "Car Type: " << obj.get_car_type() << "\n"
            << "Car ID: " << obj.get_car_id() << "\n"
            << "Customer Details:\n" << obj.get_customer();

        return os;
    }
    friend istream& operator>>(istream& is, Transaction& obj) {
        int transaction_id;
        float transaction_amount;
        string car_type;
        int car_id;
        Customer customer;

        if (typeid(is) != typeid(cin)) {
            is >> transaction_id >> transaction_amount >> car_type >> car_id >> customer;
        }
        else {
            cout << "\nEnter Transaction ID: ";
            while (!(is >> transaction_id)) {
                cerr << "\nError: Invalid input for Transaction ID. Please enter a valid integer." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nEnter Transaction ID: ";
            }
            is.ignore();

            cout << "\nEnter Transaction Amount: ";
            while (!(is >> transaction_amount)) {
                cerr << "\nError: Invalid input for Transaction Amount. Please enter a valid float." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nEnter Transaction Amount: ";
            }
            is.ignore();

            cout << "\nEnter Car Type (SUV/Sedan/Hatchback): ";
            getline(is, car_type);

            cout << "\nEnter Car ID: ";
            while (!(is >> car_id)) {
                cerr << "\nError: Invalid input for Car ID. Please enter a valid integer." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nEnter Car ID: ";
            }
            is.ignore();


            cout << "\nEnter Customer Details: " << endl;
            is >> customer;
            obj.set_customer(customer);

            customer.store_to_file();
            cout << "\nOTHER OFFERS IN OUR SHOWROOM YOU CAN AVAIL";
            cout << "\nOffers \n1.Insurance \n2.Service \n3.Both";
            int option; cin >> option;
            switch(option)
            {
            case 1:
            {

                cout << "OUR SHOWROOM Insurance FACILITY";
                Insurance i;
                ofstream fout("insurance.txt", ios::app);
                cout << "\nEnter Insurance id : ";
                int temp; cin >> temp;
                cout << "\nEnter Insurance Name : ";
                string temp1; cin >> temp1;
                i.set_Insurance_id(temp);
                i.set_Insurance_type(temp1);
                fout << "\n" << i.get_Insurance_id() << "\t" << i.get_Insurance_type();
                cout << "\nINSURANCE DATA STORED IN FILE";
                break;
            }
            case 2:
            {
                cout << "OUR SHOWROOM SERVICE FACILITY";
                Service s;
                ofstream fout("service.txt", ios::app);
                cout << "\nEnter service id : ";
                int temp; cin >> temp;
                cout << "\nEnter service Name : ";
                string temp1; cin >> temp1;
                s.set_service_id(temp);
                s.set_service_name(temp1);
                fout << "\n" << s.get_service_id() << "\t" << s.get_service_name();
                cout << "\nSERVICE DATA STORED IN FILE";
                break;
            }
            case 3:
            {
                cout << "OUR SHOWROOM SERVICE AND INSURANCE FACILITY";

                Service s;
                ofstream fout_i("service.txt", ios::app);
                cout << "\nEnter service id : ";
                int temp; cin >> temp;
                cout << "\nEnter service Name : ";
                string temp1; cin >> temp1;
                s.set_service_id(temp);
                s.set_service_name(temp1);
                fout_i << "\n" << s.get_service_id() << "\t" << s.get_service_name();
                cout << "\nSERVICE DATA STORED IN FILE";

                Insurance i;
                ofstream fout_s("insurance.txt", ios::app);
                cout << "\nEnter Insurance id : ";
                int temp2; cin >> temp2;
                cout << "\nEnter Insurance Name : ";
                string temp3; cin >> temp3;
                i.set_Insurance_id(temp2);
                i.set_Insurance_type(temp3);
                fout_s << "\n" << i.get_Insurance_id() << "\t" << i.get_Insurance_type();
                cout << "\nINSURANCE DATA STORED IN FILE";
                break;

            }
            default:
                cout << "\nInvalid Option Selected";

            }
            

        }

        obj.set_transaction_id(transaction_id);
        obj.set_transaction_amount(transaction_amount);
        obj.set_car_type(car_type);
        obj.set_car_id(car_id);

        return is;
    }
};

#endif
