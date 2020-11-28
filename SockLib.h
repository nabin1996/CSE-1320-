// Nabin Shrestha 1001746226
#ifndef __SockLib_h
#define __SockLib_h
#include "SockLib.h"
typedef struct
{
	int DrawerID;
	int NumberOfSocks;
	char SockColor[40];
	int MaxDrawerCapacity;

} SockDrawer;

#define MAX_DRAWERS 10

void SortMySocks(SockDrawer SD[]);
void PutAwayMySocks(SockDrawer SD[]);
void PutOnMySocks(SockDrawer SD[]);

#endif
