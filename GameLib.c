//Nabin Shrestha 1001746226
#include <stdio.h>
#include <stdlib.h>
#include "GameLib.h"
#include <string.h>
#include <stdio.h>

void StartGame(char ChosenPhrase[MAX_INPUT])
{
	#include "PhraseBank.txt"
	char DashPhrase[MAX_INPUT];
	printf("Welcome to %d STRIKES - YOU'RE OUT - the CSE version\n", STRIKES);
	printf("Please pick a phrase from the following menu\n\n");
	int i = 0;
	while (PhraseBank[i] != "")
	{
		CheckPhrase(PhraseBank[i]);
		DashIt(PhraseBank[i], DashPhrase);
		printf("%d.\t%s\n", i + 1, DashPhrase);
		i++;
	}
	int choice = 0;
	while (choice <1 || choice > i)
	{
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		getchar();
		//printf("Here's the phrase you need to guess\n");
	}
	printf("Here's the phrase you need to guess\n");
	strcpy(ChosenPhrase, PhraseBank[choice - 1]);
}

void CheckPhrase(char *Phrase)
{
	char dash = '-';
	char *check = strchr(Phrase, dash);
	int dist = abs(Phrase - check);
	while (check != NULL)
	{
		printf("%s contain a dash in position %d", *Phrase, dist);
	}
}
int GuessALetter(char Phrase[MAX_INPUT], char DashedPhrase[MAX_INPUT], char UpperPhrase[MAX_INPUT])
{
	char Guess;
	char *FindGuess = NULL;
	char UpperCaseCopy[MAX_INPUT];
	char UpperPhraseCopy[MAX_INPUT];
	int FoundALetter = 0;
	strcpy(UpperPhraseCopy, UpperPhrase);
	//printf("Here's the phrase you need to guess\n");
	printf("%s\n", DashedPhrase);
	printf("\nGuess a letter: ");
	scanf("%c", &Guess);
	getchar();
	char UpperCaseGuess;
	Guess = toupper(Guess);
	FindGuess = strchr(UpperPhraseCopy, Guess);
	while (FindGuess != NULL)
	{
		FoundALetter = 1;
		DashedPhrase[FindGuess - UpperPhraseCopy] = Phrase[FindGuess - UpperPhraseCopy];
		*FindGuess = '-';
		FindGuess = strchr(UpperPhraseCopy, Guess);
	}
	return FoundALetter;
}
void DashIt(char *Phrase, char DashPhrase[MAX_INPUT])
{
	char *check = NULL;
	int i = 0;
	//while (*(Phrase + i) != '\0')
	//{
	for (i = 0; i < strlen(Phrase); i++)
	{
		DashPhrase[i] = toupper(Phrase[i]);
	}
	DashPhrase[strlen(Phrase)] = '\0';
	check = strpbrk(DashPhrase, "QWERTYUIOPLKJHGFDSAZXCVBNM");
	while (check != NULL)
	{
		*check = '-';
		check = strpbrk(DashPhrase, "QWERTYUIOPLKJHGFDSAZXCVBNM");
	}
}
