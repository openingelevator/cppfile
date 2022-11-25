#include<iostream>
#include<string>
using namespace std;

class HeroNode
{
public:
	HeroNode(int hno, string hName, string hNickName)
		:num(hno), name(hName), nickName(hNickName), next(nullptr)
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
	//����˳�����
	//����ͨ������������ָ�룩�ҵ�����ӽڵ��λ��
	//�µĽڵ�->next=temp->next
	//��temp->next=�µĽڵ�
	void addNode(HeroNode* node)
	{
		//��Ϊ����������tempλ�����λ�õ�ǰһ���ڵ�
		HeroNode* temp = head;
		//��ʶ��ӵı���Ƿ����
		bool flag = false;
		while (true)
		{
			//˵��temp�Ѿ�����������
			if (temp->next == nullptr)
			{
				break;
			}
			else if (temp->next->num>node->num)
			{
				break;
			}
			else if (temp->next->num==node->num)
			{
				//����Ѵ���
				flag = true;
				break;
			}
			temp = temp->next;
		}

		if (flag == true)
		{
			cout << "׼������Ľڵ����Ѵ��ڣ��޷��������" << endl;
		}
		else
		{
			//���뵽������
			node->next = temp->next;
			temp->next = node;
		}
	}
	//�޸Ľڵ���Ϣ
	void update(HeroNode* newNode)
	{
		//�ж������Ƿ�Ϊ��
		if (head->next == nullptr)
		{
			cout << "����Ϊ��" << endl;
		}
		//��Ϊ�����ҵ���Ҫ�޸ĵĽڵ�
		HeroNode* temp = head->next;
		//��ʾ�Ƿ��ҵ��ڵ�
		bool flag = false;
		while (true)
		{
			if (temp == nullptr)//��ʾ�Ѿ�����������
			{
				break;
			}
			if (temp->num == newNode->num)
			{
				//�ҵ���Ҫ�޸ĵĽڵ�
				flag = true;
				break;
			}
			temp = temp->next;
		}
		//��ʾδ�ҵ��ڵ�
		if (flag == false)
		{
			cout << "û���ҵ����Ϊ" << newNode->num << "�Ľڵ�" << endl;
		}
		else
		{
			temp->name = newNode->name;
			temp->nickName = newNode->nickName;
		}
	}
	//ɾ���ڵ�
	//�ҵ���ɾ���ڵ��ǰ��temp
	//temp->next=temp->next->next
	//delete ��ɾ���ڵ�
	void deleteNode(int index)
	{
		//�ж������Ƿ�Ϊ��
		if (head->next == nullptr)
		{
			cout << "����Ϊ��" << endl;
		}
		HeroNode* temp = head;
		bool flag = false;//��ʶ�ڵ��Ƿ��ҵ�
		while (true)
		{
			if (temp->next == nullptr)
			{
				break;
			}
			if (temp->next->num == index)
			{
				flag = true;
				break;
			}
			temp = temp->next;
		}
		if (flag)
		{
			HeroNode* node = temp->next;
			temp->next = temp->next->next;
			delete node;
		}
		else
		{
			cout << "δ�ҵ���ɾ���Ľڵ�" << endl;
		}

	}

	//��ʾ����
	void showList()
	{
		//�ж������Ƿ�Ϊ��
		if (head->next == nullptr)
		{
			cout << "����Ϊ��" << endl;
			return;
		}
		//������ͨ������������������
		HeroNode* temp = head->next;
		while (true)
		{
			//�ж��Ƿ��������
			if (temp == nullptr)
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
	HeroNode* node1 = new HeroNode(1, "�ν�", "��ʱ��");
	HeroNode* node2 = new HeroNode(2, "¬����", "������");
	HeroNode* node3 = new HeroNode(3, "����", "�Ƕ���");
	HeroNode* node4 = new HeroNode(4, "�ֳ�", "����ͷ");

	list.addNode(node1);
	list.addNode(node4);
	list.addNode(node3);
	list.addNode(node2);

	cout << "�޸�ǰ���������" << endl;
	list.showList();
	cout << "�޸ĺ���������" << endl;
	//�����޸Ľ��Ĵ���
	//HeroNode* node5 = new HeroNode(2, "С¬", "������~~");
	//list.update(node5);
	list.deleteNode(4);
	list.showList();
	system("pause");
	return 0;
}