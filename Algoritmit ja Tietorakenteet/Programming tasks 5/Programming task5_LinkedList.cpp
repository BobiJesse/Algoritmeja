#include "linkedlist.h"
#include <iostream>

using std::cout;
using std::endl;

bool LinkedList::IsEmpty()
{
	return this->pHead == nullptr;
}

void LinkedList::Insert(int value)
{
	Node* pNode = new Node(value); //Make a new Node

	if (IsEmpty()) //If the list is empty, the new node becomes the first node.
	{
		this->pHead = pNode;
	}
	else //Put the new node before the current first node.
	{
		pNode->pNext = pHead;
		pHead = pNode;
	}
}

void LinkedList::InsertEnd(int value)
{
	Node* pNode = new Node(value); //Make a new node

	if (IsEmpty())//If there are no nodes, this is the first one.
	{
		this->pHead = pNode;
	}
	else //Start from the first node and move through the list.
	{
		Node* pCurrent = pHead;

		while (pCurrent->pNext != nullptr)
		{
			pCurrent = pCurrent->pNext;
		}

		pCurrent->pNext = pNode;
	}
}

void LinkedList::Print()
{
	Node* pTmp = this->pHead;
	while (pTmp != nullptr)
	{
		cout << pTmp->data << endl; // Prints out the data
		pTmp = pTmp->pNext; // Sets the node to the next one.
	}
}

bool LinkedList::Find(int value)
{
	Node* cTmp = this->pHead;
	while (cTmp != nullptr)
	{
		if (cTmp->data == value) 
		{
			//cout << "Found: " << cTmp->data << endl; //Just confirmation print during debug
			return true;
		}
		else
		{
			cTmp = cTmp->pNext; // Set's the head to next node.
		}
	}

	return false; // If the value isn't found;
}

bool LinkedList::Delete(int value)
{
	Node* cTmp = this->pHead;

	//Check if the first node contains the value.
	if (pHead->data == value) 
	{
		Node* tempNode = pHead;
		pHead = pHead->pNext;
		delete tempNode;
		return true;
	}

	while (cTmp->pNext != nullptr)
	{
		if (cTmp->pNext->data == value) 
		{
			Node* tempNode = cTmp->pNext;
			cTmp->pNext = tempNode->pNext;
			delete tempNode;
			return true;
		}
		else
		{
			cTmp = cTmp->pNext; //Set's the head to next node.
		}
	}
	return false; // If the value isn't found;
}
