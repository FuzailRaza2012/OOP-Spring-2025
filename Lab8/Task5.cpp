#include <iostream>
using namespace std;

class Fraction {
    int num, den;

public:
    Fraction(int n = 0, int d = 1) {
        num = n;
        den = d;
    }

    Fraction operator+(const Fraction &f) {
        return Fraction(num * f.den + f.num * den, den * f.den);
    }

    Fraction operator-(const Fraction &f) {
        return Fraction(num * f.den - f.num * den, den * f.den);
    }

    Fraction operator*(const Fraction &f) {
        return Fraction(num * f.num, den * f.den);
    }

    Fraction operator/(const Fraction &f) {
        return Fraction(num * f.den, den * f.num);
    }

    friend ostream& operator<<(ostream &out, const Fraction &f) {
        out << f.num << "/" << f.den;
        return out;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction prod = f1 * f2;
    Fraction div = f1 / f2;

    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Division: " << div << endl;

    return 0;
}
