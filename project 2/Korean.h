#include "Store.h"
#pragma once
class Korean :
	public Store
{
public:
	Korean() {};
	Korean(int StoreId, int AvailableDistance, string StoreName, string StoreType);
	~Korean() {};
	void order(User* loginedUser);
	int calculateDeliverTime(int userLat, int userLon, int storeLat, int storeLon);
};

