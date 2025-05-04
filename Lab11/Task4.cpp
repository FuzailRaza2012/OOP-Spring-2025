#include <iostream>
#include <cmath>
#include <string>
#include <exception>
using namespace std;

class NegativeValueError : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeValueError - Input must be zero or positive.";
    }
};

class TypeMismatchError : public exception {
public:
    const char* what() const noexcept override {
        return "TypeMismatchError - Invalid type passed to function.";
    }
};

template <typename T>
T getSquareRoot(T value) {
    if (value < 0) {
        throw NegativeValueError();
    }
    return sqrt(value);
}

// Overloads for invalid types
double getSquareRoot(const char* input) {
    throw TypeMismatchError();
}

double getSquareRoot(string input) {
    throw TypeMismatchError();
}

int main() {
    try {
        cout << "Square root of -10: ";
        cout << getSquareRoot(-10) << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "Square root of \"test\": ";
        cout << getSquareRoot("test") << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "Square root of 25: ";
        cout << getSquareRoot(25) << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
