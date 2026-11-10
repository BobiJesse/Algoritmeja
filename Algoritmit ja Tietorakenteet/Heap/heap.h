#pragma once
#define MAX_SIZE 255

class heap
{
public:
	heap() { heaparray[0] = 0; } //just initialize

	void insert(int key);
	//int del_min();
	void print();
	int length() { return heaparray[0]; } //just return the current length (stored at index 0)
private:
	int heaparray[MAX_SIZE + 1];
};

