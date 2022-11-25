#include<iostream>
#include<string>
using namespace std;
//链表是以节点的方式存储的，每个节点包括data域，next域指向下一个节点
//链表的各个节点不一定是连续存放的
//链表分带头节点的链表与不带头节点的链表

class HeroNode
{
public:
	HeroNode(int hno,string hName,string hNickName)
		:num(hno),name(hName),nickName(hNickName),next(NULL)
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
	//添加
    //先创建一个头节点，作用就是单链表的头
    //后面每添加一个节点，就直接加入到链表的最后
	void addNode(HeroNode* node)//此处传入的节点参数必须以指针或引用的方式传递，否则赋值给temp的地址是拷贝出来的节点的地址
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
	SingleLinkedList list;
	HeroNode* node1=new HeroNode(1, "宋江", "及时雨");
	HeroNode* node2=new HeroNode(2, "卢俊义", "玉麒麟");
	HeroNode* node3 = new HeroNode(3, "吴用", "智多星");
	list.addNode(node1);
	list.addNode(node2);
	list.addNode(node3);
	list.showList();
	system("pause");
	return 0;
}