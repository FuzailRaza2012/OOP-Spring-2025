#include <iostream>
using namespace std;

class Currency {
    double value;

public:
    Currency(double v = 0) {
        value = v;
    }

    Currency operator-() {
        return Currency(-value);
    }

    Currency operator+(const Currency &c) {
        return Currency(value + c.value);
    }

    Currency operator-(const Currency &c) {
        return Currency(value - c.value);
    }

    Currency& operator+=(const Currency &c) {
        value += c.value;
        return *this;
    }

    Currency& operator-=(const Currency &c) {
        value -= c.value;
        return *this;
    }

    friend ostream& operator<<(ostream &out, const Currency &c) {
        out << c.value;
        return out;
    }
};

int main() {
    Currency price1(100.5);
    Currency price2(50.25);

    Currency total = price1 + price2;
    Currency diff = price1 - price2;
    Currency discounted = -price2;

    cout << "Price 1: " << price1 << endl;
    cout << "Price 2: " << price2 << endl;
    cout << "Total: " << total << endl;
    cout << "Difference: " << diff << endl;
    cout << "Discounted (negated): " << discounted << endl;

    price1 += price2;
    cout << "After += : " << price1 << endl;

    price1 -= Currency(25.75);
    cout << "After -= : " << price1 << endl;

    return 0;
}
