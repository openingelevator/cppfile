#pragma once
#include<iostream>
using namespace std;

template<class T>
class myArray
{
public:
	//有参构造
	myArray(int capacity)
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
	//尾插法
	void Push_Back(const T&value)
	{
		if (this->m_Size == this->m_Capacity)return;
		this->arrayPtr[this->m_Size] = value;
		this->m_Size++;//更新数组大小
	}
	//尾删法
	void Pop_Back()
	{
		if (this->m_Size == 0)return;
		this->m_Size--;//逻辑删除
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
	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//返回数组大小
	int getSize()
	{
		return this->m_Size;
	}
private:
	T* arrayPtr;
	int m_Capacity;//数组容量
	int m_Size;//数组大小

};