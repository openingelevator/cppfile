#include<iostream>
using namespace std;
//˫�����������ǰ����������
//��������������ɾ������Ҫ���������ڵ㣬��˫�����������ʵ������ɾ��
//������ʽ�뵥����һ�£�������ǰ���ң�Ҳ����������
//��ӣ�Ĭ����ӵ�˫����������
//��1�����ҵ�˫����������һ���ڵ�
//��2��temp->next=newNode; newNode->pre=temp;
//�޸�˼·�뵥������һ��
//ɾ����ֱ���ҵ���ɾ���ڵ㼴�ɣ�
//temp->pre->next=temp->next; temp->next->pre=temp->pre;

class HeroNode
{
public:
	HeroNode(int hno, string hName, string hNickName)
		:num(hno), name(hName), nickName(hNickName), next(NULL),pre(NULL)
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
	HeroNode* next;//ָ����һ���ڵ�
	HeroNode* pre;//ָ��ǰһ���ڵ�
};

class DoubleLinkedList
{
private:
	//�ȳ�ʼ��ͷ�ڵ�
	HeroNode* head = new HeroNode(0, "", "");
public:
	//����ͷ�ڵ�
	HeroNode* getHead()
	{
		return head;
	}
	//���
	void addNode(HeroNode* node)
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
		//�����½ڵ��pre��ָ��ǰһ���ڵ�
		node->pre = temp;
	}
	void addNodeByOrder(HeroNode* node)
	{
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
			else if (temp->next->num > node->num)
			{
				break;
			}
			else if (temp->next->num == node->num)
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
			if (temp->next != nullptr)
			{
				temp->next->pre = node;
			}
			temp->next = node;
			node->pre = temp;
		}
	}

	//�޸�һ���ڵ������
	void update(HeroNode* newNode)
	{
		//�ж������Ƿ�Ϊ��
		if (head->next == nullptr)
		{
			cout << "����Ϊ��" << endl;
			return;
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
	//ɾ��
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
			if (temp== nullptr)
			{
				break;
			}
			if (temp->num == index)
			{
				flag = true;
				break;
			}
			temp = temp->next;
		}
		if (flag)
		{
			temp->pre->next = temp->next; 
			//�˴���Ҫ����ɾ���Ľڵ�Ϊ���һ���ڵ�����
			if (temp->next != nullptr)
			{
				temp->next->pre = temp->pre;
			}
			delete temp;
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
	HeroNode* node1 = new HeroNode(1, "�ν�", "��ʱ��");
	HeroNode* node2 = new HeroNode(2, "¬����", "������");
	HeroNode* node3 = new HeroNode(3, "����", "�Ƕ���");
	HeroNode* node4 = new HeroNode(4, "�ֳ�", "����ͷ");

	cout << "˫���������" << endl;
	//����һ��˫������
	//DoubleLinkedList* list=new DoubleLinkedList();
	//list->addNode(node1);
	//list->addNode(node2);
	//list->addNode(node3);
	//list->addNode(node4);
	//cout << "�޸�ǰ������" << endl;
	//list->showList();
	////�޸�
	//HeroNode* node5 = new HeroNode(4, "����ʤ", "������");
	//list->update(node5);
	//cout << "�޸ĺ������" << endl;
	//list->showList();
	////ɾ��
	//list->deleteNode(3);
	//cout << "ɾ���ڵ�������" << endl;
	//list->showList();

	DoubleLinkedList* list2 = new DoubleLinkedList();
	cout << "��˳�򴴽�˫������" << endl;
	list2->addNodeByOrder(node1);
	list2->addNodeByOrder(node2);
	list2->addNodeByOrder(node3);
	list2->addNodeByOrder(node4);
	list2->showList();
	system("pause");
	
	return 0;
}