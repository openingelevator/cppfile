#pragma once
#include <iostream>
using std::ostream;
using std::istream;

class Array
{
	   friend ostream & operator<<(ostream&output, const Array&a);
	   friend istream & operator>>(istream&input, Array&a);
public:
	   Array(int arraySize= 10);
	   Array(const Array& arrayToCopy);
	   ~Array();              
	   int getSize() const; 

	  const Array & operator=(const Array& right); 
	  bool operator==(const Array&right) const; 
	  bool operator!=(const Array& right) const
	  {
		  return !(*this == right);
	  }
	  int& operator[](int subscript);
	  int operator[](int subscript) const;
private:
	int size;
	int* ptr; 
}; 
