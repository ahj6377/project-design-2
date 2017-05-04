#include "Processor.h"
#pragma once
class ClientProcessor :
	public Processor
{
public:
	ClientProcessor() {};
	ClientProcessor(vector<User*> &userdb, vector<Store*> &storedb, vector<Location*> &locationdb);
	~ClientProcessor() {};
	void processOrder(User* logineduser);
};

