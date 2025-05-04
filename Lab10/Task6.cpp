#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

class InventoryItem{
	private:
		int itemID;
		char itemName[20];
		
	public:
		InventoryItem() {
			itemID = 0;
			strcpy(itemName, "");
		}
		
		InventoryItem(int ii, char* is) : itemID(ii) {
			for (int i = 0; i < 19; i++){
				itemName[i] = is[i];
			}
			itemName[19] = '\0';
		}
		
		int getItemID(){
			return itemID;
		}
		
		const char* getItemName() const{
			return itemName;
		}
		
		~InventoryItem(){
			
		}
};

int main(){
	InventoryItem a(1, "Apple");
	
	ofstream ofile("inventory.dat", ios::binary);
	
	if (!ofile){
		cout << "Error in opening file";
		return 1;
	}
	
	ofile.write((char*)&a, sizeof(a));
	
	ofile.close();
	
	InventoryItem b;
	
	ifstream ifile("inventory.dat", ios::binary);
	
	if (!ifile){
		cout << "Error in opening file";
		return 1;
	}
	
	ifile.read((char*)&b, sizeof(b));
	
	ifile.close();
	
	cout << "Item ID: " << b.getItemID() << endl << "Item Name: " << b.getItemName() << endl;
}
