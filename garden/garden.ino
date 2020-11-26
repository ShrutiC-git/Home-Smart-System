void moisture_sensor()
{
   Serial.print("the value of moisture is ");
  Serial.println(digitalRead(moisture_pin));
  if (digitalRead(moisture_pin) == 1)
  {
    Serial.println("moisture is not there turning on pump motor");
    digitalWrite(pump_pin,HIGH);
    moisture_flag=true;
    pump_flag=true;
    tx_esp32+="P_S:";
  tx_esp32+=String(1);
//  tx_esp32+=",";
  }
  else
  {
//    if(pump_flag == true);
//    {
      Serial.println("moisture is  there turning off pump motor");
      digitalWrite(pump_pin,LOW);
      moisture_flag=false;
    pump_flag=false;
    tx_esp32+="P_S:";
  tx_esp32+=String(0);
//  tx_esp32+=",";
//    }
  }
}
