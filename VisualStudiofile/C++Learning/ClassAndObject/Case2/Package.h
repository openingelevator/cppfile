#pragma once
#include<iostream>
#include<string>
using namespace std;
class Package
{
public:
	Package(string sName, string rName, string s_address,string r_address,string code, double weight, double fee);
	virtual double calculateCost();
	string getSenderAddress();
	string getReceiverAddress();
protected:
	string senderName;
	string receiverName;
	string m_address1;
	string m_address2;
	string zipCode;
	double m_weight;
	double feePerOunce;
};
class TwoDayPackage:public Package
{
public:
	TwoDayPackage(string sName, string rName, string s_address, string r_address,string code, double weight, double fee,double averagePay);
	double calculateCost();
private:
	double m_averagePay;

};
class OvernightPackage:public Package
{
public:
	OvernightPackage(string sName, string rName, string s_address, string r_address,string code, double weight, double fee, double extraPay);
	double calculateCost();
private:
	double m_extraPay;

};