#include "Manager.h"
#include "Client.h"
#include "Location.h"
#include "Chinese.h"
#include "Korean.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#include<string>
#pragma once
class Processor
{
public:
	Processor() ;
	//Processor(User* _userdb, Store* _storedb, Location* locationdb);
	Processor(vector<User*> &userdb, vector<Store*> &storedb, vector<Location*> &locationdb);
	~Processor();

	virtual void processOrder(User* logineduser) = 0;

protected:
	vector<User*> userDBPtr;
	vector<Store*> storeDBPtr;
	vector<Location*> locationDBPtr;
};

