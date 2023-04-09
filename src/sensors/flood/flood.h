
int readFloodValue(int pin) {
    return digitalRead(pin);
}

int readAverageFloodValue(int pin, int cycles) {
    int count = cycles;
    int sum = 0;

    while(count > 0) {
        sum += readFloodValue(pin);
        count -= 1;
    }

    if(float(sum) > 0.5*float(cycles))
        return 1;
    else
        return 0;
}


void tsunamiAlarm(int speaker_pin, int cycles) {
  for(cycles; cycles > 0; cycles--) {
      for(int i = 0; i < 100; i++){
//        tone(speaker_pin, i * i, 500);
        analogWrite(speaker_pin, 254 * (i + 1)/100);
        delay(20);
      }
  }
  digitalWrite(speaker_pin, LOW);
}

void powerFloodAlarm(int speaker_pin) {
    tsunamiAlarm(speaker_pin, 2);
}

void unPowerFloodAlarm(int speaker_pin) {
    digitalWrite(speaker_pin, LOW);
}

void powerFloodLight(int pin) {
    digitalWrite(pin, HIGH);
}

void unPowerFloodLight(int pin) {
    digitalWrite(pin, LOW);
}
