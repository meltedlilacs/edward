import processing.serial.*;

Serial port;
String input = "";

int mapWidth = 5;
int mapHeight = 5;
int scale = 150;

int x = 0;
int y = 0;
int preX = -1;
int preY = -1;
color robotColor = color(65, 144, 232);

// 0 = open, 1 = wall, 2 = dead end, 3 = gone through
color colors[] = {color(255, 255, 255, 0), color(0, 0, 0), color(232, 16, 29), color(54, 255, 40)};

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
  fill(robotColor);
  
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
    println(temp);
    for(int i = 0; i < temp.length(); i++) {
      int current = Character.getNumericValue(temp.charAt(i));
      if(current >= 0 && current < 4 && input.length() < 6) {
        input += current;
        }
      }
    if(input.length() == 6) {
      println(input);
      x = Character.getNumericValue(input.charAt(0));
      y = Character.getNumericValue(input.charAt(1));
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

  stroke(255);
  fill(255);
  ellipse((preX * scale) + (scale / 2), ((mapHeight - 1 - preY) * scale) + (scale / 2), 25, 25);
  stroke(robotColor);
  fill(robotColor);
  ellipse((x * scale) + (scale / 2), ((mapHeight - 1 - y) * scale) + (scale / 2), 25, 25);
  preX = x;
  preY = y;
  }