#include <iostream>
#include <string>

using namespace std;

class Store;
class Product;

class Product{
    public:
        static int count;
        int ID;
        string name;
        float price;
        
        Product(){
            name = "";
            price = 0.0;
            ID = 0;
        }

        Product(string n, float p){
            name = n;
            price = p;
            ID = ++count;
        }

};

class Store{
    public:
        Product products[100];
        int cur;

        Store(){
            cur = 0;
        }

        void addProd(string n, float p){
            if (cur < 100){
                products[cur] = Product(n, p);
                cur++;
                cout << "Product was Added" << endl;
            }
            else{
                cout << "Inventory Full" << endl;
            }
        }

        void search(string n){
            int index = -1;
            for (int i = 0; i < cur; i++){
                if (products[i].name == n){
                    index = i;
                    break;
                } 
            }

            if (index == -1){
                cout << "Item was not found!" << endl;
            }
            else{
                cout << "Item was found!" << endl;
                cout << "--Item Details--" << endl;
                cout << "Product ID: " << products[index].ID << endl;
                cout << "Product Name: " << products[index].name << endl;
                cout << "Product Price: " << products[index].price << endl;
            }
        }

        void sort(){
            for (int i = 0; i < cur - 1; i++){
                for (int j = 0; j < cur - i - 1; j++){
                    if (products[j].price > products[j + 1].price){
                        Product temp = products[j + 1];
                        products[j + 1] = products[j];
                        products[j] = temp;
                    }
                }
            }
        }

        void display(){
            cout << "--Displaying Product List--" << endl;
            for (int i = 0; i < cur; i++){
                cout << "Product " << i + 1 << ": " << endl;
                cout << "Product ID: " << products[i].ID << endl;
                cout << "Product Name: " << products[i].name << endl;
                cout << "Product Price: $" << products[i].price << endl;
            }
        }

};

int Product:: count = 0;

int main(){
    Store inventory;

    while(1) {
        int ch;
        cout << "Press 1 to Add a Product" << endl;
        cout << "Press 2 to Display the Product List" << endl;
        cout << "Press 3 to Search for a Product" << endl;
        cout << "Press 4 to Exit" << endl;

        cout << "Make a Choice: ";
        cin >> ch;

        if (ch == 1){
            string n;
            float p;

            cout << "Enter the name of Product: ";
            cin.ignore();
            getline(cin, n);

            cout << "Enter price of the named Product: ";
            cin >> p;

            inventory.addProd(n, p);
        }
        else if (ch == 2){
            inventory.sort();
            inventory.display();
        }
        else if (ch == 3){
            string n;
            cout << "Enter Product Name to search for: ";
            cin.ignore();
            getline(cin, n);

            inventory.search(n);
        }
        else if (ch == 4){
            cout << "Exiting..." << endl;
            break;
        }
        else{
            cout << "Incorrect Choice" << endl;
        }
    }
}
