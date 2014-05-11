#include "ave.h"

/*******************************
 throws away highest and lowest
 number and returns the average
 of the remaining three numbers
*******************************/

byte average(byte array[5])  {
  byte result = 0;
  byte entries = 0;
  for(byte i = 0; i < 5; i++)  {
    if(!(((array[i] > array[0]) && (array[i] > array[1]) && (array[i] > array[2]) && (array[i] > array[3]) && (array[i] > array[4])) || ((array[i] < array[0]) && (array[i] < array[1]) && (array[i] < array[2]) && (array[i] < array[3]) && (array[i] < array[4]))))  {
      result += array[i];
      entries++;
      }
    }
  return result / entries;
  }