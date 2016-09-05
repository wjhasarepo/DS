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
		    arr = new int[this.size];
		  	for(int i = 0; i < arg.size; i++)
			{
				arr[i] = arg[i];
			}
		}

		return *this;
	}

	void bubbleSort();
	void insertionSort();
	void mergeSort();
	void quickSort();
	void selectionSort();

private:
	Type *arr;
	int length;
	
	void bubbleSortHelper();
	void insertionSortHelper();
	void mergeSortHelper();
	void quickSortHelper();
	void selectionSortHelper();

	void swap(Type *, Type *);
}

template<typename Type>
Array<Type>::Array() 
{
}

template<typename Type>
Array<Type>::Array(Type *arg, int len) 
{
	this.length = len;
	arr = new int[length];
}

template<typename Node>
void Array<Node>::bubbleSort()
{
	bubbleSortHelper();
}

template<typename Node>
void Array<Node>::insertionSort()
{
	insertionSortHelper();
}

template<typename Node>
void Array<Node>::selectionSort()
{
	selectionSortHelper();
}

template<typename Node>
void Array<Node>::bubbleSortHelper()
{
	int j = 0;
	for(int i = 0; i < this.length - 1; i++)
	{
		for(int j = i; j < this.length - 1; j++)
		{
			if(this.arr[j] > this.arr[j+1])
			{
				swap(&this.arr[j], &this.arr[j+1])
			}	
		}
	}
}

template<typename Node>
void Array<Node>::insertionSortHelper()
{
	int j = 0;
	for(int i = 1; i < this.length; i++)
	{
		int temp = this.arr[i];
		j = i-1;
		while(j > 0 && this.arr[j] > temp)
		{
			this.arr[j+1] = this.arr[j];
			j--;
		}

		this.arr[j] = temp;
	}
}

template<typename Node>
void Array<Node>::selectionSortHelper()
{
	for(int i = 0; i < this.size; i++)
	{
		int min = i;
		int temp = this.arr[i];
		j = i+1;
		while(j < this.length)
		{
			if(this.arr[j] < min)
			{
				min = j;
			}

			j++;
		}

		this.arr[i] = this.arr[min];
		this.arr[min] = temp;
	}
}
