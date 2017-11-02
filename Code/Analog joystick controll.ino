#include <Servo.h>

const int servoBas = 11;       
const int servoLeft = 10;       
const int servoRight = 9;
const int servoClaw = 6;

const int joyH = 5;        
const int joyV = 4;        
const int joyH1 = 3;
const int joyV1 = 2;

int servoVal1;           
int servoVal2;
int servoVal3;
int servoVal4;

Servo myservoBas;  
Servo myservoLeft; 
Servo myservoRight;
Servo myservoClaw;


String Hanna = " Hanna = BAJSKORV"; //create object to control shitflow

void setup() {

  // Servo  
  myservoBas.attach(servoBas);  
  myservoLeft.attach(servoLeft);  
  myservoRight.attach(servoRight);
  myservoClaw.attach(servoClaw);

  // Inizialize Serial
  Serial.begin(9600);

  pinMode(0, OUTPUT);
}


void loop(){

    // Display Joystick values using the serial monitor
    outputJoystick();
    blinkLed();

    // Read the horizontal joystick value  (value between 0 and 1023)
    servoVal1 = analogRead(joyH);          
    servoVal1 = map(servoVal1, 0, 1023, 0, 180);     // scale it to use it with the servo (result  between 0 and 180)
    

    myservoLeft.write(servoVal1);                         // sets the servo position according to the scaled value    

    // Read the horizontal joystick value  (value between 0 and 1023)
    servoVal2 = analogRead(joyV);           
    servoVal2 = map(servoVal2, 0, 1023, 70, 180);     // scale it to use it with the servo (result between 70 and 180)

    myservoBas.write(servoVal2);        


    servoVal3 = analogRead(joyV1);           
    servoVal3 = map(servoVal3, 0, 1023, 70, 180);     

    myservoBas.write(servoVal3);  

    servoVal4 = analogRead(joyH1);           
    servoVal4 = map(servoVal4, 0, 1023, 70, 180);   

    delay(15);                                       // waits for the servo to get there

}

void blinkLed(){
  digitalWrite(0, HIGH);  
  delay(1000);                      
  digitalWrite(0, LOW);
  delay(1000); 
  
}


/**
* Display joystick values
*/
void outputJoystick(){
    Serial.print(Hanna);
    Serial.print(analogRead(joyH));
    Serial.println ("---"); 
    Serial.print(analogRead(joyV));
    Serial.println ("----------------");
    Serial.print(analogRead(joyH1));
    Serial.println ("---"); 
    Serial.print(analogRead(joyV1));
    Serial.println ("----------------");
}
