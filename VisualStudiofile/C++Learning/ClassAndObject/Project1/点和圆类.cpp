//设计点与圆类，计算点和圆的关系
#include<iostream>
using namespace std;
class Point
{
public:
	void setX(int x)
	{
		m_x = x;
	}
	int getX()
	{
		return m_x;
	}
	void setY(int y)
	{
		m_y = y;
	}
	int getY()
	{
		return m_y;
	}

private:
	int m_x;
	int m_y;
};
class Circle
{
public:
	void setR(int r)
	{
		m_r = r;
	}
	int getR()
	{
		return m_r;
	}
	void setCenter(Point C)
	{
		center = C;
	}
	Point getCenter()
	{
		return center;
	}

private:
	//圆的半径
	int m_r;
	//圆心
	Point center;
};
void isinCircle(Circle& c, Point& p)
{
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX())
		- (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rdistance = c.getR() * c.getR();
	if (distance == rdistance)
	{
		cout << "点在圆上";
	}
	else if(distance > rdistance)
	{
		cout << "点在圆外";
	}
	else 
	{
		cout << "点在圆内";
     }
}
int main()
{
	Circle m;
	Point p,circlep;
	p.setX(10);
	p.setY(0);
	circlep.setX(0);
	circlep.setY(0);
	m.setCenter(circlep);
	m.setR(10);
	isinCircle(m, p);
	return 0;
}