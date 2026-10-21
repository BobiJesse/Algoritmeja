#pragma once
#include "bstNode.h"

class BST
{
public:

	BST() //Constructor, just set the root-node pointer to null
	{
		pRoot = nullptr;
	}

	bool IsEmpty() //return true if pRoot is null
	{
		return pRoot == nullptr;
	}

	void Insert(int key);

	void Print();

private:
	//Pointer to the root-node of the BST
	BSTNode* pRoot;

};

