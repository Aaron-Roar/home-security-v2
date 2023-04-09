#include "./identification.h"

//Analog values with no person 300-330
//Someone of max height (same as door way)  reads 505-535
//Dog or Baby is between 360-390 7/16 of the door way height
int psd_global = 0;
int psd_pin = A7;
int psd_light_pin = 9;

void psd_init(){
    pinMode(psd_light_pin, OUTPUT);
    delay(44); //Typical Start Up delay
}

void update_psd(){
  psd_global = psd_avg_read(psd_pin);
}

void psd_light_indication(){
  if(400 <= psd_global && psd_global <= 535){ //Height of an adult would be between 400-535
    //Light will remain constant if an adult is present
    Serial.println("400-535");
    power_psd_light(psd_light_pin);
  }
  else if(360 <=psd_global && psd_global <= 390){ //Any Height around half of the doorways height will be in this range
    //Light will flash if an animal/child is present
        Serial.println("360-390");
        power_psd_light(psd_light_pin);
        delay(500);
        unpower_psd_light(psd_light_pin);
        delay(500);
  }
  else {
  Serial.println("other");
    unpower_psd_light(psd_light_pin);
  } 
}

//void setup() {
//  Serial.begin(9600);
//  psd_init();
//  update_psd();
//}
//
//void loop(){
//  update_psd();
//  psd_light_indication();
//  Serial.println(psd_global);
//
//}
