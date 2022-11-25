#include<iostream>
using namespace std;
//栈是一个先入后出的有序列表
//栈允许插入和删除一端，为变化的一端，称为栈顶，另一端为固定的一端，称为栈底
//栈的应用
//子程序的调用：在跳往子程序前，会先将下个指令的地址存到堆栈中，直到子程序执行完后再将地址取出，以回到原来的程序中
//处理递归调用，和子程序的调用类似，只是除了存储下一个指令的地址外，也将参数，区域变量等数据存入堆栈中
//表达式的转换【中缀表达式转后缀表达式】与求值
//二叉树的遍历
//图形的深度优先搜索

//数据模拟栈
//定义一个变量top表示栈顶，初始化为-1
//入栈，当有数据加入到栈中，top++; stack[top]=data;
//出栈，temp=stack[top]; top--; return temp;
class ArrayStack
{
public:
	ArrayStack(int Size):top(-1),maxSize(Size),stack(new int[maxSize])
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
		top++;
		stack[top] = val;
	}
	//出栈 将栈顶的数据返回
	int pop()
	{
		if (isEmpty())
		{
			cout << "栈空" << endl;
			return -1;
		}
		int temp = stack[top];
		top--;
		return temp;
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
		for (int i = top; i >= 0; i--)
		{
			cout << "stack[" << i << "]" << "=" << stack[i] << endl;
		}
	}
private:
	//栈的大小
	int maxSize;
	//数组模拟栈
	int* stack;
	//代表栈顶的指针
	int top;
};
int main()
{
	ArrayStack stack(4);
	int choice = 0;
	while (true)
	{
		cout << "1：表示显示栈" << endl;
		cout << "2：退出程序" << endl;
		cout << "3：表示添加数据到栈" << endl;
		cout << "4：表示从栈中取出数据" << endl;
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			stack.showStack();
			break;
		case 2:
			exit(1);
			break;
		case 3:
			cout << "请输入要添加的数据" << endl;
			int val;
			cin >> val;
			stack.push(val);
			break;
		case 4:
			cout << "栈顶的元素为" << stack.pop() << endl;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}