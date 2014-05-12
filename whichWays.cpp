#include "whichWays.h"
#include "debug.h" // what could this be used for?
#include "enums.h"
#include "map.h"
#include <Arduino.h>

/******************************
 returns most efficient path
******************************/

compassDir whichWay(Robot& aRobot)  {
	compassDir nextSq;
	boolean notSet = true;
	
	// use the pythagorean theorem to calculate the distance between the goal and all four squares adjecent to the robot
	// then pick the one that shortens the distance to the goal the most that doesn't have a wall or doesn't lead to a dead end
	byte distance[4] = {0, 0, 0, 0}; // distance to goal from one square away in any direction       
	// the square of the difference in the y axis of the end point and one square above current position plus
	// the square of the difference in the x axis of the end point and one square above current position
	distance[0] = pow(abs(abs(aRobot.endY()) - (abs(aRobot.y()) + 1)), 2) + pow(abs(abs(aRobot.endX()) - abs(aRobot.x())), 2);
	// the square of the difference in the y axis of the end point and one square to the right current position plus
	// the square of the difference in the x axis of the end point and one square to the right current position
	distance[1] = pow(abs(abs(aRobot.endY()) - abs(aRobot.y())), 2) + pow(abs(abs(aRobot.endX()) - (abs(aRobot.x()) + 1)), 2);
	// the square of the difference in the y axis of the end point and one square below current position plus
	// the square of the difference in the x axis of the end point and one square below current position
	distance[2] = pow(abs(abs(aRobot.endY()) - (abs(aRobot.y()) - 1)), 2) + pow(abs(aRobot.endX()) - abs(aRobot.x()), 2);
	// the square of the difference in the y axis of the end point and one square to the left current position plus
	// the square of the difference in the x axis of the end point and one square to the left current position
	distance[3] = pow(abs(abs(aRobot.endY()) - abs(aRobot.y())), 2) + pow(abs(abs(aRobot.endX()) - (abs(aRobot.x() - 1))), 2);

	// if no way is viable or this is shorter than the previous shortest viable way and this way is viable, go this way
	if(aRobot.World.squareExists(aRobot.x(), aRobot.y() + 1) && (notSet || distance[0] < distance[enumToInt(nextSq)]) && (!aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), intToCompass(0))) && (!aRobot.World.getWall(aRobot.x(), aRobot.y(), intToCompass(0))))  {
		nextSq = intToCompass(0);
		notSet = false;
		}
	// if no way is viable or this is shorter than the previous shortest viable way and this way is viable, go this way
	if(aRobot.World.squareExists(aRobot.x() + 1, aRobot.y()) && (notSet || distance[1] < distance[enumToInt(nextSq)]) && (!aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), intToCompass(1))) && (!aRobot.World.getWall(aRobot.x(), aRobot.y(), intToCompass(1))))  {
		nextSq = intToCompass(1);
		notSet = false;
		}
	// if no way is viable or this is shorter than the previous shortest viable way and this way is viable, go this way
	if(aRobot.World.squareExists(aRobot.x(), aRobot.y() - 1) && (notSet || distance[2] < distance[enumToInt(nextSq)]) && (!aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), intToCompass(2))) && (!aRobot.World.getWall(aRobot.x(), aRobot.y(), intToCompass(2))))  {
		nextSq = intToCompass(2);
		notSet = false;
		}
	// if no way is viable or this is shorter than the previous shortest viable way and this way is viable, go this way
	if(aRobot.World.squareExists(aRobot.x() - 1, aRobot.y()) && (notSet || distance[3] < distance[enumToInt(nextSq)]) && (!aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), intToCompass(3))) && (!aRobot.World.getWall(aRobot.x(), aRobot.y(), intToCompass(3))))  {
		nextSq = intToCompass(3);
		notSet = false;
		}

	if(notSet) {
		debug("Trapped");
		while(true) {}
	}

	return nextSq; 
	}
