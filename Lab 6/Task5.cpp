#include <iostream>
#include <string>

using namespace std;

class Device{
	public:
		int deviceID;
		bool status;
		
		Device(int ID, bool s) : deviceID(ID), status(s) {}
		
		virtual void displayDetails(){
			cout << "Device ID: " << deviceID << endl << "Status: ";
			if (status){
				cout << "on" << endl;
			}
			else{
				cout << "off" << endl;
			}
		}
};

class SmartPhone: virtual public Device{
	public:
		float screenSize;
		
		SmartPhone(int ID, bool s, float ss) : Device(ID, s), screenSize(ss) {}
		
		void displayDetails() override{
			Device::displayDetails();
			cout << "Screen Size: " << screenSize << endl;
		}
};

class SmartWatch: virtual public Device{
	public:
		bool heartRateMonitor;
		
		SmartWatch(int ID, bool s, bool hr) : Device(ID, s), heartRateMonitor(hr) {}
		
		void displayDetails() override{
			Device::displayDetails();
			cout << "Heart-Rate Monitor: ";
			if (heartRateMonitor){
				cout << "on" << endl;
			}
			else{
				cout << "off" << endl;
			}
		}
};

class SmartWearable: public SmartPhone, public SmartWatch{
	public:
		int stepCounter;
		
		SmartWearable(int ID, bool s, float ss, bool hr, int sc) : Device(ID, s), SmartWatch(ID, s, hr), SmartPhone(ID, s, ss), stepCounter(sc){}
		
		void displayDetails() override{
			Device::displayDetails();
			cout << "Screen Size: " << screenSize << endl;
			cout << "Heart-Rate Monitor: ";
			if (heartRateMonitor){
				cout << "on" << endl;
			}
			else{
				cout << "off" << endl;
			}
			cout << "Step Counter: " << stepCounter << endl;
		}
};

int main(){
	SmartWearable smartwearable(123, true, 6.9, true, 108);
	
	smartwearable.displayDetails();
}
