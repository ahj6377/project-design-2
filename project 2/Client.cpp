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
	cout << "����" << name << "���� ��ġ��" << endl;
	



}
void Client::getUserInfo(string &Id, string& Password, int &Usertype, int &locId)
{
	Id = id;
	Password = password;
	Usertype = userType;
	locId = locationId;

}