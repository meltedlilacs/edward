#include "squares.h"

/*****************************
 class containing info
 about one square of the map
*****************************/

// constructor just defaults everything
Square::Square()  {
  mapped = false;
  numSides = 4;
  numMapped = 0;
  for(byte i = 0; i < 4; i++)  {
    wall[i] = false;
    deadEnd[i] = false;
    sideMapped[i] = false;
    }
  }
  
// is a wall
boolean Square::setWall(compassDir side)  {
  if(wall[enumToInt(side)] != true)  {
    wall[enumToInt(side)] = true;
    numSides--;
    return true;
    }
  return false;
  }

// is a wall?
boolean Square::getWall(compassDir side) const  {
  return wall[enumToInt(side)];
  }

// is a dead end
boolean Square::setDeadEnd(compassDir side)  {
  if(deadEnd[enumToInt(side)] != true)  {
    deadEnd[enumToInt(side)] = true;
    numSides--;
    return true;
    }
  return false;
  }

// is a bad side?
boolean Square::getDeadEnd(compassDir side) const  {
  return deadEnd[enumToInt(side)];
  }

// number of exitable sides
byte Square::getNumSides() const  {
  return numSides;
  }

// is mapped
boolean Square::setSideMapped(compassDir side) {
  if(sideMapped[enumToInt(side)] != true)  {
    sideMapped[enumToInt(side)] = true;
    numMapped--;
    if(numMapped == 4) {
      mapped = true;
      }
    return true;
    }
  return false;
  }

// is mapped?
boolean Square::getSideMapped(compassDir side) const {
  return sideMapped[enumToInt(side)];
  }

// square has been mapped
boolean Square::setMapped() {
  if(!mapped) {
    setSideMapped(NORTH);
    setSideMapped(EAST);
    setSideMapped(SOUTH);
    setSideMapped(WEST);
    return true;
    }
  return false;
  }

// square has been mapped?
boolean Square::getMapped() const {
  return mapped;
  }
  
// has been gone through
boolean Square::setGoneThrough(compassDir side)  {
  if(goneThrough[enumToInt(side)] != true)  {
    goneThrough[enumToInt(side)] = true;
    numSides--;
    return true;
    }
  return false;
  }

// has been gone through?
boolean Square::getGoneThrough(compassDir side) const  {
  return goneThrough[enumToInt(side)];
  }
