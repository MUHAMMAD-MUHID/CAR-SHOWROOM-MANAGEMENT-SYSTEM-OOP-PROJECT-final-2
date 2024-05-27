#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Car.h"
class Car {
private:
    int car_id, car_seating_capacity, car_ground_clearance;
    string car_make, car_model,is_car_available;float car_price;
public:
    Car() {
        car_id = 0;
        car_make = "n/a";
        car_model = "n/a";
        car_price = 0.0;
        car_seating_capacity = 0;
        car_ground_clearance = 0;
        is_car_available = "n/a";
    }
    Car(int car_id, string car_make, string car_model, float car_price, int car_seating_capacity, int car_ground_clearance, string is_car_available) {
        this->car_id = car_id;
        this->car_make = car_make;
        this->car_model = car_model;
        this->car_price = car_price;
        this->car_seating_capacity = car_seating_capacity;
        this->car_ground_clearance = car_ground_clearance;
        this->is_car_available = is_car_available;
    }
    Car(const Car& obj) {
        car_id = obj.car_id;
        car_make = obj.car_make;
        car_model = obj.car_model;
        car_price = obj.car_price;
        car_seating_capacity = obj.car_seating_capacity;
        car_ground_clearance = obj.car_ground_clearance;
        is_car_available = obj.is_car_available;
    }
    void set_car_id(int car_id) {
        this->car_id = car_id;
    }
    void set_car_make(string car_make) {
        this->car_make = car_make;
    }
    void set_car_model(string car_model) {
        this->car_model = car_model;
    }
    void set_car_seating_capacity(int car_seating_capacity) {
        this->car_seating_capacity = car_seating_capacity;
    }
    void set_car_ground_clearance(int car_ground_clearance) {
        this->car_ground_clearance = car_ground_clearance;
    }
    void set_car_price(float car_price) {
        this->car_price = car_price;
    }
    void set_car_availability(string is_car_available) {
        this->is_car_available = is_car_available;
    }

    int get_car_id()const {
        return car_id;
    }
    string get_car_make()const {
        return car_make;
    }
    string get_car_model()const {
        return car_model;
    }
    int get_car_seating_capacity()const {
        return car_seating_capacity;
    }
    int get_car_ground_clearance()const {
        return car_ground_clearance;
    }
    float get_car_price()const {
        return car_price;
    }
    string get_car_availability() const {
        return is_car_available;
    }

    string tostring() const {
        return to_string(car_id) + "\t" + car_make + "\t" + car_model + "\t" + to_string(car_price) + "\t" + to_string(car_seating_capacity) + "\t" + to_string(car_ground_clearance) + "\t" + is_car_available;
    }
    friend ostream& operator<<(ostream& cout, const Car& car) {
        // Output car data to the output stream
        cout << "Car ID: " << car.get_car_id() << endl;
        cout << "Car Make: " << car.get_car_make() << endl;
        cout << "Car Model: " << car.get_car_model() << endl;
        cout << "Car Price: " << car.get_car_price() << endl;
        cout << "Car Seating Caapacity: " << car.get_car_seating_capacity() << endl;
        cout << "Car Ground Clearance: " << car.get_car_ground_clearance() << endl;
        cout << "Car Availability: " << car.get_car_availability() << endl;
        return cout;
    }
  
   friend istream& operator>>(istream& cin, Car& car) {
        cout << "Car ID: ";cin >> car.car_id;
        cout << "Car Make: ";cin >> car.car_make;
        cout << "Car Model: ";cin >> car.car_model;
        cout << "Car Price: ";cin >> car.car_price;
        cout << "Car Seating Caapacity: ";cin >> car.car_seating_capacity;
        cout << "Car Ground Clearance: ";cin >> car.car_ground_clearance;
        cout << "Car Availability: ";cin >> car.is_car_available;
        return cin;
    }
};
#endif
