#include "squares.h"

/*****************************
 class containing info
 about one square of the map
*****************************/

// constructor just defaults everything
Square::Square()  {
  mapped = false;
  numSides = 4;
  for(byte i = 0; i < 4; i++)  {
    wall[i] = false;
    deadEnd[i] = false;
    }
  }
  
// is a wall
void Square::setWall(byte side)  {
  if(wall[side] != true && side > -1 && side < 4)  {
    wall[side] = true;
    numSides--;
    }
  }

// is a wall?
boolean Square::getWall(byte side) const  {
  if(side > -1 && side < 4)  {
    return wall[side];
    }
  }

// is a dead end
void Square::setDeadEnd(byte side)  {
  if(deadEnd[side] != true && side > -1 && side < 4)  {
    deadEnd[side] = true;
    numSides--;
    }
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
  
// has been gone through
void Square::setGoneThrough(byte side)  {
  if(goneThrough[side] != true && side > -1 && side < 4)  {
    goneThrough[side] = true;
    numSides--;
    }
  }

// has been gone through?
boolean Square::getGoneThrough(byte side) const  {
  if(side > -1 && side < 4)  {
    return goneThrough[side];
    }
  }