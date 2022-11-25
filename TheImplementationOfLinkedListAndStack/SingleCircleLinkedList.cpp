#include<iostream>
using namespace std;

class Node
{
public:
	Node(int no)
		:num(no), next(nullptr)
	{
	}
	int num;
	Node* next;
};
class CircleLinkedList
{
private:
	Node* first =new Node(-1);
public:
	//构建单向环形链表
    //先创建第一个节点，让first指向该节点，并形成环形
    //后面当我们每创建一个新的节点，就把该节点，加入到已有的环形链表当中即可
	void addNode(int nums)//nums代表有几个小孩
	{
		//对nums做数据校验
		if (nums < 2) {
			cout << "nums的值不正确" << endl;
			return;
		}
		//辅助指针，帮助遍历环形链表
		Node* cur = nullptr;
		//使用for循环创建环形链表
		for (int i = 1; i <= nums; i++)
		{
			//根据编号创建节点
			Node* node = new Node(i);
			//考虑first指针
			if (i==1)
			{
				first = node;
				//构成环
				first->next = first;
				cur = first;
			}else{
				cur->next = node;
				node->next = first;
				cur = node;
			}
		}
	}
	//遍历环形链表
	//先让一个辅助指针cur，指向first节点
	//然后通过while循环遍历该环形链表
	//遍历完条件，cur->next=first;
	void showList()
	{
		//判断链表是否为空
		if (first == nullptr)
		{
			cout << "链表为空" << endl;
			return;
		}
		Node* cur = first;
		while (true)
		{
			cout << "节点的编号为：" << cur->num << endl;
			if (cur->next == first)
			{
				break;
			}
			cur = cur->next;
		}
	}
	//根据用户输入，生成节点出列顺序
	// 出列前，需要先让first与helper移动k-1次
	//创建一个辅助指针helper事先指向环形链表的最后一个节点 
	//当报数时，让helper与first同时移动m-1次
	//这时就可以将first往后移动 first=first->next; helper->next=first;
	//原来first指向的节点即被删除
	//startNum代表起始的节点位置，countNum代表报数的周期，nums代表节点的个数
	void countNode(int startNum, int countNum,int nums)
	{
		//先对数据进行校验
		if (first == nullptr||startNum<1||startNum>nums)
		{
			cout << "参数输入有误，请重新输入" << endl;
			return;
		}
		Node* helper = first;
		while (true)
		{
			if (helper->next == first)
			{
				break;
			}
			helper = helper->next;
		}
		for (int i = 0; i < startNum-1; i++)
		{
			first = first->next;
			helper = helper->next;
		}
		//循环出列，直到列中只有一个节点
		while (true)
		{
			if (helper == first)
			{
				//此时链表中只有一个节点
				break;
			}
			for (int j = 0; j < countNum - 1; j++)
			{
				first = first->next;
				helper = helper->next;
			}
			//此时first指向的节点就是要出列的节点
			cout << "出列的节点编号为：" << first->num << endl;
			Node* temp = first;
			first = first->next;
			helper->next = first;
			delete temp;
		}
		cout << "最后留在列中的节点编号为：" << first->num;
	}

};

int main()
{

	CircleLinkedList list;
	list.addNode(5);
	list.showList();
	list.countNode(1, 2, 5);
	system("pause");
	return 0;
}