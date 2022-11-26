#pragma once
#include<iostream>
#include<string>
using namespace std;
class Employee
{
public:
	Employee(const string&s1, const string&s2,const string&s3);
	void setFirstName(const string&first);
	string getFirstName()const;

	void setLastName(const string&last);
	string getLastName()const;

	void setSocialNumber(const string&ssn);
	string getSocialNumber()const;
	virtual double earning()const =0;
	virtual void print()const;
private:
	string firstName;
	string lastName;
	string socialNumber;
};