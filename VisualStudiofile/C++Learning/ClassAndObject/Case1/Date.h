#pragma once
#include<string>
class Date
{
public:
	const static int monthsPerYear = 12; 
	Date(int  , int , int  ); 
	Date(int,int);
	Date(std::string, int, int);
	Date(const Date&);
	void print1() const; 
	void print2()const;
	void print3(std::string)const;
	~Date(); 
private:
	int month; 
	int day; 
	int year; 
	int checkDay(int) const;
}; 
