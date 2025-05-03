#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	string fileName = "vehicles.txt";
	ifstream file(fileName);
	
	if (!file.is_open()){
		cout << "Not Open" << endl;
		return 1;
	}
	
	string line;
	int i = 0;
	
	while (getline(file, line)){
		if (line.substr(0, 2) == "//" || line.empty()){
			continue;
		}
		
		i += 1;
		
		istringstream ss(line);
		string Type, ID, Name, Year, ExtraData, Certification;
		
		getline(ss, Type, ',');
		getline(ss, ID, ',');
		getline(ss, Name, ',');
		getline(ss, Year, ',');
		getline(ss, ExtraData, ',');
		getline(ss, Certification, ',');
		
		if (Type == "AutonomousCar") {
    		size_t pos = ExtraData.find(':');
    		if (pos != string::npos) {
        		string valueStr = ExtraData.substr(pos + 1);
        		float softwareVersion = stof(valueStr);
        		cout << "ID: " << ID << " | Software Version: " << softwareVersion << endl;
    		}
		} 
		else if (Type == "ElectricVehicle") {
    		size_t pos = ExtraData.find(':');
    		if (pos != string::npos) {
        		string valueStr = ExtraData.substr(pos + 1);
        		int batteryCapacity = stoi(valueStr);
        		cout << "ID: " << ID << " | Battery Capacity: " << batteryCapacity << endl;
    		}
		}

	}
	
	file.close();
	return 0;
}
