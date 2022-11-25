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
	//��������������
    //�ȴ�����һ���ڵ㣬��firstָ��ýڵ㣬���γɻ���
    //���浱����ÿ����һ���µĽڵ㣬�ͰѸýڵ㣬���뵽���еĻ��������м���
	void addNode(int nums)//nums�����м���С��
	{
		//��nums������У��
		if (nums < 2) {
			cout << "nums��ֵ����ȷ" << endl;
			return;
		}
		//����ָ�룬����������������
		Node* cur = nullptr;
		//ʹ��forѭ��������������
		for (int i = 1; i <= nums; i++)
		{
			//���ݱ�Ŵ����ڵ�
			Node* node = new Node(i);
			//����firstָ��
			if (i==1)
			{
				first = node;
				//���ɻ�
				first->next = first;
				cur = first;
			}else{
				cur->next = node;
				node->next = first;
				cur = node;
			}
		}
	}
	//������������
	//����һ������ָ��cur��ָ��first�ڵ�
	//Ȼ��ͨ��whileѭ�������û�������
	//������������cur->next=first;
	void showList()
	{
		//�ж������Ƿ�Ϊ��
		if (first == nullptr)
		{
			cout << "����Ϊ��" << endl;
			return;
		}
		Node* cur = first;
		while (true)
		{
			cout << "�ڵ�ı��Ϊ��" << cur->num << endl;
			if (cur->next == first)
			{
				break;
			}
			cur = cur->next;
		}
	}
	//�����û����룬���ɽڵ����˳��
	// ����ǰ����Ҫ����first��helper�ƶ�k-1��
	//����һ������ָ��helper����ָ������������һ���ڵ� 
	//������ʱ����helper��firstͬʱ�ƶ�m-1��
	//��ʱ�Ϳ��Խ�first�����ƶ� first=first->next; helper->next=first;
	//ԭ��firstָ��Ľڵ㼴��ɾ��
	//startNum������ʼ�Ľڵ�λ�ã�countNum�����������ڣ�nums����ڵ�ĸ���
	void countNode(int startNum, int countNum,int nums)
	{
		//�ȶ����ݽ���У��
		if (first == nullptr||startNum<1||startNum>nums)
		{
			cout << "����������������������" << endl;
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
		//ѭ�����У�ֱ������ֻ��һ���ڵ�
		while (true)
		{
			if (helper == first)
			{
				//��ʱ������ֻ��һ���ڵ�
				break;
			}
			for (int j = 0; j < countNum - 1; j++)
			{
				first = first->next;
				helper = helper->next;
			}
			//��ʱfirstָ��Ľڵ����Ҫ���еĽڵ�
			cout << "���еĽڵ���Ϊ��" << first->num << endl;
			Node* temp = first;
			first = first->next;
			helper->next = first;
			delete temp;
		}
		cout << "����������еĽڵ���Ϊ��" << first->num;
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