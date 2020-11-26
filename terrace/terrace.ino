void rain_servo_on()
{

  for (pos = 0; pos <= 90; pos += 1) { // sweep from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);
    delay(5);             // waits 20ms for the servo to reach the position
  }
}

void rain_servo_off()
{
  for (pos = 90; pos >= 0; pos -= 1) { // sweep from 180 degrees to 0 degrees
    myservo1.write(pos);
    delay(5);
  }
}

void rain_sensor()
{
//  Serial.print("the value of rain is ");
//  Serial.println(digitalRead(13));
//  Serial.print("the value of rain2 is ");
//  Serial.println(digitalRead(11));
  Serial.print("the value of rain is ");
  Serial.println(digitalRead(rain_pin));
  
  if (digitalRead(rain_pin) == 0)

  {
    //    if (rain_servo_flag == false)
    //    {
    Serial.println("rain is there turning servo motor");
    //      rain_servo_on();
    for (pos = 0; pos <= 90; pos += 1) { // sweep from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo1.write(pos);
      delay(1);             // waits 20ms for the servo to reach the position
    }
    rain_flag = true;
    rain_servo_flag = true;

    //    }
    tx_esp32 += "R_S:";
    tx_esp32 += String(1);
    tx_esp32 += ",";

  }
  else
  {
    //    if (rain_flag == true)
    //    {
    Serial.println("rain is not there turning off servo motor");
    //      rain_servo_off();
    //      rain_flag = false;
    //      rain_servo_flag = false;
    tx_esp32 += "R_S:";
    tx_esp32 += String(0);
    tx_esp32 += ",";
    //    }

  }
}
