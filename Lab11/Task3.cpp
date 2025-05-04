#include <iostream>
#include <exception>
#include <fstream>
#include <string>
using namespace std;

class FileException : public exception {
public:
    const char* what() const noexcept override {
        return "FileException - General file error";
    }
};

class FileNotFoundException : public FileException {
public:
    const char* what() const noexcept override {
        return "FileNotFoundException - File not found";
    }
};

class PermissionDeniedException : public FileException {
public:
    const char* what() const noexcept override {
        return "PermissionDeniedException - Access denied";
    }
};

void readFile(const string& filename) {
    ifstream file(filename);
    
    if (!file) {
        if (errno == ENOENT) {
            throw FileNotFoundException();
        } else if (errno == EACCES) {
            throw PermissionDeniedException();
        } else {
            throw FileException();
        }
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    file.close();
}

int main() {
    string filename;
    cout << "Enter filename to read: ";
    cin >> filename;

    try {
        cout << "Reading '" << filename << "':" << endl;
        readFile(filename);
    }
    catch (const FileNotFoundException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const PermissionDeniedException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const FileException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
