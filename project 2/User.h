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
	int locId; //Client의 locId는 로케이션 정보를 나타내고 Manager의 LocId는 가게의 LocId인 동시에 가게의 Id이다
};

