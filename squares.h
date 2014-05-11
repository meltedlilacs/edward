#ifndef squares.h
#define squares.h

#include <Arduino.h>
#include "enums.h"

/*****************************
 class containing info
 about one square of the map
*****************************/

class Square  {
  public:
    // constructor just defaults everything
    Square();
    
    // is a wall
    boolean setWall(compassDir side);
    
    // is a wall?
    boolean getWall(compassDir side) const;
    
    // is a dead end
    boolean setDeadEnd(compassDir side);
    
    // is a dead end?
    boolean getDeadEnd(compassDir side) const;
    
    // number of exitable sides
    byte getNumSides() const;
    
    // is mapped
    boolean setSideMapped(compassDir side);
    
    // is mapped?
    boolean getSideMapped(compassDir side) const;
    
    // square has been mapped
    boolean setMapped();
    
    // square has been mapped?
    boolean getMapped() const;
    
    // has been gone through
    boolean setGoneThrough(compassDir side);
    
    // has been gone through?
    boolean getGoneThrough(compassDir side) const;
    
  private:
    boolean wall[4]; // where walls are
    boolean deadEnd[4]; // where deadends are
    byte numSides; // number of viable sides
    boolean sideMapped[4]; // sides that have been mapped
    boolean mapped; // has this square been scanned
    byte numMapped;
    boolean goneThrough[4]; // sides that have been gone through
  };
  
#endif
