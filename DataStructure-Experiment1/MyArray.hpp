/*
 * @Author: 郑岱锋 
 * @Date: 2022-09-24 12:14:29 
 * @Last Modified by:   郑岱锋 
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
	//有参构造
	myArray(int capacity=DEFAULT_CAPACITY)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->arrayPtr = new T[this->m_Capacity];
	}
	//拷贝构造
	myArray(const myArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->arrayPtr = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->arrayPtr[i] = arr.arrayPtr[i];
		}
	}
	//析构函数
	~myArray()
	{
		if (this->arrayPtr != NULL) { delete[]this->arrayPtr; this->arrayPtr = NULL; }
	}
	//尾插法
	void append(const T&value)
	{
		insert(this->m_Size,value);
	}
	//输出特定元素的位置
	//整个过程涉及对列表中元素的遍历操作，最好情况为1，最坏情况为n，平均情况为n/2，时间复杂度为O(n)
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
	//输出特定位置的元素
	//整个过程涉及对列表中元素的遍历操作，最好情况为1，最坏情况为n，平均情况为n/2，时间复杂度为O(n)
	void find(int index)
	{
		if(index<0||index>=this->m_Size)
		{
			cout<<"the index is out of range"<<endl;
		}
		cout<<"array["<<index<<"]="<<this->arrayPtr[index]<<endl;
	}
	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//在特定位置插入元素
	//插入操作涉及将插入位置后面的位置后移的操作，最好情况为在末尾插入，无需后移元素，最坏情况为在数组开头插入
	//操作的平均复杂度为O(n)
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
	//判断列表是否为空
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
	//返回数组大小
	int length()
	{
		return this->m_Size;
	}
	//等号运算符重载，用于拷贝列表
	myArray& operator=(const myArray&arr)
	{
		//防止自我赋值
		if (this == &arr)return *this;
			//先判断原来堆区是否有数据，如果有先释放
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
	//重载下标运算符，仅做右值版本
	T operator[](int index)const
	{
		if (index >= 0 && index < this->m_Size)
			return this->arrayPtr[index];
		else throw out_of_range("index out of range");
	}
	//重载左值版本
	T& operator[](int index)
	{
		if (index >= 0 && index < this->m_Size)
			return this->arrayPtr[index];
		else throw out_of_range("index out of range");
	}
	//打印列表的值
	void print()
	{
		if(isEmpty())
		{
			cout<<"列表为空，没有数据"<<endl;
			return;
		}
		for(int i=0;i<this->m_Size;i++)
		{
			cout<<this->arrayPtr[i]<<"\n";
		}
	}
	//调整列表的容量
	//调整容量大小涉及拷贝操作，需要对原数组进行遍历，时间复杂度为O(n)
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

	//移除列表中特定位置的元素
	//移除操作涉及将移除位置后面的位置前移的操作，最好情况为在末尾删除，无需前移元素，最坏情况为在数组开头删除
	//操作的平均复杂度为O(n)
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
	int m_Capacity;//数组容量
	int m_Size;//数组大小
};