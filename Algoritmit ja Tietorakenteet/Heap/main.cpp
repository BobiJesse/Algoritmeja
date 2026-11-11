#include <chrono>
#include <iostream>
#include "heap.h"

heap myheap;

void HeapSortSpeed(int size);

int main()
{
	std::cout << std::endl << "==================Programming task 8.1====================" << std::endl << std::endl;

	std::cout << std::endl << "Inserting values (17, 11, 6, 14, 22, 8, 1, 16, 10, 19, 12, 3, 5, 15 and 13) into the heap" << std::endl << std::endl;
	myheap.insert(17);
	myheap.insert(11);
	myheap.insert(6);
	myheap.insert(14);
	myheap.insert(22);
	myheap.insert(8);
	myheap.insert(1);
	myheap.insert(16);
	myheap.insert(10);
	myheap.insert(19);
	myheap.insert(12);
	myheap.insert(3);
	myheap.insert(5);
	myheap.insert(15);
	myheap.insert(13);

	std::cout << "Printing the heap" << std::endl << std::endl;
	myheap.print();

    std::cout << std::endl << "Creating array to hold deleted values..." << std::endl << std::endl;
	int deletedValues[15];

    std::cout << "Deleting min value until heap is empty" << std::endl << std::endl;
	for (int i = 0; i < 15; i++)
	{
		deletedValues[i] = myheap.del_min();
	}

	std::cout << "Printing the heap" << std::endl << std::endl;
	myheap.print();

	std::cout << std::endl << "Printing the array that holds deleted values" << std::endl << std::endl;

	for (int i = 0; i < 15; i++)
	{
		std::cout << deletedValues[i] << " ";
	}

	std::cout << std::endl;

	std::cout << std::endl << "==================Programming task 8.2====================" << std::endl << std::endl;

	HeapSortSpeed(100000);
	HeapSortSpeed(1000000);
	HeapSortSpeed(10000000);

	return EXIT_SUCCESS;
}

void HeapSortSpeed(int size)
{
	int* array1 = new int[size];

	//give random values to array
	for (int i = 0; i < size; i++)
	{
		array1[i] = rand() % 100000;
	}

	// Start measuring
	auto start = std::chrono::high_resolution_clock::now();

	//insert all values to heap
	for (int i = 0; i < size; i++)
	{
		myheap.insert(array1[i]);
	}

	//delete min value until heap is empty
	for (int i = 0; i < size; i++)
	{
		myheap.del_min();
	}

	// Stop measuring
	auto end = std::chrono::high_resolution_clock::now();

	// Calculate elapsed time
	std::chrono::duration<double> elapsed = end - start;

	std::cout << "Sorting of array with " << size << " elements took: " << elapsed.count() << " seconds" << std::endl;
}