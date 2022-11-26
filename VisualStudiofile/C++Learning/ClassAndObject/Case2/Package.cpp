#include<string>
#include<iostream>
#include"Package.h"
using namespace std;
Package::Package(string sName, string rName, string s_address, string r_address,string code ,double weight, double fee)
	:senderName(sName), receiverName(rName), m_address1(s_address),m_address2(r_address),zipCode(code), m_weight(weight > 0 ? weight : 0)
	, feePerOunce(fee > 0 ? fee : 0)
{

}
double Package::calculateCost()
{
	return m_weight * feePerOunce;
}
string Package::getSenderAddress()
{
	return m_address1;
}
string Package::getReceiverAddress()
{
	return m_address2;
}
TwoDayPackage::TwoDayPackage(string sName, string rName, string s_address, string r_address, string code,double weight, double fee, double averagePay)
	: Package(sName, rName, s_address,r_address, code,weight,fee)
{
	m_averagePay = averagePay;
}
double TwoDayPackage::calculateCost()
{
	return m_averagePay + Package::calculateCost();
}
OvernightPackage::OvernightPackage(string sName, string rName, string s_address, string r_address,string code, double weight, double fee, double extraPay)
	: Package(sName, rName, s_address,r_address,code, weight, fee)
{
	m_extraPay = extraPay;
}
double OvernightPackage::calculateCost()
{
	return m_weight*(m_extraPay+feePerOunce);
}