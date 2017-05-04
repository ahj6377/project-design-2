#pragma once
#include "User.h"
class Client :
	public User
{
public:
	Client() {};
	Client(string Id, string Password, int UserType, int LocId, string Name);
	~Client() {};
	void printInfo();
	void getUserInfo(string &Id, string& Password, int &Usertype, int &locId);
	virtual void getCname(string& Name) { Name = name; };
private:
	string name;
	int locationId;
};

