#include <Streaming.h>

const int AIR_VAL = 500;
const int WATER_VAL = 250;
const int NUMBER_OF_POTS = 2;
String pot_ports[NUMBER_OF_POTS] = {"BASIL", "MINT"};

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
}
void loop() {
  for(int i = 0 ; i < NUMBER_OF_POTS; i = i + 1){
    readSoil(i);
  }
  Serial << endl;
  delay(2000);
}

void readSoil(int input){
  int val;
  val = analogRead(input); //connect sensor to Analog 0
  int calibratedVal = 100 - map(val, WATER_VAL, AIR_VAL, 0, 100); //map to moisture percentage

  Serial << pot_ports[input] << " / " << calibratedVal << " - " ;

  if(calibratedVal > 95){
    Serial << "In water, it's dead" << endl;
  }
  else if(calibratedVal > 66){
    Serial << "Kinda wet" << endl;
  }
  else if(calibratedVal > 33){
    Serial << "Medium" << endl;
  }
  else if (calibratedVal > 5){
    Serial << "Kinda dry, need water" << endl;
  }
  else{
    Serial << "In air, wtf" << endl;
  } 
  delay(500);
}
