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
    void setWall(byte side);
    
    // is a wall?
    boolean getWall(byte side) const;
    
    // is a dead end
    void setDeadEnd(byte side);
    
    // is a bad side?
    boolean getDeadEnd(byte side) const;
    
    // number of exitable sides
    byte getNumSides() const;
    
    // has been gone through
    void setGoneThrough(byte side);
    
    // has been gone through?
    boolean getGoneThrough(byte side) const;
    
    boolean mapped; // has this square been scanned
    boolean goneThrough[4]; // sides that have been gone through
  private:
    boolean wall[4]; // where walls are
    boolean deadEnd[4]; // where deadends are
    byte numSides; // number of viable sides
  };
  
#endif
