#pragma once
#ifndef LIGHT_SYSTEM_H
#define LIGHT_SYSTEM_H

#include <string>
#include <vector>
using namespace std;
class Lamp {
private:
    double lightIntensity;  
    double power;           
    bool isOn;              

public:
    Lamp();
    Lamp(double lightIntensity, double power, bool isOn);
    Lamp(const Lamp& other);

    double getLightIntensity() const;
    void setLightIntensity(double newIntensity);

    double getPower() const;
    void setPower(double newPower);

    bool getIsOn() const;
    void turnOn();
    void turnOff();

    double calculateIllumination(double x, double y, double z) const;

    virtual string identify() const;
    virtual ~Lamp() = default;
};

class LEDLamp : public Lamp {
private:
    double redIntensity;
    double greenIntensity;
    double blueIntensity;

public:
    LEDLamp(double redIntensity, double greenIntensity, double blueIntensity, double power, bool isOn);

    void updateLightIntensity();
    double calculateIllumination(double x, double y, double z) const ;
    string identify() const override;
};

class LightSourceMatrix {
private:
    vector<Lamp> lamps;

public:
    void addLamp(const Lamp& lamp);
    double calculateTotalIllumination(double x, double y, double z) const;
};

#endif 
