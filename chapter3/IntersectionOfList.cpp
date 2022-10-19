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
class SingleLinkedList
{
private:
	Node* head = new Node(0);
public:
	Node* getHead()
	{
		return head;
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

};
//显示链表
void showList(Node* head)
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
        cout<<endl;
}
Node* InterSectionOfLists(Node* l1,Node* l2)
{
    Node* temp1=l1->next;
    Node* temp2=l2->next;
    Node* newhead=new Node(0);
    Node* cur=newhead;
    while(temp1!=nullptr)
    {
        while(temp2!=nullptr)
        {
            if(temp2->num==temp1->num)
            {
                cur->next=new Node(temp2->num);
                cur=cur->next;
                break;
            }//升序的情况下，在此节点的数值小于待查找的链表节点数值时可以停止遍历
            else if(temp2->num>temp1->num)
            {
                break;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return newhead;
}
int main()
{
    SingleLinkedList l1;
    SingleLinkedList l2;
    l1.addNode(new Node(1));
    l1.addNode(new Node(2));
    l1.addNode(new Node(4));
    cout<<"链表1为"<<endl;
    showList(l1.getHead());
    cout<<"链表2为"<<endl;
    l2.addNode(new Node(4));
    l2.addNode(new Node(3));
    l2.addNode(new Node(1));
    l2.addNode(new Node(5));
    showList(l2.getHead());
    Node* head=InterSectionOfLists(l1.getHead(),l2.getHead());
    cout<<"取交集后的链表为"<<endl;
    showList(head);
    system("pause");
    return 0;
}