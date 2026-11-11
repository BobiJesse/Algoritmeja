#include <iostream>
#include "heap.h"

heap::heap()
{
    heaparray = new int[MAX_SIZE + 1];
    heaparray[0] = 0;
}

heap::~heap()
{
    delete[] heaparray;
}

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
    if (length() == 0)
    {
        std::cout << "The heap is empty" << std::endl;
        return;
    }

	for (int i = 1; i <= length(); i++)
	{
		std::cout << heaparray[i] << " ";
	}
	std::cout << std::endl;
}


int heap::del_min()
{
    if (length() == 0)
    {
        std::cout << "The heap is empty" << std::endl;
        return -1;
    }

    int min = heaparray[1];


    heaparray[1] = heaparray[length()];
    heaparray[0]--;

    int index = 1;
    int leftChild = index * 2;
    int rightChild = index * 2 + 1;

    // Continue while the node has at least one child
    while (leftChild <= length())
    {
        int smallerChild;

        // Node has no right child
        if (rightChild > length())
        {
            smallerChild = leftChild;
        }
        //left child is smaller than right
        else if (heaparray[leftChild] <= heaparray[rightChild])
        {
            smallerChild = leftChild;
        }
        //right child is smaller
        else
        {
            smallerChild = rightChild;
        }

        // Check if we need to swap
        if (heaparray[index] > heaparray[smallerChild])
        {
            int temp = heaparray[index];
            heaparray[index] = heaparray[smallerChild];
            heaparray[smallerChild] = temp;

            // Move down to the child's position
            index = smallerChild;

            // Update child indices
            leftChild = index * 2;
            rightChild = index * 2 + 1;
        }
        else
        {
            // Heap order is correct
            break;
        }
    }

    return min;
}

