#include"Processor.h"

Processor::Processor(vector<User*> &userdb, vector<Store*> &storedb, vector<Location*> &locationdb)
{
	userDBPtr = userdb;
	storeDBPtr = storedb;
	locationDBPtr = locationdb;




}
Processor::Processor()
{

}
Processor::~Processor()
{

}