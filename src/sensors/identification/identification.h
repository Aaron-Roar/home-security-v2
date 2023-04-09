
int psd_read(int pin){
  delay(80); //Delay of 39ms + 32ms = 71ms thus 80ms is delayed to allow a guaranteed 
  return analogRead(pin);
}
int psd_avg_read(int pin){
  int sum =0;
  for(int count=0; count <3; count++){
  sum +=psd_read(pin);
  }
  return sum/3;
}

void power_psd_light(int lightpin){
  digitalWrite(lightpin, HIGH);
}

void unpower_psd_light(int lightpin){
  digitalWrite(lightpin, LOW);
}
