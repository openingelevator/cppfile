#include"employee.h"
#include<iostream>
using namespace std;
class PieceWorker:public Employee
{
public:
	PieceWorker(const string& first, const string& last, const string& ssn, double piecewage = 0.0, int piece = 0)
		:Employee(first, last, ssn)
	{
		m_piece = piece;
		m_wage = piecewage;
	}
	int getPiece()const
	{
		return m_piece;
	}
	double getPieceWage()const
	{
		return m_wage;
	}
	virtual double earning()const
	{
		return getPiece() * getPieceWage();
	}
	void print()const
	{
		cout << "Piece employee" << endl;
		Employee::print();
		cout << "\npiece wages" << getPieceWage() << "\npieces worked" << getPiece() << endl;
	}
private:
	double m_wage;
	int m_piece;
};
class HourlyWorker :public Employee
{
public:
	HourlyWorker(const string& first, const string& last, const string& ssn, double hourlywage = 0.0, int hours = 0)
		:Employee(first, last, ssn)
	{
		m_hours = hours;
		m_hourlywage = hourlywage;
	}
	int getHour()const
	{
		return m_hours;
	}
	double getHourlyWage()const
	{
		return m_hourlywage;
	}
	virtual double earning()const
	{
		if (this->m_hours <= 40)return getHour() * getHourlyWage();
		else
			return 40 * getHourlyWage() + ((getHour() - 40) * getHourlyWage() * 1, 5);
	}
	void print()const
	{
		cout << "Hourly employee" << endl;
		Employee::print();
		cout << "\nhourly wages" << getHourlyWage() << "\nhours worked" << getHour() << endl;
	}
private:
	int m_hours;
	double m_hourlywage;
};
int main()
{
	Employee* p1 = new HourlyWorker("Mike","Jones","1784",18.3,50);
	p1->print();
	cout << "该职工的收入为：" << endl;
	cout << p1->earning() << endl;
	Employee* p2 = new PieceWorker("Tom", "Bill", "1145", 12.5, 70);
	p2->print();
	cout << "该职工的收入为：" << endl;
	cout << p2->earning() << endl;
	delete p1;
	delete p2;
	return 0;

}