#include <iostream>
using namespace std;

class Humidity;

class Temperature{
    float temp;
public:
    Temperature(float t){
        temp = t;
    }
    friend float calculateHeatIndex(Temperature t, Humidity h);
};

class Humidity{
    float hum;
public:
    Humidity(float h){
        hum = h;
    }
    friend float calculateHeatIndex(Temperature t, Humidity h);
};

float calculateHeatIndex(Temperature t, Humidity h){
    return t.temp + 0.1 * h.hum;
}

int main(){
    Temperature t(32);
    Humidity h(70);

    float heatIndex = calculateHeatIndex(t, h);

    if(heatIndex > 40){
        cout << "Very hot! Heat Index: " << heatIndex << "°C" << endl;
    }
    else{
        cout << "Heat Index: " << heatIndex << "°C" << endl;
    }

    return 0;
}
