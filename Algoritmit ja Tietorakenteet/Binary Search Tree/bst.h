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

	void PrintSimple();

	void Print();

	void PrintNode(BSTNode* _node);

	bool FindKey(int _key);

	int CountNodes();

	int CountNode(BSTNode* _node);

	int CountLeaves();

	int CountLeaf(BSTNode* _node);

	bool Delete(int _key);

private:
	//Pointer to the root-node of the BST
	BSTNode* pRoot;

};

