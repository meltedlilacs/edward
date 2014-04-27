#include "squares.h"
#include "scanWalls.h"
#include "ave.h"
#include <Arduino.h>

/****************************************
 reads all walls that need to be read,
 and stores them in robot's memory
****************************************/

void scanWalls(Robot& aRobot)  {
  const byte maxDist = 12; // the range between which a wall is adjacent to the robot
  const byte minDist = 0; // (in inches)
  Square* position = aRobot.location(); // conveince variable
  
  // reset head
  aRobot.Neck.write(90);
  delay(100);
  
  // if left of robot has not been scanned, scan it
  if(position->getDeadEnd(aRobot.leftOf()) != true && position->getWall(aRobot.leftOf()) != true)  {
    // average three values for ping sensor
    byte dist[5] = {0, 0, 0, 0, 0};
    aRobot.Neck.write(4);
    delay(100);
    for(byte i = 0; i < 5; i++)  {
      dist[i] = aRobot.Sensor.distance();
      delay(50);
      }
    byte ave = average(dist);
    if(ave > minDist && ave < maxDist)  {
      position->setWall(aRobot.leftOf());
      switch(aRobot.frontOf())  {
        case 0:
          aRobot.Array[aRobot.x() - 1][aRobot.y()].setWall(1);
          break;
        case 1:
          aRobot.Array[aRobot.x()][aRobot.y() + 1].setWall(2);
          break;
        case 2:
          aRobot.Array[aRobot.x() + 1][aRobot.y()].setWall(3);
          break;
        case 3:
          aRobot.Array[aRobot.x()][aRobot.y() - 1].setWall(0);
          break;
        }
      }
    }
  
  // if right of robot has not been scanned, scan it  
  if(position->getDeadEnd(aRobot.rightOf()) != true && position->getWall(aRobot.rightOf()) != true)  {
    // average three values for ping sensor
    byte dist[5] = {0, 0, 0, 0, 0};
    aRobot.Neck.write(176);
    delay(100);
    for(byte i = 0; i < 5; i++)  {
      dist[i] = aRobot.Sensor.distance();
      delay(50);
      }
    byte ave = average(dist);
    if(ave > minDist && ave < maxDist)  {
      position->setWall(aRobot.rightOf());
      switch(aRobot.frontOf())  {
        case 0:
          aRobot.Array[aRobot.x() + 1][aRobot.y()].setWall(3);
          break;
        case 1:
          aRobot.Array[aRobot.x()][aRobot.y() - 1].setWall(0);
          break;
        case 2:
          aRobot.Array[aRobot.x() - 1][aRobot.y()].setWall(1);
          break;
        case 3:
          aRobot.Array[aRobot.x()][aRobot.y() + 1].setWall(2);
          break;
        }
      }
    }
  
  // if front of robot has not been scanned, scan it  
  if(position->getDeadEnd(aRobot.frontOf()) != true && position->getWall(aRobot.frontOf()) != true)  {
    // average three values for ping sensor
    byte dist[5] = {0, 0, 0, 0, 0};
    aRobot.Neck.write(90);
    delay(100);
    for(byte i = 0; i < 5; i++)  {
      dist[i] = aRobot.Sensor.distance();
      delay(50);
      }
    byte ave = average(dist);
    if(ave > minDist && ave < maxDist)  {
      position->setWall(aRobot.frontOf());
      switch(aRobot.frontOf())  {
        case 0:
          aRobot.Array[aRobot.x()][aRobot.y() + 1].setWall(2);
          break;
        case 1:
          aRobot.Array[aRobot.x() + 1][aRobot.y()].setWall(3);
          break;
        case 2:
          aRobot.Array[aRobot.x()][aRobot.y() - 1].setWall(0);
          break;
        case 3:
          aRobot.Array[aRobot.x() - 1][aRobot.y()].setWall(1);
          break;
        }
      }
    }
  
  // reset head
  delay(100);
  aRobot.Neck.write(90);
  delay(100);
    
  // this square has been scanned
  position->mapped = true; // this square has now been scanned
  }
