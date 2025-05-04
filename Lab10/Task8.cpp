#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
	fstream file;
	
	file.open("config.txt", ios::in | ios::out);
	
	file << "AAAAABBBBBCCCCC" << endl;
	
	file.seekp(5, ios::beg);
	
	file << "XXXXX";

	file.seekp(0, ios::beg);
	
	string line;
	
	getline(file, line);

	cout << line << endl;
}
