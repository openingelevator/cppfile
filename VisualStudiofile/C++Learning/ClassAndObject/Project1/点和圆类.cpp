//��Ƶ���Բ�࣬������Բ�Ĺ�ϵ
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
	//Բ�İ뾶
	int m_r;
	//Բ��
	Point center;
};
void isinCircle(Circle& c, Point& p)
{
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX())
		- (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rdistance = c.getR() * c.getR();
	if (distance == rdistance)
	{
		cout << "����Բ��";
	}
	else if(distance > rdistance)
	{
		cout << "����Բ��";
	}
	else 
	{
		cout << "����Բ��";
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