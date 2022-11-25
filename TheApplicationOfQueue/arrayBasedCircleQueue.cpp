#include<iostream>
using namespace std;

class ArrayQueue
{
public:
	ArrayQueue(int Size):maxSize(Size),arr(new int[maxSize])
	{
		front = -1;
		rear = -1;
	}
	~ArrayQueue()
	{
		delete[] arr;
	}

	//�ж϶����Ƿ�Ϊ��
	bool isFull()
	{
		return rear == maxSize - 1;
	}
	//�ж϶����Ƿ�Ϊ��
	bool isEmpty()
	{
		return rear == front;
	}
	//������ݵ�����
	void addQueue(int var)
	{
		//�ж϶����Ƿ���
		if (isFull())
		{
			cout << "�����������ܼ�������" << endl;
			return;
		}
		rear++;
		arr[rear] = var;
	}
	//��ȡ���е����ݣ�������
	int getQueue()
	{
		if (isEmpty())
		{
			throw invalid_argument("����Ϊ�գ��޷�ȡ������");
		}
		front++;
		return arr[front];
	}
	//��ʾ���е���������
	void showQueue()
	{
		if (isEmpty())
		{
			cout << "����Ϊ�գ�û������" << endl;
		}
		for (int i = front+1; i <= rear; i++)
		{
			cout << arr[i] << " ";
		}
	}
	//��ʾ���е�ͷ����
	int headQueue()
	{
		//�ж϶����Ƿ�Ϊ��
		if(isEmpty())
		{
			throw invalid_argument("����Ϊ�գ��޷�ȡ������");
		}
		return arr[front+1];
	}
private:
	//��ʾ������������
	int maxSize;
	//ָ�����ͷǰһ��λ�õ�ָ��
	int front;
	//ָ�����β��ָ��
	int rear;
	//���ڴ�����ݵ�����
	int* arr;
};

int main()
{
	//����һ������
	ArrayQueue q1(3);
	int choice;
	while (true)
	{
		cout << "1����ʾ����" << endl;
		cout << "2���˳�����" << endl;
		cout << "3��������ݵ�����" << endl;
		cout << "4���Ӷ���ȡ������" << endl;
		cout << "5���鿴����ͷ������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "��������Ϊ" << endl;
			q1.showQueue();
			cout << endl;
			break;
		case 2:
			exit(0);
			break;
		case 3:
			cout << "������Ҫ��ӵ�����" << endl;
			int num;
			cin >> num;
			q1.addQueue(num);
			break;
		case 4:
			try
			{
				int res = q1.getQueue();
				cout << "ȡ����������" << res << endl;
			}
			catch(exception e) {
				cout << e.what();
			}
			break;
		case 5:
			cout<<"����ͷ������Ϊ" << q1.headQueue() << endl;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}

