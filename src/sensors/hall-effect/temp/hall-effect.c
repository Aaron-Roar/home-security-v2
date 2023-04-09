#include "hall_effect.h"

int hall_effect_array[] =       {2, 3, 4}; //Hall Effect D2 and D3
int hall_effect_light_array[] = {5, 6, 7}; //Lights D4 and D5
int cycle_amount = 100;
int hall_states[sizeof(hall_effect_array)/sizeof(hall_effect_array[0])] = {0};

void setHallStates() {
    int count = 0;
    while(count < sizeof(hall_states)/sizeof(hall_states[0])) {
        if(readAverageHallValue(hall_effect_array[count], cycle_amount) == 1)
            hall_states[count] = 1;
        else
            hall_states[count] = 0;
        count += 1;
    }
}

void hallStateResponse() {
    int count = 0;
    while(count < sizeof(hall_states)/sizeof(hall_states[0])) {
        if(hall_states[count] == 1)
            powerHallLight(hall_effect_light_array[count]);
        else
            unPowerHallLight(hall_effect_light_array[count]);
        count += 1;
    }
}

//void setup() {
//    Serial.begin(9600);
//initHall(hall_effect_array, hall_effect_light_array, sizeof(hall_effect_array)/sizeof(hall_effect_array[0]));
//}
//
//void loop() {
//    setHallStates();
//    hallStateResponse();
//}
