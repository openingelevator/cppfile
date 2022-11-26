#include<iostream>
#include"commission.h"
#include<string>
using namespace std;
commissionEmp::commissionEmp(const string& first, const string& last, const string& ssn,
	double sales, double rate)
{
	firstName = first;
	lastName = last;
	socialNumber = ssn;
	grossSales = sales;
	commissionRate = rate;
}
void commissionEmp::setFirstName(const string& first)
{
	firstName = first;
}
string commissionEmp::getFirstName()const
{
	return firstName;
}

void commissionEmp::setLastName(const string& last)
{
	lastName = last;
}
string commissionEmp::getLastName()const
{
	return lastName;
}

void commissionEmp::setSocialNumber(const string& ssn)
{
	socialNumber = ssn;
}
string commissionEmp::getSocialNumber()const
{
	return socialNumber;
}

void commissionEmp::setGrossSales(double sales)
{
	grossSales = (sales<0.0)?0.0:sales;
}
double commissionEmp::getGrossSales()const
{
	return grossSales;
}

void commissionEmp::setCommissionRate(double rate)
{
	commissionRate = (rate>0.0&&rate<1.0)?rate:0.0;
}
double commissionEmp::getCommissionRate()const
{
	return commissionRate;
}
double commissionEmp::earning()const
{
	return grossSales * commissionRate;
}
void commissionEmp::print()const
{
	cout << "commission employee " << firstName << "  " << lastName
		<< "\nsocialSecurityNumber " << socialNumber
		<< "\ngrossSales " << grossSales
		<< "\ncommissionRate " << commissionRate;
}
