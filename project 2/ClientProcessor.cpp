#include"ClientProcessor.h"
ClientProcessor::ClientProcessor(vector<User*> &userdb, vector<Store*> &storedb, vector<Location*> &locationdb)
	:Processor(userdb, storedb, locationdb)
{


}



void ClientProcessor::processOrder(User* loginedUser)
{
	string Uname;
	loginedUser->getCname(Uname);
	

//	while (1)
	//{
		cout << "고객 메뉴" << endl;
		cout << "--------------------------------" << endl;
		cout << Uname << "님" << endl;
		cout << "--------------------------------" << endl;
		cout << "1. 음식점 이름을 검색" << endl;
		cout << "2. 음식점 종류로 검색" << endl;
		cout << "3. 위치 정보 변경" << endl;
		cout << "--------------------------------" << endl;
		int b;
		cin >> b;
		if (cin.fail())			//정해진 형식이 아닌 값이 들어왔을때의 예외처리
		{
			cout << "잘못된 입력입니다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			//continue;
		}
		if (b == 1)
		{
			cout << "음식점 이름 검색" << endl;
			cout << "이름 : ";
			string SearchbyName;
			cin >> SearchbyName;
			int Index = 0;
			int* Indexptr;
			Store* OrderedStore;
			for (int i = 0; i < storeDBPtr.size(); i++)
			{
				string Sname;
				storeDBPtr[i]->getSname(Sname);
				if (Sname.find(SearchbyName) != string::npos)
				{
					Index++;
					string sname;
					storeDBPtr[i]->getSname(sname);
					cout << Index << ". " << Sname << endl;

				}
			}	
				if (Index == 0)
				{
					cout << "검색 결과 없음!" << endl;
				}
				else
				{
					Indexptr = new int[Index];
					int Index2 = 0;
					for (int i = 0; i < storeDBPtr.size(); i++)
					{
						string Sname;
						storeDBPtr[i]->getSname(Sname);
						if (Sname.find(SearchbyName) != string::npos)//Stype.find(SearchbyType) != string::npos
						{
							Indexptr[Index2] = i;
							Index2++;
							

						}
					}


					int a;
					cout << "->";
					cin >> a;
					if (a > Index)
					{
						cout << "잘못된 입력입니다." << endl;
					}
					else
					{
						for (int i = 0; i < Index2; i++)
						{
							if ((a - 1) == i)
							{
								OrderedStore = storeDBPtr[Indexptr[i]];
							}
						}
						int SLID, ULID;
						OrderedStore->getSID(SLID);
						loginedUser->getLID(ULID);
						int Slat, Slon, Ulat, Ulon;
						for (int i = 0; i < locationDBPtr.size(); i++)
						{
							if (locationDBPtr[i]->locationId == SLID)
							{
								Slat = locationDBPtr[i]->latitude;
								Slon = locationDBPtr[i]->lontitude;

							}
							if (locationDBPtr[i]->locationId == ULID)
							{
								Ulat = locationDBPtr[i]->latitude;
								Ulon = locationDBPtr[i]->lontitude;

							}

						}
						int Distance, AD;
						Distance = (Ulat - Slat)*(Ulat - Slat) + (Ulon - Slon)*(Ulon - Slon);
						AD = OrderedStore->printAD();
						if (Distance > AD)
						{
							cout << "주문이 불가능한 지역입니다." << endl;
						}
						else
						OrderedStore->order(loginedUser);

					}
				}
		}
		if (b == 2)
		{
			cout << "음식점 종류 검색" << endl;
			cout << "종류 : ";
			string SearchbyType;
			cin >> SearchbyType;
			int Index = 0;
			int* Indexptr;
			Store* OrderedStore;
			for (int i = 0; i < storeDBPtr.size(); i++)
			{
				string Stype;
				storeDBPtr[i]->getStype(Stype);
				if (Stype == SearchbyType)
				{
					string Sname;
					Index++;
					storeDBPtr[i]->getSname(Sname);
					cout << Index << ". " << Sname << endl;
				}
			
			}
			if (Index == 0)
			{
				cout << "검색 결과 없음!" << endl;
			}
			else
			{
				Indexptr = new int[Index];
				int Index2 = 0;
				for (int i = 0; i < storeDBPtr.size(); i++)
				{
					string Stype;
					storeDBPtr[i]->getStype(Stype);
					if (Stype == SearchbyType)
					{
						Indexptr[Index2] = i;
						Index2++;
					}
				}
				cout << "--------------------------------" << endl;
				int a;
				cout << "->";
				cin >> a;
				if (a > Index)
				{
					cout << "잘못된 입력입니다" << endl;
				}
				else {
					for (int i = 0; i < Index2; i++)
					{
						if ((a - 1) == i)
						{
							OrderedStore = storeDBPtr[Indexptr[i]];
						}
					}
					int SLID,ULID;
					OrderedStore->getSID(SLID);
					loginedUser->getLID(ULID);
					int Slat, Slon, Ulat, Ulon;
					for (int i = 0; i < locationDBPtr.size(); i++)
					{
						if (locationDBPtr[i]->locationId == SLID)
						{
							Slat = locationDBPtr[i]->latitude;
							Slon = locationDBPtr[i]->lontitude;

						}
						if (locationDBPtr[i]->locationId == ULID)
						{
							Ulat = locationDBPtr[i]->latitude;
							Ulon = locationDBPtr[i]->lontitude;

						}

					}
					int Distance,AD;
					Distance = (Ulat - Slat)*(Ulat - Slat) + (Ulon - Slon)*(Ulon - Slon);
					AD = OrderedStore->printAD();
					if (Distance > AD)
					{
						cout << "주문이 불가능한 지역입니다." << endl;
					}
					else					
					OrderedStore->order(loginedUser);
				}
			}
		}
		if (b == 3)
		{
			int LID,lat,lont;
			loginedUser->printInfo();//손님의 현재 위치는 까지 출력
			loginedUser->getLID(LID);
			for (int i = 0; i < locationDBPtr.size(); i++)
			{
				int getLid;
				getLid = locationDBPtr[i]->locationId;
				if (getLid == LID)
				{
					
					lat = locationDBPtr[i]->latitude;
					lont = locationDBPtr[i]->lontitude;

				}

			}
			cout << "위도 " << lat << ", 경도 " << lont << " 입니다." << endl;
			
			cout << "변경할 위도와 경도 값을 입력해 주세요" << endl;
			cin >> lat >> lont;
			for (int i = 0; i < locationDBPtr.size(); i++)
			{
				int getLid;
				getLid = locationDBPtr[i]->locationId;
				if (getLid == LID)
				{
					locationDBPtr[i]->latitude = lat;
					locationDBPtr[i]->lontitude = lont;
				}

			}
			cout << "위치 정보가 위도 " << lat << " 경도 " << lont << " 로 변경 되었습니다." << endl;
			
		}
		
	/*	if (b == 0)
		{	
			break;
		}*/

	//}//while문 닫는괄호
}
