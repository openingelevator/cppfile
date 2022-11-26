#include<vector>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
class Person
{
public:
	Person(string name, double score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	//平均分
	double m_score;
};
void creatPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		double score = 0.0;
		Person temp(name, score);
		v.push_back(temp);
	}
}
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		//排序
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		double averageScore = sum / 1.0 / d.size();

		it->m_score = averageScore;

	}

}
void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手姓名为：" << (*it).m_name << " 平均分为：" << it->m_score << endl;
	}
}
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	//1、创建五名选手
	vector<Person>v;
	creatPerson(v);
	//2、给五名选手打分
	setScore(v);
	//3、显示最后得分
	showScore(v);
	return 0;
}