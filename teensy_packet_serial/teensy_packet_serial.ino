#include "RoboClaw.h"

RoboClaw roboclaw = RoboClaw(&Serial1, 10000);
int encoder_count = 0;

void setup() {
  roboclaw.begin(38400);
  Serial.begin(9600);
}

void loop() {
  roboclaw.ForwardM1(0x80, 64);
  delay(1000);
  //encoder_count = roboclaw.ReadEncM1(0x80);
  Serial.println("Test");
  delay(2000);

  roboclaw.ForwardM1(0x80,0);
  //delay(1000);
  //encoder_count = roboclaw.ReadEncM1(0x80);
  //Serial.println(encoder_count);
  delay(2000);

  /*
  roboclaw.BackwardM1(0x80, 64);
  delay(1000);
  encoder_count = roboclaw.ReadEncM1(0x80);
  Serial.println(encoder_count);
  delay(2000);
  
  roboclaw.BackwardM1(0x80,0);
  delay(1000);
  encoder_count = roboclaw.ReadEncM1(0x80);
  Serial.println(encoder_count);
  delay(2000);
  */
  

}
