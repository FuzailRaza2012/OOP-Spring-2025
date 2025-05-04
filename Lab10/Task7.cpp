#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
	ofstream file;
	file.open("sensor_log.txt", ios::out);
	
	int up_Next = 0;
	
	char* str = new char[2];
	
	int size = 2;
		
	int original = 0;
	
	int final = 0;
	
	while (1){
		
		char ch = '\0'; 
		
		while ((ch = cin.get()) != '\n'){
			
			if (original == size - 1){
				size *= 2;
				char* temp = new char[size];
				
				strcpy(temp, str);
				
				delete[] str;
				
				str = temp;
			}
			
			str[original++] = ch;
			
			if (original == 1){
				str[original - 1] = toupper(str[original - 1]);
			}
			else if (up_Next == 1){
				str[original - 1] = toupper(str[original - 1]);
				if (ch == ' '){
					up_Next = 1;
				}
				else{
					up_Next = 0;
				}	
			}
			else{
				str[original - 1] = tolower(str[original - 1]);
			}
			
			if (ch == '.'){
				up_Next = 1;
			}
						
			str[original] = '\0';
			
			string low = str;
			
			size_t condition = low.find("exit");
			size_t vice = low.find("Exit");
			
			if (condition != string::npos || vice != string::npos){
				final = 1;
				break;
			}
			
		}
		try {
			if (final == 1) throw true;
			throw false;
		}
		catch (bool a){
			if (a == true){
				file << str << "(Statement broken due to trigger word)" << endl;
				delete[] str;
				break;
			}
			file << str << endl;
			
			str[original] = '\0';
			
			streampos cur = file.tellp();			
			
			cout << "current position in file is: " << cur << endl;
			
			delete[] str;
			
			original = 0;
			
			size = 2;
			
			str = new char[size];
		}
	}
	
	cout << "leaving the sensor_log.txt interface..." << endl;
	
	file.close();
	
	return 0;
	
}
