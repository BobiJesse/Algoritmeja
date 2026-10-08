#pragma once
#include "node.h"

template<typename T> class Stack
{
public:
	bool IsEmpty() { return pTop == nullptr; }
	void Push(T data)
	{
		Node<T>* pNewNode = new Node<T>(data); //Create a new Node
		pNewNode->pNext = pTop; //New Node's next has to point to the old top Node
		pTop = pNewNode; //Make top point to the new Node
	}
	T Pop()
	{
		if (IsEmpty())
		{
			return static_cast<T>(-1); //return -1 if stack is empty
		}

		//The stack is not empty, so lets pop!
		Node<T>* pToBeDeleted = pTop;
		//Store the data
		T value = pToBeDeleted->data;
		//Update Top-Pointer
		pTop = pToBeDeleted->pNext;
		//Remove the node to be deleted
		delete pToBeDeleted;

		return value;
	}
	int Top()
	{
		if (IsEmpty())
		{
			return static_cast<T>(-1);
		}

		return pTop->data;
	}

private:
	Node<T>* pTop;
};