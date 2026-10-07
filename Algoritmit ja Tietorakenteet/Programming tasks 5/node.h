#pragma once
class Node {
public:
	int data;
	Node* pNext;

	Node(int data) {
		this->data = data;
		this->pNext = nullptr;
	}
};