#include<iostream>
using namespace std;
//双向链表可以向前或者向后查找
//单向链表不能自我删除，需要依靠辅助节点，而双向链表则可以实现自我删除
//遍历方式与单链表一致，可以向前查找，也可以向后查找
//添加（默认添加到双向链表的最后）
//（1）先找到双向链表的最后一个节点
//（2）temp->next=newNode; newNode->pre=temp;
//修改思路与单向链表一致
//删除（直接找到待删除节点即可）
//temp->pre->next=temp->next; temp->next->pre=temp->pre;

class HeroNode
{
public:
	HeroNode(int hno, string hName, string hNickName)
		:num(hno), name(hName), nickName(hNickName), next(NULL),pre(NULL)
	{

	}
	void printInfo()
	{
		cout << "HeroNode num=" << num << " name=" << name << " nickName=" << nickName << endl;
	}
	//英雄编号
	int num;
	//英雄名称
	string name;
	//英雄绰号
	string nickName;
	HeroNode* next;//指向下一个节点
	HeroNode* pre;//指向前一个节点
};

class DoubleLinkedList
{
private:
	//先初始化头节点
	HeroNode* head = new HeroNode(0, "", "");
public:
	//返回头节点
	HeroNode* getHead()
	{
		return head;
	}
	//添加
	void addNode(HeroNode* node)
	{
		//不考虑编号顺序时
		HeroNode* temp = head;
		//找到链表的最后一个节点
		while (true)
		{
			//找到链表的最后
			if (temp->next == NULL)
			{
				break;
			}
			//未找到链表的最后，则将temp后移
			temp = temp->next;
		}
		//然后将最后节点的next域指向新的节点
		temp->next = node;
		//并将新节点的pre域指向前一个节点
		node->pre = temp;
	}
	void addNodeByOrder(HeroNode* node)
	{
		HeroNode* temp = head;
		//标识添加的编号是否存在
		bool flag = false;
		while (true)
		{
			//说明temp已经在链表的最后
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
			if (temp->next != nullptr)
			{
				temp->next->pre = node;
			}
			temp->next = node;
			node->pre = temp;
		}
	}

	//修改一个节点的内容
	void update(HeroNode* newNode)
	{
		//判断链表是否为空
		if (head->next == nullptr)
		{
			cout << "链表为空" << endl;
			return;
		}
		//不为空则找到需要修改的节点
		HeroNode* temp = head->next;
		//表示是否找到节点
		bool flag = false;
		while (true)
		{
			if (temp == nullptr)//表示已经遍历完链表
			{
				break;
			}
			if (temp->num == newNode->num)
			{
				//找到需要修改的节点
				flag = true;
				break;
			}
			temp = temp->next;
		}
		//表示未找到节点
		if (flag == false)
		{
			cout << "没有找到编号为" << newNode->num << "的节点" << endl;
		}
		else
		{
			temp->name = newNode->name;
			temp->nickName = newNode->nickName;
		}
	}
	//删除
	void deleteNode(int index)
	{
		//判断链表是否为空
		if (head->next == nullptr)
		{
			cout << "链表为空" << endl;
		}
		HeroNode* temp = head;
		bool flag = false;//标识节点是否找到
		while (true)
		{
			if (temp== nullptr)
			{
				break;
			}
			if (temp->num == index)
			{
				flag = true;
				break;
			}
			temp = temp->next;
		}
		if (flag)
		{
			temp->pre->next = temp->next; 
			//此处需要考虑删除的节点为最后一个节点的情况
			if (temp->next != nullptr)
			{
				temp->next->pre = temp->pre;
			}
			delete temp;
		}
		else
		{
			cout << "未找到待删除的节点" << endl;
		}
	}
	//显示链表
	void showList()
	{
		//判断链表是否为空
		if (head->next == NULL)
		{
			cout << "链表为空" << endl;
			return;
		}
		//遍历，通过辅助变量遍历链表
		HeroNode* temp = head->next;
		while (true)
		{
			//判断是否到链表最后
			if (temp == NULL)
			{
				break;
			}
			//输出节点信息
			temp->printInfo();
			temp = temp->next;
		}
	}

};

int main()
{
	HeroNode* node1 = new HeroNode(1, "宋江", "及时雨");
	HeroNode* node2 = new HeroNode(2, "卢俊义", "玉麒麟");
	HeroNode* node3 = new HeroNode(3, "吴用", "智多星");
	HeroNode* node4 = new HeroNode(4, "林冲", "豹子头");

	cout << "双向链表测试" << endl;
	//建立一个双向链表
	//DoubleLinkedList* list=new DoubleLinkedList();
	//list->addNode(node1);
	//list->addNode(node2);
	//list->addNode(node3);
	//list->addNode(node4);
	//cout << "修改前的链表" << endl;
	//list->showList();
	////修改
	//HeroNode* node5 = new HeroNode(4, "公孙胜", "入云龙");
	//list->update(node5);
	//cout << "修改后的链表" << endl;
	//list->showList();
	////删除
	//list->deleteNode(3);
	//cout << "删除节点后的链表" << endl;
	//list->showList();

	DoubleLinkedList* list2 = new DoubleLinkedList();
	cout << "按顺序创建双向链表" << endl;
	list2->addNodeByOrder(node1);
	list2->addNodeByOrder(node2);
	list2->addNodeByOrder(node3);
	list2->addNodeByOrder(node4);
	list2->showList();
	system("pause");
	
	return 0;
}