#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileName = "vehicles.txt";
	ifstream file(fileName);
	
	if (!file.is_open()){
		cout << "Not Open" << endl;
		return 1;
	}
	
	string line;
	while (getline(file, line)){
		if (line.substr(0, 2) == "//" || line.empty()){
			continue;
		}
		
		cout << line << endl;
	}
	
	file.close();
	return 0;
}
