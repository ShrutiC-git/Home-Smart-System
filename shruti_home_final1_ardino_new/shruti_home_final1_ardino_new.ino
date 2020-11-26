//sending string from uno to esp32 main serial working and publish the data to mqtt box worked.
//mqtt subscribe in esp32, make it like give the signal from esp32 to uno and check if it is high then make the servo on
//T:20.1,G:200,F_S:1,M_S:1,R_S:1,P_S:1,W_S:1
#include <Servo.h>
#include <dht11.h>
#include <SoftwareSerial.h>

SoftwareSerial sw(2, 3); // RX, TX
Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
dht11 DHT11;
bool getTemperature();
void triggerGetTemp();
void rain_senosr();
//for servo motor
int minUs = 1000;
int maxUs = 2000;


String tx_esp32="";
String subscribe_msg="";

//for buzzer

int channel = 0;
int channel1 = 1;
int resolution = 8;

int pos = 0;      // position in degrees


/** Pin number for DHT11 data pin */
// Recommended pins include 2,4,12-19,21-23,25-27,32-33 
//pins 12,13 completed
int DHT11PIN = 4;
int SPEAKER_security = 7;
int SPEAKER_kitchen = 8;    // The speaker is on pin 8
int servo1Pin = 9;
int servo2Pin = 10;
int pump_pin = 12;
int fan_kitchen=5;
//int subscribe_pin=11;
int mq2pin = A1;
int pir_pin = A0;
//int rain_pin=A2;
int rain_pin=13;
//int moisture_pin=A3;
int moisture_pin=11;


int freq = 8000;
int moisture_value=0;
int smoke_value=0;
float dht_temp=0.0;
int pir_value=0;
int rain_value=0;



bool rain_flag=false;
bool rain_servo_flag=false;
bool moisture_flag=false;
bool pump_flag=false;
bool rest_room_flag=false;
bool rest_room_flag1=false;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
sw.begin(9600);
  Serial.println();
  
 
  myservo1.attach(servo1Pin);  
  myservo2.attach(servo2Pin);  
  pinMode(SPEAKER_kitchen, OUTPUT);
  pinMode(SPEAKER_security, OUTPUT);
  pinMode(fan_kitchen,OUTPUT);
  pinMode(pump_pin,OUTPUT);
//  pinMode(subscribe_pin,INPUT);
  pinMode(rain_pin,INPUT);
  pinMode(moisture_pin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 
getTemperature();
getmq2();
kitchen_process();
motion_sensor();
rain_sensor();
moisture_sensor();
//restroom();
Serial.print("the final string is ");
Serial.println(tx_esp32);
sw.println(tx_esp32);
delay(4000);
if (sw.available()) {
    //    Serial.print(char(Serial2.read()));
    char bfr[501];
    memset(bfr, 0, 501);

    sw.readBytesUntil( '\n', bfr, 500);
    Serial.print("the received msg from esp is ");
    Serial.println(bfr);
    subscribe_msg=String(bfr);
    Serial.print("the string subscribe msg is ");
    Serial.println(subscribe_msg);
    if(subscribe_msg[0]=='0') //fan
    {
      Serial.println("given command from mqtt is fan low");
      digitalWrite(fan_kitchen,LOW);
    }
    if(subscribe_msg[2]=='0') //rain shade
    {
      Serial.println("given command from mqtt is rain servo off");
      rain_servo_off();
      rain_servo_flag = false;
    }
     if(subscribe_msg[4]=='0')  //restroom
    {
      Serial.println("given command from mqtt is restroom servo off");
//      rain_servo_off();
      for (pos = 90; pos >= 0; pos -= 1) { // sweep from 180 degrees to 0 degrees
        myservo2.write(pos);
        delay(5);
      }
    }
    else if(subscribe_msg[4]=='1')
    {
      for (pos = 0; pos <= 90; pos += 1) { // sweep from 180 degrees to 0 degrees
        myservo2.write(pos);
        delay(5);
      }
    }
  }
tx_esp32="";
}
