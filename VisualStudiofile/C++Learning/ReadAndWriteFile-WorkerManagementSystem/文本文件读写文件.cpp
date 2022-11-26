#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void test01()
{
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "姓名：18" << endl;
	ofs.close();
}
void test02()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	//读数据
	//方式一
	/*char buf[1024] = { 0 };
	while (ifs>>buf)
	{
		cout << buf << endl;
	}*/
	//方式二
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	//方式三
	/*string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/
	//方式四
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	ifs.close();
}
int main()
{
	//test01();
	test02();
	return 0;

}