/*
 * @Author: ֣᷷� 
 * @Date: 2022-09-24 12:14:29 
 * @Last Modified by:   ֣᷷� 
 * @SID:202130462264
 * @Last Modified time: 2022-09-24 12:14:29 
 */
#pragma once
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
const int DEFAULT_CAPACITY=2;

template<class T>
class myArray
{
public:
	//�вι���
	myArray(int capacity=DEFAULT_CAPACITY)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->arrayPtr = new T[this->m_Capacity];
	}
	//��������
	myArray(const myArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���
		this->arrayPtr = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->arrayPtr[i] = arr.arrayPtr[i];
		}
	}
	//��������
	~myArray()
	{
		if (this->arrayPtr != NULL) { delete[]this->arrayPtr; this->arrayPtr = NULL; }
	}
	//β�巨
	void append(const T&value)
	{
		insert(this->m_Size,value);
	}
	//����ض�Ԫ�ص�λ��
	//���������漰���б���Ԫ�صı���������������Ϊ1������Ϊn��ƽ�����Ϊn/2��ʱ�临�Ӷ�ΪO(n)
	void at(const T&value)
	{
		for(int i=0;i<m_Size;i++)
		{
			if(this->arrayPtr[i]==value)
			{
				cout<<"the position of value"<<value<<"is "<<i<<endl;
				return ;
			}
		}
		cout<<"the position of value"<<value<<"has not been found"<<endl;
	}
	//����ض�λ�õ�Ԫ��
	//���������漰���б���Ԫ�صı���������������Ϊ1������Ϊn��ƽ�����Ϊn/2��ʱ�临�Ӷ�ΪO(n)
	void find(int index)
	{
		if(index<0||index>=this->m_Size)
		{
			cout<<"the index is out of range"<<endl;
		}
		cout<<"array["<<index<<"]="<<this->arrayPtr[index]<<endl;
	}
	//������������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//���ض�λ�ò���Ԫ��
	//��������漰������λ�ú����λ�ú��ƵĲ�����������Ϊ��ĩβ���룬�������Ԫ�أ�����Ϊ�����鿪ͷ����
	//������ƽ�����Ӷ�ΪO(n)
	bool insert(int pos,const T&typeValue)
	{
		if(pos<0||pos>this->m_Size)
		{
			cout<<"insert operatiion fails"<<endl;
			return false;
		}
		for(int i=this->m_Size;i>pos;i--)
		{
			this->arrayPtr[i]=this->arrayPtr[i-1];
		}
		this->arrayPtr[pos]=typeValue;
		this->m_Size++;
		if(this->m_Size==this->m_Capacity)
		{
			resize(2*this->m_Capacity);
		}
		return true;
	}
	//�ж��б��Ƿ�Ϊ��
	bool isEmpty()
	{
		if(this->m_Size==0)
		{
			return true;
		}else
		{
			return false;
		}
	}
	//���������С
	int length()
	{
		return this->m_Size;
	}
	//�Ⱥ���������أ����ڿ����б�
	myArray& operator=(const myArray&arr)
	{
		//��ֹ���Ҹ�ֵ
		if (this == &arr)return *this;
			//���ж�ԭ�������Ƿ������ݣ���������ͷ�
			if (this->arrayPtr != NULL)
			{
				delete[] this->arrayPtr;
				this->m_Capacity = 0;
				this->m_Size = 0;
			}
			this->m_Capacity = arr.m_Capacity;
			this->m_Size = arr.m_Size;
			this->arrayPtr = new T[arr.m_Capacity];
			for (int i = 0; i < this->m_Size; i++)
			{
				this->arrayPtr[i] = arr.arrayPtr[i];
			}
			return *this;
	}
	//�����±��������������ֵ�汾
	T operator[](int index)const
	{
		if (index >= 0 && index < this->m_Size)
			return this->arrayPtr[index];
		else throw out_of_range("index out of range");
	}
	//������ֵ�汾
	T& operator[](int index)
	{
		if (index >= 0 && index < this->m_Size)
			return this->arrayPtr[index];
		else throw out_of_range("index out of range");
	}
	//��ӡ�б��ֵ
	void print()
	{
		if(isEmpty())
		{
			cout<<"�б�Ϊ�գ�û������"<<endl;
			return;
		}
		for(int i=0;i<this->m_Size;i++)
		{
			cout<<this->arrayPtr[i]<<"\n";
		}
	}
	//�����б������
	//����������С�漰������������Ҫ��ԭ������б�����ʱ�临�Ӷ�ΪO(n)
	void resize(int newCapacity)
	{
		if(newCapacity<this->m_Size)
		{
			cout<<"resize operation fails";
			return ;
		}
		T*temp=new T[newCapacity];
		this->m_Capacity=newCapacity;
		for(int i=0;i<this->m_Size;i++)
		{
			temp[i]=this->arrayPtr[i];
		}
		delete[] this->arrayPtr;
		this->arrayPtr=temp;
	}

	//�Ƴ��б����ض�λ�õ�Ԫ��
	//�Ƴ������漰���Ƴ�λ�ú����λ��ǰ�ƵĲ�����������Ϊ��ĩβɾ��������ǰ��Ԫ�أ�����Ϊ�����鿪ͷɾ��
	//������ƽ�����Ӷ�ΪO(n)
	bool remove(int pos)
	{
		if(pos<0||pos>=this->m_Size)
		{
			cout<<"the index is out of range";
			return false;
		}
		for(int i=pos;i+1<this->m_Size;i++)
		{
			this->arrayPtr[i]=this->arrayPtr[i+1];
		}
		this->m_Size--;
		if(this->m_Size<this->m_Capacity/4)
		{
			resize(this->m_Capacity/2);
		}
		return true;
	}
private:
	T* arrayPtr;
	int m_Capacity;//��������
	int m_Size;//�����С
};