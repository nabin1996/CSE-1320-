// Nabin Shrestha 1001746226
#include "FileLib.h"
FILE *OpenFile(int argc, char *argv[], char *mode)
{
	int maxsize = 99;
	char FILENAME[maxsize];
	FILE *readfile = NULL;
	if (argc >= 2)
	{
		strcpy(FILENAME, argv[1]);
	}
	else
	{
		printf("Please Enter the file name: ");
		fgets(FILENAME, maxsize - 1, stdin);
		FILENAME[strlen(FILENAME) - 1] = '\0';
	}
	do
	{
		readfile = fopen(FILENAME, mode);
		if (readfile == NULL)
		{
			printf("Error reading file. \nPlease enter the file name: ");
			scanf("%s", FILENAME);
		}
	} while (readfile == NULL);
	return readfile;
}
int ReadFileIntoArray(FILE *FILENAME, record recordlist[])
{
	int i = 0;
	char info[500];
	char *token = NULL;
	while (fgets(info, 499, FILENAME) != NULL && i < MAX_ENTRIES)
	{
		if (info[0] == ' ' || info[0] == '\n')
			continue;
		if (info[strlen(info) - 1] == '\n')
		{
			info[strlen(info) - 1] = '\0';
		}
		token = strtok(info, "|");
		recordlist[i].artist = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(recordlist[i].artist, token);

		token = strtok(NULL, "|");
		recordlist[i].title = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(recordlist[i].title, token);

		token = strtok(NULL, "|");
		strcpy(recordlist[i].year, token);

		token = strtok(NULL, "|");
		recordlist[i].album = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(recordlist[i].album, token);
		i++;
	}
	return i;
}
void writeintofile(FILE *FILENAME, int index, record recordlist[])
{
	int lastposition = ftell(FILENAME);
	fseek(FILENAME, 0, SEEK_SET);
	int i = 0;
	while (recordlist[i].artist != NULL)
	{
		if (i != index)
		{
			fprintf(FILENAME, "%s|%s|%s|%s\n", recordlist[i].artist, recordlist[i].title, recordlist[i].year, recordlist[i].album);
		}
		i++;
	}
	int currentposition = ftell(FILENAME);
	int bytes_space = lastposition - currentposition;
	fseek(FILENAME, currentposition, SEEK_SET);
	for (i = 0; i < bytes_space; i++)
	{
		fprintf(FILENAME, "%s", " ");
	}
	int j =0;
	while (recordlist[j].artist != NULL)
	{
		free(recordlist[j].artist);
		free(recordlist[j].title);
		free(recordlist[j].album);
		j++;
        }
	fclose(FILENAME);
}
