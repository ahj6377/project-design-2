#include "User.h"
#pragma once
class Manager :
	public User
{
public:
	Manager() {};
	Manager(string Id, string Password, int UserType, int LocId);
	~Manager() {};
	void printInfo();
	void getUserInfo(string &Id, string& Password, int &Usertype, int &locId);
	void getCname(string& Name) {};
private:
	int storeId;
};

