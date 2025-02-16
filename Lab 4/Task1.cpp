#include <iostream>
#include <string>

using namespace std;

class Book {
    public:
        string title;
        float price;
        int *stock;

        Book(){
            title = "Unknown";
            price = 0.0;
            stock = new int(30);
        }
        
        ~Book(){
            delete stock;
        }

        void update(){
            int ch = 0;

            cout << "What do you wish to change?" << endl;
            cout << "Press 1 for Title" << endl;
            cout << "Press 2 for Price" << endl;
            cout << "Press 3 for Stock" << endl;

            cout << "Choose: ";
            cin >> ch;

            if (ch == 1){
                cin.ignore();
                cout << "Enter new Title: ";
                getline(cin, title);

                cout << "The Title was successfully updated!" << endl;
            }
            else if (ch == 2){
                cout << "Enter new Price: ";
                cin >> price;

                cout << "The Price was successfully updated!" << endl;
            }
            else if (ch == 3){
                int add;

                cout << "Enter Number of books being added to the stock: ";
                cin >> add;

                while (add <= 0){
                    cout << "Invalid Addition!" << endl;
                    cout << "Enter Number of books being added to the stock: ";
                    cin >> add;
                }

                (*stock) += add;

                cout << "The Stock was successfully updated!" << endl;
            }
            else{
                cout << "Invalid Choice!" << endl;
            }
        }

        void control(){
            int buy;

            cout << "How many books do you wish to buy: ";
            cin >> buy;

            if (*stock - buy < 0){
                cout << "The ask for buying is more than the available stock which is: " << *stock << endl; 
            }
            else if (*stock - buy < 5){
                *stock -= buy;

                cout << "Bought successfully!" << endl;

                cout << "LOW STOCK WARNING" << endl;
                cout << "The new remaining stock is: " << *stock << endl;
            }
            else{
                cout << "Bought successfully!" << endl;
                cout << "The new remaining stock is: " << *stock << endl;
            }
        }

};

int main(){
    Book book;
    book.update();
    book.update();
    book.update();
    book.control();
    book.control();
}
