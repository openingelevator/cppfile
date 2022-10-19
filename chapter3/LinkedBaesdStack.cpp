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
	//栈满
	bool isFull()
	{
		return top == maxSize - 1;
	}
	//栈空
	bool isEmpty()
	{
		return top == -1;
	}
	//入栈
	void push(int val)
	{
		//判断栈是否满
		if (isFull())
		{
			cout << "栈已满" << endl;
			return;
		}
		//判断头指针是否为空
		if (head == nullptr)
		{
			//新建第一个数据节点
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
	//出栈 将栈顶的数据返回
	int pop()
	{
		if (isEmpty())
		{
			cout << "栈空" << endl;
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
	//显示栈顶元素但不出栈
	int peek()
	{
		if (isEmpty())
		{
			cout << "栈空" << endl;
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
	//显示栈的情况
	void showStack()
	{
		if (isEmpty())
		{
			cout << "栈空，没有数据" << endl;
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
	//栈的大小
	int maxSize;
	//代表栈顶的指针
	int top;
	//链表的头指针
	Node *head;
};
int main()
{
	LinkedListStack s1(10);
	int choice;
	while (true)
	{
		cout << "1、显示打印单链表" << endl;
		cout << "2、退出程序" << endl;
		cout << "3、压数据入栈" << endl;
		cout << "4、取数据出栈" << endl;
		cout << "5、查看栈顶数据" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "栈数据为" << endl;
			s1.showStack();
			cout << endl;
			break;
		case 2:
			exit(0);
			break;
		case 3:
			cout << "请输入要入栈的数据" << endl;
			int num;
			cin >> num;
			s1.push(num);
			break;
		case 4:
			cout << "取出的栈顶数据为"<<s1.pop() << endl;
			break;
		case 5:
			cout<<"栈顶元素为"<<s1.peek()<<endl;
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
