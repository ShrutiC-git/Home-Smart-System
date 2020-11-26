

bool getTemperature() {
  // Reading temperature for humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
   int chk = DHT11.read(DHT11PIN);

 

  Serial.print("Temperature (C): ");
  Serial.println((float)DHT11.temperature, 2);
  dht_temp=(float)DHT11.temperature;
  tx_esp32+="T:";
  tx_esp32+=String(dht_temp);
  tx_esp32+=",";
}
void getmq2()
{
  
  smoke_value=analogRead(mq2pin);
  tx_esp32+="G:";
  tx_esp32+=String(smoke_value);
  tx_esp32+=",";
  Serial.print("the smoke value is  ");
  Serial.println(smoke_value);
}

void kitchen_process()
{
  if(dht_temp>40 || smoke_value>80/*check the smoke sensor value*/)
  {
    Serial.println("turning on buzzer and fan");
//    fan on
digitalWrite(fan_kitchen,HIGH);
tx_esp32+="F_S:";
  tx_esp32+=String(1);
  tx_esp32+=",";
tone(SPEAKER_kitchen, freq);

    delay(3000);
 noTone(SPEAKER_kitchen);
//buzzer on
//delay
//buzzer off
  }
  else
  {
//    fan off
//digitalWrite(fan_kitchen,LOW);
tx_esp32+="F_S:";
  tx_esp32+=String(0);
  tx_esp32+=",";
  }
}


//smoke sensor when keeping dhoop stick near to the gas sensor then value will increase to 300+ otherwise
//if no smoke then it will remain <300 
//voltage for smoke sensor is 5v
