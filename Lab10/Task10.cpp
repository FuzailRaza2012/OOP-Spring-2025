#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ofstream file("data_records.txt");
	
	file << "Record 1\n";
	
	file << "Record 2\n";
	
	file << "Record 3\n";
	
	file << "Record 4\n";
	
	file.close();
	
	ifstream infile("data_records.txt");
	
	string read;
	
	int i = 0;
	
	streampos total = 0; 
	
	while (getline(infile, read)){
		if (i < 2){
			total += read.size() + 2;
			i++;
		}
		else{
			i++;
		}
	}
	
	infile.clear();
	
	infile.seekg(total, ios::beg);
	
	cout << "reReading from outside: " << endl;
	
	
	string reread;
	
	getline(infile, reread);
	
	cout << "Line content seeked: " << reread << endl;
	cout << "At position: " << total;
}
