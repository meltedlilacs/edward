#ifndef map_h
#define map_h

#include "squares.h"

class Map {
  public:
    Map();
    
    // get a square
    const Square& getSquare(byte x, byte y);
    
    // is a wall
    void setWall(Square& square, byte side);
    
    // is a dead end
    void setDeadEnd(Square& square, byte side);
    
    // is mapped
    void setSideMapped(Square& square, byte side);
    
    // square has been mapped
    void setMapped(Square& square);
    
    // has been gone through
    void setGoneThrough(Square& square, byte side);
    
  private:
    Square Array[5][5]; // map
    byte width, height;
  };

#endif
