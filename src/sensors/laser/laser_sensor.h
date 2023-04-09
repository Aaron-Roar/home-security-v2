int laser_pin = A2;
int laser_power_pin = A1;
int laser_norm = 0;
int led_array[3] = {12, 11, 13};

int readLaser() {
    delay(10);
    return (analogRead(laser_pin) - laser_norm);
}

void powerLaser(int pin) {
    digitalWrite(pin, HIGH);
}

void unPowerLaser(int pin) {
    digitalWrite(pin, LOW);
}

int readAverageLaser(int cycles) {
    int i = 0;
    int sum = 0;

    while (i < cycles) {
        sum += readLaser();
        i += 1;
    }

    return (sum/i);
}

void calibrateLaser() {
    laser_norm = readAverageLaser(20);
}

void unPowerLed(int value) {
    digitalWrite(led_array[value], LOW);
}

void powerLed(int value) {
    int i = 0;
    while(i < 3) {
        if(i != value) {
            unPowerLed(i);
        }
        i += 1;

    }
        digitalWrite(led_array[value], HIGH);
}
