#include"Store.h"

void Store::getStoreInfo(int& Sid, int& aD, string& Storename, string& Storetype)
{
	Sid = storeId;
	aD = availableDistance;
	Storename = storeName;
	Storetype = storeType;
}
void Store::printOrderedMenu(string& returnName)
{
	string OrderedUser;
	cout << "주문 목록" << endl;
	cout << "--------------------------------" << endl;
	if (recievedOrder.size() == 0)
	{
		cout << "없음" << endl;
	}
	else
	{
		int i;
		for (i = 0; i < recievedOrder.size(); i++)
		{
			cout << i + 1 << ". " << recievedOrder[i].orderedFood << endl;
		}
		cout << "--------------------------------" << endl;
		int a;
		cin >> a;
		for (i = 0; i < recievedOrder.size(); i++)
		{
			if (i == (a - 1))
			{
				cout << "주문이 처리됨" << endl;
				cout << "--------------------------------" << endl;
				cout << "주문자 : " << recievedOrder[i].orderedUserId << endl;
				cout << "메뉴 : " << recievedOrder[i].orderedFood << endl;
				OrderedUser = recievedOrder[i].orderedUserId;
				returnName = OrderedUser;
				recievedOrder.erase(recievedOrder.begin() + i);
				
				

			}


		}

	}





}
Store::Store()
{

	storeId = 0;
	storeName = "";
	storeType = "";
	availableDistance = 0;

}
Store::~Store()
{


}
void Store::PrintClientOrderedMenu(string Uname)
{
	for (int i = 0; i < recievedOrder.size(); i++)
	{
		if (Uname == recievedOrder[i].orderedUserId)
		{
			cout << "가게 : " << storeName << ",  메뉴 : " << recievedOrder[i].orderedFood << endl;


		}

	}



}