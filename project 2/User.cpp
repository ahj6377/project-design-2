#include"User.h"

void User::getId(string& ID)
{
	ID = id;

}
void User::getPW(string& PW)
{
	PW = password;
}
void User::getUT(int& UT)
{
	UT = userType;
}
void User::getLID(int& Lid)
{

	Lid = locId;
}
User::User()
{
	id = "";
	password = "";
	userType = 0;
	locId = 0;


}
User::~User()
{

}
