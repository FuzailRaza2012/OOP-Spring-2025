    #include <iostream>
    #include <string>

    using namespace std;

    class Book {
        public:
            static int bookcount;
            int id;
            string title;
            float price;
            int *stock;

            Book(string t, float p, int s) : id(bookcount++), title (t), price (p), stock (new int(s)){
                cout << "Book of Name: " << title << ", Price: " << this->price << ", Stock: " << *stock << " Has been Created!" << endl;
            }

            Book(Book &obj) : id(bookcount++), title (obj.title), price (obj.price), stock (new int(*obj.stock)){
                cout << "Book of Name: " << title << ", Price: " << this->price << ", Stock: " << *stock << " Has been Copied!" << endl;
            }
            
            ~Book(){
                cout << "Book of Name: " << title << ", Price: " << this->price << ", Stock: " << *stock << " Has been Destroyed!" << endl;
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

                    applyDiscount(buy);
                    cout << "Bought successfully!" << endl;

                    cout << "LOW STOCK WARNING" << endl;
                    cout << "The new remaining stock is: " << *stock << endl;
                }
                else{
                    *stock -= buy;

                    applyDiscount(buy);
                    cout << "Bought successfully!" << endl;
                    cout << "The new remaining stock is: " << *stock << endl;
                }
            }

            void applyDiscount(int buy){
                if (buy > 5 && buy < 11){
                    cout << "DISCOUNT APPLIED!" << endl;
                    cout << "Original cost: " << (this->price * buy) << endl;
                    cout << " New Discounted cost: " << (this->price * 0.95 * buy) << endl;
                }
                else if (buy > 11){
                    cout << "DISCOUNT APPLIED!" << endl;
                    cout << "Original cost: " << (this->price * buy) << endl;
                    cout << " New Discounted cost: " << (this->price * 0.90 * buy) << endl;
                }
                else{
                    cout << "No changes to the this->price" << endl;
                    cout << "Cost: " << (this->price * buy) << endl;
                }
            }

            void display(){
                cout << "--Book Details--" << endl;
                cout << "Book ID: " << id << endl; 
                cout << "Book Title: " << title << endl;
                cout << "Price: " << price << endl;
                cout << "Stock: " << *stock << endl;
            }
    };

    int Book:: bookcount = 0;



    int main(){
        Book book("Area 404", 3.5, 30);
        Book book2(book);
        cout << "Before Changes to Original: " << endl;
        cout << "Original: " << endl;
        book.display();
        cout << "Copied: " << endl;
        book2.display();
        cout << "Making Changes to Original: " << endl;
        book.update();
        book.update();
        book.update();
        cout << "After Changes to Original: " << endl;
        cout << "Original: " << endl;
        book.display();
        cout << "Copied: " << endl;
        book2.display();
    }
