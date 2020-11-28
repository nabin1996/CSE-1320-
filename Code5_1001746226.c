//Nabin Shrestha 1001746226
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameLib.h"

int main(void)
{
	char Phrase[MAX_INPUT];
	char DashedPhrase[MAX_INPUT];
	char UpperPhrase[MAX_INPUT];
	int strikes = 0;
	char *dash = NULL;
	StartGame(Phrase);
	DashIt(Phrase, DashedPhrase);
	int i = 0;
	for (i = 0; i < strlen(Phrase); i++)
	{
		UpperPhrase[i] = toupper(*(Phrase + i));
	}
	do
	{
		int Guess = GuessALetter(Phrase, DashedPhrase, UpperPhrase);
		dash = strchr(DashedPhrase, '-');
		if (Guess == 0)
		{
			strikes++;
			printf("\nStrikes\t%d\n", strikes);
		}
	} while (dash != NULL && (strikes < STRIKES));
	if (strikes < STRIKES)
	{
		printf("You figured it out!!\n\n The phrase was \n\n %s \n YOU WIN!!!", Phrase);
	}
	else
		printf("%d STRIKES- YOU'RE OUT!! \n\n Game over\n", strikes);
	return 0;
}
