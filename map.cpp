#include "map.h"

Map::Map() {
  width = 5;
  height = 5;
  }

// get a square
const Square& Map::getSquare(byte x, byte y) {
  return Array[x][y]; // dangourous but what else are you going to do???
  }

// is a wall
void Map::setWall(Square& square, byte side) {
  }

// is a dead end
void Map::setDeadEnd(Square& square, byte side) {
  
  }

// is mapped
void Map::setSideMapped(Square& square, byte side) {
  
  }

// square has been mapped
void Map::setMapped(Square& square) {
  
  }

// has been gone through
void Map::setGoneThrough(Square& square, byte side) {
  
  }
