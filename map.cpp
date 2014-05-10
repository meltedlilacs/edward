#include "map.h"

Map::Map() {
  width = 5;
  height = 5;
  }
    
// is a wall?
boolean Map::getWall(byte x, byte y, byte side) {
  if(x >= 0 && x < width && y >= 0 && y < height && side >= 0 && side < 4) {
    return Array[x][y].getWall(side);
    }
  else {
    // should throw an exception
    return true;
    }
  }

// is a dead end?
boolean Map::getDeadEnd(byte x, byte y, byte side) {
  if(x >= 0 && x < width && y >= 0 && y < height && side >= 0 && side < 4) {
    return Array[x][y].getDeadEnd(side);
    }
  else {
    // should throw an exception
    return true;
    }
  }

// is mapped?
boolean Map::getSideMapped(byte x, byte y, byte side) {
  if(x >= 0 && x < width && y >= 0 && y < height && side >= 0 && side < 4) {
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
boolean Map::getGoneThrough(byte x, byte y, byte side) {
  if(x >= 0 && x < width && y >= 0 && y < height && side >= 0 && side < 4) {
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
boolean Map::setWall(byte x, byte y, byte side) {
  if(x >= 0 && x < width && y >= 0 && y < height && getWall(x, y, side) != true) {
    switch(side) {
      case 0:
        Array[x][y + 1].setWall(2);
        break;
      case 1:
        Array[x + 1][y].setWall(3);
        break;
      case 2:
        Array[x][y - 1].setWall(0);
        break;
      case 3:
        Array[x - 1][y].setWall(1);
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
boolean Map::setDeadEnd(byte x, byte y, byte side) {
  if(x >= 0 && x < width && y >= 0 && y < height && getWall(x, y, side) != true) {
    switch(side) {
      case 0:
        Array[x][y + 1].setDeadEnd(2);
        break;
      case 1:
        Array[x + 1][y].setDeadEnd(3);
        break;
      case 2:
        Array[x][y - 1].setDeadEnd(0);
        break;
      case 3:
        Array[x - 1][y].setDeadEnd(1);
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
boolean Map::setSideMapped(byte x, byte y, byte side) {
  if(x >= 0 && x < width && y >= 0 && y < height && getWall(x, y, side) != true) {
    switch(side) {
      case 0:
        Array[x][y + 1].setSideMapped(2);
        break;
      case 1:
        Array[x + 1][y].setSideMapped(3);
        break;
      case 2:
        Array[x][y - 1].setSideMapped(0);
        break;
      case 3:
        Array[x - 1][y].setSideMapped(1);
        break;
      }
    if(getSideMapped(x, y, 0) && getSideMapped(x, y, 1) && getSideMapped(x, y, 2) && getSideMapped(x, y, 3)) {
      Array[x][y].setMapped();
      }
    return Array[x][y].setSideMapped(side);
    }
  else {
    return false;
    }
  }

// has been gone through
boolean Map::setGoneThrough(byte x, byte y, byte side) {
  if(x >= 0 && x < width && y >= 0 && y < height && getWall(x, y, side) != true) {
    switch(side) {
      case 0:
        Array[x][y + 1].setGoneThrough(2);
        break;
      case 1:
        Array[x + 1][y].setGoneThrough(3);
        break;
      case 2:
        Array[x][y - 1].setGoneThrough(0);
        break;
      case 3:
        Array[x - 1][y].setGoneThrough(1);
        break;
      }
    setSideMapped(x, y, side);
    return Array[x][y].setGoneThrough(side);
    }
  else {
    return false;
    }
  }
