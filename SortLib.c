//Nabin Shrestha 1001746226
#include "SockLib.h"
#include "SortLib.h"
#include "DrawerLib.h"
#include "DresserLib.h"

int DrawerIDCompare(const void *a, const void *b)
{
	return (((SockDrawer *)a)->DrawerID, (((SockDrawer *)b)->DrawerID));
}
int NumberOfSocksCompare(const void *a, const void *b)
{
	return (((SockDrawer *)a)->NumberOfSocks, (((SockDrawer *)b)->NumberOfSocks));
}
int MaxCapacityCompare(const void *a, const void *b)
{
	return (((SockDrawer *)a)->MaxDrawerCapacity,(((SockDrawer *)b)->MaxDrawerCapacity));
}
int SockColorCompare(const void *a, const void *b)
{
	return (strcmp(((SockDrawer *)a)->SockColor, ((SockDrawer *)b)->SockColor));
}
