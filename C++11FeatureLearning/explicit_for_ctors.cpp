#include<iostream>
using namespace std;

class P
{
public:
	P(int a, int b)
	{
		cout << "P(int a, int b)\n";
	}
	P(initializer_list<int>)
	{
		cout << "P(initializer_list<int>)\n";
	}
	//explicit for constructor taking more than one argument
	explicit P(int a, int b, int c)
	{
		cout << "explicit P(int a, int b, int c)\n" ;
	}

};
void fp(const P& p) {

}
class Complex
{
	friend ostream& operator<<(ostream& out,const Complex&c);
public:
	explicit Complex(int re, int im=0):real(re),imag(im)
	{

	}
	Complex operator+(const Complex& x)
	{
		return Complex((real + x.real), (imag + x.imag));
	}
private:
	int real;
	int imag;

};
ostream& operator<<(ostream& out, const Complex& c)
{
	out << c.real << "+" << c.imag << "i";
	return out;
}
void test01()
{
	Complex c1(12, 5);
	//when the keyword explict for constructor is called, the expression Complex c2=c1+5; is not allowed
	//Complex c2 = c1 + 5;
	Complex c2 = c1 + Complex(5);
	cout << c1 << endl;
	cout << c2 << endl;
}
void test02()
{
	P p1(1, 2);
	P p2{ 1,2 };
	P p3{ 1,2,3 };
	P p4 = { 1,2 };
	P p5 = { 1,2,3 };
	P p6(1, 2, 3);
	cout << endl;
	fp({ 1,2,3 });
	fp({ 1,2 });
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}