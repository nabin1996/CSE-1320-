//Nabin Shrestha 1001746226
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DrawerLib.h"
#include "SockLib.h"
#include "SortLib.h"
#include "DresserLib.h"

int main(void)
{
	int DrawerID;
	int menuOption;
	enum
	{
		RemoveSocks = 1,
		AddSocks,
		DisplayDresser,
		SortSocks
	} SockAction;
	SockDrawer SD[MAX_DRAWERS];
	GetNumDrawers();
	int i;
	for (i = 0; i < NumDrawers; i++)
	{
		SD[i].DrawerID = i;
		CreateDrawer(&SD[i], i + 1);
	}
	do
	{
		printf("\nWhat do you need to do?\n");
		//scanf("%d", &menuOption);
		printf("\n0. Don't have socks!!");
		printf("\n1. Take socks out of a drawer?");
		printf("\n2. Put more socks in a drawer?");
		printf("\n3. Display dresser");
		printf("\n4. Sort Socks\n\n");

		printf("Choice: ");
		scanf("%d", &menuOption);

		switch (menuOption)
		{
		case RemoveSocks:
			PutOnMySocks(SD);
			DisplayMyDresser(SD);
			break;
		case AddSocks:
			PutAwayMySocks(SD);
			DisplayMyDresser(SD);
			break;
		case DisplayDresser:
			DisplayMyDresser(SD);
			break;
		case SortSocks:
			SortMySocks(SD);
			DisplayMyDresser(SD);
			break;
		}
	} while (menuOption != 0);
	if (menuOption == 0)
	{
		printf("Time to do laundry\n");
	}
	return 0;
}
