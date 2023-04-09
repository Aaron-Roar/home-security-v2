#include "/root/development/home-security2/src/sensors/flood/flood.h"

int flood_pin = 8;
int speaker_pin = A0;
int flood_light_pin = 10;
int flood_state = 0;

void flood_init() {
    pinMode(flood_pin, INPUT);
    pinMode(speaker_pin, OUTPUT);
}

void floodDetection() {
    if(readAverageFloodValue(flood_pin, 10) == 1)
        flood_state = 1;
    else
        flood_state = 0;
}

void floodResponse() {
    if(flood_state == 1) {
        powerFloodLight(flood_light_pin);
        powerFloodAlarm(speaker_pin);
    }
    else {
        unPowerFloodLight(flood_light_pin);
        unPowerFloodAlarm(speaker_pin);
    }
}

//void setup() {
//Serial.begin(9600);
//    flood_init();
//}
//
//void loop() {
//    floodDetection();
//    floodResponse();
//    Serial.println(readAverageFloodValue(flood_pin, 10));
//}
