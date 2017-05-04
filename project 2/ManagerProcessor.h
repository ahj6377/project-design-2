#include "Processor.h"
#pragma once
class ManagerProcessor :
	public Processor
{
public:
	ManagerProcessor() {};
	ManagerProcessor(vector<User*> &userdb, vector<Store*> &storedb, vector<Location*> &locationdb);
	~ManagerProcessor() {};
	void processOrder(User* logineduser);
};

