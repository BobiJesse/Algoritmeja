#pragma once
#include "node.h"

class LinkedList {
public:
	bool IsEmpty();
	void Insert(int value);
	void InsertEnd(int value);
	void Print();
	bool Find(int value);
	bool Delete(int value);

	LinkedList() {
		this->pHead = nullptr;
	}

private:
	Node* pHead;
};