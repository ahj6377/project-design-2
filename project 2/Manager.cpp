#include"Manager.h"

Manager::Manager(string Id, string Password, int UserType, int LocId)
{
	id = Id;
	password = Password;
	userType = UserType;
	storeId = LocId;
	locId = LocId;
}
void Manager::printInfo()
{


}
void Manager::getUserInfo(string &Id, string& Password, int &Usertype, int &locId)
{
	Id = id;
	Password = password;
	Usertype = userType;
	locId = storeId;


}