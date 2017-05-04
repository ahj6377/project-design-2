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
	cout << "������ ������ �޴�" << endl;
	cout << "--------------------------------" << endl;
	cout << "������: " << StoreName << endl;
	cout << "--------------------------------" << endl;
	cout << "1. �ֹ� ��� Ȯ��" << endl;
	cout << "2. ��� ���� �Ÿ� ����" << endl;
	cout << "--------------------------------" << endl;
	int a;
	cin >> a;
							//ULID�� Manager�� ULID�̴�
	
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
		cout << "��� ���� �ð� : " << ThisStore->calculateDeliverTime(Ulat, Ulont, Slat, Slont) << "��" << endl;
		cout << "--------------------------------" << endl;
	
	}
	if (a == 2)
	{
		cout << "������ ��� ���� �Ÿ��� �Է����ּ���. ��� ���� �Ÿ��� ��Ŭ���� �Ÿ��� �������Դϴ�." << endl;
		cout << "���� ��� ���� �Ÿ� : " << ThisStore->printAD() << endl;
		int a;
		cin >> a;
		ThisStore->changeAD(a);
		cout << "��� ���� �Ÿ��� " << ThisStore->printAD() << "�� ����Ǿ����ϴ�." << endl;
		
	}

	



}