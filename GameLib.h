//Nabin Shrestha 1001746226
#ifndef GAMELIB
#define GAMELIB

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 81
#define STRIKES 3

void StartGame(char ChosenPhrase[MAX_INPUT]);
void CheckPhrase(char *Phrase);
int GuessALetter(char Phrase[MAX_INPUT], char DashedPhrase[MAX_INPUT], char UpperPhrase[MAX_INPUT]);
void DashIt(char *Phrase, char DashPhrase[MAX_INPUT]);

#endif
