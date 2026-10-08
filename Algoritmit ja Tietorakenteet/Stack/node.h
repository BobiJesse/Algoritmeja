#pragma once
template <typename T> class Node {
public:
	T data;
	Node* pNext;

	Node(T data) {
		this->data = data;
		this->pNext = nullptr;
	}
};