#include <iostream>
#include <string>

using namespace std;

class Battery;
class Smartphone;

class Battery {
    public:
        int capacity;

        Battery(){
            capacity = 0;
        }

        Battery(int c){
            capacity = c;
        }

        void disp(){
            cout << "Battery Capacity in mAh: " << capacity << endl;
        }
};

class Smartphone {
    public:
        string model;
        Battery battery;

        Smartphone (){
            model = "";
            battery = Battery();
        }

        Smartphone (string m, int bc){
            model = m;
            battery = Battery(bc);
        }

        void display(){
            cout << "Model: " << model << endl;
            battery.disp();
        }
};

int main(){
    Smartphone phone1("Samsung Galaxy S24 Ultra", 6000);
    Smartphone phone2("Tecno SPARK 50+ Pro", 7000);

    phone1.display();
    cout << "---------------------------------" << endl;
    phone2.display();


}
