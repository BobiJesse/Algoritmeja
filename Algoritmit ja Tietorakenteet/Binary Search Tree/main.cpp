#include <iostream>
#include "bst.h"

int main()
{
	BST bst;

	std::cout << "=================== Programming Task 7.1 =========================" << std::endl << std::endl;
	std::cout << "Inserting values..." << std::endl << std::endl;
	bst.Insert(5);
	bst.Insert(3);
	bst.Insert(8);
	bst.Insert(2);
	bst.Insert(4);
	bst.Insert(1);
	bst.Insert(7);
	bst.Insert(6);
	bst.Insert(9);
	std::cout << "Done." << std::endl << std::endl;

	std::cout << std::endl << "Printing simple version..." << std::endl << std::endl;
	bst.PrintSimple();

	std::cout << std::endl << "Printing level by level..." << std::endl << std::endl;
	bst.Print();

	std::cout << std::endl << "Finding element from BST..." << std::endl << std::endl;
	std::cout << std::boolalpha;
	std::cout << "Test if 5 is inside the tree: " << bst.FindKey(5) << std::endl;
	std::cout << "Test if 7 is inside the tree: " << bst.FindKey(7) << std::endl;
	std::cout << "Test if 9 is inside the tree: " << bst.FindKey(9) << std::endl;
	std::cout << "Test if 1 is inside the tree: " << bst.FindKey(1) << std::endl;
	std::cout << "Test if 6 is inside the tree: " << bst.FindKey(6) << std::endl;
	std::cout << "Test if 15 is inside the tree: " << bst.FindKey(15) << std::endl;

	std::cout << std::endl << "Counting nodes from BST..." << std::endl << std::endl;
	std::cout << "Number of nodes in the BST: " << bst.CountNodes() << std::endl;

	std::cout << std::endl << "Counting Leaves from BST..." << std::endl << std::endl;
	std::cout << "Number of leaves in the BST: " << bst.CountLeaves() << std::endl;

	std::cout << std::endl << "=================== Programming Task 7.2 =========================" << std::endl << std::endl;


	return EXIT_SUCCESS;
}