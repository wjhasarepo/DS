#ifndef ARRAY_H
#define ARRAY_H

#include<array>

template<typename Type>
class Array
{
public:
	Array();
	Array(Type *, int);
	~Array();
	Array& operator=(const Array &arg)
	{
		if (this != &arg) 
		{ 
			this.size = arg.size;
		    this.array = new int[this.size];
		  	for(int i = 0; i < arg.size; i++)
			{
				this.array[i] = arg[i];
			}
		}

		return *this;
	}

	void mergeSort();
	void quickSort();

private:
	Type *array;
	int length;
	
	void mergeSortHelper();
	void quickSortHelper();

	void swap(Type *, Type *);
}

template<typename Type>
Array<Type>::Array() 
{
}

template<typename Type>
Array<Type>::Array(Type *arg, int size) 
{
	this.length = size;
	this.array = new int[length];
}

templeate<typename Type>
void Array<Type>::quickSort(int start, int end)
{
	if(start < end)
		int q = quickSortHelper(start, end);
	quickSort(start, q-1);
	quickSort(q+1, end);
}

templeate<typename Type>
void Array<Type>::randomizedSelect(int start, int end, int kth_smallest)
{
	if(kth_smallest == end)
		return this.array[end];

	int q = quickSortHelper(start, end);
	int k = q - start + 1;
	if(kth_smallest == k)
		return this.array[k];
	else if(kth_smallest < k)
		return quickSort(start, q-1);
	else
		return quickSort(q+1, end);
}

template<typename Type>
void Array<Node>::quickSortHelper(int start, int end)
{
	int x = this.array[end];
	int i = start - 1;
	for(int j = start; j < end; j++)
	{
		if(this.array[j] <= x)
		{
			i++;
			swap(&this.array[i], &this.array[j]);
		}
	}
	
	swap(&this.array[i+1], &x);

	return i + 1;
}
