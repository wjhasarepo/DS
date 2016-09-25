#ifndef ARRAY_H
#define ARRAY_H

#include<array>

template<typename Type>
class Array
{
	friend ostream &operator<<(ostream &, const Array &);
	friend istream &operator>>(istream &, Array &);
public:
	Array();
	Array(int);
	~Array();
	const Array $operator=(const Array &);
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
	void quickSort(int, int);
	void randomizedSelect(int, int, int);

private:
	Type *ptr;
	int size;
	
	void mergeSortHelper();
	void quickSortHelper(int, int);

	void swap(Type *, Type *);
}

template<typename Type>
Array<Type>::Array(int arraySize) 
{
	size = (arraySize > 0 ? arraySize:10);
	ptr = new int[size];
	assert(ptr!=0);
	++arrayCount;

	for(int i = 0; i<size; i++)
		ptr[i] = 0;
}

template<typename Type>
Array<Type>::~Array()
{
	delete []ptr;
	--arrayCount;
}

template<typename Type>
const Array &Array::operator=(const Array &right)
{
	if(&right != this)
	{
		if(size != right.size)
		{
			delete []ptr;
			size = right.size;
			ptr = new int[size];
			assert(ptr!=0);
		}
	
		for(int i = 0; i<size; i++)
			ptr[i] = right.ptr[i];
	}
	
	return *this;
}

template<typename Type>
istream &operator>>(istream &input, Array &a)
{
	for(int i=0; i<a.size; i++)
		input>>a.ptr[i];

	return input;
}

template<typename Type>
ostream &operator<<(istream &input, Array &a)
{
	int i;

	for(int i=0; i<a.size; i++)
		onput<<setw(4)<<a.ptr[i];
	if(i%4!=0)
		output<<endl;

	return output;
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
