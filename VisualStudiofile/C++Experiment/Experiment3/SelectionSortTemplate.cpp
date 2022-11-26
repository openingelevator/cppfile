#include<iostream>
using namespace std;
template<class T>
void swap(T* const element1, T* const element2)
{
	T hold = *element1;
	*element1 = *element2;
	*element2 = hold;
}

template<class T>
void selectionSort(T* const array, const int size)
{
	int smallest;
	for (int i = 0; i < size - 1; ++i)
	{
		smallest = i;
		for (int index = i + 1; index < size; ++index)
		
			if (array[index] < array[smallest])
			{
				smallest = index;
			}
			swap<T>(&array[i], &array[smallest]);
	
	}
}
int main()
{
	const int asize = 10;
	int array1[asize] = { 8,2,5,1,6,7,4,3,9,0 };
	float array2[asize] = { 2.1,2.2,2.4,1.5,1.8,3.0,1.9,0.4,0.2,0.5 };
	selectionSort<int>(array1, asize);
	selectionSort<float>(array2, asize);
	cout << "SelectionSort with type int" << endl;
	for (int i = 0; i < asize; i++)
	{
		cout << array1[i] << " ";
	}
	cout << "\nSelectionSort with type float" << endl;
	for (int i = 0; i < asize; i++)
	{
		cout << array2[i] << " ";
	}
}