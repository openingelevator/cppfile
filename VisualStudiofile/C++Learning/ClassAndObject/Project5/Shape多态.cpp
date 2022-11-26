#include<iostream>
using namespace std;
class Shape
{
public:
	virtual float square() = 0;
};
class rectangular :public Shape
{
public:
	rectangular(float width,float height):m_width(width),m_height(height)
	{

	}
	virtual float square()
	{
		return m_width * m_height;
	}
private:
	float m_width;
	float m_height;
};
class circle :public Shape
{
public:
	circle(float r):m_R(r)
	{

	}
	virtual float square()
	{
		return 3.14 * m_R * m_R;
	}

private:
	float m_R;
};
void test()
{
	Shape *s1 = new rectangular(3, 4);
	Shape* s2 = new circle(5);
	cout << "矩形的面积为：" << s1->square() << endl;
	cout << "圆的面积为：" << s2->square() << endl;
	delete s1;
	delete s2;
}
int main()
{
	test();
	return 0;
}