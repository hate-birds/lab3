#include <iostream>
#include <cassert>
#include "LightSystem.h"

using namespace std;

void testLamp() {
    Lamp lamp(1000, 60, true);

    assert(lamp.getLightIntensity() == 1000);
    assert(lamp.getPower() == 60);
    assert(lamp.getIsOn() == true);

    double illumination = lamp.calculateIllumination(1, 2, 1);
    cout << "Illumination at (1, 2, 1): " << illumination << endl;

    lamp.turnOff();
    assert(lamp.getIsOn() == false);
    assert(lamp.calculateIllumination(1, 1, 1) == 0);
}

void testLEDLamp() {
    LEDLamp ledLamp(300, 400, 500, 40, true);

    assert(ledLamp.getLightIntensity() == 1200);
    assert(ledLamp.getPower() == 40);
    assert(ledLamp.getIsOn() == true);

    double illumination = ledLamp.calculateIllumination(1, 1, 1);
    cout << "Illumination at (1, 1, 1): " << illumination << endl;
}

void testLightSourceMatrix() {
    LightSourceMatrix matrix;
    matrix.addLamp(Lamp(1000, 60, true));
    matrix.addLamp(Lamp(500, 30, true));

    double illumination = matrix.calculateTotalIllumination(1, 1, 1);
    cout << "Total illumination at (1, 1, 1): " << illumination << endl;
}

int main() {
    testLamp();
    testLEDLamp();
    testLightSourceMatrix();

    cout << "All tests passed!" << endl;
    return 0;
}
