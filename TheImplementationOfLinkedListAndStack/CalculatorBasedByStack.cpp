#include<iostream>
#include<string>
using namespace std;

//˼·����
//ʹ��ջ��ɼ���һ�����ʽ�Ľ��
//��������ջnumStack�����ջoperStack
//ͨ������index���������ʽ
//���ɨ�赽���֣���ѹ����ջ
//���ɨ�赽���ţ����������
//������ջΪ�գ���ֱ����ջ��������ջ��Ϊ�գ�����бȽ�
//����ǰ�����������ȼ�С�ڻ����ջ�еĲ�����������Ҫ����ջ��pop�����������ٴӷ���ջ��pop��һ�����ţ�������Ľ��push����ջ��Ȼ�󽫵�ǰ���������ջ
//�����ʽɨ����ɣ���˳��ش���ջ�ͷ���ջ��pop����Ӧ�����ͷ��Ų�����
//�����ջ��ֻ��һ�����ݾ��Ǳ��ʽ�Ľ��
class Node
{
public:
	Node(int num):data(num),next(nullptr),pre(nullptr)
	{

	}
	int data;
	Node* next;
	Node* pre;
};
class LinkedListStack
{
public:
	LinkedListStack(int Size) :top(-1), maxSize(Size),head(new Node(0))
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
		Node* node = new Node(val);
		Node* temp = head;
		while (true)
		{
			if (temp->next == nullptr)
			{
				break;
			}
			temp = temp->next;
		}
		temp->next = node;
		node->pre = temp;
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
		Node* temp = head;
		for (int i = 0; i < top; i++)
		{
			temp = temp->next;
		}

		int val = temp->next->data;
		Node* tail = temp->next;
		delete tail;

		temp->next = nullptr;
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
		Node* temp = head;
		for (int i = 0; i < top; i++)
		{
			temp = temp->next;
		}
		int val = temp->next->data;
		return val;
	}
	//��ʾջ�����
	//����ʱ��Ҫ��ջ����ʼ��ʾ����
	void showStack()
	{
		if (isEmpty())
		{
			cout << "ջ�գ�û������" << endl;
			return;
		}
		Node* temp = head;
		while (true)
		{
			if (temp->next == nullptr)
			{
				break;
			}
			temp = temp->next;
		}

		for (int i = top; i >=0; i--)
		{
			cout << "stack[" << i << "]=" << temp->data << endl;
			temp = temp->pre;
		}
	}
	//������������ȼ������ȼ�ʹ�����ֱ�ʾ������Խ�������ȼ�Խ��
	int priority(char oper)
	{
		if (oper == '*'||oper=='/')
		{
			return 1;
		}
		else if (oper == '+' || oper == '-')
		{
			return 0;
		}
		else {
			return -1;//�ٶ�Ŀǰ���ʽֻ�мӼ��˳�
		}
	}
	//�ж��ǲ���һ�������
	bool isOper(char val)
	{
		return val == '+' || val == '-' || val == '*' || val == '/';
	}
	//���㷽��
	int cal(int num1, int num2, char oper)
	{
		int res = 0;//���ڴ�ż�����
		switch (oper)
		{
		case '+':
			res = num1 + num2;
			break;
		case '-':
			res = num2 - num1;//ע��˳��
			break;
		case '*':
			res = num1 * num2;
			break;
		case '/':
			res = num2 / num1;
			break;
		default:
			break;
		}
		return res;
	}
private:
	//ջ�Ĵ�С
	int maxSize;
	//����ջ����ָ��
	int top;
	//�����ͷ�ڵ�
	Node* head;
};
class Calculator
{
public:
	Calculator(string exp, int maxSize):numStack(maxSize),operStack(maxSize)
	{
		this->expression = exp;
	}
	int result()
	{
		//ɨ������
		int index = 0;
		int num1 = 0;
		int num2 = 0;
		int oper = 0;
		int res = 0;//����������
		char ch = ' ';

		while (true)
		{
			//���εõ�expression��ÿһ���ַ�
			ch = expression.substr(index, index + 1).at(0);
			//�ж�ch����Ȼ������Ӧ����
			if (operStack.isOper(ch))//���Ϊ�����
			{
				//�жϵ�ǰջ�Ƿ�Ϊ��
				if (operStack.isEmpty())
				{
					operStack.push(ch);
				}
				else
				{
					if (operStack.priority(ch) <= operStack.priority(operStack.peek()))
					{
						//����ջpop������Ԫ�ؽ�������
						num1 = numStack.pop();
						num2 = numStack.pop();
						oper = operStack.pop();
						res = numStack.cal(num1, num2,oper);
						//��������������ջ
						numStack.push(res);
						//Ȼ��ѵ�ǰ�Ĳ���ѹ�����ջ
						operStack.push(ch);
					}
					else
					{
						operStack.push(ch);
					}
				}
			}
			else
			{
				//�����λ��ʱ�����ܷ���һ��������������ջ
				//������ʱ����Ҫ��expression�ı��ʽ��index���ٿ�һλ������Ƿ��Ų���ջ
				keepNum += ch;
				if (index == expression.length() - 1)
				{
					numStack.push(ch - 48);
				}
				else
				{
					if (numStack.isOper(expression.substr(index + 1, index + 2).at(0)))
					{
						int integer = 0;
						for (int i = 0; i < keepNum.length(); i++)
						{
							integer = integer * 10 + (keepNum[i]-48);
						}
						numStack.push(integer);
						keepNum = "";
					}

				}
			
			}
			index++;
			if (index >= expression.length())
			{
				break;
			}
		}

		//�����ʽɨ����ϣ���˳��Ĵ���ջ�ͷ���ջpop����Ӧ�����ֺͷ���
		while (true)
		{
			//�������ջΪ�գ�����㵽���Ľ������ջ��ֻ��һ������
			if (operStack.isEmpty())
			{
				break;
			}
			//����ջpop������Ԫ�ؽ�������
			num1 = numStack.pop();
			num2 = numStack.pop();
			oper = operStack.pop();
			res = numStack.cal(num2, num1, oper);
			//��������������ջ
			numStack.push(res);
		}
		return numStack.pop();
	}
private:
	string expression;
	//������ջ
	LinkedListStack numStack;
	//��������ջ
	LinkedListStack operStack;
	//����ƴ�Ӷ�λ��
	string keepNum;
};
int main()
{
	string expression;
	cin >> expression;
	Calculator cal(expression, 20);
	cout << "������Ϊ" << endl;
	cout << cal.result() << endl;
	system("pause");
	return 0;
}
