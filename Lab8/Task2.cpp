#include <iostream>
using namespace std;

class Librarian;

class Book{
    string title;
    float price;
public:
    Book(string t, float p){
        title = t;
        price = p;
    }
    friend class Librarian;
};

class Librarian{
public:
    void display(Book b){
        cout << "Title: " << b.title << endl;
        cout << "Price: " << b.price << endl;
    }

    void applyDiscount(Book &b, float percent){
        b.price -= b.price * (percent / 100);
    }
};

int main(){
    Book b("Intro to C++", 500);

    Librarian l;
    l.display(b);

    l.applyDiscount(b, 20);

    cout << endl;

    l.display(b);

    return 0;
}
