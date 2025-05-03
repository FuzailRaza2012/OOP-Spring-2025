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
		
		if (Type == "HybridTruck"){
			size_t pos;
			size_t end;
			size_t next;
			
			pos = ExtraData.find(':');
			end = ExtraData.find('|');
			next = ExtraData.find(':', end);
			
			if (pos != string::npos || end != string::npos || next != string::npos){
				string x = ExtraData.substr(pos + 1, end - pos + 1);
				int X = stoi(x);
				
				string y = ExtraData.substr(next + 1);
				int Y = stoi(y);
				
				cout << "Cargo: " << X << endl << "Battery: " << Y << endl;
			}		
		}
	}
	
	file.close();
	return 0;
}
