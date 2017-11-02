//#define BLYNK_PRINT Serial

#include <SPI.h>
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "AuthToken"; //Auth token
char ssid[] = "SSID"; // SSID
char pass[] = "Paswd"; // Password -WIFI

Servo servoClaw;
Servo servoLeft;
Servo servoRight;
Servo servoBase;

BLYNK_WRITE(V1)
{
  servoClaw.write(param.asInt());  
}

BLYNK_WRITE(V2){
  servoLeft.write(param.asInt());
}

BLYNK_WRITE(V3){
  servoRight.write(param.asInt());
}

BLYNK_WRITE(V4){
  servoBase.write(param.asInt());
}

void setup()
{
  
  //Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  servoClaw.attach(D1);
  servoLeft.attach(D2);
  servoRight.attach(D3);
  servoBase.attach(D4);
  
}

void loop()
{
  Blynk.run();
}

