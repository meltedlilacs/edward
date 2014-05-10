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
boolean Square::setWall(byte side)  {
  if(wall[side] != true && side > -1 && side < 4)  {
    wall[side] = true;
    numSides--;
    return true;
    }
  return false;
  }

// is a wall?
boolean Square::getWall(byte side) const  {
  if(side > -1 && side < 4)  {
    return wall[side];
    }
  }

// is a dead end
boolean Square::setDeadEnd(byte side)  {
  if(deadEnd[side] != true && side > -1 && side < 4)  {
    deadEnd[side] = true;
    numSides--;
    return true;
    }
  return false;
  }

// is a bad side?
boolean Square::getDeadEnd(byte side) const  {
  if(side > -1 && side < 4)  {
    return deadEnd[side];
    }
  }

// number of exitable sides
byte Square::getNumSides() const  {
  return numSides;
  }

// is mapped
boolean Square::setSideMapped(byte side) {
  if(sideMapped[side] != true && side > -1 && side < 4)  {
    sideMapped[side] = true;
    numMapped--;
    if(numMapped == 4) {
      mapped = true;
      }
    return true;
    }
  return false;
  }

// is mapped?
boolean Square::getSideMapped(byte side) const {
  if(side > -1 && side < 4)  {
    return sideMapped[side];
    }
  }

// square has been mapped
boolean Square::setMapped() {
  if(!mapped) {
    for(int i = 0; i < 4; i++) {
      setSideMapped(i);
      }
    return true;
    }
  return false;
  }

// square has been mapped?
boolean Square::getMapped() const {
  return mapped;
  }
  
// has been gone through
boolean Square::setGoneThrough(byte side)  {
  if(goneThrough[side] != true && side > -1 && side < 4)  {
    goneThrough[side] = true;
    numSides--;
    return true;
    }
  return false;
  }

// has been gone through?
boolean Square::getGoneThrough(byte side) const  {
  if(side > -1 && side < 4)  {
    return goneThrough[side];
    }
  }
