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
		
		int year = stoi(Year);
		
		cout << "\nInfo " << i << ": " << endl;
		cout << "Type: " << Type << endl << "ID: " << ID << endl << "Name: " << Name << endl << "Year: " << year << endl << "Extra Data: " << ExtraData << endl << "Certification: " << Certification << endl;
	}
	
	file.close();
	return 0;
}
