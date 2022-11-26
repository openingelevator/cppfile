#pragma once
#include<string>
using namespace std;
class commissionEmp
{
public:
	commissionEmp(const string&, const string&,const string &, double = 0.0, double = 0.0);
	void setFirstName(const string&);
	string getFirstName()const;

	void setLastName(const string&);
	string getLastName()const;

	void setSocialNumber(const string&);
	string getSocialNumber()const;

	void setGrossSales(double);
	double getGrossSales()const;

	void setCommissionRate(double);
	double getCommissionRate()const;
	double earning()const;
	void print()const;

protected:
	string firstName;
	string lastName;
	string socialNumber;
	double grossSales;
	double commissionRate;

};