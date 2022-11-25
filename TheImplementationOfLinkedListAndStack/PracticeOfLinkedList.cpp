#include<iostream>
#include<stack>
using namespace std;

class Node
{
public:
	Node(int hno)
		:num(hno), next(nullptr)
	{
	}
	int num;
	Node* next;
};
class SingleLinkedList
{
private:
	Node* head = new Node(0);
public:
	Node* getHead()
	{
		return head;
	}

	//�ϲ�������������
	Node* mergeList(Node* anotherHead)
	{
		Node* temp = anotherHead->next;
		Node* rear = nullptr;
		while (temp != nullptr)
		{
			rear = temp->next;
			this->addNode(temp);
			temp = rear;
		}
		return this->head;
	}

	void addNode(Node* node)
	{
		Node* temp = head;
		bool flag = false;
		while (true)
		{
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
			temp->next = node;
		}
	}
	void deleteNode(int index)
	{
		//�ж������Ƿ�Ϊ��
		if (head->next == nullptr)
		{
			cout << "����Ϊ��" << endl;
		}
		Node* temp = head;
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
			Node* node = temp->next;
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
		if (head->next == nullptr)
		{
			cout << "����Ϊ��" << endl;
			return;
		}
		Node* temp = head->next;
		while (true)
		{
			//�ж��Ƿ��������
			if (temp == nullptr)
			{
				break;
			}
			//����ڵ���Ϣ
			cout << temp->num << " ";
			temp = temp->next;
		}
	}
};
//��ȡ������Ч���ĸ���
int getLength(Node* head)
{
	if (head->next == nullptr)//������
	{
		return 0;
	}
	int length = 0;
	//��ͳ��ͷ�ڵ�
	Node* cur = head->next;
	while (true)
	{
		if (cur == nullptr)
		{
			break;
		}
		cur = cur->next;
		length++;
	}
	return length;
}
//���ҵ������еĵ�����k���ڵ�
int searchNode(Node* head, int k)
{
	if (head->next == nullptr)
	{
		//����Ϊ��
		return -1;
	}
	int len = getLength(head);
	int index = len - k;
	if (index<0||index>=len)
	{
		cout << "������k���ڵ�Խ��" << endl;
		return -1;
	}
	Node* temp = head;
	while (index >=0)
	{
		temp = temp->next;
		index--;
	}
	return temp->num;
}
//������ķ�ת
void reverseList(Node* head)
{
	if (head->next == nullptr||head->next->next==nullptr)
	{
		//����Ϊ�ջ���ֻ��һ���ڵ㣬���跴ת
		return;
	}
	//���帨������������ԭ��������
	Node* cur = head->next;
	//ָ��ǰ������һ���ڵ�
	Node* rear =nullptr;
	Node* reverseHead = new Node(0);
	while (true)
	{
		if (cur== nullptr)
		{
			break;
		}
		rear = cur->next;//��ʱ����cur��һ���ڵ�ĵ�ַ
		cur->next = reverseHead->next;//��cur����һ���ڵ�ָ���������ͷ�ڵ�
		reverseHead->next = cur;
		cur = rear;
	}
	head->next = reverseHead->next;
}
Node* reverseKGroup(Node* head, int k) {
	Node* preNode = new Node(0);
	preNode->next = head;
	Node* ktail = preNode->next;
	//������ֻ��һ���ڵ㣬���跴ת
	if (head->next == nullptr)
	{
		return head;
	}
	Node* reverseNode = new Node(0);
	Node* tempHead = reverseNode;
	Node* cur = preNode->next;
	Node* rear = nullptr;
	while (ktail!= nullptr)
	{
		int count = 0;
		for (int i = 0; i < k && ktail != nullptr; i++)
		{
			ktail = ktail->next;
			count++;
		}
		if (count  < k)
		{
			tempHead->next = cur;
			break;
		}
		for (int i = 0; i < k && cur != nullptr; i++)
		{
			rear = cur->next;//��ʱ����cur��һ���ڵ�ĵ�ַ
			cur->next = tempHead->next;//��cur����һ���ڵ�ָ���������ͷ�ڵ�
			tempHead->next = cur;
			cur = rear;
		}
		for (int i = 0; i < k && tempHead != nullptr; i++)
		{
			tempHead = tempHead->next;
		}
	}
	return reverseNode->next;
}
//�����ӡ����
void reversePrint(Node* head)
{
	//��ʽһ�Ƚ���������з�ת֮���ٱ���
	//��ʽ������ջ�����ݽṹ���������ڵ�ѹ�뵽ջ�У�Ȼ������ջ�Ƚ�������ص㣬ʵ�������ӡ��Ч��
	if (head->next == nullptr)
	{
		return;
	}
	//����һ��ջ���������ڵ�ѹ��ջ
	stack<Node*>nodeContain;
	Node* temp = head->next;
	while (temp != nullptr)
	{
		nodeContain.push(temp);
		temp = temp->next;
	}
	//��ջ�еĽڵ���д�ӡ
	while (nodeContain.size() > 0)
	{
		cout << nodeContain.top()->num << " ";
		nodeContain.pop();
	}
}
int main()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	SingleLinkedList list;
	list.addNode(n1);
	list.addNode(n2);
	list.addNode(n3);
	list.addNode(n4);
	list.addNode(n5);
	//cout << "��תǰ������" << endl;
	//list.showList();
	//cout << endl;
	////reverseList(list.getHead());

	////cout << "��ת�������" << endl;
	////list.showList();
	////cout << endl;
	////cout << getLength(list.getHead()) << endl;
	////cout << "������3���ڵ������Ϊ��" << searchNode(list.getHead(), 3);
	////cout << "�����ӡ�Ľ��Ϊ" << endl;
	////reversePrint(list.getHead());

	//Node* n5 = new Node(4);
	//Node* n6 = new Node(9);
	//Node* n7 = new Node(8);
	//SingleLinkedList newList;
	//newList.addNode(n5);
	//newList.addNode(n6);
	//newList.addNode(n7);
	//newList.showList();
	//cout << endl;

	//list.mergeList(newList.getHead());
	//cout << "�ϲ��������" << endl;
	//list.showList();
	reverseKGroup(list.getHead(), 2);
	system("pause");
	return 0;
}