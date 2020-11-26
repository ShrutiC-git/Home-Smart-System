//void restroom()
//{
//  if (digitalRead(subscribe_pin) == HIGH)
//  {
//    Serial.println("esp digital pin is high");
//    if (rest_room_flag == false)
//    {
//      for (pos = 0; pos <= 90; pos += 1) { // sweep from 0 degrees to 180 degrees
//        // in steps of 1 degree
//        myservo2.write(pos);
//        delay(1);             // waits 20ms for the servo to reach the position
//      }
//      rest_room_flag = true;
//      rest_room_flag1 = false;
//      
//    }
//    tx_esp32 += "W_S:";
//      tx_esp32 += "1";
//  }
//
//  else
//  {
//    Serial.println("esp digital pin is low");
//    if ( rest_room_flag1 == false)
//    {
//      
////      for (pos = 180; pos >= 0; pos -= 1) { // sweep from 180 degrees to 0 degrees
////        myservo2.write(pos);
////        delay(1);
////      }
//      rest_room_flag = false;
//      rest_room_flag1 = true;
//      
//    }
//    tx_esp32 += "W_S:";
//      tx_esp32 += "0";
//  }
//}
////for the rest room
