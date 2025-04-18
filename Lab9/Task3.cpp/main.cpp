#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    Book b("1984", "George Orwell", "123-456-789");

    cout << "Title: " << b.getTitle() << endl;
    cout << "Author: " << b.getAuthor() << endl;
    cout << "ISBN: " << b.getISBN() << endl;

    return 0;
}
