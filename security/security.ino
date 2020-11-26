void motion_sensor()
{
  pir_value=analogRead(pir_pin);
  Serial.print("the value of pir_pin is ");
  Serial.println(pir_value);
  //used 3.3v only arduino
////  if motion then buzzer
//if(pir_value<250)
//if(pir_value<50)
if(pir_value<300)
{
  tone(SPEAKER_security, freq);

    delay(3000);
 noTone(SPEAKER_security);
 tx_esp32+="M_S:";
  tx_esp32+=String(1);
  tx_esp32+=",";
}
else
{
   tx_esp32+="M_S:";
  tx_esp32+=String(0);
  tx_esp32+=",";
}

}
