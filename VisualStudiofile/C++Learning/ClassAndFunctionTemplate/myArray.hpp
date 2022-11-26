#pragma once
#include<iostream>
using namespace std;

template<class T>
class myArray
{
public:
	//�вι���
	myArray(int capacity)
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
	//β�巨
	void Push_Back(const T&value)
	{
		if (this->m_Size == this->m_Capacity)return;
		this->arrayPtr[this->m_Size] = value;
		this->m_Size++;//���������С
	}
	//βɾ��
	void Pop_Back()
	{
		if (this->m_Size == 0)return;
		this->m_Size--;//�߼�ɾ��
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
	//������������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//���������С
	int getSize()
	{
		return this->m_Size;
	}
private:
	T* arrayPtr;
	int m_Capacity;//��������
	int m_Size;//�����С

};