#include <string>
#include<iostream>
using namespace std;
#pragma once
class User
{
public:
	User() ;
	~User() ;
	User(string Id, string Password, int UserType, int LocId)
	{
		id = Id; password = Password; userType = UserType; locId = LocId;
	};
	virtual void printInfo() = 0;
	virtual void getUserInfo(string &Id, string& Password, int &Usertype, int &locId) = 0;
	virtual void getCname(string& Name) {};
	void getId(string& ID);
	void getUT(int &UT);
	void getPW(string &PW);
	void getLID(int &Lid);
protected:
	string id;
	string password;
	int userType;
	int locId; //Client�� locId�� �����̼� ������ ��Ÿ���� Manager�� LocId�� ������ LocId�� ���ÿ� ������ Id�̴�
};

