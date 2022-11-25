#include<iostream>
using namespace std;
//���ζ���ʵ��˼·
//front�������������frontָ����еĵ�һ��Ԫ�أ�front�ĳ�ʼֵΪ0
//rear�������������rearָ��������һ��Ԫ�صĺ�һ��λ�ã��ճ�һ��Ԫ����ΪԼ����rear�ĳ�ʼֵΪ0
//��������������(rear+1)%maxSize==front
//���пյ�������rear==front	��
//��������Ч�������У�(rear+maxSize-front)%maxSize

class CircleArray
{
public:
	CircleArray(int Size) :maxSize(Size), arr(new int[maxSize])
	{
		front = 0;
		rear = 0;
	}
	~CircleArray()
	{
		delete[] arr;
	}

	//�ж϶����Ƿ�Ϊ��
	bool isFull()
	{
		return (rear + 1) % maxSize == front;
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
		//ֱ�ӽ����ݼ���
		arr[rear] = var;
		//��rearָ�����
		rear = (rear + 1) % maxSize;
	}
	//��ȡ���е����ݣ�������
	int getQueue()
	{
		if (isEmpty())
		{
			throw invalid_argument("����Ϊ�գ��޷�ȡ������");
		}
		//�Ȱ�front��Ӧ��ֵ���浽��ʱ����
		int temp = arr[front];
		//��front����
		front = (front + 1) % maxSize;
		return temp;
	}
	//��ʾ���е���������
	void showQueue()
	{
		if (isEmpty())
		{
			cout << "����Ϊ�գ�û������" << endl;
		}
		//��front��ʼ����(rear+maxSize-front)%maxSize��Ԫ��
		for (int i = front; i <front+validSize(); i++)
		{
			cout << "arr["<<i%maxSize<<"]"<<"=" <<arr[i%maxSize] << " ";
		}
	}
	//��ʾ���е�ͷ����
	int headQueue()
	{
		//�ж϶����Ƿ�Ϊ��
		if (isEmpty())
		{
			throw invalid_argument("����Ϊ�գ��޷�ȡ������");
		}
		return arr[front];
	}

	//�����ǰ������Ч���ݵ�Ԫ��
	int validSize()
	{
		return (rear + maxSize - front) % maxSize;
	}
private:
	//��ʾ������������
	int maxSize;
	//ָ�����ͷλ�õ�ָ��
	int front;
	//ָ�����β��һ��λ�õ�ָ��
	int rear;
	//���ڴ�����ݵ�����
	int* arr;
};

int main()
{
	//����һ������
	CircleArray q1(4);
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
			catch (exception e) {
				cout << e.what();
			}
			break;
		case 5:
			cout << "����ͷ������Ϊ" << q1.headQueue() << endl;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}