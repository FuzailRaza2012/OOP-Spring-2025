#include <iostream>
#include <string>

using namespace std;

class Car {
 public:
  static int id;
  int regnum;
  string model;
  string owner;
  bool taken;

  Car(string m, string o) {
    regnum = id++;
    model = m;
    owner = o;
    taken = false;

    cout << "Created Car of model: " << model << " And Owner: " << owner
         << endl;
  }

  Car(Car &c) {
    regnum = id++;
    model = c.model;
    cout << "Enter name of owner: ";
    cin.ignore();
    getline(cin, owner);

    cout << "Copied Car of model: " << model << " And Owner: " << owner << endl;
  }

  void display() {
    cout << "Registration Number: " << regnum << endl;
    cout << "Model: " << model << endl;
    cout << "Owner Name: " << owner << endl;
  }
};

int Car::id = 0;

int main() {
  Car car1("abc", "John");
  Car car2("xyz", "James");

  int ch = -1;

  cout << "Press 1 to rent car 1" << endl;
  cout << "Press 2 to rent car 2" << endl;

  cout << "Enter choice: ";
  cin >> ch;

  if (ch == 1) {
    Car car3(car1);

    car1.display();
    car2.display();
    car3.display();
  } else {
    Car car3(car2);

    car1.display();
    car2.display();
    car3.display();
  }
}
