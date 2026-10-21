#include "bst.h"
#include <iostream>

//This inserts smaller values left
//and equal or greater values right

void BST::Insert(int key)
{
	BSTNode* pNewNode = new BSTNode(key);

	if (IsEmpty())
	{
		//Set the new node with key value as the root
		pRoot = pNewNode;
		return;
	}
	else
	{
		//The tree is NOT empty...
		BSTNode* pCurrent = pRoot;
		BSTNode* pCandidate = pRoot; //pointer for next node

		while (pCandidate != nullptr)
		{
			pCurrent = pCandidate;
			if (pNewNode->key < pCurrent->key)
			{
				pCandidate = pCurrent->pLeft;
			}
			else
			{
				pCandidate = pCurrent->pRight;
			}
		}

		//Check which direction we need to put the new node
		if (pNewNode->key < pCurrent->key)
		{
			pCurrent->pLeft = pNewNode;
		}
		else
		{
			pCurrent->pRight = pNewNode;
		}
	}
}

void BST::Print()
{
	std::cout << pRoot->key << std::endl;
}
