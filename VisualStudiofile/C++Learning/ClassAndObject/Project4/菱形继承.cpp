#include<iostream>
using namespace std;
class animal
{
public:
	int m_Age;
};
//������̳п��Խ�����μ̳�����
//�ڼ̳�֮ǰ���Ϲؼ���virtual��Ϊ��̳�
//animal���Ϊ�����
//���Ϲؼ���virtual��sheepCamel������������̳������Ĳ������������ݣ�����vbptr�������ָ��
//vbptrָ��vbtable��������б��б��м�¼�����ݵ�ַ��ƫ���������Ϻ�����ָ��Ψһһ������
class sheep :virtual public animal{};
class camel :virtual public animal{};
class sheepCamel :public sheep,public camel{};
void test01()
{
	sheepCamel s1;
	s1.sheep::m_Age = 18;
	s1.camel::m_Age = 28;
	//�����μ̳У���������ӵ����ͬ�����ݣ���Ҫ���������������
	cout << "s1.sheep::m_Age =" << s1.sheep::m_Age << endl;
	cout << "s1.camel::m_Age =" << s1.camel::m_Age << endl;
	//���μ̳е������������ݣ������Դ�˷�
	cout << "s1.m_Age=" << s1.m_Age << endl;
}
int main()
{
	test01();
	return 0;
}