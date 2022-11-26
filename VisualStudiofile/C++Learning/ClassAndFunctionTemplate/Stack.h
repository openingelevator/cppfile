#pragma once
template<typename T>
class Stack
{
public:
	explicit Stack(int s = 10) :size(s > 0 ? s:10),top(-1),stackPtr(new T[size]){

	}
	~Stack(){
		delete[]stackPtr;
	}
	bool isEmpty()const{
		return top == -1;
	}
	bool isFull()const{
		return top == size - 1;
	}
	bool push(const T&pushvalue){
		if (!isFull())
		{
			stackPtr[++top] = pushvalue;
			return true;
		}
		return false;
	}
	bool pop(T&popvalue){
		if (!isEmpty()){
			popvalue = stackPtr[top--];
			return true;
		}
		return false;
	}

private:
	int size;
	int top;
	T* stackPtr;
};