#pragma once
#define MAX_SIZE 10000000

class heap
{
public:
	//heap() { heaparray[0] = 0; } //just initialize

	heap();
	~heap();

	void insert(int key);
	//int del_min();
	void print();
	int length() { return heaparray[0]; } //just return the current length (stored at index 0)
	int del_min();
private:
	//int heaparray[MAX_SIZE + 1];
	int* heaparray;
};

