#ifndef squares.h
#define squares.h

#include <Arduino.h>

/*****************************
 class containing info
 about one square of the map
*****************************/

class Square  {
  public:
    // constructor just defaults everything
    Square();
    
    // is a wall
    boolean setWall(byte side);
    
    // is a wall?
    boolean getWall(byte side) const;
    
    // is a dead end
    boolean setDeadEnd(byte side);
    
    // is a dead end?
    boolean getDeadEnd(byte side) const;
    
    // number of exitable sides
    byte getNumSides() const;
    
    // is mapped
    boolean setSideMapped(byte side);
    
    // is mapped?
    boolean getSideMapped(byte side) const;
    
    // square has been mapped
    boolean setMapped();
    
    // square has been mapped?
    boolean getMapped() const;
    
    // has been gone through
    boolean setGoneThrough(byte side);
    
    // has been gone through?
    boolean getGoneThrough(byte side) const;
    
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
