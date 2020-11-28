//Nabin Shrestha 1001746226
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "SockLib.h"
#include "SortLib.h"
#include "DrawerLib.h"
#include "DresserLib.h"

int GetDrawer(SockDrawer SD[])
{
	int ask;

	do
	{

		scanf("%d", &ask);
		if (ask < 0 || ask > NumDrawers)
			printf("That's not one of your drawers !! \n Pick again\n");
	} while (ask < 0 || ask > NumDrawers);
	return ask - 1;
}

void GetNumDrawers()
{
	int Dnum;
	do
	{
		printf("How many drawers does your dresser have? (1-10) ");
		scanf("%d", &Dnum);
	} while (Dnum == 0 && Dnum > MAX_DRAWERS);
	NumDrawers = Dnum;
}

void CreateDrawer(SockDrawer *drawer, int MaxDrawerCapacity)
{
	int NumSocks, SocksFit;
	int Socksput = drawer->DrawerID + 1;
	char color;
	printf("How many total socks will fit in the drawer %d? ", Socksput);
	scanf("%d", &drawer->MaxDrawerCapacity);
	printf("How many socks you are putting in the drawer %d? ", Socksput);
	scanf("%d", &NumSocks);
	getchar();
	drawer->NumberOfSocks = NumSocks;
	if (NumSocks > drawer->MaxDrawerCapacity)
	{
		printf("%d socks fit in the drawer and %d fell on the floor.\n", drawer->MaxDrawerCapacity, (-drawer->MaxDrawerCapacity + NumSocks));
		drawer->NumberOfSocks = drawer->MaxDrawerCapacity;
	}
	printf("What color are the socks on the drawer %d? ", Socksput);
	fgets(drawer->SockColor, sizeof(drawer->SockColor) - 1, stdin);
}
