//Nabin Shrestha  1001746226
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "SockLib.h"
#include "SortLib.h"
#include "DrawerLib.h"
#include "DresserLib.h"

void DisplayMyDresser(SockDrawer SD[])
{

	printf("\nMy Dresser\n");
	int i;
	for (i = 0; i < NumDrawers; i++)
	{
		printf("Drawer %d\n", SD[i].DrawerID);
		printf("\t Contents: %d %s\n", SD[i].NumberOfSocks, SD[i].SockColor); // i need color here
		printf("\t Capacity: %d socks\n", SD[i].MaxDrawerCapacity);
	}
}
