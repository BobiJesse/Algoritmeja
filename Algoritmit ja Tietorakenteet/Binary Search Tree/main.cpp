#include <iostream>
#include "bst.h"

int main()
{
	BST bst;

	std::cout << "Inserting values" << std::endl << std::endl;
	bst.Insert(5);
	bst.Insert(3);
	bst.Insert(8);
	bst.Insert(2);
	bst.Insert(4);
	bst.Insert(1);
	bst.Insert(7);
	bst.Insert(6);
	bst.Insert(9);

	std::cout << "Printing..." << std::endl;
	bst.Print();

	return EXIT_SUCCESS;
}