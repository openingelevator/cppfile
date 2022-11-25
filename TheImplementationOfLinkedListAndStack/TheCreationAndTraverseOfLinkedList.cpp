#include<iostream>
#include<string>
using namespace std;
//�������Խڵ�ķ�ʽ�洢�ģ�ÿ���ڵ����data��next��ָ����һ���ڵ�
//����ĸ����ڵ㲻һ����������ŵ�
//����ִ�ͷ�ڵ�������벻��ͷ�ڵ������

class HeroNode
{
public:
	HeroNode(int hno,string hName,string hNickName)
		:num(hno),name(hName),nickName(hNickName),next(NULL)
	{
	
	}
	void printInfo()
	{
		cout << "HeroNode num=" << num << " name=" << name << " nickName=" << nickName << endl;
	}
	//Ӣ�۱��
	int num;
	//Ӣ������
	string name;
	//Ӣ�۴º�
	string nickName;
	HeroNode* next;
};
//����SingleLinkedList ������hero
class SingleLinkedList
{
private:
	//�ȳ�ʼ��ͷ�ڵ�
	HeroNode* head = new HeroNode(0, "", "");
public:
	//���
    //�ȴ���һ��ͷ�ڵ㣬���þ��ǵ������ͷ
    //����ÿ���һ���ڵ㣬��ֱ�Ӽ��뵽��������
	void addNode(HeroNode* node)//�˴�����Ľڵ����������ָ������õķ�ʽ���ݣ�����ֵ��temp�ĵ�ַ�ǿ��������Ľڵ�ĵ�ַ
	{
		//�����Ǳ��˳��ʱ
		HeroNode* temp = head;
		//�ҵ���������һ���ڵ�
		while (true)
		{
			//�ҵ���������
			if (temp->next == NULL)
			{
				break;
			}
			//δ�ҵ�����������temp����
			temp = temp->next;
		}
	    //Ȼ�����ڵ��next��ָ���µĽڵ�
		temp->next = node;
	}
	//��ʾ����
	void showList()
	{
		//�ж������Ƿ�Ϊ��
		if (head->next == NULL)
		{
			cout << "����Ϊ��" << endl;
			return;
		}
		//������ͨ������������������
		HeroNode* temp = head->next;
		while (true)
		{
			//�ж��Ƿ��������
			if (temp == NULL)
			{
				break;
			}
			//����ڵ���Ϣ
			temp->printInfo();
			temp = temp->next;
		}
	}

};
int main()
{
	SingleLinkedList list;
	HeroNode* node1=new HeroNode(1, "�ν�", "��ʱ��");
	HeroNode* node2=new HeroNode(2, "¬����", "������");
	HeroNode* node3 = new HeroNode(3, "����", "�Ƕ���");
	list.addNode(node1);
	list.addNode(node2);
	list.addNode(node3);
	list.showList();
	system("pause");
	return 0;
}