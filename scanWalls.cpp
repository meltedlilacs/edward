#include "scanWalls.h"
#include "debug.h"

/****************************************
 reads all walls that need to be read,
 and stores them in robot's memory
****************************************/

void scanWalls(Robot& aRobot)  {
  const unsigned int head_turn_delay = 300;
  const byte maxDist = 12; // the range between which a wall is adjacent to the robot
  const byte minDist = 3; // (in inches)
  
  // reset head
  aRobot.Neck.write(90);
  delay(100);
  
  // if left of robot has not been scanned, scan it
  if(aRobot.World.getSideMapped(aRobot.x(), aRobot.y(), aRobot.leftOf()) != true)  {
    // average three values for ping sensor
    byte dist[5] = {0, 0, 0, 0, 0};
    aRobot.Neck.write(10);
    delay(head_turn_delay);
    for(byte i = 0; i < 5; i++)  {
      dist[i] = aRobot.Sensor.distance();
      delay(50);
      }
    byte ave = average(dist);
    if(ave > minDist && ave < maxDist)  {
      aRobot.World.setWall(aRobot.x(), aRobot.y(), aRobot.leftOf());
      }
    }
  
  // if right of robot has not been scanned, scan it  
  if(aRobot.World.getSideMapped(aRobot.x(), aRobot.y(), aRobot.rightOf()) != true)  {
    // average three values for ping sensor
    byte dist[5] = {0, 0, 0, 0, 0};
    aRobot.Neck.write(176);
    delay(head_turn_delay);
    for(byte i = 0; i < 5; i++)  {
      dist[i] = aRobot.Sensor.distance();
      delay(50);
      }
    byte ave = average(dist);
    if(ave > minDist && ave < maxDist)  {
      aRobot.World.setWall(aRobot.x(), aRobot.y(), aRobot.rightOf());
      }
    }
  
  // if front of robot has not been scanned, scan it  
  if(aRobot.World.getSideMapped(aRobot.x(), aRobot.y(), aRobot.frontOf()) != true)  {
    // average three values for ping sensor
    byte dist[5] = {0, 0, 0, 0, 0};
    aRobot.Neck.write(90);
    delay(head_turn_delay);
    for(byte i = 0; i < 5; i++)  {
      dist[i] = aRobot.Sensor.distance();
      delay(50);
      }
    byte ave = average(dist);
    if(ave > minDist && ave < maxDist)  {
      aRobot.World.setWall(aRobot.x(), aRobot.y(), aRobot.frontOf());
      }
    }
  
  // reset head
  delay(head_turn_delay);
  aRobot.Neck.write(90);
  delay(100);
  }
