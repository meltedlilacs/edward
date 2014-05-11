#include "enums.h"
#include <Arduino.h>

// important: do not use for conversion between enums! instead use functions in class Robot

byte enumToInt(compassDir dir) {
	switch(dir) {
		case NORTH:
			return 0;
			break;
		case EAST:
			return 1;
			break;
		case SOUTH:
			return 2;
			break;
		case WEST:
			return 3;
			break;
		}
	}
byte enumToInt(relativeDir dir) {
	switch(dir) {
		case FRONT:
			return 0;
			break;
		case RIGHT:
			return 1;
			break;
		case BACK:
			return 2;
			break;
		case LEFT:
			return 3;
			break;
		}
	}

compassDir intToCompass(byte dir) {
	switch(dir) {
		case 0:
			return NORTH;
			break;
		case 1:
			return EAST;
			break;
		case 2:
			return SOUTH;
			break;
		case 3:
			return WEST;
			break;
		}
	}
relativeDir intToRelative(byte dir) {
	switch(dir) {
		case 0:
			return FRONT;
			break;
		case 1:
			return RIGHT;
			break;
		case 2:
			return BACK;
			break;
		case 3:
			return LEFT;
			break;
		}
	}

String toString(compassDir dir) {
	switch(dir) {
		case NORTH:
			return "NORTH";
			break;
		case EAST:
			return "EAST";
			break;
		case SOUTH:
			return "SOUTH";
			break;
		case WEST:
			return "WEST";
			break;
		}
	}
String toString(relativeDir dir) {
	switch(dir) {
		case FRONT:
			return "FRONT";
			break;
		case RIGHT:
			return "RIGHT";
			break;
		case BACK:
			return "BACK";
			break;
		case LEFT:
			return "LEFT";
			break;
		}
	}