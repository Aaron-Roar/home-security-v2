#include "/root/development/home-security2/src/sensors/laser/laser_sensor.h"

int first_run_laser = 0;
int norm_laser = 0;
int laser_state = 0;

void laserInit() {
    pinMode(laser_power_pin, OUTPUT);
    pinMode(led_array[0], OUTPUT);
    pinMode(led_array[1], OUTPUT);
    pinMode(led_array[2], OUTPUT);

    powerLaser(laser_power_pin);
    calibrateLaser();
}

void setLaserState(int laser_value) {
    if((laser_value + laser_norm) < (laser_norm/4)) {
        laser_state = 0;
    }
    else if((laser_value + laser_norm) < (laser_norm/2)) {
        laser_state = 1;
    }
    else {
        laser_state = 2;
    }
}

void laser() {

    int laser_val = readAverageLaser(15);
    Serial.println(laser_val);
    Serial.println(laser_norm);
    setLaserState(laser_val);
}

void updateLed(int new_laser_state) {
    if(new_laser_state == 0) {
        //grren Light on
        powerLed(0);
    }
    else if(new_laser_state == 1) {
        //Yellow Light on
        powerLed(1);
    }
    else {
        //Rde light on
        powerLed(2);
    }
}

int previous_laser_state = 0;
void isLaserTriped() {
    if(laser_state != previous_laser_state) {
        previous_laser_state = laser_state;
    }
    Serial.println(laser_state);
    updateLed(laser_state);
}

//void setup() {
//    Serial.begin(9600);
//    laserInit();
//    Serial.println("setup-laser");
//}
//
//void loop() {
//    laser();
//    isLaserTriped();
//    Serial.println("loop-laser");
//}
