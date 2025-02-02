#include "Header.hpp"

Person::Person()
{
	name = "";
	id = 0;
	email = "";
	bday = "";
}

Person::~Person() {}


void Person::setFname(string n)
{
	fname = n;
}

void Person::setLname(string n)
{
	lname = n;
}


void Person::setgender(char g)
{
	gender = g;
}

void Person::setName()
{
	name = getFname() + " " + getLname();
}

void Person::setID(int i)
{
	id = i;
}

void Person::setEmail(string e)
{
	email = e;
}

void Person::setBday(string b)
{
	bday = b;
}
void Person::setContactNum(string c)
{
	contactNum = c;
}

char Person::getGender()
{
	return gender;
}

string Person::getFname()
{
	return fname;
}

string Person::getLname()
{
	return lname;
}

string Person::getName()
{
	return name;
}

int Person::getID()
{
	return id;
}

string Person::getEmail()
{
	return email;
}

string Person::getBday()
{
	return bday;
}

string Person::getContactNum()
{
	return contactNum;
}