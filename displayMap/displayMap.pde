int mapWidth = 5;
int mapHeight = 5;
int scale = 200;

color wall = color(0, 0, 0);
color deadEnd = color(211, 61, 61);
color goneThrough = color(83, 209, 69);

class Square  {
    // constructor just defaults everything
    public Square() {
      for(int i = 0; i < 4; i++) {
        wall[i] = false;
        deadEnd[i] = false;
        goneThrough[i] = false;
        }
      }
    
    public boolean wall[] = new boolean[4]; // where walls are
    public boolean deadEnd[] = new boolean[4]; // where deadends are
    public boolean goneThrough[] = new boolean[4]; // sides that have been gone through
  };

Square Maze[][] = new Square[mapWidth][mapHeight];

void setup() {
  size(mapWidth * scale, mapHeight * scale);
  smooth();
  strokeWeight(5);
  strokeCap(SQUARE);
  background(255);
  for(int w = 0; w < mapWidth; w++) {
    for(int h = 0; h < mapHeight; h++) {
      Maze[w][h] = new Square();
      }
    }
  Square temp = Maze[2][2];
  temp.wall[0] = true;
  temp.deadEnd[1] = true;
  temp.goneThrough[2] = true;
  }

void draw() {
  for(int w = mapWidth - 1; w >= 0; w--) {
    for(int h = mapHeight - 1; h >= 0; h--) {
      Square Current = Maze[w][h];
      
      if(Current.wall[0] == true) {
        stroke(wall);
        }
      else if(Current.deadEnd[0] == true) {
        stroke(deadEnd);
        }
      else if(Current.goneThrough[0] == true) {
        stroke(goneThrough);
        }
      else {
        stroke(255);
        }
      line(w * scale, h * scale, (w + 1) * scale, h * scale);
      
      if(Current.wall[1] == true) {
        stroke(wall);
        }
      else if(Current.deadEnd[1] == true) {
        stroke(deadEnd);
        }
      else if(Current.goneThrough[1] == true) {
        stroke(goneThrough);
        }
      else {
        stroke(255);
        }
      line((w + 1) * scale, h * scale, (w + 1) * scale, (h + 1) * scale);
      
      if(Current.wall[2] == true) {
        stroke(wall);
        }
      else if(Current.deadEnd[2] == true) {
        stroke(deadEnd);
        }
      else if(Current.goneThrough[2] == true) {
        stroke(goneThrough);
        }
      else {
        stroke(255);
        }
      line(w * scale, (h + 1) * scale, w * scale, (h + 1) * scale);
      
      if(Current.wall[3] == true) {
        stroke(wall);
        }
      else if(Current.deadEnd[3] == true) {
        stroke(deadEnd);
        }
      else if(Current.goneThrough[3] == true) {
        stroke(goneThrough);
        }
      else {
        stroke(255);
        }
      line(w * scale, h * scale, w * scale, (h + 1) * scale);
      }
    }
  }
