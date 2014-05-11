#ifndef enums.h
#define enums.h

#include <Arduino.h>

enum compassDir {NORTH, EAST, SOUTH, WEST};
enum relativeDir {FRONT, RIGHT, BACK, LEFT};

byte enumToInt(compassDir dir);
byte enumToInt(relativeDir dir);

compassDir intToCompass(byte dir);
relativeDir intToRelative(byte dir);

String toString(compassDir dir);
String toString(relativeDir dir);

#endif