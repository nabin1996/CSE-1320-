//Nabin Shrestha 1001746226
//here is the prototype of functions used in DrawTool.c
#ifndef _Draw_Tool

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxSize 20

void mapInitilization(char maxArray[][maxSize], int *Size);
void instructionPrint();
void mapPrint(char maxArray[][maxSize], int userSize);
void drawLine(char maxArray[][maxSize], int row, int col, char action, int numspot, char bg);

#endif
