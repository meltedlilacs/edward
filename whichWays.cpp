#include "whichWays.h"

/******************************
 returns most efficient path
******************************/

// currentRoute[i][0] = x pos
// currentRoute[i][1] = y pos
// currentRoute[i][2] = next move

byte whichWay(Robot& aRobot)  {
  // byte bestCost = abs(aRobot.x() - aRobot.endX()) + abs(aRobot.y() - aRobot.endY());
  byte bestCost = 26;
  byte bestFirstMove = 4;
  byte currentFirstMove = 4;
  byte currentRoute[25][3];
  byte currentCost = 0;
  byte currentNode = 0;
  int finishedNode = -1;
  for(byte i = 0; i < 25; i++)  {
    for(byte j = 0; j < 3; j++)  {
      currentRoute[i][j] = 6;
      }
    }
  
  currentRoute[currentNode][0] = aRobot.x();
  currentRoute[currentNode][1] = aRobot.y();
  while(finishedNode < 25)  { // while all posiblities on all nodes haven't been tried
    int tempCurrentMove = currentRoute[currentNode][2] == 6 ? -1 : currentRoute[currentNode][2];
    int tempLastMove = tempCurrentMove;
    for(; tempCurrentMove < 4; tempCurrentMove++)  {
      if((aRobot.Array[currentRoute[currentNode][0]][currentRoute[currentNode][1]].getWall(tempCurrentMove) == false) && (tempCurrentMove == (currentRoute[currentNode - 1][2] < 2 ? currentRoute[currentNode - 1][2] == 0 ? 0 : 1 : currentRoute[currentNode - 1][2] == 2 ? 2 : 3)))  {
        for(int tempTempCurrentMove; tempTempCurrentMove < 4; tempTempCurrentMove++)  {
          if((aRobot.Array[currentRoute[currentNode][0]][currentRoute[currentNode][1]].getWall(tempTempCurrentMove) == false) && (tempTempCurrentMove == (currentRoute[currentNode - 1][2] < 2 ? currentRoute[currentNode - 1][2] == 0 ? 0 : 1 : currentRoute[currentNode - 1][2] == 2 ? 2 : 3)))  {
            if(finishedNode == currentNode - 1)  {
              finishedNode++;
              }
            }
        currentRoute[currentNode][2] = tempCurrentMove;
        currentNode++;
        currentCost++;
        break;
        }
      }
      if(tempCurrentMove == tempLastMove || tempCurrentMove > 3)  {
        currentRoute[currentNode][2] = 6;
        currentNode--;
        currentCost--;
        }
      if(currentRoute[currentNode][0] == aRobot.endX() && currentRoute[currentNode][1] == aRobot.endY())  {
        if(currentCost < bestCost)  {
          bestCost = currentCost;
          bestFirstMove = currentRoute[0][2];
          }
        currentRoute[currentNode][2] = 6;
        currentNode--;
        currentCost--;
        }
      for(byte i = 0; i < 25; i++)  {
        if(currentRoute[i][0] == currentRoute[currentNode][0] && currentRoute[i][1] == currentRoute[currentNode][1])  {
          currentRoute[currentNode][2] = 6;
          currentNode--;
          currentCost--;
          }
        }
      }
    }
  return bestFirstMove;
  }
