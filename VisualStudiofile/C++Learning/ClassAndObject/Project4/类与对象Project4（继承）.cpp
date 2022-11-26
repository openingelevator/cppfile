﻿#include <iostream>
using namespace std;
//普通实现页面

////Java页面
//class Java
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、python、c++...（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	}
//
//};
////python页面
//class Python
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java、python、c++...（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};


//继承方法实现
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
	}
	void left()
	{
		cout << "Java、python、c++...（公共分类列表）" << endl;
	}
};
class Java :public BasePage
{
public:

	void content()
	{
			cout << "Java学科视频" << endl;
		}
};
class Python:public BasePage
{
public:

	void content()
	{
		cout << "Python学科视频" << endl;
	}
};

void test01()
{
	cout << "Java下载视频页面如下：" << endl;
	Java j1;
	j1.header();
	j1.footer();
	j1.left();
	j1.content();

	cout << "-----------------------" << endl;
	cout << "Python下载页面如下：" << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
}
int main()
{

	test01();
	return 0;
}

