#include<iostream>
#include"employee.h"
using namespace std;
Employee::Employee(const string& s1, const string& s2,const string&s3):
	firstName(s1),lastName(s2),socialNumber(s3)
{

}
void Employee::setFirstName(const string& first)
{
	firstName = first;
}
void Employee::setLastName(const string& last)
{
	lastName = last;
}
void Employee::setSocialNumber(const string&ssn)
{
	socialNumber = ssn;
}
string Employee::getFirstName()const
{
	return  firstName;
}
string Employee::getLastName()const
{
	return lastName;
}
string Employee::getSocialNumber()const
{
	return socialNumber;
}
void Employee::print()const
{
	cout << getFirstName() << " " << getLastName()
		<< "\nsocial security number :" << getSocialNumber();
}