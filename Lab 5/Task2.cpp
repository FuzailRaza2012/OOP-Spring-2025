#include <iostream>
#include <string>

using namespace std;

class Patient {
 public:
  static int id;
  int ID;
  string name;
  string *reports;
  int tests;

  Patient(string n, string *r, int na) {
    ID = id++;
    name = n;
    tests = na;
    reports = new string[na];
    reports = r;
  }

  ~Patient() { delete[] reports; }

  Patient(Patient &p) {
    ID = id++;
    name = p.name;
    tests = p.tests;
    reports = new string[p.tests];
    for (int i = 0; i < tests; i++) {
      reports[i] = p.reports[i];
    }
  }

  void update() {
    cout << "Change Name: ";
    getline(cin, name);
    reports[1] = "AIDS";
  }

  void display() {
    cout << "Name: " << name << endl;
    cout << "Tests Conducted: " << tests << endl;
    cout << "Patient ID: " << ID << endl;
    for (int i = 0; i < tests; i++) {
      cout << "Result of report " << i + 1 << " is " << reports[i] << endl;
    }
  }
};

int Patient::id = 0;

int main() {
  string a[] = {"Diabetes", "Sugar"};
  Patient patient1("Akbar", a, 2);

  Patient patient2(patient1);

  patient1.display();
  patient2.update();
  patient2.display();
}
