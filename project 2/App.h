#pragma once
#include "Processor.h"
#include<vector>
#include<algorithm>
using namespace std;
class App
{
public:
	App();
	~App();

	void run();

private:
	vector<User*> users;
	vector<Store*> stores;
	vector<Location*> locations;

	User* loginedUser;
	Processor* pc;
	int Unum,Snum,Lnum;

};

