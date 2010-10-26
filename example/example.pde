#include <Streaming.h>
#include <SSC32.h>

int HOME0 = 1800;
int HOME1 = 1500;
int HOME2 = 1050; // 1000 for normal, 1050 for gyro
int HOME3 = 1300;
int HOME4 = 800;   // 1300 for hockey, 800 for normal
int HOME5 = 1600;
int HOME6 = 1900;
int HOME16 = 1550;
int HOME17 = 1250;
int HOME18 = 1000;
int HOME19 = 1600;
int HOME20 = 1600;
int HOME21 = 1500;
int HOME22 = 1250;
int HOME23 = 1000;
int HOME24 = 1580;
int HOME25 = 1600;

int homeFrame[17] = {
      HOME0,
      HOME1,
      HOME2,
      HOME3,
      HOME4,
      HOME5,
      HOME6,
      HOME16,
      HOME17,
      HOME18,
      HOME19,
      HOME20,
      HOME21,
      HOME22,
      HOME23,
      HOME24,
      HOME25
};

SSC32 ssc(true);

void setup() {
  
  Serial.begin(9600);
  Serial1.begin(9600);
  
  Serial.println("Setup");
  
  for(int i=0; i<7; i++) {
    ssc.servoMode(i, true);
  }
  
  for(int i=16; i<25; i++) {
    ssc.servoMode(i, true); 
  }
  
  ssc.servoMode(31, true);
  
}

void loop() {
  
  Serial.println("Loop");
  
  ssc.setFrame(homeFrame, 1000, 100);
  
}

