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

	//判断队列是否为满
	bool isFull()
	{
		return rear == maxSize - 1;
	}
	//判断队列是否为空
	bool isEmpty()
	{
		return rear == front;
	}
	//添加数据到队列
	void addQueue(int var)
	{
		//判断队列是否满
		if (isFull())
		{
			cout << "队列满，不能加入数据" << endl;
			return;
		}
		rear++;
		arr[rear] = var;
	}
	//获取队列的数据，出队列
	int getQueue()
	{
		if (isEmpty())
		{
			throw invalid_argument("队列为空，无法取得数据");
		}
		front++;
		return arr[front];
	}
	//显示队列的所有数据
	void showQueue()
	{
		if (isEmpty())
		{
			cout << "队列为空，没有数据" << endl;
		}
		for (int i = front+1; i <= rear; i++)
		{
			cout << arr[i] << " ";
		}
	}
	//显示队列的头数据
	int headQueue()
	{
		//判断队列是否为空
		if(isEmpty())
		{
			throw invalid_argument("队列为空，无法取得数据");
		}
		return arr[front+1];
	}
private:
	//表示数组的最大容量
	int maxSize;
	//指向队列头前一个位置的指针
	int front;
	//指向队列尾的指针
	int rear;
	//用于存放数据的数组
	int* arr;
};

int main()
{
	//创建一个队列
	ArrayQueue q1(3);
	int choice;
	while (true)
	{
		cout << "1、显示队列" << endl;
		cout << "2、退出程序" << endl;
		cout << "3、添加数据到队列" << endl;
		cout << "4、从队列取出数据" << endl;
		cout << "5、查看队列头的数据" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "队列数据为" << endl;
			q1.showQueue();
			cout << endl;
			break;
		case 2:
			exit(0);
			break;
		case 3:
			cout << "请输入要添加的数据" << endl;
			int num;
			cin >> num;
			q1.addQueue(num);
			break;
		case 4:
			try
			{
				int res = q1.getQueue();
				cout << "取出的数据是" << res << endl;
			}
			catch(exception e) {
				cout << e.what();
			}
			break;
		case 5:
			cout<<"队列头的数据为" << q1.headQueue() << endl;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}

