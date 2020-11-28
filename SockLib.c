//Nabin Shrestha 1001746226
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "SockLib.h"
#include "SortLib.h"
#include "DrawerLib.h"
#include "DresserLib.h"

void SortMySocks(SockDrawer SD[])
{
	int numD, numD2, choice;
	int (*Comparefunction[])(const void *, const void *) = {DrawerIDCompare, NumberOfSocksCompare, MaxCapacityCompare, SockColorCompare};

	do
	{
		printf("Do you want to sort by?\n");
		printf("0. Changed my mind - don't want to sort\n");
		printf("1. Drawer ID?\n");
		printf("2. Number of socks in drawer?\n");
		printf("3. Max capacity of the drawers?\n");
		printf("4. Sock color?\n");

		printf("Choice: \n");
		scanf("%d", &choice);
	} while (choice < 0 || choice > 4);

	if (choice == 0)
	{
		printf("Your sock drawer is a mess!\n");
	}
	else
	{
		qsort(SD, NumDrawers, sizeof(SockDrawer), (*Comparefunction[choice - 1]));
		DisplayMyDresser(SD);
	}
}
void PutAwayMySocks(SockDrawer SD[])
{
	int drawernum, socksin;
	printf("Which drawer are you putting socks into?");
	int GD = GetDrawer(SD);
	int maxnum = SD[GD].MaxDrawerCapacity;

	printf("How many socks are you putting away?");
	scanf("%d", &socksin);
	int remainingcapacity = maxnum - SD[GD].NumberOfSocks;
	if (remainingcapacity < socksin)
	{
		printf("%d socks fit in the drawer and %d fell on the floor\n", remainingcapacity, socksin - remainingcapacity);
		SD[GD].NumberOfSocks = remainingcapacity + SD[GD].NumberOfSocks;
	}
	else
	{
		printf("%d fit in the drawer", socksin);
		SD[GD].NumberOfSocks = SD[GD].NumberOfSocks + socksin;
	}
}

void PutOnMySocks(SockDrawer SD[])
{
	int SocksOut;
	printf("Which drawer do you want to get socks from?  ");
	int drawID = GetDrawer(SD);
	int maxnum = SD[drawID].MaxDrawerCapacity;
	printf("How many socks are you getting out? ");
	scanf("%d", &SocksOut);
	if (SD[drawID].NumberOfSocks < SocksOut)
	{
		printf("You don't have that many socks!! You only get %d socks", SD[drawID].NumberOfSocks);
		SD[drawID].NumberOfSocks = 0;
	}
	else
	{
		SD[drawID].NumberOfSocks = SD[drawID].NumberOfSocks - SocksOut;
	}
}
