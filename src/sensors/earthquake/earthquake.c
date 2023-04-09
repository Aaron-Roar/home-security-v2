#include <math.h>
#include "/root/development/home-security2/src/sensors/earthquake/earthquake.h"

int earthquake_led = A3;
int earthquake_alarm_pin = A0;

void powerEarthquakeLed(int pin) {
    digitalWrite(pin, HIGH);
}

void unPowerEarthquakeLed(int pin) {
    digitalWrite(pin, LOW);
}
void earthquakeInit() {
    Wire.begin();
    setupMPU();
    pinMode(earthquake_led, OUTPUT);
    pinMode(earthquake_alarm_pin, OUTPUT);
    ort_error = averageOrientation(1000, 0);
}

void updateOrientation() {
    struct Orientation ort = averageOrientation(10, 1);
    current_ort.roll = ort.roll;
    current_ort.pitch = ort.pitch;
}

void evaluateEarthQuake() {
    if(abs(current_ort.roll) > 1 || abs(current_ort.pitch) > 1) {
        powerEarthquakeLed(earthquake_led);
        Serial.println("QUAKE!!");
        fireAlarm(A0, 2);
    }
    else {
        unPowerEarthquakeLed(earthquake_led);
        Serial.println("No quake");
    }
}


void printCurrentOrt() {
     Serial.println("");
     Serial.print("Roll: ");
     Serial.print(current_ort.roll);
     Serial.print(" Pitch: ");
     Serial.print(current_ort.pitch);
     Serial.println("");
}

void printOrientation(struct Orientation ort) {
     Serial.println(""); //Had to print line for output to be registered on serial monitor
     Serial.print("Roll: ");
     Serial.print(ort.roll);
     Serial.print(" Pitch: ");
     Serial.print(ort.pitch);
}



//void setup() {
//  Serial.begin(9600);
//  earthquakeInit();
//}
//
//void loop() {
//Serial.println("loop");
//  struct Orientation ort = averageOrientation(10, 1);
//  updateOrientation();
//  evaluateEarthQuake();
//  printCurrentOrt();
//  delay(100);
//}
