#include"Chinese.h"

Chinese::Chinese(int StoreId, int AvailableDistance, string StoreName, string StoreType)
{
	storeId = StoreId;
	availableDistance = AvailableDistance;
	storeName = StoreName;
	storeType = StoreType;
}
void Chinese::order(User* loginedUser)
{
	cout << "¼±ÅÃµÈ À½½ÄÁ¡ : " << storeName << endl;

	cout << "--------------------------------------" << endl;
	cout << "1. Â¥Àå¸é" << endl;
	cout << "2. Â«»Í" << endl;
	cout << "3. ÅÁ¼öÀ°" << endl;
	cout << "--------------------------------------" << endl;
	
	int a;
	cout << "->";
	cin >> a;
	string Uid;
	loginedUser->getCname(Uid);				//ID->nameÀ¸·Î º¯°æ
	switch (a)
	{
	case 1:
		recievedOrder.insert(recievedOrder.end(), Order{ Uid,"Â¥Àå¸é" });
		break;
	case 2:
		recievedOrder.insert(recievedOrder.end(), Order{ Uid,"Â«»Í" });
		break;
	case 3:
		recievedOrder.insert(recievedOrder.end(), Order{ Uid,"ÅÁ¼öÀ°" });
		break;
	}
	cout << "ÁÖ¹® ¿Ï·á" << endl;
}

int Chinese::calculateDeliverTime(int userLat, int userLon, int storeLat, int storeLon)
{
	int time;
	time = (userLat - storeLat) * (userLat - storeLat) + (userLon - storeLon) * (userLon - storeLon);
	time = time * 5;
	return time;
}