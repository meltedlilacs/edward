#ifndef whichWays.h
#define whichWays.h

#include <Arduino.h>
#include "robot.h"
#include "map.h"

/******************************
 returns most efficient path
******************************/

compassDir whichWay(Robot& aRobot);

#endif
