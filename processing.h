#include <Arduino.h>
#include "robot.h"

// for processing, of form x y sideone sidetwo sidethree sidefour facing backtracking (no spaces) with 0 = open, 1 = wall, 2 = dead end, 3 = gone through for the sides
void processing(Robot& aRobot);