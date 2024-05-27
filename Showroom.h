#ifndef SHOWROOM_H
#define SHOWROOM_H

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void main_menu(); // Forward declaration for main menu

class Showroom {
private:
    int id;
    string name, location;

public:
    Showroom() {
        id = 0;
        name = "n/a";
        location = "n/a";
    }
    Showroom(int s_id, string s_name, string s_location) {
        id = s_id;
        name = s_name;
        location = s_location;
    }
    Showroom(const Showroom& obj) {
        id = obj.id;
        name = obj.name;
        location = obj.location;
    }
    void set_id(int s_id) {
        id = s_id;
    }
    void set_name(string s_name) {
        name = s_name;
    }
    void set_location(string s_location) {
        location = s_location;
    }
    int get_id() const {
        return id;
    }
    string get_name() const {
        return name;
    }
    string get_location() const {
        return location;
    }
    string to_string() const {
        return std::to_string(id) + "\t" + name + "\t" + location;
    }
    void store_to_file() const {
        ofstream fout("Showroom.txt", ios::app);
        if (fout.is_open()) {
            fout << to_string() << endl;
            fout.close();
            cout << "\nData Stored To Showroom File";
        }
        else {
            cerr << "Error: Unable to open file for writing." << endl;
        }
    }
    void view_from_file() const {
        cout << "\n-------------------";
        cout << "\n----ALL RECORDS----";
        cout << "\n-------------------";
        ifstream fin("Showroom.txt");
        if (fin.is_open()) {
            Showroom line;
            while (fin >> line.id >> line.name >> line.location) {
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
        int update_id;
        cout << "Enter the ID of the Showroom to update: ";
        cin >> update_id;

        ifstream fin("Showroom.txt");
        ofstream fout("temp.txt");
        if (fin.is_open() && fout.is_open()) {
            bool found = false;
            int temp_id;
            string temp_name, temp_location;

            while (fin >> temp_id >> temp_name >> temp_location) {
                if (temp_id == update_id) {
                    found = true;
                    cout << "Enter Showroom Name: ";
                    cin.ignore();
                    getline(cin, temp_name);
                    cout << "Enter Showroom Location: ";
                    getline(cin, temp_location);
                    fout << temp_id << "\t" << temp_name << "\t" << temp_location << endl;
                }
                else {
                    fout << temp_id << "\t" << temp_name << "\t" << temp_location << endl;
                }
            }
            fin.close();
            fout.close();
            remove("Showroom.txt");
            rename("temp.txt", "Showroom.txt");
            if (!found) {
                cout << "Showroom with ID " << update_id << " not found." << endl;
            }
            else {
                cout << "Showroom updated successfully." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading or writing." << endl;
        }
    }
    void search() const {
        int search_id;
        cout << "Enter the ID of the Showroom to search: ";
        cin >> search_id;

        ifstream fin("Showroom.txt");
        if (fin.is_open()) {
            bool found = false;
            int temp_id;
            string temp_name, temp_location;

            while (fin >> temp_id >> temp_name >> temp_location) {
                if (temp_id == search_id) {
                    found = true;
                    cout << "\nShowroom ID: " << temp_id;
                    cout << "\nShowroom Name: " << temp_name;
                    cout << "\nShowroom Location: " << temp_location << endl;
                }
            }
            fin.close();
            if (!found) {
                cout << "Showroom with ID " << search_id << " not found." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
    }
    void del() {
        int delete_id;
        cout << "Enter the ID of the Showroom to delete: ";
        cin >> delete_id;

        ifstream fin("Showroom.txt");
        ofstream fout("temp.txt");
        if (fin.is_open() && fout.is_open()) {
            bool found = false;
            int temp_id;
            string temp_name, temp_location;

            while (fin >> temp_id >> temp_name >> temp_location) {
                if (temp_id == delete_id) {
                    found = true;
                }
                else {
                    fout << temp_id << "\t" << temp_name << "\t" << temp_location << endl;
                }
            }
            fin.close();
            fout.close();
            remove("Showroom.txt");
            rename("temp.txt", "Showroom.txt");
            if (!found) {
                cout << "Showroom with ID " << delete_id << " not found." << endl;
            }
            else {
                cout << "Showroom with ID " << delete_id << " deleted successfully." << endl;
            }
        }
        else {
            cerr << "Error: Unable to open file for reading or writing." << endl;
        }
    }
   /* void total_cars()
    {
        int count = 0;
        ifstream fin_s("SUV.txt");
        ifstream fin_se("Sedan.txt");
        ifstream fin_h("SUV.txt");
        string temp;
        while (getline(fin_s, temp))
        {
            count++;
        }
        while (getline(fin_se, temp))
        {
            count++;
        }
        while (getline(fin_h, temp))
        {
            count++;
        }
        cout << "\nTotal Records in the File is : " << count;
        fin_s.close();
        fin_se.close();
        fin_h.close();
        ofstream fout("total_cars.txt");
        fout << count;
    }*/


    void menu(Showroom& obj) {
        int choice;
        do {
            cout << "\n<--Showroom Menu-->\n1 - Add Showroom\n2 - View Showroom\n3 - Update Showroom\n4 - Search Showroom\n5 - Delete Showroom\n6 - Return To Main Menu : ";
            cin >> choice;
            switch (choice) {
            case 1:
            {
                cin >> obj;
                obj.store_to_file();
                break;
            }
            case 2:
            {
                obj.view_from_file();
                break;
            }
            case 3:
            {
                obj.update();
                break;
            }
            case 4:
            {
                obj.search();
                break;
            }
            case 5:
            {
                obj.del();
                break;
            }
            case 6:
            {
                main_menu();
                break;
            }
            default:
            {
                cout << "\nInvalid Choice";
                break;
            }
            }
        } while (choice != 6);
    }
    friend ostream& operator<<(ostream& out, const Showroom& obj) {
        out << "\nShowroom ID: " << obj.id;
        out << "\nShowroom Name: " << obj.name;
        out << "\nShowroom Location: " << obj.location;
        return cout;
    }
    friend istream& operator>>(istream& is, Showroom& obj) {
        if (typeid(is) != typeid(cin)) {
            is >> obj.id >> obj.name >> obj.location;
        }
        else {
            cout << "Enter Showroom ID: ";
            while (!(is >> obj.id)) {
                cerr << "Error: Invalid input for Showroom ID. Please enter a valid integer." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Showroom ID: ";
            }
            is.ignore(); // To consume the newline character left in the buffer

            cout << "Enter Showroom Name: ";
            getline(is, obj.name);

            cout << "Enter Showroom Location: ";
            getline(is, obj.location);
        }
        return is;
    }
};

#endif