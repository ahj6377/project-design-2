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
	cout << "���õ� ������ : " << storeName << endl;

	cout << "--------------------------------------" << endl;
	cout << "1. ¥���" << endl;
	cout << "2. «��" << endl;
	cout << "3. ������" << endl;
	cout << "--------------------------------------" << endl;
	
	int a;
	cout << "->";
	cin >> a;
	string Uid;
	loginedUser->getCname(Uid);				//ID->name���� ����
	switch (a)
	{
	case 1:
		recievedOrder.insert(recievedOrder.end(), Order{ Uid,"¥���" });
		break;
	case 2:
		recievedOrder.insert(recievedOrder.end(), Order{ Uid,"«��" });
		break;
	case 3:
		recievedOrder.insert(recievedOrder.end(), Order{ Uid,"������" });
		break;
	}
	cout << "�ֹ� �Ϸ�" << endl;
}

int Chinese::calculateDeliverTime(int userLat, int userLon, int storeLat, int storeLon)
{
	int time;
	time = (userLat - storeLat) * (userLat - storeLat) + (userLon - storeLon) * (userLon - storeLon);
	time = time * 5;
	return time;
}