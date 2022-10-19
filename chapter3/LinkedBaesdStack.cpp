#include <iostream>
using namespace std;

class Node
{
public:
	Node(int num) : data(num), next(nullptr)
	{
	}
	int data;
	Node *next;
};
class LinkedListStack
{
public:
	LinkedListStack(int Size) : top(-1), maxSize(Size), head(nullptr)
	{
	}
	//ջ��
	bool isFull()
	{
		return top == maxSize - 1;
	}
	//ջ��
	bool isEmpty()
	{
		return top == -1;
	}
	//��ջ
	void push(int val)
	{
		//�ж�ջ�Ƿ���
		if (isFull())
		{
			cout << "ջ����" << endl;
			return;
		}
		//�ж�ͷָ���Ƿ�Ϊ��
		if (head == nullptr)
		{
			//�½���һ�����ݽڵ�
			head = new Node(val);
			top++;
			return;
		}
		Node *node = new Node(val);
		Node *temp = head;
		while (true)
		{
			if (temp->next == nullptr)
			{
				break;
			}
			temp = temp->next;
		}
		temp->next = node;
		top++;
	}
	//��ջ ��ջ�������ݷ���
	int pop()
	{
		if (isEmpty())
		{
			cout << "ջ��" << endl;
			return -1;
		}
		Node *temp = head;
		if(temp->next==nullptr)
		{
			int val=temp->data;
			head=nullptr;
			top--;
			return val;
		}

		for (int i = 0; i < top-1; i++)
		{
			temp = temp->next;
		}

		int val = temp->next->data;
		Node *tail = temp->next;
		delete tail;

		temp->next= nullptr;
		top--;
		return val;
	}
	//��ʾջ��Ԫ�ص�����ջ
	int peek()
	{
		if (isEmpty())
		{
			cout << "ջ��" << endl;
			return -1;
		}
		Node *temp = head;
		for (int i = 0; i < top; i++)
		{
			temp = temp->next;
		}
		int val = temp->data;
		return val;
	}
	//��ʾջ�����
	void showStack()
	{
		if (isEmpty())
		{
			cout << "ջ�գ�û������" << endl;
			return;
		}
		Node *temp = head;
		int count = 0;
		while (true)
		{
			if (temp==nullptr)
			{
				break;
			}
			cout << "stack[" << count << "]=" << temp->data << endl;
			temp = temp->next;
			count++;
		}
	}

private:
	//ջ�Ĵ�С
	int maxSize;
	//����ջ����ָ��
	int top;
	//�����ͷָ��
	Node *head;
};
int main()
{
	LinkedListStack s1(10);
	int choice;
	while (true)
	{
		cout << "1����ʾ��ӡ������" << endl;
		cout << "2���˳�����" << endl;
		cout << "3��ѹ������ջ" << endl;
		cout << "4��ȡ���ݳ�ջ" << endl;
		cout << "5���鿴ջ������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "ջ����Ϊ" << endl;
			s1.showStack();
			cout << endl;
			break;
		case 2:
			exit(0);
			break;
		case 3:
			cout << "������Ҫ��ջ������" << endl;
			int num;
			cin >> num;
			s1.push(num);
			break;
		case 4:
			cout << "ȡ����ջ������Ϊ"<<s1.pop() << endl;
			break;
		case 5:
			cout<<"ջ��Ԫ��Ϊ"<<s1.peek()<<endl;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
