#include"SevSeg.h"
SevSeg sevseg;

int Hour=0;
int Min=0;
void setup(){
  byte numDigits=4;
  byte digitPins[]={5,4,3,2};
  byte segmentPins[]={8,9,10,11,12,13,14,15};
  sevseg.begin(COMMON_CATHODE,numDigits,digitPins,segmentPins);
  sevseg.setBrightness(90);
}
void loop(){
static unsigned long timer = millis();
if(millis()>timer){
  timer+=300;
  
  Min = Min+1;
  if( Min == 60){
    Min = 0;
    if(Hour == 23)
          Hour=0;
    else
          Hour++;
  };
  sevseg.setNumber(Hour*100+Min,0);
}
  sevseg.refreshDisplay();                                                   
}
