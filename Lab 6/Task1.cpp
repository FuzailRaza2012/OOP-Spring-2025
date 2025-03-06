#include <iostream>
#include <string>

using namespace std;

class Employee{
	public:
		string name;
		float salary;
		
		Employee(string n, float s) : name(n), salary(s) {
		}
		
		void displayDetails(){
			cout << "Name: " << name << endl << "Salary: " << salary << endl;
		}
};

class Manager : public Employee {
	public:
		float bonus;
		
		Manager (string n, float s, float b) : Employee(n, s), bonus(b) {
			
		}
		
		void displayDetails(){
			cout << "Name: " << name << endl << "Salary: " << salary << endl << "Bonus: " << bonus << endl;
		}
};

int main(){
	Manager man("Ales", 23.6, 24.5);
	
	man.displayDetails();
}
