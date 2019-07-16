#include "RoboClaw.h"

RoboClaw roboclaw = RoboClaw(&Serial1, 10000);
int encoder_count = 0;

void setup() {
  roboclaw.begin(38400);
  Serial.begin(9600);
}

void loop() {

  Serial.println("Resetting both encoder counts");
  roboclaw.ResetEncoders(0x80);
  delay(50);
  encoder_count = roboclaw.ReadEncM1(0x80);
  Serial.println("Encoder 1 count after reset:");
  Serial.println(encoder_count);
  
  
  roboclaw.ForwardM1(0x80, 64);
  delay(1000);
  encoder_count = roboclaw.ReadEncM1(0x80);
  Serial.println("Encoder count after moving forward:");
  Serial.println(encoder_count);
  delay(2000);

  roboclaw.ForwardM1(0x80,0);
  delay(1000);
  encoder_count = roboclaw.ReadEncM1(0x80);
  Serial.println("Encoder count after stopping:");
  Serial.println(encoder_count);
  delay(2000);

  roboclaw.BackwardM1(0x80, 64);
  delay(1000);
  encoder_count = roboclaw.ReadEncM1(0x80);
  Serial.println("Encoder count after moving backwards:");
  Serial.println(encoder_count);
  delay(2000);
  
  roboclaw.BackwardM1(0x80,0);
  delay(1000);
  encoder_count = roboclaw.ReadEncM1(0x80);
  Serial.println("Encoder count after stopping:");
  Serial.println(encoder_count);
  delay(2000);

  Serial.println("Setting encoder 1 to 100000");
  roboclaw.SetEncM1(0x80, 100000);
  delay(50);
  encoder_count = roboclaw.ReadEncM1(0x80);
  Serial.println("Encoder count after setting value:");
  Serial.println(encoder_count);
  delay(2000);
  
  
}
