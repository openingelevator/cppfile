#include<iostream>
#include<string>
using namespace std;

//思路分析
//使用栈完成计算一个表达式的结果
//创建数字栈numStack与符号栈operStack
//通过索引index来遍历表达式
//如果扫描到数字，则压入数栈
//如果扫描到符号，分两种情况
//若符号栈为空，则直接入栈，若符号栈不为空，需进行比较
//若当前操作符的优先级小于或等于栈中的操作符，就需要从数栈中pop出两个数，再从符号栈中pop出一个符号，将运算的结果push进数栈，然后将当前符号入符号栈
//当表达式扫描完成，就顺序地从数栈和符号栈中pop出相应的数和符号并运算
//最后数栈中只有一个数据就是表达式的结果
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
	//出栈 将栈顶的数据返回
	int pop()
	{
		if (isEmpty())
		{
			cout << "栈空" << endl;
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
	//显示栈顶元素但不出栈
	int peek()
	{
		if (isEmpty())
		{
			cout << "栈空" << endl;
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
	//显示栈的情况
	//遍历时需要从栈顶开始显示数据
	void showStack()
	{
		if (isEmpty())
		{
			cout << "栈空，没有数据" << endl;
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
	//返回运算符优先级，优先级使用数字表示，数字越大则优先级越高
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
			return -1;//假定目前表达式只有加减乘除
		}
	}
	//判断是不是一个运算符
	bool isOper(char val)
	{
		return val == '+' || val == '-' || val == '*' || val == '/';
	}
	//计算方法
	int cal(int num1, int num2, char oper)
	{
		int res = 0;//用于存放计算结果
		switch (oper)
		{
		case '+':
			res = num1 + num2;
			break;
		case '-':
			res = num2 - num1;//注意顺序
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
	//栈的大小
	int maxSize;
	//代表栈顶的指针
	int top;
	//链表的头节点
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
		//扫描索引
		int index = 0;
		int num1 = 0;
		int num2 = 0;
		int oper = 0;
		int res = 0;//保存运算结果
		char ch = ' ';

		while (true)
		{
			//依次得到expression的每一个字符
			ch = expression.substr(index, index + 1).at(0);
			//判断ch属性然后做相应处理
			if (operStack.isOper(ch))//如果为运算符
			{
				//判断当前栈是否为空
				if (operStack.isEmpty())
				{
					operStack.push(ch);
				}
				else
				{
					if (operStack.priority(ch) <= operStack.priority(operStack.peek()))
					{
						//从数栈pop出两个元素进行运算
						num1 = numStack.pop();
						num2 = numStack.pop();
						oper = operStack.pop();
						res = numStack.cal(num1, num2,oper);
						//把运算结果加入数栈
						numStack.push(res);
						//然后把当前的操作压入符号栈
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
				//处理多位数时，不能发现一个数就立即入数栈
				//处理数时，需要向expression的表达式的index后再看一位，如果是符号才入栈
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

		//当表达式扫描完毕，就顺序的从数栈和符号栈pop出相应的数字和符号
		while (true)
		{
			//如果符号栈为空，则计算到最后的结果，数栈中只有一个数字
			if (operStack.isEmpty())
			{
				break;
			}
			//从数栈pop出两个元素进行运算
			num1 = numStack.pop();
			num2 = numStack.pop();
			oper = operStack.pop();
			res = numStack.cal(num2, num1, oper);
			//把运算结果加入数栈
			numStack.push(res);
		}
		return numStack.pop();
	}
private:
	string expression;
	//创建数栈
	LinkedListStack numStack;
	//创建符号栈
	LinkedListStack operStack;
	//用于拼接多位数
	string keepNum;
};
int main()
{
	string expression;
	cin >> expression;
	Calculator cal(expression, 20);
	cout << "计算结果为" << endl;
	cout << cal.result() << endl;
	system("pause");
	return 0;
}
