#include <iostream>
#include "heap.h"

void heap::insert(int key)
{
	if (length() >= MAX_SIZE)
	{
		std::cerr << "ERROR: heap reached maximum size!" << std::endl;
		return;
	}

	if (length() < 1) //if the heap is empty
	{
		heaparray[1] = key; //put the key into index 1
		heaparray[0]++;
		return;
	}

	//Otherwise

	//1. insert the key into first available slot
	int index = length() + 1;
	heaparray[index] = key;

	//2. Increment length of the heap
	heaparray[0]++;

	//3. While heaporder not guaranteed:
	//	-track the newly inserted element
	//	-swap places with parent
	//	
	int parent_index = index / 2;
	while (heaparray[parent_index] > heaparray[index] && index > 1)
	{
		//Swap
		int tmp = heaparray[parent_index];
		heaparray[parent_index] = heaparray[index];
		heaparray[index] = tmp;
		//...done
		//update indices
		index = parent_index;
		parent_index = index / 2;
	}

	return;
}

void heap::print()
{
	for (int i = 1; i <= length(); i++)
	{
		std::cout << heaparray[i] << " ";
	}
	std::cout << std::endl;
}

