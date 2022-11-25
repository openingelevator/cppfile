#include<iostream>
#include<stack>
using namespace std;

class Node
{
public:
	Node(int hno)
		:num(hno), next(nullptr)
	{
	}
	int num;
	Node* next;
};
class SingleLinkedList
{
private:
	Node* head = new Node(0);
public:
	Node* getHead()
	{
		return head;
	}

	//合并两个有序链表
	Node* mergeList(Node* anotherHead)
	{
		Node* temp = anotherHead->next;
		Node* rear = nullptr;
		while (temp != nullptr)
		{
			rear = temp->next;
			this->addNode(temp);
			temp = rear;
		}
		return this->head;
	}

	void addNode(Node* node)
	{
		Node* temp = head;
		bool flag = false;
		while (true)
		{
			if (temp->next == nullptr)
			{
				break;
			}
			else if (temp->next->num > node->num)
			{
				break;
			}
			else if (temp->next->num == node->num)
			{
				//编号已存在
				flag = true;
				break;
			}
			temp = temp->next;
		}

		if (flag == true)
		{
			cout << "准备插入的节点编号已存在，无法继续添加" << endl;
		}
		else
		{
			//插入到链表中
			node->next = temp->next;
			temp->next = node;
		}
	}
	void deleteNode(int index)
	{
		//判断链表是否为空
		if (head->next == nullptr)
		{
			cout << "链表为空" << endl;
		}
		Node* temp = head;
		bool flag = false;//标识节点是否找到
		while (true)
		{
			if (temp->next == nullptr)
			{
				break;
			}
			if (temp->next->num == index)
			{
				flag = true;
				break;
			}
			temp = temp->next;
		}
		if (flag)
		{
			Node* node = temp->next;
			temp->next = temp->next->next;
			delete node;
		}
		else
		{
			cout << "未找到待删除的节点" << endl;
		}

	}

	//显示链表
	void showList()
	{
		if (head->next == nullptr)
		{
			cout << "链表为空" << endl;
			return;
		}
		Node* temp = head->next;
		while (true)
		{
			//判断是否到链表最后
			if (temp == nullptr)
			{
				break;
			}
			//输出节点信息
			cout << temp->num << " ";
			temp = temp->next;
		}
	}
};
//获取链表有效结点的个数
int getLength(Node* head)
{
	if (head->next == nullptr)//空链表
	{
		return 0;
	}
	int length = 0;
	//不统计头节点
	Node* cur = head->next;
	while (true)
	{
		if (cur == nullptr)
		{
			break;
		}
		cur = cur->next;
		length++;
	}
	return length;
}
//查找单链表中的倒数第k个节点
int searchNode(Node* head, int k)
{
	if (head->next == nullptr)
	{
		//链表为空
		return -1;
	}
	int len = getLength(head);
	int index = len - k;
	if (index<0||index>=len)
	{
		cout << "倒数第k个节点越界" << endl;
		return -1;
	}
	Node* temp = head;
	while (index >=0)
	{
		temp = temp->next;
		index--;
	}
	return temp->num;
}
//单链表的反转
void reverseList(Node* head)
{
	if (head->next == nullptr||head->next->next==nullptr)
	{
		//链表为空或者只有一个节点，无需反转
		return;
	}
	//定义辅助变量，遍历原来的链表
	Node* cur = head->next;
	//指向当前结点的下一个节点
	Node* rear =nullptr;
	Node* reverseHead = new Node(0);
	while (true)
	{
		if (cur== nullptr)
		{
			break;
		}
		rear = cur->next;//暂时保存cur下一个节点的地址
		cur->next = reverseHead->next;//将cur的下一个节点指向新链表的头节点
		reverseHead->next = cur;
		cur = rear;
	}
	head->next = reverseHead->next;
}
Node* reverseKGroup(Node* head, int k) {
	Node* preNode = new Node(0);
	preNode->next = head;
	Node* ktail = preNode->next;
	//链表中只有一个节点，无需反转
	if (head->next == nullptr)
	{
		return head;
	}
	Node* reverseNode = new Node(0);
	Node* tempHead = reverseNode;
	Node* cur = preNode->next;
	Node* rear = nullptr;
	while (ktail!= nullptr)
	{
		int count = 0;
		for (int i = 0; i < k && ktail != nullptr; i++)
		{
			ktail = ktail->next;
			count++;
		}
		if (count  < k)
		{
			tempHead->next = cur;
			break;
		}
		for (int i = 0; i < k && cur != nullptr; i++)
		{
			rear = cur->next;//暂时保存cur下一个节点的地址
			cur->next = tempHead->next;//将cur的下一个节点指向新链表的头节点
			tempHead->next = cur;
			cur = rear;
		}
		for (int i = 0; i < k && tempHead != nullptr; i++)
		{
			tempHead = tempHead->next;
		}
	}
	return reverseNode->next;
}
//反向打印链表
void reversePrint(Node* head)
{
	//方式一先将单链表进行反转之后再遍历
	//方式二利用栈的数据结构，将各个节点压入到栈中，然后利用栈先进后出的特点，实现逆序打印的效果
	if (head->next == nullptr)
	{
		return;
	}
	//创建一个栈，将各个节点压入栈
	stack<Node*>nodeContain;
	Node* temp = head->next;
	while (temp != nullptr)
	{
		nodeContain.push(temp);
		temp = temp->next;
	}
	//将栈中的节点进行打印
	while (nodeContain.size() > 0)
	{
		cout << nodeContain.top()->num << " ";
		nodeContain.pop();
	}
}
int main()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	SingleLinkedList list;
	list.addNode(n1);
	list.addNode(n2);
	list.addNode(n3);
	list.addNode(n4);
	list.addNode(n5);
	//cout << "反转前的链表" << endl;
	//list.showList();
	//cout << endl;
	////reverseList(list.getHead());

	////cout << "反转后的链表" << endl;
	////list.showList();
	////cout << endl;
	////cout << getLength(list.getHead()) << endl;
	////cout << "倒数第3个节点的数据为：" << searchNode(list.getHead(), 3);
	////cout << "逆序打印的结果为" << endl;
	////reversePrint(list.getHead());

	//Node* n5 = new Node(4);
	//Node* n6 = new Node(9);
	//Node* n7 = new Node(8);
	//SingleLinkedList newList;
	//newList.addNode(n5);
	//newList.addNode(n6);
	//newList.addNode(n7);
	//newList.showList();
	//cout << endl;

	//list.mergeList(newList.getHead());
	//cout << "合并后的链表" << endl;
	//list.showList();
	reverseKGroup(list.getHead(), 2);
	system("pause");
	return 0;
}