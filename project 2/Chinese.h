#pragma once
#include "Store.h"
class Chinese :
	public Store
{
public:
	Chinese() {};
	Chinese(int StoreId, int AvailableDistance, string StoreName, string StoreType);
	~Chinese() {};
	void order(User* loginedUser);
	int calculateDeliverTime(int userLat, int userLon, int storeLat, int storeLon);
};

