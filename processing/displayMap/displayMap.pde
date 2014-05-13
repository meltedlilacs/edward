int mapWidth = 5;
int mapHeight = 5;
int scale = 100;

// 0 = open, 1 = wall, 2 = dead end, 3 = gone through
color colors[] = {color(255, 255, 255, 0), color(0, 0, 0), color(211, 61, 61), color(83, 209, 69)};

// Maze[x][y][side]
byte Maze[][][] = new byte[mapWidth][mapHeight][4];

void setup() {
  size(mapWidth * scale, mapHeight * scale);
  smooth();
  strokeWeight(5);
  strokeCap(SQUARE);
  background(255);
  for(int w = 0; w < mapWidth; w++) {
    for(int h = 0; h < mapHeight; h++) {
      for(int i = 0; i < 4; i++) {
        Maze[w][h][i] = 0;
        }
      }
    }
  Maze[2][2][0] = 1;
  Maze[2][2][1] = 2;
  Maze[2][2][2] = 2;
  Maze[2][2][3] = 3;
  }

void draw() {
  for(int w = 0; w < mapWidth; w++) {
    for(int h = 0; h < mapHeight; h++) {
      stroke(colors[Maze[w][h][0]]);
      line(w * scale, h * scale, (w + 1) * scale, h * scale);
      
      stroke(colors[Maze[w][h][1]]);
      line((w + 1) * scale, h * scale, (w + 1) * scale, (h + 1) * scale);
      
      stroke(colors[Maze[w][h][2]]);
      line(w * scale, (h + 1) * scale, (w + 1) * scale, (h + 1) * scale);
      
      stroke(colors[Maze[w][h][3]]);
      line(w * scale, h * scale, w * scale, (h + 1) * scale);
      }
    }
  }
