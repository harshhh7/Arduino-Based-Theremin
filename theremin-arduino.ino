#include "Volume3.h"

#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247


int melody[] = {
  NOTE_C1, NOTE_CS1 ,NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1, NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2, NOTE_B2, NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3
};


//frequency
const int echoPin = 2; // Echo Pin of Ultrasonic Sensor
const int pingPin = 3; // Trigger Pin of Ultrasonic Sensor

//volume
const int echoPinV =4;
const int pingPinV =5;

int volume;
void setup() 
{
  Serial.begin(9600); // Starting Serial Communication
  pinMode(pingPin, OUTPUT); // initialising pin 3 as output
  pinMode(echoPin, INPUT); // initialising pin 2 as input
  pinMode(pingPinV, OUTPUT);
  pinMode(echoPinV, INPUT);
}

void loop()
{
  long duration1,duration2;
  int cmF,cmV;
  
  //digitalWrite(pingPin, LOW);
  //delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(100);
  
  digitalWrite(pingPin, LOW);
  
  duration1 = pulseIn(echoPin, HIGH);
  cmF = microsecondsToCentimeters(duration1); // calling method

  //digitalWrite(pingPinV, LOW);
  //delayMicroseconds(2);
  
  digitalWrite(pingPinV, HIGH);
  delayMicroseconds(100);
  
  digitalWrite(pingPinV, LOW);
  
  duration2 = pulseIn(echoPinV, HIGH);
  cmV = microsecondsToCentimeters(duration2); // calling method
  
  Serial.print(cmF);
  Serial.print("cm,");
  Serial.print(cmV);
  Serial.print("cm");
  Serial.println();
  
  SoundSet(cmF,cmV);
  
  delay(250);
}
void SoundSet(int CMF,int CMV)
{
  if(CMF>=35)
    {
      CMF=35;
    }
  else if(CMF<=0)
    {
      CMF =0;
    }
    if(CMV>=35)
    {
      CMV=35;
    }
  else if(CMV<=0)
    {
      CMV =0;
    }
  CMF=35-CMF;
  CMV=35-CMV;
  volume=CMV*29;
  //vol.tone(9,melody[CMF],volume);
  vol.tone(9,melody[CMF]*10,volume);
   //tone(8, melody[centiMeter], noteDuration);
}
long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
{
   return microseconds / 58;
}
