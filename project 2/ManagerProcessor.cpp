#include"ManagerProcessor.h"

ManagerProcessor::ManagerProcessor(vector<User*> &userdb, vector<Store*> &storedb, vector<Location*> &locationdb)
{
	userDBPtr = userdb;
	storeDBPtr = storedb;
	locationDBPtr = locationdb;


}
void ManagerProcessor::processOrder(User* loginedUser)
{
	int ULID,SLID;
	loginedUser->getLID(ULID);
	Store* ThisStore;
	for (int i = 0; i < storeDBPtr.size(); i++)
	{
		storeDBPtr[i]->getSID(SLID);
		if (SLID == ULID)
		{
			ThisStore = storeDBPtr[i];

		}

	}

	string StoreName;
	ThisStore->getSname(StoreName);
	cout << "음식점 관리자 메뉴" << endl;
	cout << "--------------------------------" << endl;
	cout << "음식점: " << StoreName << endl;
	cout << "--------------------------------" << endl;
	cout << "1. 주문 목록 확인" << endl;
	cout << "2. 배달 가능 거리 변경" << endl;
	cout << "--------------------------------" << endl;
	int a;
	cin >> a;
							//ULID가 Manager의 ULID이다
	
	if (a == 1)
	{
		User* OrderedUser;
		string OrderedUserName;
		ThisStore->printOrderedMenu(OrderedUserName);
		for (int i = 0; i < userDBPtr.size(); i++)
		{
			int UT;
			userDBPtr[i]->getUT(UT);
			if (UT == 0)
			{
				OrderedUser = userDBPtr[i];
				string Searchname;
				OrderedUser->getCname(Searchname);
				if (OrderedUserName == Searchname)
				{
					break;

				}

			}

		}
		int Ulat, Ulont, Slat, Slont;
		int OrderedUserLId;
		OrderedUser->getLID(OrderedUserLId);
		ThisStore->getSID(SLID);
		for (int i = 0; i < locationDBPtr.size(); i++)
		{
			if (locationDBPtr[i]->locationId == OrderedUserLId && locationDBPtr[i]->locationType == 1)
			{
				Ulat = locationDBPtr[i]->latitude;
				Ulont = locationDBPtr[i]->lontitude;

			}
			else if (locationDBPtr[i]->locationId == SLID && locationDBPtr[i]->locationType == 2)
			{
				Slat = locationDBPtr[i]->latitude;
				Slont = locationDBPtr[i]->lontitude;

			}
		}
		cout << "배달 예상 시간 : " << ThisStore->calculateDeliverTime(Ulat, Ulont, Slat, Slont) << "분" << endl;
		cout << "--------------------------------" << endl;
	
	}
	if (a == 2)
	{
		cout << "변경할 배달 가능 거리를 입력해주세요. 배달 가능 거리는 유클리드 거리의 제곱값입니다." << endl;
		cout << "현재 배달 가능 거리 : " << ThisStore->printAD() << endl;
		int a;
		cin >> a;
		ThisStore->changeAD(a);
		cout << "배달 가능 거리가 " << ThisStore->printAD() << "로 변경되었습니다." << endl;
		
	}

	



}