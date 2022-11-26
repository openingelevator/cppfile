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
	//ƽ����
	double m_score;
};
void creatPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
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
		//����
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
		cout << "ѡ������Ϊ��" << (*it).m_name << " ƽ����Ϊ��" << it->m_score << endl;
	}
}
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	//1����������ѡ��
	vector<Person>v;
	creatPerson(v);
	//2��������ѡ�ִ��
	setScore(v);
	//3����ʾ���÷�
	showScore(v);
	return 0;
}