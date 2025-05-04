#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ifstream file("large_log.txt");
	
	string dump;
	
	int i = 0;
	
	while(getline(file, dump)){
		
		cout << "The first 10 characters of line " << i + 1 << " are: " << dump.substr(0, 10) << endl;
		
		cout << "The position is: " << file.tellg() << endl;
		
		i++;
	}
}
