import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class displayMap extends PApplet {



PFont font;

Serial port;
String input = "";

int mapWidth = 5;
int mapHeight = 5;
int scale = 150;

int fadeInRate = 10;
int fadeOutRate = 5;

// rCoordinates[number][0] = x, rCoordinates[number][1] = y
int rCoordinates[][] = new int[fadeOutRate][2];
int robotColor = color(65, 144, 232);

int destinations[][] = {{0, 0}, {1, 4}};
int destColor = color(255, 253, 135);

boolean backtracking = false;

int facing = 0;

// 0 = open, 1 = wall, 2 = dead end, 3 = gone through
int colors[] = {color(255, 255, 255, 0), color(0, 0, 0, fadeInRate), color(232, 16, 29, fadeInRate), color(54, 255, 40, fadeInRate)};

int red = color(232, 16, 29);
int green = color(54, 255, 40);

// Maze[x][y][side]
int Maze[][][] = new int[mapWidth][mapHeight][4];

public void setup() {
  font = loadFont("DejaVuSans-48.vlw");
  textFont(font, 32);
  
  size(mapWidth * scale, mapHeight * scale + 100);
  smooth();
  
  //println(Serial.list()[32]);
  String arduinoPort = Serial.list()[32];
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
  
  rCoordinates[0][0] = 0;
  rCoordinates[0][1] = 0;
  for(int i = 1; i < fadeOutRate; i++) {
    rCoordinates[i][0] = -1;
    rCoordinates[i][1] = -1;
    }
  }

public void draw() {
  if(port.available() > 0) {
    String temp = port.readString();
    println(temp);
    for(int i = 0; i < temp.length(); i++) {
      int current = Character.getNumericValue(temp.charAt(i));
      if(current >= 0 && (current < 4 || (input.length() == 0 && current < mapWidth) || (input.length() == 1 && current < mapHeight)) && input.length() < 8) {
        input += current;
        }
      }
    if(input.length() == 8) {
      println(input);
      for(int i = fadeOutRate - 1; i > 0; i--) {
        rCoordinates[i][0] = rCoordinates[i - 1][0];
        rCoordinates[i][1] = rCoordinates[i - 1][1];
        }
      rCoordinates[0][0] = Character.getNumericValue(input.charAt(0));
      rCoordinates[0][1] = Character.getNumericValue(input.charAt(1));
      int x = rCoordinates[0][0];
      int y = rCoordinates[0][1];
      Maze[x][y][0] = Character.getNumericValue(input.charAt(2));
      Maze[x][y][1] = Character.getNumericValue(input.charAt(3));
      Maze[x][y][2] = Character.getNumericValue(input.charAt(4));
      Maze[x][y][3] = Character.getNumericValue(input.charAt(5));
      facing = Character.getNumericValue(input.charAt(6));
      backtracking = (Character.getNumericValue(input.charAt(7)) == 1);
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
  
  stroke(destColor);
  fill(255, 0);
  for(int i = 0; i < destinations.length; i++) {
    ellipse((destinations[i][0] * scale) + (scale / 2), ((mapHeight - 1 - destinations[i][1]) * scale) + (scale / 2), scale / 2, scale / 2);
    }

  stroke(robotColor);
  fill(robotColor);
  ellipse((rCoordinates[0][0] * scale) + (scale / 2), ((mapHeight - 1 - rCoordinates[0][1]) * scale) + (scale / 2), scale / 4, scale / 4);
  
  stroke(255, 225/(fadeOutRate - 1));
  fill(255, 225/(fadeOutRate - 1));
  for(int i = 1; i < fadeOutRate; i++) {
    ellipse((rCoordinates[i][0] * scale) + (scale / 2), ((mapHeight - 1 - rCoordinates[i][1]) * scale) + (scale / 2), scale / 4, scale / 4);
    }
  
  rect(0, mapHeight * scale, mapWidth * scale, 100);
  stroke(255);
  String dispText = "";
  if(backtracking) {
    fill(red);
    dispText += "is backtracking";
    }
  else {
    fill(green);
    dispText += "not backtracking";
    }
  textAlign(LEFT);
  text(dispText, 50, mapHeight * scale + 50, mapWidth * scale - 50, mapHeight * scale + 50);
  dispText = "facing ";
  switch (facing) {
    case 0:
      dispText += "north";
      break;
    case 1:
      dispText += "east";
      break;
    case 2:
      dispText += "south";
      break;
    case 3:
      dispText += "west";
      break;
    }
  fill(robotColor);
  textAlign(RIGHT);
  text(dispText, 50, mapHeight * scale + 50, mapWidth * scale - 100, mapHeight * scale + 50);
  }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "displayMap" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
