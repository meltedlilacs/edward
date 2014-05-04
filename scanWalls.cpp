#include "squares.h"
#include "scanWalls.h"
#include "ave.h"
#include <Arduino.h>

/****************************************
 reads all walls that need to be read,
 and stores them in robot's memory
****************************************/

void scanWalls(Robot& aRobot)  {
  const unsigned int head_turn_delay = 300;
  const byte maxDist = 12; // the range between which a wall is adjacent to the robot
  const byte minDist = 3; // (in inches)
  Square* position = aRobot.location(); // convience variable
  
  // reset head
  aRobot.Neck.write(90);
  delay(100);
  
  // if left of robot has not been scanned, scan it
  if(position->sidesMapped[aRobot.leftOf()] != true)  {
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
      position->setWall(aRobot.leftOf());
      position->sidesMapped[aRobot.leftOf()] = true;
      switch(aRobot.frontOf())  {
        case 0:
          aRobot.Array[aRobot.x() - 1][aRobot.y()].setWall(1);
          aRobot.Array[aRobot.x() - 1][aRobot.y()].sidesMapped[1] = true;
          break;
        case 1:
          aRobot.Array[aRobot.x()][aRobot.y() + 1].setWall(2);
          aRobot.Array[aRobot.x()][aRobot.y() + 1].sidesMapped[2] = true;
          break;
        case 2:
          aRobot.Array[aRobot.x() + 1][aRobot.y()].setWall(3);
          aRobot.Array[aRobot.x() + 1][aRobot.y()].sidesMapped[3] = true;
          break;
        case 3:
          aRobot.Array[aRobot.x()][aRobot.y() - 1].setWall(0);
          aRobot.Array[aRobot.x()][aRobot.y() - 1].sidesMapped[0] = true;
          break;
        }
      }
    }
  
  // if right of robot has not been scanned, scan it  
  if(position->sidesMapped[aRobot.rightOf()] != true)  {
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
      position->setWall(aRobot.rightOf());
      position->sidesMapped[aRobot.rightOf()] = true;
      switch(aRobot.frontOf())  {
        case 0:
          aRobot.Array[aRobot.x() + 1][aRobot.y()].setWall(3);
          aRobot.Array[aRobot.x() + 1][aRobot.y()].sidesMapped[3] = true;
          break;
        case 1:
          aRobot.Array[aRobot.x()][aRobot.y() - 1].setWall(0);
          aRobot.Array[aRobot.x() + 1][aRobot.y()].sidesMapped[0] = true;
          break;
        case 2:
          aRobot.Array[aRobot.x() - 1][aRobot.y()].setWall(1);
          aRobot.Array[aRobot.x() + 1][aRobot.y()].sidesMapped[1] = true;
          break;
        case 3:
          aRobot.Array[aRobot.x()][aRobot.y() + 1].setWall(2);
          aRobot.Array[aRobot.x() + 1][aRobot.y()].sidesMapped[2] = true;
          break;
        }
      }
    }
  
  // if front of robot has not been scanned, scan it  
  if(position->sidesMapped[aRobot.frontOf()] != true)  {
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
      position->setWall(aRobot.frontOf());
      position->sidesMapped[aRobot.frontOf()] = true;
      switch(aRobot.frontOf())  {
        case 0:
          aRobot.Array[aRobot.x()][aRobot.y() + 1].setWall(2);
          aRobot.Array[aRobot.x() + 1][aRobot.y()].sidesMapped[2] = true;
          break;
        case 1:
          aRobot.Array[aRobot.x() + 1][aRobot.y()].setWall(3);
          aRobot.Array[aRobot.x() + 1][aRobot.y()].sidesMapped[3] = true;
          break;
        case 2:
          aRobot.Array[aRobot.x()][aRobot.y() - 1].setWall(0);
          aRobot.Array[aRobot.x() + 1][aRobot.y()].sidesMapped[0] = true;
          break;
        case 3:
          aRobot.Array[aRobot.x() - 1][aRobot.y()].setWall(1);
          aRobot.Array[aRobot.x() + 1][aRobot.y()].sidesMapped[1] = true;
          break;
        }
      }
    }
  
  // reset head
  delay(head_turn_delay);
  aRobot.Neck.write(90);
  delay(100);
    
  // this square has been scanned
  position->mapped = true; // this square has now been scanned
  }
