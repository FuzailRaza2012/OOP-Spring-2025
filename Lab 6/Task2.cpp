#include <iostream>
#include <string>

using namespace std;

class Vehicle {
	public:
		string brand;
		int speed;
		
		Vehicle(string b, int s) : brand(b), speed(s) {
		}
		
		void displayDetails(){
			cout << "Brand: " << brand << endl << "Speed: " << speed << endl;
		}
};

class Car : public Vehicle{
	public:
		int seats;
		
		Car(string b, int s, int se) : Vehicle(b, s), seats(se) {
		}
		
		void displayDetails(){
			cout << "Brand: " << brand << endl << "Speed: " << speed << endl << "Seats: " << seats << endl;
		}
};

class ElectricCar : public Car{
	public:
		int batteryLife;
		
		ElectricCar(string b, int s, int se, int bl) : Car(b, s, s), batteryLife(bl) {
		}
		
		void displayDetails(){
			cout << "Brand: " << brand << endl << "Speed: " << speed << endl << "Seats: " << seats << endl << "Battery Life: " << batteryLife << " years " << endl;
		}
};


int main(){
	ElectricCar car("Toyota", 120, 4, 5);
	
	car.displayDetails();
}
