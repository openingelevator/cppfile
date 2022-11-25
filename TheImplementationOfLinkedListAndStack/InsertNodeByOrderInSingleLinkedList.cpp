#include<iostream>
#include<string>
using namespace std;

class HeroNode
{
public:
	HeroNode(int hno, string hName, string hNickName)
		:num(hno), name(hName), nickName(hNickName), next(nullptr)
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
	HeroNode* next;
};
//定义SingleLinkedList 来管理hero
class SingleLinkedList
{
private:
	//先初始化头节点
	HeroNode* head = new HeroNode(0, "", "");
public:
	//按照顺序添加
	//首先通过辅助变量（指针）找到新添加节点的位置
	//新的节点->next=temp->next
	//将temp->next=新的节点
	void addNode(HeroNode* node)
	{
		//因为单链表，所以temp位于添加位置的前一个节点
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
			else if (temp->next->num>node->num)
			{
				break;
			}
			else if (temp->next->num==node->num)
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
	//修改节点信息
	void update(HeroNode* newNode)
	{
		//判断链表是否为空
		if (head->next == nullptr)
		{
			cout << "链表为空" << endl;
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
	//删除节点
	//找到待删除节点的前驱temp
	//temp->next=temp->next->next
	//delete 待删除节点
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
			HeroNode* node = temp->next;
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
		//判断链表是否为空
		if (head->next == nullptr)
		{
			cout << "链表为空" << endl;
			return;
		}
		//遍历，通过辅助变量遍历链表
		HeroNode* temp = head->next;
		while (true)
		{
			//判断是否到链表最后
			if (temp == nullptr)
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
	SingleLinkedList list;
	HeroNode* node1 = new HeroNode(1, "宋江", "及时雨");
	HeroNode* node2 = new HeroNode(2, "卢俊义", "玉麒麟");
	HeroNode* node3 = new HeroNode(3, "吴用", "智多星");
	HeroNode* node4 = new HeroNode(4, "林冲", "豹子头");

	list.addNode(node1);
	list.addNode(node4);
	list.addNode(node3);
	list.addNode(node2);

	cout << "修改前的链表情况" << endl;
	list.showList();
	cout << "修改后的链表情况" << endl;
	//测试修改结点的代码
	//HeroNode* node5 = new HeroNode(2, "小卢", "玉麒麟~~");
	//list.update(node5);
	list.deleteNode(4);
	list.showList();
	system("pause");
	return 0;
}