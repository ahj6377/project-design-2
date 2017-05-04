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
		cout << "�� �޴�" << endl;
		cout << "--------------------------------" << endl;
		cout << Uname << "��" << endl;
		cout << "--------------------------------" << endl;
		cout << "1. ������ �̸��� �˻�" << endl;
		cout << "2. ������ ������ �˻�" << endl;
		cout << "3. ��ġ ���� ����" << endl;
		cout << "--------------------------------" << endl;
		int b;
		cin >> b;
		if (cin.fail())			//������ ������ �ƴ� ���� ���������� ����ó��
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			//continue;
		}
		if (b == 1)
		{
			cout << "������ �̸� �˻�" << endl;
			cout << "�̸� : ";
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
					cout << "�˻� ��� ����!" << endl;
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
						cout << "�߸��� �Է��Դϴ�." << endl;
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
							cout << "�ֹ��� �Ұ����� �����Դϴ�." << endl;
						}
						else
						OrderedStore->order(loginedUser);

					}
				}
		}
		if (b == 2)
		{
			cout << "������ ���� �˻�" << endl;
			cout << "���� : ";
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
				cout << "�˻� ��� ����!" << endl;
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
					cout << "�߸��� �Է��Դϴ�" << endl;
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
						cout << "�ֹ��� �Ұ����� �����Դϴ�." << endl;
					}
					else					
					OrderedStore->order(loginedUser);
				}
			}
		}
		if (b == 3)
		{
			int LID,lat,lont;
			loginedUser->printInfo();//�մ��� ���� ��ġ�� ���� ���
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
			cout << "���� " << lat << ", �浵 " << lont << " �Դϴ�." << endl;
			
			cout << "������ ������ �浵 ���� �Է��� �ּ���" << endl;
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
			cout << "��ġ ������ ���� " << lat << " �浵 " << lont << " �� ���� �Ǿ����ϴ�." << endl;
			
		}
		
	/*	if (b == 0)
		{	
			break;
		}*/

	//}//while�� �ݴ°�ȣ
}
