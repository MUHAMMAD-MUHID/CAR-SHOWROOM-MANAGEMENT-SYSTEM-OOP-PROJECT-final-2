#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits> 
using namespace std;
void main_menu();
class Employee : public Person {
private:
    string employee_position;
    float employee_salary;
    public:
    Employee() : Person() {
        employee_position = "n/a";
        employee_salary = 0.0;
    }
    Employee(int person_id, string person_name, string employee_position, float employee_salary)
        : Person(person_id, person_name) {
        this->employee_position = employee_position;
        this->employee_salary = employee_salary;
    }
    Employee(const Employee& obj) : Person(obj) {
        this->employee_position = obj.employee_position;
        this->employee_salary = obj.employee_salary;
    }
    void set_employee_position(string employee_position) {
        this->employee_position = employee_position;
    }
    void set_employee_salary(float employee_salary) {
        this->employee_salary = employee_salary;
    }
    string get_employee_position() const {
        return employee_position;
    }
    float get_employee_salary() const {
        return employee_salary;
    }

    string toString() const {
        return Person::tostring() + "\t" + employee_position + "\t" + to_string(employee_salary) + "\n";
    }

    void store_to_file() const {
        ofstream fout("Employee.txt", ios::app);
        if (fout.is_open()) {
            fout << toString();
            fout.close();
            cout << "\nData Stored To Employee File" << endl;
        }
        else {
            cerr << "\nError: Unable to open file for writing." << endl;
        }
    }
    void view_from_file() const {
        cout << "\n-------------------";
        cout << "\n----ALL RECORDS----";
        cout << "\n-------------------";
        ifstream fin("Employee.txt");
        if (fin.is_open()) {
            Employee line;
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
    void update() {
        int id;
        cout << "Enter the ID of the Employee to update: ";
        cin >> id;
        cin.ignore();
        ifstream fin("Employee.txt");
        ofstream fout("temp.txt");
        if (fin.is_open() && fout.is_open()) {
            bool found = false;
            int temp_id;
            string temp_name, temp_position;
            float temp_salary;

            while (fin >> temp_id >> temp_name >> temp_position >> temp_salary) {
                if (temp_id == id) {
                    found = true;
                    cout << "Enter Employee Name: ";
                    getline(cin, temp_name);
                    cout << "Enter Employee Position: ";
                    getline(cin, temp_position);
                    cout << "Enter Employee Salary: ";
                    cin >> temp_salary;
                    fout << temp_id << "\t" << temp_name << "\t" << temp_position << "\t" << temp_salary << endl;
                }
                else {
                    fout << temp_id << "\t" << temp_name << "\t" << temp_position << "\t" << temp_salary << endl;
                }
            }
            fin.close();
            fout.close();
            remove("Employee.txt");
            rename("temp.txt", "Employee.txt");
            if (!found) {
                cout << "Employee with ID " << id << " not found." << endl;
            }
            else {
                cout << "Employee updated successfully." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading or writing." << endl;
        }
    }
    void search() const {
        int id;
        cout << "Enter the ID of the Employee to search: ";
        cin >> id;
        ifstream fin("Employee.txt");
        if (fin.is_open()) {
            bool found = false;
            int temp_id;
            string temp_name, temp_position;
            float temp_salary;

            while (fin >> temp_id >> temp_name >> temp_position >> temp_salary) {
                if (temp_id == id) {
                    found = true;
                    cout << "\nEmployee ID: " << temp_id;
                    cout << "\nEmployee Name: " << temp_name;
                    cout << "\nEmployee Position: " << temp_position;
                    cout << "\nEmployee Salary: " << temp_salary << endl;
                }
            }
            fin.close();
            if (!found) {
                cout << "Employee with ID " << id << " not found." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
    }
    void del() {
        int id;
        cout << "Enter the ID of the Employee to delete: ";
        cin >> id;
        ifstream fin("Employee.txt");
        ofstream fout("temp.txt");
        if (fin.is_open() && fout.is_open()) {
            bool found = false;
            int temp_id;
            string temp_name, temp_position;
            float temp_salary;

            while (fin >> temp_id >> temp_name >> temp_position >> temp_salary) {
                if (temp_id == id) {
                    found = true;
                }
                else {
                    fout << temp_id << "\t" << temp_name << "\t" << temp_position << "\t" << temp_salary << endl;
                }
            }
            fin.close();
            fout.close();
            remove("Employee.txt");
            rename("temp.txt", "Employee.txt");
            if (!found) {
                cout << "Employee with ID " << id << " not found." << endl;
            }
            else {
                cout << "Employee with ID " << id << " deleted successfully." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading or writing." << endl;
        }
    }

    void menu(Employee& obj) {
        int choice;
        do {
            cout << "\n<--Employee Menu-->\n1.Add Employee\n2.View Employees\n3.Update Employee\n4.Search Employee\n5.Delete Employee\n6.Return To Main Menu: ";
            cin >> choice;
            cin.ignore(); // To consume newline character left in the input buffer
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
    friend ostream& operator<<(ostream& cout, const Employee& obj) {
        cout << "\nEmployee ID: " << obj.get_person_id();
        cout << "\nEmployee Name: " << obj.get_person_name();
        cout << "\nEmployee Position: " << obj.employee_position;
        cout << "\nEmployee Salary: " << obj.employee_salary;
        return cout;
    }
    friend istream& operator>>(istream& is, Employee& obj) {
        int person_id;
        string person_name, employee_position;
        float employee_salary;

        if (typeid(is) != typeid(cin)) {
            is >> person_id >> person_name >> employee_position >> employee_salary;
        }
        else {
            cout << "\nEnter Employee ID: ";
            while (!(is >> person_id)) {
                cerr << "\nError: Invalid input for Employee ID. Please enter a valid integer." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nEnter Employee ID: ";
            }
            is.ignore(); 

            cout << "\nEnter Employee Name: ";
            getline(is, person_name);

            cout << "\nEnter Employee Position: ";
            getline(is, employee_position);

            cout << "\nEnter Employee Salary: ";
            while (!(is >> employee_salary)) {
                cerr << "Error: Invalid input for Employee Salary. Please enter a valid number." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Employee Salary: ";
            }
        }

        obj.set_person_id(person_id);
        obj.set_person_name(person_name);
        obj.set_employee_position(employee_position);
        obj.set_employee_salary(employee_salary);

        return is;
    }
};
#endif // EMPLOYEE_H
