#include"Korean.h"

Korean::Korean(int StoreId, int AvailableDistance, string StoreName, string StoreType)
{
	storeId = StoreId;
	availableDistance = AvailableDistance;
	storeName = StoreName;
	storeType = StoreType;
}
void Korean::order(User* loginedUser)
{



	cout << "¼±ÅÃµÈ À½½ÄÁ¡ : " << storeName << endl;
	cout << "--------------------------------------" << endl;
	cout << "1. ±èÄ¡Âî°³" << endl;
	cout << "2. ºñºö¹ä" << endl;
	cout << "3. ºÒ°í±â" << endl;
	cout << "--------------------------------------" << endl;

	int a;
	cout << "->";
	cin >> a;
	string Uid;
	loginedUser->getCname(Uid);				//ID->nameÀ¸·Î º¯°æ
	switch (a)
	{
	case 1:
		recievedOrder.insert(recievedOrder.end(), Order{ Uid,"±èÄ¡Âî°³" });
		break;
	case 2:
		recievedOrder.insert(recievedOrder.end(), Order{ Uid,"ºñºö¹ä" });
		break;
	case 3:
		recievedOrder.insert(recievedOrder.end(), Order{ Uid,"ºÒ°í±â" });
		break;
	}
	cout << "ÁÖ¹® ¿Ï·á" << endl;
}
int Korean::calculateDeliverTime(int userLat, int userLon, int storeLat, int storeLon)
{
	int time;
	time = (userLat - storeLat) * (userLat - storeLat) + (userLon - storeLon) * (userLon - storeLon);
	time = time * 5;
	return time;
}
