//Nabin Shrestha 1001746226
#ifndef __DrawerLib_h
#define __DrawerLib_h

#include "SockLib.h"

#define MAX_DRAWERS 10

int NumDrawers; //declared global

void GetNumDrawers();
void CreateDrawer(SockDrawer *drawer, int Dnum);
int GetDrawer(SockDrawer SD[]);

#endif
