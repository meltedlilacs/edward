import processing.serial.*;

Serial port;
String input = "";

int mapWidth = 5;
int mapHeight = 5;
int scale = 150;

// 0 = open, 1 = wall, 2 = dead end, 3 = gone through
color colors[] = {color(255, 255, 255, 0), color(0, 0, 0), color(211, 61, 61), color(83, 209, 69)};

// Maze[x][y][side]
int Maze[][][] = new int[mapWidth][mapHeight][4];

void setup() {
  size(mapWidth * scale, mapHeight * scale);
  smooth();
  
  // println(Serial.list());
  String arduinoPort = Serial.list()[0];
  port = new Serial(this, arduinoPort, 9600);
  
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
  }

void draw() {
  if(port.available() > 0) {
    String temp = port.readString();
    for(int i = 0; i < temp.length(); i++) {
      int current = Character.getNumericValue(temp.charAt(i));
      if(current >= 0 && current < 4 && input.length() < 6) {
        input += current;
        }
      }
    if(input.length() == 6) {
      println(input);
      int x = Character.getNumericValue(input.charAt(0));
      int y = Character.getNumericValue(input.charAt(1));
      Maze[x][y][0] = Character.getNumericValue(input.charAt(2));
      Maze[x][y][1] = Character.getNumericValue(input.charAt(3));
      Maze[x][y][2] = Character.getNumericValue(input.charAt(4));
      Maze[x][y][3] = Character.getNumericValue(input.charAt(5));
      input = "";
      }
    }
  
  for(int w = 0; w < mapWidth; w++) {
    for(int h = 0; h < mapHeight; h++) {
      stroke(colors[Maze[w][h][0]]);
      line(w * scale, (mapHeight - 1 - h) * scale, (w + 1) * scale, (mapHeight - 1 - h) * scale);
      
      stroke(colors[Maze[w][h][1]]);
      line((w + 1) * scale, (mapHeight - 1 - h) * scale, (w + 1) * scale, ((mapHeight - 1 - h) + 1) * scale);
      
      stroke(colors[Maze[w][h][2]]);
      line(w * scale, ((mapHeight - 1 - h) + 1) * scale, (w + 1) * scale, ((mapHeight - 1 - h) + 1) * scale);
      
      stroke(colors[Maze[w][h][3]]);
      line(w * scale, (mapHeight - 1 - h) * scale, w * scale, ((mapHeight - 1 - h) + 1) * scale);
      }
    }
  }
