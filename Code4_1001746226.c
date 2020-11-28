//Nabin Shrestha 1001746226
#include <stdio.h>
#include <stdlib.h>
#include "DrawTool.h"

int main()
{
	int userSize;
	char array[maxSize][maxSize];
	int quit = 1;
	mapInitilization(array, &userSize); //user chosen size passing my reference
	mapPrint(array, userSize);
	instructionPrint();
	while (quit)
	{
		int drawcmdsize = 100;
		char drawcmd[drawcmdsize], action, mark;
		int row, col, numspot;
		printf("Enter draw command or (enter Q to quit) ");
		fgets(drawcmd, drawcmdsize - 1, stdin);
		char *token;

		if (drawcmd[0] == 'q' || drawcmd[0] == 'Q')
		{
			quit = 0;
		}
		else
		{
			token = strtok(drawcmd, "(,)");
			action = toupper(*token);
			token = strtok(NULL, "(,)"); //using strtok to parse out the components of the draw command.
			row = atoi(token);
			token = strtok(NULL, "(,)");
			col = atoi(token);
			token = strtok(NULL, "(,)");
			numspot = atoi(token);
			token = strtok(NULL, "(,)");
			mark = *token;

			if (mark == '\n')
			{
				mark = 'X';
			}
			action = toupper(action);
			if (action == 'P' || action == 'p')
			{
				if ((row < userSize) && (col < userSize) && (row >= 0) && (col >= 0))
				{
					*(*(array + row) + col) = mark; //updating the array with the input mark
				}
				else
					printf("That draw command is out of range.\n");
			}
			else if (action == 'V' || action == 'v')
			{
				if ((numspot + row) <= (userSize) && (numspot > 0) && (col < userSize) && (row < userSize) && (0 <= col) && (0 <= row))
				{
					drawLine(array, row, col, action, numspot, mark); //calling function drawLine
				}
				else
					printf("That draw command is out of range.\n");
			}
			else if (action == 'H' || action == 'h')
			{
				if ((numspot + col) <= (userSize) && (numspot > 0) && (col < userSize) && (row < userSize) && (0 <= col) && (0 <= row))
				{
					drawLine(array, row, col, action, numspot, mark); //calling function drawLine
				}
				else
					printf("That draw command is out of range.");
			}
			else
				printf("That draw command is out of range.\n");

			mapPrint(array, userSize);
		}
	}
	return 0;
}
