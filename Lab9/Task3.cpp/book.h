#pragma once
#include <string>
using namespace std;

class Book {
    string title;
    string author;
    string ISBN;

public:
    Book(string t, string a, string i);
    string getTitle();
    string getAuthor();
    string getISBN();
};
