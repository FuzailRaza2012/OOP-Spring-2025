#include<iostream>
#include<string>
using namespace std;

class Media {
public:
    string title, publisher;
    int publicationdate;
    static int uniqueid;
    bool available;

    Media(string t, int p, string pub) : title(t), publicationdate(p), publisher(pub), available(true) {
        uniqueid++;
    }

    virtual void displayinfo() {
        cout << "ID: " << uniqueid << " | Title: " << title << " | Published: " << publicationdate
             << " | Publisher: " << publisher << " | Available: " << (available ? "YES" : "NO") << endl;
    }

    void checkout() {
        if (available) {
            available = false;
            cout << "You just borrowed '" << title << "'. Enjoy!" << endl;
        } else {
            cout << "Oops! '" << title << "' is already checked out." << endl;
        }
    }

    void returnitem() {
        if (!available) {
            available = true;
            cout << "Thanks for returning '" << title << "'!" << endl;
        } else {
            cout << "Huh? '" << title << "' wasn't borrowed in the first place." << endl;
        }
    }

    virtual ~Media() {}
};

int Media::uniqueid = 0;

class Book : public Media {
public:
    string author;
    int isbn, nopages;

    Book(string t, int p, string pub, string a, int i, int pages)
        : Media(t, p, pub), author(a), isbn(i), nopages(pages) {}

    void displayinfo() {
        Media::displayinfo();
        cout << "Author: " << author << " | ISBN: " << isbn << " | Pages: " << nopages << endl;
        cout << "------------------------------------------------" << endl;
    }
};

class DVD : public Media {
public:
    string director;
    float duration, rating;

    DVD(string t, int p, string pub, string d, float dur, float r)
        : Media(t, p, pub), director(d), duration(dur), rating(r) {}

    void displayinfo() {
        Media::displayinfo();
        cout << "Director: " << director << " | Duration: " << duration << " min | Rating: " << rating << "/10" << endl;
        cout << "------------------------------------------------" << endl;
    }
};

class CD : public Media {
public:
    string artist, genre;
    int notracks;

    CD(string t, int p, string pub, string a, int tracks, string g)
        : Media(t, p, pub), artist(a), notracks(tracks), genre(g) {}

    void displayinfo() {
        Media::displayinfo();
        cout << "Artist: " << artist << " | Tracks: " << notracks << " | Genre: " << genre << endl;
        cout << "------------------------------------------------" << endl;
    }
};

int main() {
    Book book1("1984", 1949, "Secker & Warburg", "George Orwell", 123789, 328);
    DVD dvd1("The Matrix", 1999, "Warner Bros", "Wachowskis", 136.0, 8.7);
    CD cd1("Back in Black", 1980, "Atlantic Records", "AC/DC", 10, "Rock");

    book1.displayinfo();
    dvd1.displayinfo();
    cd1.displayinfo();

    book1.checkout();
    dvd1.checkout();
    cd1.checkout();

    book1.returnitem();
    dvd1.returnitem();
    cd1.returnitem();
    book1.returnitem();

    return 0;
}
