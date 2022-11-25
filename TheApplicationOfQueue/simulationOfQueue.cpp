#include<iostream>
using namespace std;
//环形队列实现思路
//front变量含义调整，front指向队列的第一个元素，front的初始值为0
//rear变量含义调整，rear指向队列最后一个元素的后一个位置，空出一个元素作为约定，rear的初始值为0
//队列满的条件：(rear+1)%maxSize==front
//队列空的条件：rear==front	空
//队列中有效的数据有：(rear+maxSize-front)%maxSize

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

	//判断队列是否为满
	bool isFull()
	{
		return (rear + 1) % maxSize == front;
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
		//直接将数据加入
		arr[rear] = var;
		//将rear指针后移
		rear = (rear + 1) % maxSize;
	}
	//获取队列的数据，出队列
	int getQueue()
	{
		if (isEmpty())
		{
			throw invalid_argument("队列为空，无法取得数据");
		}
		//先把front对应的值保存到临时变量
		int temp = arr[front];
		//将front后移
		front = (front + 1) % maxSize;
		return temp;
	}
	//显示队列的所有数据
	void showQueue()
	{
		if (isEmpty())
		{
			cout << "队列为空，没有数据" << endl;
		}
		//从front开始遍历(rear+maxSize-front)%maxSize个元素
		for (int i = front; i <front+validSize(); i++)
		{
			cout << "arr["<<i%maxSize<<"]"<<"=" <<arr[i%maxSize] << " ";
		}
	}
	//显示队列的头数据
	int headQueue()
	{
		//判断队列是否为空
		if (isEmpty())
		{
			throw invalid_argument("队列为空，无法取得数据");
		}
		return arr[front];
	}

	//求出当前队列有效数据的元素
	int validSize()
	{
		return (rear + maxSize - front) % maxSize;
	}
private:
	//表示数组的最大容量
	int maxSize;
	//指向队列头位置的指针
	int front;
	//指向队列尾后一个位置的指针
	int rear;
	//用于存放数据的数组
	int* arr;
};

int main()
{
	//创建一个队列
	CircleArray q1(4);
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
			catch (exception e) {
				cout << e.what();
			}
			break;
		case 5:
			cout << "队列头的数据为" << q1.headQueue() << endl;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}