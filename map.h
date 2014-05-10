#ifndef map_h
#define map_h

#include "squares.h"

class Map {
  public:
    Map();
    
    // is a wall?
    boolean getWall(byte x, byte y, byte side);
    
    // is a dead end?
    boolean getDeadEnd(byte x, byte y, byte side);
    
    // is mapped?
    boolean getSideMapped(byte x, byte y, byte side);
    
    // square has been mapped?
    boolean getMapped(byte x, byte y);
    
    // has been gone through?
    boolean getGoneThrough(byte x, byte y, byte side);
    
    // number of exitable sides
    byte getNumSides(byte x, byte y) const;
    
    // is a wall
    boolean setWall(byte x, byte y, byte side);
    
    // is a dead end
    boolean setDeadEnd(byte x, byte y, byte side);
    
    // is mapped
    boolean setSideMapped(byte x, byte y, byte side);
    
    // square has been mapped
    boolean setMapped(byte x, byte y);
    
    // has been gone through
    boolean setGoneThrough(byte x, byte y, byte side);
    
  private:
    Square Array[5][5]; // map
    byte width, height;
  };

#endif
