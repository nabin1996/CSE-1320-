// Nabin Shrestha 1001746226
#ifndef __FileLib__H
#define __FileLib__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameLib.h"

FILE *OpenFile(int argc, char *argv[], char *mode);
int ReadFileIntoArray(FILE *FILENAME, record recordlist[]);
void writeintofile(FILE *FILENAME, int index, record recordlist[]);

#endif
