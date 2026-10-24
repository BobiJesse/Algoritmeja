#include "bst.h"
#include <iostream>
#include <queue>

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
	if (IsEmpty())
	{
		return;
	}

	std::queue<BSTNode*> nodeQueue;
	nodeQueue.push(pRoot);

	while (!nodeQueue.empty())
	{
		int queueSize = nodeQueue.size();

		for (int i = 0; i < queueSize; i++)
		{
			BSTNode* pCurrent = nodeQueue.front();

			nodeQueue.pop();

			std::cout << pCurrent->key << " ";

			if (pCurrent->pLeft != nullptr)
			{
				nodeQueue.push(pCurrent->pLeft);
			}

			if (pCurrent->pRight != nullptr)
			{
				nodeQueue.push(pCurrent->pRight);
			}
		}

		std::cout << std::endl;
	}
}

void BST::PrintSimple()
{
	PrintNode(pRoot);
}

void BST::PrintNode(BSTNode* _node)
{
	if (_node == nullptr)
	{
		return;
	}

	std::cout << _node->key << std::endl;

	if (_node->pLeft != NULL)
	{
		PrintNode(_node->pLeft);
	}

	if (_node->pRight != NULL)
	{
		PrintNode(_node->pRight);
	}
}

bool BST::FindKey(int _key) //Checks if key is found inside BST
{
	BSTNode* pCurrent = pRoot;

	while (pCurrent != nullptr)
	{
		if (_key == pCurrent->key)
		{
			return true;
		}
		else if (_key < pCurrent->key)
		{
			pCurrent = pCurrent->pLeft;
			continue;
		}
		else
		{
			pCurrent = pCurrent->pRight;
		}
	}
	return false;
}

int BST::CountNodes()
{
	int numberOfNodes = CountNode(pRoot);

	return numberOfNodes;
}

int BST::CountNode(BSTNode* _node)
{
	if (_node == nullptr)
	{
		return 0;
	}

	int _leftCount = CountNode(_node->pLeft);

	int _rightCount = CountNode(_node->pRight);

	return _leftCount + _rightCount + 1;
}

int BST::CountLeaves()
{
	int numberOfLeaves = CountLeaf(pRoot);

	return numberOfLeaves;
}

int BST::CountLeaf(BSTNode* _node)
{
	if (_node == nullptr)
	{
		return 0;
	}

	int _leftCount = CountLeaf(_node->pLeft);
	int _rightCount = CountLeaf(_node->pRight);

	if (_node->pLeft == nullptr && _node->pRight == nullptr)
	{
		return _leftCount + _rightCount + 1;
	}
	else
	{
		return _leftCount + _rightCount;
	}
}

bool BST::Delete(int _key)
{
	if (IsEmpty())
	{
		std::cout << "BST already empty, returning false" << std::endl;
		return false;
	}

	BSTNode* pCurrent = pRoot;
	BSTNode* pPrevious = pRoot;

	while (pCurrent != nullptr)
	{
		if (_key == pCurrent->key) //Value of key found
		{
			//=========================ROOT===========================
			if (pCurrent == pRoot && pPrevious == pRoot && pCurrent->pLeft == nullptr && pCurrent->pRight == nullptr) //Check if deleted node is the root with no children
			{
				pRoot = nullptr;
				std::cout << "Deleted node was the root of the BST with no child nodes, deleting that node..." << std::endl;
				delete pCurrent;
				return true;
			}

			//=========================LEAF===========================
			if (pCurrent->pLeft == nullptr && pCurrent->pRight == nullptr) //Deleted node is a leaf
			{
				std::cout << "Deleted node was a leaf, deleting that node..." << std::endl;
				if (pCurrent->key < pPrevious->key) //Parent node is bigger than current
				{
					pPrevious->pLeft = nullptr;
					delete pCurrent;
				}
				else //Parent node is smaller or same size as current
				{
					pPrevious->pRight = nullptr;
					delete pCurrent;
				}
				return true;
			}

			//=========================NODE WITH 2 CHILDREN===========================
			if (pCurrent->pLeft != nullptr && pCurrent->pRight != nullptr)
			{
				BSTNode* pReplaceParent = pCurrent;
				BSTNode* pReplace = pCurrent->pRight;

				//Search for the smallest value on the right
				while (pReplace->pLeft != nullptr)
				{
					pReplaceParent = pReplace;
					pReplace = pReplace->pLeft;
				}

				pCurrent->key = pReplace->key;

				if (pReplaceParent->pLeft == pReplace)
				{
					pReplaceParent->pLeft = pReplace->pRight; //Connect parent with right node
				}
				else
				{
					pReplaceParent->pRight = pReplace->pRight;
				}

				delete pReplace;
				return true;
			}

			//=========================NODE WITH 1 CHILD===========================
			if (pCurrent->pLeft != nullptr) //Current node has a child node on the left side
			{
				if (pCurrent == pRoot)
				{
					pRoot = pCurrent->pLeft;
					delete pCurrent;
					return true;
				}

				if (pPrevious->pLeft == pCurrent) //Parent node is on the right
				{
					pPrevious->pLeft = pCurrent->pLeft;
					delete pCurrent;
				}
				else //Parent node is on the left
				{
					pPrevious->pRight = pCurrent->pLeft;
					delete pCurrent;
				}
				return true;
			}
			else if (pCurrent->pRight != nullptr) //Current node has a child node on the right side
			{
				if (pCurrent == pRoot)
				{
					pRoot = pCurrent->pRight;
					delete pCurrent;
					return true;
				}

				if (pPrevious->pRight == pCurrent) //Parent node is on the left side
				{
					pPrevious->pRight = pCurrent->pRight;
					delete pCurrent;
				}
				else //Parent node is on the right side
				{
					pPrevious->pLeft = pCurrent->pRight;
					delete pCurrent;
				}
				return true;
			}
		}
		else if (_key < pCurrent->key) //Value is bigger than searched key
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->pLeft;
			continue;
		}
		else //Value is smaller than searched key
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->pRight;
		}
	}
	return false;
}
