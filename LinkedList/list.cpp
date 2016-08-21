#include<iostream>
#include "list.h"

void test()
{
	List<int> IntegerList;
	int value[5] = {1, 4, 6, 7, 0};
	for(int i = 0; i < 5; i++)
	{
		IntegerList.insertAtBack(value[i]);
	}

	IntegerList.removeAt(value[2]);
	
	IntegerList.print();
}

int main(int argc, char **argv)
{
	test();
	
	return 0;
}
