#include<iostream>
using namespace std;
//ջ��һ���������������б�
//ջ��������ɾ��һ�ˣ�Ϊ�仯��һ�ˣ���Ϊջ������һ��Ϊ�̶���һ�ˣ���Ϊջ��
//ջ��Ӧ��
//�ӳ���ĵ��ã��������ӳ���ǰ�����Ƚ��¸�ָ��ĵ�ַ�浽��ջ�У�ֱ���ӳ���ִ������ٽ���ַȡ�����Իص�ԭ���ĳ�����
//����ݹ���ã����ӳ���ĵ������ƣ�ֻ�ǳ��˴洢��һ��ָ��ĵ�ַ�⣬Ҳ��������������������ݴ����ջ��
//���ʽ��ת������׺���ʽת��׺���ʽ������ֵ
//�������ı���
//ͼ�ε������������

//����ģ��ջ
//����һ������top��ʾջ������ʼ��Ϊ-1
//��ջ���������ݼ��뵽ջ�У�top++; stack[top]=data;
//��ջ��temp=stack[top]; top--; return temp;
class ArrayStack
{
public:
	ArrayStack(int Size):top(-1),maxSize(Size),stack(new int[maxSize])
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
		top++;
		stack[top] = val;
	}
	//��ջ ��ջ�������ݷ���
	int pop()
	{
		if (isEmpty())
		{
			cout << "ջ��" << endl;
			return -1;
		}
		int temp = stack[top];
		top--;
		return temp;
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
		for (int i = top; i >= 0; i--)
		{
			cout << "stack[" << i << "]" << "=" << stack[i] << endl;
		}
	}
private:
	//ջ�Ĵ�С
	int maxSize;
	//����ģ��ջ
	int* stack;
	//����ջ����ָ��
	int top;
};
int main()
{
	ArrayStack stack(4);
	int choice = 0;
	while (true)
	{
		cout << "1����ʾ��ʾջ" << endl;
		cout << "2���˳�����" << endl;
		cout << "3����ʾ������ݵ�ջ" << endl;
		cout << "4����ʾ��ջ��ȡ������" << endl;
		cout << "���������ѡ��" << endl;
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
			cout << "������Ҫ��ӵ�����" << endl;
			int val;
			cin >> val;
			stack.push(val);
			break;
		case 4:
			cout << "ջ����Ԫ��Ϊ" << stack.pop() << endl;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}