//Nabin Shrestha 1001746226
#include <stdio.h>
#include <stdlib.h>
#include "DrawTool.h"

void mapInitilization(char array[][maxSize], int *size)
{
    int userSize;
    char input[maxSize];

    while (userSize <= 0 || userSize > maxSize) //using while loop to verify that the entered size fits within the bounds of the max array size.
    {
        printf("How big is the array? (Enter number between 1 and %d) ", maxSize);
        scanf("%d", &userSize);
        getchar();
    }

    *size = userSize;
    char bgchar;
    printf("What is the background character? ");
    scanf(" %c", &bgchar);
    getchar();
    int i, j;
    for (i = 0; i < userSize; i++)
    {
        for (j = 0; j < userSize; j++)
        {
            *(*(array + i) + j) = bgchar; //initializing the array with the background character using the user input size.
        }
    }
}
void instructionPrint()
{
    printf("Draw commands start with \n\n");
    printf("\t P for a single point\n"
           "\t H for a horizontal line\n"
           "\t V for a vertical line \n\n");
    printf("After the P/V/H, enter a row,col coordinate and the number of spots to mark\n"
           "enclosed in () and separated by commas and then the character for the mark.\n"
           "'X' will be used if a mark is not entered. For example,\n");
    printf("\n\t P(2,3,1)* \t start at point 2,3 in the array and mark one spot\n"
           "\t\t\t with an *. For P, the 3rd parameter is ignored.\n");
    printf("\n\t V(1,2,3)$ \t start at point 1,2 in the array and mark the next\n"
           "\t\t\t 3 spots down from the current position with $\n");
    printf("\n\t H(4,6,7)# \t start at point 4,6 in the array and mark the next\n"
           "\t\t\t 7 spots to the right with # \n\n");
    printf("Coordinates out of range and lines drawn past the borders are not allowed.\n\n");
}

void mapPrint(char array[][maxSize], int userSize)
{
    int i, j;
    for (i = 0; i < userSize; i++) //using nested for loops
    {
        for (j = 0; j < userSize; j++)
        {
            printf("%c", *(*(array + i) + j));
        }
        printf("\n");
    }
}
void drawLine(char array[][maxSize], int row, int col, char action, int numspot, char bg)
{
    int i;
    if (action == 'V' || action == 'v') // handling for both vertical and horizontal line.
    {
        for (i = 0; i < numspot; i++) //updating the array elements.
        {
            *(*(array + row) + col) = bg;
            row++;
        }
    }
    if (action == 'H' || action == 'h')
    {
        for (i = 0; i < numspot; i++)
        {
            *(*(array + row) + col) = bg;
            col++;
        }
    }
}
