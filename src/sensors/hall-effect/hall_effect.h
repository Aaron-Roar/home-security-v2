
int readHallValue(int pin) {
    return digitalRead(pin);
}

//Returns the ratio of High/Low
//Low->Strong Field : High->Weak Field
int readAverageHallValue(int pin, int cycles) {
    int counter = cycles;
    int sum = 0;

    while(counter > 0) {
        sum += readHallValue(pin);
        counter -= 1;
    }

    if(sum >= cycles/2)
        return 1;
    else
        return 0;
}

void powerHallLight(int pin) {
    digitalWrite(pin, HIGH);
}

void unPowerHallLight(int pin) {
    digitalWrite(pin, LOW);
}
