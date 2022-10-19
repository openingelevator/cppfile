#include<iostream>
using namespace std;
class Node
{
public:
	Node(int hno)
		:num(hno), next(nullptr),pre(nullptr)
	{
	}
	int num;
	Node* next;
    Node* pre;
};
// Node* swapPairs(Node* head) {
//         //关键步骤，使得后续交换结点的操作一致
//         Node* temp=new Node(0);
//         temp->next=head;
//         Node* pre=temp;
//         Node* post=temp->next;
//         while(pre->next!=nullptr&&post!=nullptr&&post->next!=nullptr)
//         {
//             Node*temp1=post->next;
//             pre->next=post->next;
//             post->next=temp1->next;
//             temp1->next=post;
//             //将pre与post结点后移
//             pre=pre->next->next;
//             post=pre->next;
//         }
//         return temp->next;
// }
Node* swapPairs2(Node *head)
{
    Node* before=head;
    Node* after=head->next;
    while(before->next!=nullptr&&after!=nullptr&&after->next!=nullptr)
    {
        Node* temp1=after->next;
        before->next=temp1;
        temp1->pre=before;

        after->next=temp1->next;
        if(temp1->next!=nullptr)
        {
            temp1->next->pre=after;
        }

        temp1->next=after;
        after->pre=temp1;

        after=after->next;
        before=before->next->next;
    }
    return head;
}
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
void addNode(int value,Node*head)
{
 
		//不考虑编号顺序时
		Node* temp = head;
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
		temp->next = new Node(value);

}
int main()
{
    Node* head=new Node(0);
    addNode(1,head);
    addNode(4,head);
    addNode(3,head);
    addNode(5,head);
    addNode(2,head);
    cout<<"原来的链表"<<endl;
    showList(head);
    cout<<"两两交换后的链表"<<endl;
    showList(swapPairs2(head));
     system("pause");
     return 0;
}