#include <iostream>
using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
    bool isOn;
    int brightness;

public:
    LightBulb(int b = 100) {
        isOn = false;
        brightness = b;
    }

    void turnOn() override {
        isOn = true;
        cout << "LightBulb turned on." << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "LightBulb turned off." << endl;
    }

    void getStatus() override {
        cout << "LightBulb is " << (isOn ? "On" : "Off");
        cout << ", Brightness: " << brightness << "%" << endl;
    }
};

class Thermostat : public SmartDevice {
    bool isOn;
    double temperature;

public:
    Thermostat(double t = 22.5) {
        isOn = false;
        temperature = t;
    }

    void turnOn() override {
        isOn = true;
        cout << "Thermostat turned on." << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "Thermostat turned off." << endl;
    }

    void getStatus() override {
        cout << "Thermostat is " << (isOn ? "On" : "Off");
        cout << ", Temperature: " << temperature << "°C" << endl;
    }
};

int main() {
    SmartDevice* devices[2];

    devices[0] = new LightBulb(75);
    devices[1] = new Thermostat(20.0);

    for (int i = 0; i < 2; i++) {
        devices[i]->turnOn();
        devices[i]->getStatus();
        devices[i]->turnOff();
        devices[i]->getStatus();
        cout << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete devices[i];
    }

    return 0;
}
