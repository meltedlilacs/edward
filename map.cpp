#include "map.h"
#include "enums.h"

Map::Map() {
  width = 5;
  height = 5;
  }
    
// is a wall?
boolean Map::getWall(byte x, byte y, compassDir side) {
  if(x >= 0 && x < width && y >= 0 && y < height) {
    return Array[x][y].getWall(side);
    }
  else {
    // should throw an exception
    return true;
    }
  }

// is a dead end?
boolean Map::getDeadEnd(byte x, byte y, compassDir side) {
  if(x >= 0 && x < width && y >= 0 && y < height) {
    return Array[x][y].getDeadEnd(side);
    }
  else {
    // should throw an exception
    return true;
    }
  }

// is mapped?
boolean Map::getSideMapped(byte x, byte y, compassDir side) {
  if(x >= 0 && x < width && y >= 0 && y < height) {
    return Array[x][y].getSideMapped(side);
    }
  else {
    // should throw an exception
    return false;
    }
  }

// square has been mapped?
boolean Map::getMapped(byte x, byte y) {
  if(x >= 0 && x < width && y >= 0 && y < height) {
    return Array[x][y].getMapped();
    }
  else {
    // should throw an exception
    return false;
    }
  }

// has been gone through?
boolean Map::getGoneThrough(byte x, byte y, compassDir side) {
  if(x >= 0 && x < width && y >= 0 && y < height) {
    return Array[x][y].getGoneThrough(side);
    }
  else {
    // should throw an exception
    return false;
    }
  }

// number of exitable sides
byte Map::getNumSides(byte x, byte y) const {
  if(x >= 0 && x < width && y >= 0 && y < height) {
    return Array[x][y].getNumSides();
    }
  else {
    // should throw an exception
    return 0;
    }
  }

// is a wall
boolean Map::setWall(byte x, byte y, compassDir side) {
  if(x >= 0 && x < width && y >= 0 && y < height && getWall(x, y, side) != true) {
    switch(side) {
      case NORTH:
        Array[x][y + 1].setWall(SOUTH);
        break;
      case EAST:
        Array[x + 1][y].setWall(WEST);
        break;
      case SOUTH:
        Array[x][y - 1].setWall(NORTH);
        break;
      case WEST:
        Array[x - 1][y].setWall(EAST);
        break;
      }
    setSideMapped(x, y, side);
    return Array[x][y].setWall(side);
    }
  else {
    return false;
    }
  }

// is a dead end
boolean Map::setDeadEnd(byte x, byte y, compassDir side) {
  if(x >= 0 && x < width && y >= 0 && y < height && getWall(x, y, side) != true) {
    switch(side) {
      case NORTH:
        Array[x][y + 1].setDeadEnd(SOUTH);
        break;
      case EAST:
        Array[x + 1][y].setDeadEnd(WEST);
        break;
      case SOUTH:
        Array[x][y - 1].setDeadEnd(NORTH);
        break;
      case WEST:
        Array[x - 1][y].setDeadEnd(EAST);
        break;
      }
    setSideMapped(x, y, side);
    return Array[x][y].setDeadEnd(side);
    }
  else {
    return false;
    }
  }

// is mapped
boolean Map::setSideMapped(byte x, byte y, compassDir side) {
  if(x >= 0 && x < width && y >= 0 && y < height && getWall(x, y, side) != true) {
    switch(side) {
      case NORTH:
        Array[x][y + 1].setSideMapped(SOUTH);
        break;
      case EAST:
        Array[x + 1][y].setSideMapped(WEST);
        break;
      case SOUTH:
        Array[x][y - 1].setSideMapped(NORTH);
        break;
      case WEST:
        Array[x - 1][y].setSideMapped(EAST);
        break;
      }
    if(getSideMapped(x, y, NORTH) && getSideMapped(x, y, EAST) && getSideMapped(x, y, SOUTH) && getSideMapped(x, y, WEST)) {
      Array[x][y].setMapped();
      }
    return Array[x][y].setSideMapped(side);
    }
  else {
    return false;
    }
  }

// has been gone through
boolean Map::setGoneThrough(byte x, byte y, compassDir side) {
  if(x >= 0 && x < width && y >= 0 && y < height && getWall(x, y, side) != true) {
    switch(side) {
      case NORTH:
        Array[x][y + 1].setGoneThrough(SOUTH);
        break;
      case EAST:
        Array[x + 1][y].setGoneThrough(WEST);
        break;
      case SOUTH:
        Array[x][y - 1].setGoneThrough(NORTH);
        break;
      case WEST:
        Array[x - 1][y].setGoneThrough(EAST);
        break;
      }
    setSideMapped(x, y, side);
    return Array[x][y].setGoneThrough(side);
    }
  else {
    return false;
    }
  }

// are these real values?
boolean Map::squareExists(byte x, byte y) {
  return(x >= 0 && x < width && y >= 0 && y < height);
  }