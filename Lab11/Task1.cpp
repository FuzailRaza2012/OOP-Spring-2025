#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <exception>

using namespace std;

class InvalidValueException: public exception{
	public:
		const char* what() const noexcept override{
			return "InvalidValueException - Age cannot be in negative or go above 120";
		}
};

void validateAge(int age){
	if (age > 120 || age < 0){
		throw InvalidValueException();
	}
}

int main() {
	int age = -5;
	
	try{
		validateAge(age);
		cout << "Age is: " << age << endl;
	}
	catch(const InvalidValueException& e){
		cout << "Error:" << e.what() << endl;
	}
}
