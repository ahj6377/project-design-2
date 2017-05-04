#include"Client.h"

Client::Client(string Id, string Password, int UserType, int LocId,string Name)
{
	id = Id;
	password = Password;
	userType = UserType;
	locId = LocId;
	locationId = locId;
	name = Name;
}
void Client::printInfo()
{
	cout << "location ID : " << locationId << endl;
	cout << "현재" << name << "님의 위치는" << endl;
	



}
void Client::getUserInfo(string &Id, string& Password, int &Usertype, int &locId)
{
	Id = id;
	Password = password;
	Usertype = userType;
	locId = locationId;

}