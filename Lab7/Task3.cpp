#include <iostream>
#include <string>
using namespace std;

class Currency {
public:
    double amount;
    string currencycode;
    string currencysymbol;
    float exchangerate;

    Currency(double a, string cc, string cs, float s) : amount(a), currencycode(cc), currencysymbol(cs), exchangerate(s) {}

    virtual void converttobase() {
        cout << "Converted to USD: " << amount * exchangerate << " USD" << endl;
    }

    virtual void displaycurrency() const {
        cout << amount << " " << currencysymbol << " (" << currencycode << ") | Exchange Rate: " << exchangerate << endl;
    }

    virtual ~Currency() {}
    void converttocurrency(string targetcurrency);
};

class Dollar : public Currency {
public:
    Dollar(double a) : Currency(a, "USD", "$", 1.0) {}
    void converttobase() { cout << "USD stays USD: " << amount << " USD" << endl; }
    void displaycurrency() { cout << "Dollar -> "; Currency::displaycurrency(); }
};

class Rupee : public Currency {
public:
    Rupee(double a) : Currency(a, "PKR", "Rs", 0.0061) {}
    void converttobase() { cout << "PKR to USD: " << amount * exchangerate << " USD" << endl; }
    void displaycurrency() { cout << "Rupee -> "; Currency::displaycurrency(); }
};

class Euro : public Currency {
public:
    Euro(double a) : Currency(a, "EUR", "€", 1.1) {}
    void converttobase() { cout << "EUR to USD: " << amount * exchangerate << " USD" << endl; }
    void displaycurrency() { cout << "Euro -> "; Currency::displaycurrency(); }
};

void Currency::converttocurrency(string targetcurrency) {
    if (targetcurrency == "dollar" || targetcurrency == "Dollar") {
        Dollar d(amount); d.converttobase();
    } else if (targetcurrency == "rupee" || targetcurrency == "Rupee") {
        Rupee r(amount); r.converttobase();
    } else if (targetcurrency == "euro" || targetcurrency == "Euro") {
        Euro e(amount); e.converttobase();
    } else {
        cout << "Nah, invalid currency." << endl;
    }
}

int main() {
    Currency* usd = new Dollar(100);
    Currency* eur = new Euro(100);
    Currency* pkr = new Rupee(1000);

    usd->displaycurrency();
    eur->displaycurrency();
    pkr->displaycurrency();

    usd->converttobase();
    eur->converttobase();
    pkr->converttobase();

    pkr->converttocurrency("dollar");
    eur->converttocurrency("rupee");

    delete usd;
    delete eur;
    delete pkr;
    return 0;
}
