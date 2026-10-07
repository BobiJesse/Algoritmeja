#include "linkedlist.h"
#include <iostream>

using std::cout;
using std::endl;


int main() {
	LinkedList linkedList; //Constructor called

	cout << "IsEmpty(): " << linkedList.IsEmpty() << endl << endl;

	cout << "5.1 Test case" << endl << endl;

	for (int i = 1; i < 100; i++) {
		linkedList.Insert(i);
	}

	/*for (int i = 1; i < 100; i++) {
		ll.InsertEnd(i);
	}*/
	linkedList.Print();

	cout << endl << "5.2 test cases" << endl << endl;

	cout << "IsEmpty(): " << linkedList.IsEmpty() << endl;

	cout << "Find(42): " << linkedList.Find(42) << endl;
	cout << "Find(66): " << linkedList.Find(66) << endl;
	cout << "Find(100): " << linkedList.Find(100) << endl;

	cout << "Delete(77): " << linkedList.Delete(77) << endl;
	cout << "Delete(21): " << linkedList.Delete(21) << endl;
	cout << "Delete(-1): " << linkedList.Delete(-1) << endl;

	for (int i = 1; i < 100; i++) {
		if (!linkedList.IsEmpty()) {
			linkedList.Delete(i);
		}
	}

	std::cout << "IsEmpty(): " << linkedList.IsEmpty() << std::endl;
	return EXIT_SUCCESS;
}