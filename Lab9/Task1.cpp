#include <iostream>
using namespace std;

class Vehicle {
protected:
    string model;
    double rate;

public:
    Vehicle(string m, double r) : model(m), rate(r) {}
    virtual double getDailyRate() const = 0;
    virtual void displayDetails() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(string m, double r) : Vehicle(m, r) {}

    double getDailyRate() const override {
        return rate;
    }

    void displayDetails() const override {
        cout << "Car: " << model << " | $" << rate << " per day" << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string m, double r) : Vehicle(m, r) {}

    double getDailyRate() const override {
        return rate;
    }

    void displayDetails() const override {
        cout << "Bike: " << model << " | $" << rate << " per day" << endl;
    }
};

int main() {
    Vehicle* vehicles[2];

    vehicles[0] = new Car("Honda Civic", 60.0);
    vehicles[1] = new Bike("Ducati Monster", 45.0);

    for (int i = 0; i < 2; ++i) {
        vehicles[i]->displayDetails();
        cout << "Today's rate: $" << vehicles[i]->getDailyRate() << endl << endl;
    }

    for (int i = 0; i < 2; ++i)
        delete vehicles[i];

    return 0;
}
