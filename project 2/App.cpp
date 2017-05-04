#include"App.h"
#include<fstream>
#include<sstream>
#include"Client.h"
#include<iostream>
#include"ClientProcessor.h"
#include"ManagerProcessor.h"
App::App()
{
	string U,S,L;
	ifstream OpenUser;
	OpenUser.open("UserDB.txt");
	Unum = 0; Snum = 0; Lnum = 0;
	while (getline(OpenUser, U))
	{
		istringstream u(U);
		string Id, password;
		int usertype, locId;
		u >> usertype;

		if (usertype == 0)
		{
			string Name;
			u >> Id;
			u >> password;
			u >> Name;
			u >> locId;
			users.insert(users.end(), new Client(Id, password, usertype, locId, Name));

		}
		else if (usertype == 1)
		{
			u >> Id;
			u >> password;
			u >> locId;
			users.insert(users.end(), new Manager(Id, password, usertype, locId));
		}
		Unum++;
	}
	OpenUser.close();
	ifstream OpenStore;
	OpenStore.open("StoreDB.txt");
	while (getline(OpenStore, S))
	{
		istringstream s(S);
		int StoreId, AvailableDistance;
		string StoreType, StoreName;
		s >> StoreId;
		s >> StoreName;
		s >> StoreType;
		s >> AvailableDistance;
		if (StoreType == "�ѽ���")
		{
			stores.insert(stores.end(), new Korean(StoreId, AvailableDistance, StoreName, StoreType));

		}
		else if (StoreType == "�߱���")
		{
			stores.insert(stores.end(), new Chinese(StoreId, AvailableDistance, StoreName, StoreType));
		}
		Snum++;
	}
	OpenStore.close();
	ifstream OpenLocation;
	OpenLocation.open("LocationDB.txt");
	while (getline(OpenLocation, L))
	{
		istringstream l(L);
		int locationId, locationType, latitude,lontitude;
		l >> locationId;
		l >> locationType;
		l >> latitude;
		l >> lontitude;
		locations.insert(locations.end(), new Location{ locationType, locationId,  latitude,lontitude });
		Lnum++;
	}

	OpenLocation.close();

}

App::~App()
{
	string U, S, L;
	ofstream OpenUser;
	OpenUser.open("UserDB.txt");
	for (int i = 0; i < Unum; i++)
	{
		ostringstream U;
		string Id, password;
		int usertype, locId;
		users[i]->getUserInfo(Id, password, usertype, locId);
		if (usertype == 0)
		{
			string Name;
			users[i]->getCname(Name);
			U << usertype << "\t" << Id << "\t" << password << "\t" << Name << "\t" << locId;
			OpenUser << U.str() << endl;
		}
		if (usertype == 1)
		{
			
			U << usertype << "\t" << Id << "\t" << password << "\t" << locId;
			OpenUser << U.str() << endl;

		}
	}
	OpenUser.close();
	ofstream OpenStore;
	OpenStore.open("StoreDB.txt");
	for (int i = 0; i < Snum; i++)
	{
		ostringstream S;
		int Id,AvailableDistance;
		string Storename, Storetype;
		stores[i]->getStoreInfo(Id, AvailableDistance, Storename, Storetype);
		S << Id << "\t" << Storename << "\t" << Storetype << "\t" << AvailableDistance;
		OpenStore << S.str() << endl;
	}
	OpenStore.close();
	
	ofstream OpenLocation;
	OpenLocation.open("LocationDB.txt");
	for (int i = 0; i < Lnum; i++)
	{
		ostringstream L;
		int locationId, locationType, latitude, lontitude;
		locationId = locations[i]->locationId;
		locationType = locations[i]->locationType;
		latitude = locations[i]->latitude;
		lontitude = locations[i]->lontitude;
		L << locationId << "\t" << locationType << "\t" << latitude << "\t" << lontitude;
		OpenLocation << L.str() << endl;
	}
	OpenLocation.close();

}
void App::run()
{
	while (1)
	{
		cout << "�α���" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1. �� �α���" << endl;
		cout << "2. ������ �α���" << endl;
		cout << "0. ����" << endl;
		cout << "--------------------------------------" << endl;
		int a;
		cin >> a;
		if (cin.fail())			//������ ������ �ƴ� ���� ���������� ����ó��
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}

		else if (a == 1)
		{
			cout << "ID : ";
			string ID;
			cin >> ID;
			cout << "��й�ȣ : ";
			string Password;
			cin >> Password;
			int temp = 0;
			for (int i = 0; i < Unum; i++)
			{
				int UT;
				string UID, UPW;
				users[i]->getId(UID);
				users[i]->getPW(UPW);
				users[i]->getUT(UT);
				if (UID == ID && UPW == Password && UT == 0)
				{
					cout << "�α��� ����!" << endl;
					loginedUser = users[i];
					temp++;
					string Uname;
					users[i]->getCname(Uname);
					pc = new ClientProcessor(users, stores, locations);
					pc->processOrder(loginedUser);
					/*	while (1)
						{
							cout << "�� �޴�" << endl;
							cout << "--------------------------------" << endl;
							cout << Uname << "��" << endl;
							cout << "--------------------------------" << endl;
							cout << "1. ������ �̸��� �˻�" << endl;
							cout << "2. ������ ������ �˻�" << endl;
							cout << "3. ��ġ ���� ����" << endl;
							int b;
							cin >> b;
							if (cin.fail())			//������ ������ �ƴ� ���� ���������� ����ó��
							{
								cout << "�߸��� �Է��Դϴ�." << endl;
								cin.clear();
								cin.ignore(256, '\n');
								continue;
							}
							if (b == 1)
							{
								cout << "������ ���� �˻�" << endl;
								cout << "���� : ";
								string SearchbyType;
								cin >> SearchbyType;

							}

						}*/
				}
				


			}
			if (temp == 0)
				{
					cout << "�α��� ����!" << endl;
					continue;
				}
		}
		else if (a == 2)
		{
			cout << "ID : ";
			string ID;
			cin >> ID;
			cout << "��й�ȣ : ";
			string Password;
			cin >> Password;
			int temp = 0;
			for (int i = 0; i < Unum; i++)
			{
				int UT;
				string UID, UPW;
				users[i]->getUT(UT);
				users[i]->getId(UID);
				users[i]->getPW(UPW);
				if (UT == 1 && UID == ID && UPW == Password)
				{
					cout << "�α��� ����!" << endl;
					loginedUser = users[i];
					temp++;
					pc = new ManagerProcessor(users,stores,locations);
					pc->processOrder(loginedUser);


				}



			}
			if (temp == 0)
			{
				cout << "�α��� ����!" << endl;
				continue;
			}
		}
		else if (a == 0)
		{

			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
		else
		{
			cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
			continue;
		}
	}
}