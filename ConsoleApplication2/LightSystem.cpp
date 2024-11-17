#include "LightSystem.h"
#include <cmath>
#define M_PI 3.14
using namespace std;

Lamp::Lamp() : lightIntensity(0), power(0), isOn(false) {}

Lamp::Lamp(double lightIntensity, double power, bool isOn)
    : lightIntensity(lightIntensity), power(power), isOn(isOn) {}

Lamp::Lamp(const Lamp& other)
    : lightIntensity(other.lightIntensity), power(other.power), isOn(other.isOn) {}

double Lamp::getLightIntensity() const {
    return lightIntensity;
}

void Lamp::setLightIntensity(double newIntensity) {
    lightIntensity = newIntensity;
}

double Lamp::getPower() const {
    return power;
}

void Lamp::setPower(double newPower) {
    power = newPower;
}

bool Lamp::getIsOn() const {
    return isOn;
}

void Lamp::turnOn() {
    isOn = true;
}

void Lamp::turnOff() {
    isOn = false;
}

double Lamp::calculateIllumination(double x, double y, double z) const {
    if (!isOn) return 0;
    double distance = sqrt(x * x + y * y + z * z);
    return lightIntensity / (4 * M_PI * distance * distance);
}

string Lamp::identify() const {
    return "Lamp";
}

LEDLamp::LEDLamp(double redIntensity, double greenIntensity, double blueIntensity, double power, bool isOn)
    : Lamp(0, power, isOn), redIntensity(redIntensity), greenIntensity(greenIntensity), blueIntensity(blueIntensity) {
    updateLightIntensity();
}

void LEDLamp::updateLightIntensity() {
    double totalIntensity = redIntensity + greenIntensity + blueIntensity;
    setLightIntensity(totalIntensity);
}

double LEDLamp::calculateIllumination(double x, double y, double z) const {
    if (!getIsOn()) return 0;
    double distance = sqrt(x * x + y * y + z * z);
    return getLightIntensity() / (4 * M_PI * distance * distance);
}

string LEDLamp::identify() const {
    return "LED Lamp";
}

void LightSourceMatrix::addLamp(const Lamp& lamp) {
    lamps.push_back(lamp);
}

double LightSourceMatrix::calculateTotalIllumination(double x, double y, double z) const {
    double totalIllumination = 0;
    for (const auto& lamp : lamps) {
        totalIllumination += lamp.calculateIllumination(x, y, z);
    }
    return totalIllumination;
}

