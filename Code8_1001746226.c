//Nabin Shrestha 1001746226
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "MovieTheaterLib.h"
#include "QueueLib.h"
#include "BSTLib.h"
#include "ListLib.h"
#include "StackLib.h"

void PrintReceipts(SNODE **StackTop);
BNODE *PickAndDisplayTheater(BNODE *BSTRoot, char MovieTheaterMap[][MAXCOLS], int *MapRow, int *MapCol);
void ReadFileIntoQueue(FILE *QueueFile, QNODE **QH, QNODE **QT);
void ReadFileIntoBST(FILE *BSTFile, BNODE **BSTnode);
void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[]);
FILE* openQueueFile(char *name, char mode[5]);
FILE* openZipFile(char *name, char mode[5]);

void PrintReceipts(SNODE **StackTop)
{
	if(*StackTop == NULL)
	{
		printf("No receipts.\n");
	}
	else
	{
		printf("today's receipt\n");
		while((*StackTop) != NULL)
		{
			printf("RECEIPTNUMBER : %d \n", (*StackTop)-> ReceiptNumber);
			printf("%s \n ", (*StackTop)-> MovieTheaterName);
			while((*StackTop)->  TicketList != NULL)
			{
				printf("%s \n " , (*StackTop)->  TicketList -> Ticket);
				ReturnAndFreeLinkedListNode(&(*StackTop)->  TicketList, (*StackTop)->  TicketList -> Ticket);
			}
			pop(StackTop);
		}
	}
}
	/* 
	   if the StackTop is empty, the print appropriate message - see example output - 
	   else print out the receipts.  A receipt is one node of the stack and each receipt
	   consists of a receipt number, a movie theater name and a TicketList (a linked list
	   of all seats sold to one customer).  Use ReturnAndFreeLinkedListNode() to traverse 
	   the linked list stored in each stack node and display the seats and free the 
	   linked list nodes. Each call to ReturnAndFreeLinkedListNode() brings back ONE ticket 
	   from the linked list in the Ticket variable.  Call pop() to remove the stack node.
	*/

BNODE *PickAndDisplayTheater(BNODE *BSTRoot, char MovieTheaterMap[][MAXCOLS], int *MapRow, int *MapCol)
{
	BNODE *foundT = BSTRoot;
	char zipcode[9] = {};
	char shape[11] = {};
	char *token;
	char name[100];
	printf("\n\nPick a theater by entering the zipcode\n\n");
				
	InOrder(BSTRoot);			
	// Traverse the BST in order and print out the theaters in zip code order - use InOrder()			
	printf("Enter zip code \n");
	scanf("%s", zipcode);
	// Prompt for a zip

	foundT= SearchForBNODE(BSTRoot, zipcode);
	// Call SearchForBNODE()
    
    if (foundT == NULL)
	{
		printf("Sorry! the theater isn't available.\n");
	}
	else
	{
		char *token;
		strcpy(shape, foundT -> Dimensions);
		token = strtok(shape, "x");
		int row = atoi(token);
		*MapRow = row;
		token = strtok(NULL, "x");
		int col = atoi(token);
		*MapCol = col;
		char name[100];
		strcpy(name , foundT -> FileName);
		int foundT = ReadMovieTheaterFile(MovieTheaterMap, name, row, col);
		if(foundT != 0)
		{
			PrintSeatMap(MovieTheaterMap, row, col);
		}
		else
		{
			printf("Unable to print that seat map at this time. Check back later.");
		}
	}
	return foundT;
		
	// If theater is not found, then print message
	
	// If theater is found, then tokenize the theater's dimensions and
	// pass those dimensions and the MovieTheaterMap and the theater's filename
	// to ReadMovieTheaterFile()

	// If ReadMovieTheaterFile() returns FALSE, then print
	// "Unable to print that seat map at this time.  Check back later."
	// else call PrintSeatMap()

	// return the found theater
}	

void ReadFileIntoQueue(FILE *QueueFile, QNODE **QH, QNODE **QT)
{
	char name[100];
	while(fgets(name, sizeof(name)-1, QueueFile))
	{
		enQueue(name, QH, QT);
	}
	//	read the passed in file and calls enQueue for each name in the file
}

void ReadFileIntoBST(FILE *BSTFile, BNODE **BSTnode)
{
	char name[100], *MovieTheaterName, *token, zipcode[9], *filename, *shape;
    while(fgets(name, sizeof(name)-1, BSTFile))
	{
			
		token = strtok(name, "|");
		MovieTheaterName = malloc(sizeof(char)*strlen(token));
		strcpy(MovieTheaterName, token);
		
		token = strtok(NULL, "|");
		strcpy(zipcode, token);
		
		token = strtok(NULL, "|");
		filename = malloc(strlen(token)*sizeof(char));
		strcpy(filename, token);
		
		token = strtok(NULL, "|");
		shape = malloc(strlen(token)*sizeof(char));
		strcpy(shape, token);
		
		AddBSTNode(BSTnode, MovieTheaterName, zipcode, filename, shape);
	}
	//	read the passed in file and tokenize each line and pass the information to AddBSTNode
}

void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[])
{
	int i = 0; 
	while (argv[++i] != NULL)
	{
		if (!strncmp(argv[i], ParamName, strlen(ParamName)))
		{
			strcpy(ParamValue, strchr(argv[i], '=') + 1);
		}
	}
}
int PrintMenu()
{
	int choice = 0;
	printf("\n\n1.	Sell tickets to next customer\n\n");
	printf("2.	See who's in line\n\n");
	printf("3.	See the seat map for a given theater\n\n");
	printf("4.	Print today's receipts\n\n");
	printf("Choice : ");
	scanf("%d", &choice);
	
	while (choice < 1 || choice > 4)
	{
		printf("Invalid choice.  Please reenter. ");
		scanf("%d", &choice);
	}
	return choice;
}
FILE* openQueueFile(char *name, char mode[5])
{
	FILE *point = fopen(name, mode);
	if(point == NULL)
	{
		exit(0);
	}
	return point;
}
FILE* openZipFile(char *name, char mode[5])
{
	FILE *point = fopen(name, mode);
	if(point == NULL)
	{
		exit(0);
	}
	return point;
}

int main(int argc, char *argv[])
{
	int i, j, k;
	FILE *queueFile = NULL;
	FILE *zipFile = NULL;
	char arg_value[20];
	char queuefilename[20];
	char zipfilename[20];
	int ReceiptNumber = 0;
	int choice = 0;
	int SeatNumber;
	char Row;
	char Ticket[5];
	int ArrayRow, ArrayCol;
	int MapRow, MapCol;
	char MovieTheaterMap[MAXROWS][MAXCOLS] = {};
	LNODE *TicketLinkedListHead = NULL;
	QNODE *QueueHead = NULL;
	QNODE *QueueTail = NULL;
	BNODE *BSTRoot = NULL;
	BNODE *foundT = NULL;
	SNODE *StackTop = NULL;
	int NumberOfTickets = 0;
	
	if (argc != 4)
	{
		printf("%s QUEUE=xxxxxx ZIPFILE=xxxxx RECEIPTNUMBER=xxxxx\n", argv[0]);
		exit(0);
	}
	
	get_command_line_parameter(argv, "QUEUE=", queuefilename);
	get_command_line_parameter(argv, "ZIPFILE=", zipfilename);
	get_command_line_parameter(argv, "RECEIPTNUMBER=", arg_value);
	ReceiptNumber = atoi(arg_value);
		
	queueFile=openQueueFile(queuefilename, "r+");	
	
	/* call function to open queuefilename - if it does not open, print message and exit */	
	zipFile= openZipFile(zipfilename, "r+");
	
	/* calll function to open zipfilename - if it does not open, print message and exit */

	ReadFileIntoQueue(queueFile, &QueueHead, &QueueTail);
	ReadFileIntoBST(zipFile, &BSTRoot);
	
	while (QueueHead != NULL)
	{
		choice = PrintMenu();
	
		switch (choice)
		{
			case 1 :
				printf("\n\nHello %s\n", QueueHead->name);				
				foundT = PickAndDisplayTheater(BSTRoot, MovieTheaterMap, &MapRow, &MapCol);
				if (foundT != NULL)
				{
					printf("\n\nHow many movie tickets do you want to buy? ");
					scanf("%d", &NumberOfTickets);
					for (i = 0; i < NumberOfTickets; i++)
					{
						do
						{
							printf("\nPick a seat (Row Seat) ");
							scanf(" %c%d", &Row, &SeatNumber);
							Row = toupper(Row);
							ArrayRow = (int)Row - 65;
							ArrayCol = SeatNumber - 1;
						
							if ((ArrayRow < 0 || ArrayRow >= MapRow) ||
								(ArrayCol < 0 || ArrayCol >= MapCol))
							{
								printf("\nThat is not a valid seat.  Please choose again\n\n");
							}		
						}
						while ((ArrayRow < 0 || ArrayRow >= MapRow) ||
							   (ArrayCol < 0 || ArrayCol >= MapCol));
						
						if (MovieTheaterMap[ArrayRow][ArrayCol] == 'O')
						{	
							MovieTheaterMap[ArrayRow][ArrayCol] = 'X';
							sprintf(Ticket, "%c%d", Row, SeatNumber); 
							InsertNode(&TicketLinkedListHead, Ticket);
						}
						else
						{
							printf("\nSeat %c%d is not available.\n\n", Row, SeatNumber);
							i--;
						}
						PrintSeatMap(MovieTheaterMap, MapRow, MapCol);
					}
					
					WriteSeatMap(foundT, MovieTheaterMap, MapRow, MapCol);
					push(&StackTop, TicketLinkedListHead, ReceiptNumber, foundT->MovieTheaterName);
					TicketLinkedListHead = NULL;
					ReceiptNumber++;
					printf("\nThank you %s - enjoy your movie!\n", QueueHead->name);
					deQueue(&QueueHead);
				}
				break;
			case 2 : 
				printf("\n\nCustomer Queue\n\n");
				DisplayQueue(QueueHead);
				printf("\n\n");
				break;
			case 3 :
				PickAndDisplayTheater(BSTRoot, MovieTheaterMap, &MapRow, &MapCol);
				break;
			case 4 : 
				PrintReceipts(&StackTop);
				break;
			default :
				printf("Bad menu choice");
		}
	}
	
	printf("Good job - you sold tickets to all of the customers in line.\n");
	PrintReceipts(&StackTop);
	
	return 0;
}



