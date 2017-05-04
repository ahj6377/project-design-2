#include "Order.h"
#include<list>
#include<algorithm>
#include<vector>
#include<iostream>
#include"User.h"
using namespace std;
#pragma once
class Store
{
public:
	Store() ;
	~Store() ;

	virtual void order(User* loginedUser) = 0;
	virtual int calculateDeliverTime(int userLat, int userLon, int storeLat, int storeLon) = 0;
	void getStoreInfo(int& Sid,int& aD, string& Storename, string& Storetype);
	void getStype(string& Storetype)
	{
		Storetype = storeType;
	};
	void getSname(string& Storename)
	{
		Storename = storeName;
	};
	void getSID(int& Sid)
	{
		Sid = storeId;
	};
	void printOrderedMenu(string& returnName);
	int printAD()
	{
		return availableDistance;
	};
	void changeAD(int AD)
	{
		availableDistance = AD;
	};
protected:
	int storeId;
	int availableDistance;
	string storeName;
	string storeType;
	vector<Order> recievedOrder;
};

