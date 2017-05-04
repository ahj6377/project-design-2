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
		if (StoreType == "한식집")
		{
			stores.insert(stores.end(), new Korean(StoreId, AvailableDistance, StoreName, StoreType));

		}
		else if (StoreType == "중국집")
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
		cout << "로그인" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1. 고객 로그인" << endl;
		cout << "2. 관리자 로그인" << endl;
		cout << "0. 종료" << endl;
		cout << "--------------------------------------" << endl;
		int a;
		cin >> a;
		if (cin.fail())			//정해진 형식이 아닌 값이 들어왔을때의 예외처리
		{
			cout << "잘못된 입력입니다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}

		else if (a == 1)
		{
			cout << "ID : ";
			string ID;
			cin >> ID;
			cout << "비밀번호 : ";
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
					cout << "로그인 성공!" << endl;
					loginedUser = users[i];
					temp++;
					string Uname;
					users[i]->getCname(Uname);
					pc = new ClientProcessor(users, stores, locations);
					pc->processOrder(loginedUser);
					/*	while (1)
						{
							cout << "고객 메뉴" << endl;
							cout << "--------------------------------" << endl;
							cout << Uname << "님" << endl;
							cout << "--------------------------------" << endl;
							cout << "1. 음식점 이름을 검색" << endl;
							cout << "2. 음식점 종류로 검색" << endl;
							cout << "3. 위치 정보 변경" << endl;
							int b;
							cin >> b;
							if (cin.fail())			//정해진 형식이 아닌 값이 들어왔을때의 예외처리
							{
								cout << "잘못된 입력입니다." << endl;
								cin.clear();
								cin.ignore(256, '\n');
								continue;
							}
							if (b == 1)
							{
								cout << "음식점 종류 검색" << endl;
								cout << "종류 : ";
								string SearchbyType;
								cin >> SearchbyType;

							}

						}*/
				}
				


			}
			if (temp == 0)
				{
					cout << "로그인 실패!" << endl;
					continue;
				}
		}
		else if (a == 2)
		{
			cout << "ID : ";
			string ID;
			cin >> ID;
			cout << "비밀번호 : ";
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
					cout << "로그인 성공!" << endl;
					loginedUser = users[i];
					temp++;
					pc = new ManagerProcessor(users,stores,locations);
					pc->processOrder(loginedUser);


				}



			}
			if (temp == 0)
			{
				cout << "로그인 실패!" << endl;
				continue;
			}
		}
		else if (a == 0)
		{

			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		else
		{
			cout << "입력이 잘못되었습니다." << endl;
			continue;
		}
	}
}