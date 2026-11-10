#include <iostream>
#include "heap.h"

int main()
{
	heap myheap;

	myheap.insert(4);
	myheap.insert(2);
	myheap.insert(5);
	myheap.insert(3);
	myheap.insert(1);

	myheap.print();

	/*
	for (int i = 0; i < 300; i++)
	{
		myheap.insert(i + 10);
	}
	*/

	return EXIT_SUCCESS;
}